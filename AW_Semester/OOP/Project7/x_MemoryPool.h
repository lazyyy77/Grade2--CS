#ifndef __x_MEMORYPOOL_H__
#define __x_MEMORYPOOL_H__
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

/* this headfile contains the self-designed allocator.
It contains TWO class, "xmemory0" and "x_MemoryPool".
the first is the interface, and the second use the memorypool strategy.
*/


class x_MemoryPool
{
public:
    /*the allocate and deallocate can be called by xmeomry0,
    to alloc and dealloc memory with memorypool strategy.*/
    static void *allocate(std::size_t numBytes);
    static void deallocate(void *p, std::size_t numBytes);

private:

    /*use a union to save the space.
    when not assigned, union == FreeList *, the pointer to the freelist;
    when assigned, union == char *, the first address that save the data;*/
    union FreeList{
        union FreeList *list_next;
        char *data;
    };
    typedef FreeList *p_FreeList;

    static char *mempool_start;                             //start of the memorypool
    static char *mempool_end;                               //end of the memorypool
    static std::size_t total_capc;                          //the temporary capacity of memorypool
    static const int MAX_CAPC = 16384;                      //the biggest block that don't use malloc to alloc directly
    static const int blockStride = 64;                      //the blockstride
    static p_FreeList volatile free_list[MAX_CAPC/blockStride]; //the array that save the address of different size of freelist head

    static std::size_t FindIndex(std::size_t numBytes);     //find the corresponding size of freelist
    static std::size_t FindAlign(std::size_t numBytes);     //align the memory, accelerate the visit
    static char *AllocBlock(std::size_t size, int &num);    //alloc block from the memorypool
    static char *SupplyFreeList(std::size_t numBytes);      //supply the freelist

};

void * x_MemoryPool::allocate(std::size_t numBytes){
    p_FreeList volatile *freelist_temp;
    p_FreeList alloc_address = nullptr;
    void *return_address;

    /*case 1:   required numBytes > the max capacity of memory pool
                use malloc to apply from the memory directly.*/
    if(numBytes > (std::size_t)MAX_CAPC){
        return_address = std::malloc(numBytes);
        if(return_address != nullptr)   return return_address;
        else    throw std::bad_alloc();
    }
    /*case 2:   first check the free-list*/
    freelist_temp = free_list + FindIndex(numBytes);
    alloc_address = (*freelist_temp);
    if(alloc_address != nullptr){
        *freelist_temp = alloc_address->list_next;
        return alloc_address;
    }
    /*case 3:   alloc_address == nullptr, or in other word,
                the corresponding free_list is null. need to
                allocate from memory pool. what's more, 'd better
                supply the freelist to reduce calling case 3.*/
    return_address = SupplyFreeList(FindAlign(numBytes));
    return return_address;

}
void x_MemoryPool::deallocate(void *address_free, std::size_t numBytes){
    p_FreeList address_dealloc = (p_FreeList)address_free;
    p_FreeList volatile *freelist_temp;
    
    if(numBytes > (std::size_t)MAX_CAPC){
        std::free(address_free);
    }else{
        freelist_temp = free_list + FindIndex(numBytes);
        address_dealloc->list_next = *freelist_temp;
        *freelist_temp = address_dealloc;
    }
}

std::size_t inline x_MemoryPool::FindIndex(std::size_t numBytes){
    return (numBytes + blockStride - 1) / blockStride - 1;
}
std::size_t inline x_MemoryPool::FindAlign(std::size_t numBytes){
    return ((numBytes + blockStride - 1) & ~(blockStride - 1));
}

char *x_MemoryPool::AllocBlock(std::size_t numBytes, int &apply_num){
    char *return_address;
    std::size_t allocBytes = 0;
    std::size_t totalBytes = numBytes * apply_num;
    std::size_t leftBytes = mempool_end - mempool_start;

    /*case 1:   if memory pool is enough to allocate the totalBytes
                then just allocate to freelist*/
    if(leftBytes >= totalBytes){
        return_address = mempool_start;
        mempool_start += totalBytes;
        //std::cout << " chunallock_case1_before_return ";
        return return_address;
    }
    /*case 2:   if the memory pool can't afford totalBytes,
                but can afford at least one block than can
                fulfill the basic memory needl, then allocate the most */
    else if(leftBytes >= numBytes){
        apply_num = leftBytes/numBytes;
        return_address = mempool_start;
        mempool_start = mempool_end;
        //std::cout << " chunallock_case2_before_return ";
        return return_address;
    }
    /*case 3:   if the space is not enough for a single numBytes
                or it's already empty, */
    else{
        allocBytes = ((MAX_CAPC > totalBytes) ? MAX_CAPC : totalBytes) * 2;
        //std::cout << " _in_case3_before_add_freelist_ ";
        if(mempool_start != nullptr && allocBytes >0){
            p_FreeList volatile *freelist_temp = free_list + FindIndex(leftBytes);
            ((p_FreeList)mempool_start)->list_next = *freelist_temp;
            *freelist_temp = (p_FreeList)mempool_start;
        }
        mempool_start = (char *)malloc(allocBytes);
        mempool_end = mempool_start + allocBytes;
        total_capc += allocBytes;
        //std::cout << " chunallock_case3_before_return ";
        return AllocBlock(numBytes, apply_num);
    }
}
char *x_MemoryPool::SupplyFreeList(std::size_t numBytes){
    int apply_num = 30;                                     //apply for apply_num numBytes once to avoid frequent appliance
    p_FreeList volatile *freelist_temp;
    p_FreeList alloc_address;
    p_FreeList freelist_next;
    char *return_address = AllocBlock(numBytes, apply_num);
    if(apply_num != 1){                                     //successfully apply for more than one numBytes.
        freelist_temp = free_list + FindIndex(numBytes);    //need to connect all of them to the freelist in the way of chain
        *freelist_temp = alloc_address = (p_FreeList)((char *)return_address + numBytes);
        int count=1;
        do{
            alloc_address->list_next = (p_FreeList)((char *)alloc_address + numBytes);
            alloc_address = alloc_address->list_next;
        }while(count++ < apply_num-1);
        alloc_address->list_next = nullptr;
    }

    return return_address;

}

char *x_MemoryPool::mempool_start = nullptr;
char *x_MemoryPool::mempool_end = nullptr;
std::size_t x_MemoryPool::total_capc = 0;
x_MemoryPool::p_FreeList volatile x_MemoryPool::free_list[MAX_CAPC/blockStride]={nullptr};

/*the xmemory0 class is the interface of the allocator;
it has the basic typedef and functions that is required for a allocator;
the distinguished part is the allocate and deallocate function,
who calls the memorypool-based accomplishment with class x_MemoryPool;
*/
template<class _Ty>
class xmemory0
{
private:

public:
    typedef _Ty                 value_type;
    typedef _Ty*                pointer;
    typedef const _Ty*          const_pointer;
    typedef _Ty&                reference;
    typedef const _Ty&          const_reference;
    typedef std::size_t         size_type;
    typedef ptrdiff_t           difference_type;

    xmemory0(){};
    ~xmemory0(){};

    template<typename U> struct rebind{ 
        typedef xmemory0<U> other;
    };
    template<class U>
    xmemory0(const xmemory0<U> &diff_type) noexcept;

    pointer address(reference _Val) const noexcept{
        return &_Val;
    }
    const_pointer address(const_reference _Val) const noexcept{
        return &_Val;
    }

    void deallocate(pointer _Ptr, size_type _Count){
        x_MemoryPool::deallocate(_Ptr, _Count);
    }
    pointer allocate(std::size_t _Count){
        if(_Count > size_type(-1) / sizeof(value_type)) { std::cout << "1"; throw std::bad_alloc();}
        auto alloc_ptr = static_cast<pointer>(x_MemoryPool::allocate(_Count * sizeof(value_type)));
        if(alloc_ptr != NULL)   return alloc_ptr;
        else    {std::cout << "2";throw std::bad_alloc();}
    }
    
    template<class _Uty>
    void destroy(_Uty *_Ptr){
        _Ptr->~_Uty();
    }
    template<class _Objty, class... _Types>
    void construct(_Objty *_Ptr, _Types&&... _Args){
        ::new (const_cast<void *>(static_cast<const volatile void *>(_Ptr)))_Objty(std::forward<_Types>(_Args)...);
    }
    
};

template <class Tleft, class Tright>
bool operator==(const xmemory0<Tleft> &lhs, const xmemory0<Tright> &rhs) {
    return true;
}

template <class Tleft, class Tright>
bool operator!=(const xmemory0<Tleft> &lhs, const xmemory0<Tright> &rhs) {
    return false;
}







#endif

