# DIP 图像信息处理

## 资源
+ 包含代码、实验报告、期末复习资料。
+ 学期内lab1-4的读入“存在一定问题”，已于期末订正。故代码请以tx.cpp，而非实验报告中为准。
    - 读入存在的“错误”为：我所使用的BMP文件是在一网站上由jpg格式转换得到；后续实验发现该网站转换得到的BMP文件BMIH部分`bmih.bisize`有误，理论值为40但实际值为124，具体原因不详，应该是转换时网站的问题。导致image data在理论和实际上的开始位置不同，图像出现奇怪的溢出和边界问题。若采用文件头正确的BMP文件应不会遇到这种问题。此问题已在lab5修复，并更新所有lab的读入代码。但实验报告中代码未作修改。
    - 故个人建议不要用`./pic`中的图片作为BMP图片检测你的代码。
+ 笔记依托最后一节课黎叔画的重点而做。**有部分深度学习部分的笔记未更新，仅记录可能考点**。