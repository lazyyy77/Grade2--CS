#include <ctime>
#include <iostream>
#include <random>
#include <vector>

#include "x_MemoryPool.h"

using Point2D = std::pair<int, int>;

/*required TestSize ∈ [5000, 10000], PickSize ∈ [1000, 60000];
--when TestSize > 50000, the requirment of memory will overflow? 
  my vsc sometimes just crashed even without throw std::bad_alloc...
 -when TestSize > 20000, the shell will throw std::bad_alloc and die...
 -so 'd betten test in the recommended size (or maybe it's the problem of my laptop)
*/ 
const int TestSize = 15000;
const int PickSize = 10000;

//here's the function to test diffrent allocator with the given sample
//the function use the given allocator to operate on Point2D and vector.
template <template <class> class MyAllocator>
    void test() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, TestSize);

        // vector creation
        using IntVec = std::vector<int, MyAllocator<int>>;
        std::vector<IntVec, MyAllocator<IntVec>> vecints(TestSize);
        for (int i = 0; i < TestSize; i++) vecints[i].resize(dis(gen));

        using PointVec = std::vector<Point2D, MyAllocator<Point2D>>;
        std::vector<PointVec, MyAllocator<PointVec>> vecpts(TestSize);
        for (int i = 0; i < TestSize; i++) vecpts[i].resize(dis(gen));

        // vector resize
        for (int i = 0; i < PickSize; i++) {
            int idx = dis(gen) - 1;
            int size = dis(gen);
            vecints[idx].resize(size);
            vecpts[idx].resize(size);
        }

        // vector element assignment
        {
            int val = 10;
            int idx1 = dis(gen) - 1;
            int idx2 = vecints[idx1].size() / 2;
            vecints[idx1][idx2] = val;
            if (vecints[idx1][idx2] == val)
                std::cout << "correct assignment in vecints: " << idx1
                          << std::endl;
            else
                std::cout << "incorrect assignment in vecints: " << idx1
                          << std::endl;
        }
        {
            Point2D val(11, 15);
            int idx1 = dis(gen) - 1;
            int idx2 = vecpts[idx1].size() / 2;
            vecpts[idx1][idx2] = val;
            if (vecpts[idx1][idx2] == val)
                std::cout << "correct assignment in vecpts: " << idx1
                          << std::endl;
            else
                std::cout << "incorrect assignment in vecpts: " << idx1
                          << std::endl;
        }
    }


int main() {

    clock_t start;
    start = clock();
    //here's to test my allocator.
    test<xmemory0>();
    std::cout << "xmemory0 cost: "
              << (clock() - start) * 1.0 / CLOCKS_PER_SEC << " seconds"
              << std::endl
              << std::endl;

    start = clock();
    //here's to test std::allocator.
    test<std::allocator>();
    std::cout << "std::allocator cost: "
              << (clock() - start) * 1.0 / CLOCKS_PER_SEC << " seconds"
              << std::endl
              << std::endl;
    return 0;
}
