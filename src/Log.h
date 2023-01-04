// 检查看是否有一个_LOG_H的符号被定义
// 如果没有被定义 将继续在编译中包含以下代码
#ifndef _LOG_H
#define _LOG_H
// pragma once 监督这个头文件 
// 阻止我们单个头文件被多次包含
// 并转换为单个翻译单元
// #pragma once 
#include <iostream>

// static 将函数标记为静态的
// 在链接log函数时 log函数只能是内部函数
// 对任何其他的.obj或.o文件不可见

// 声明 没有函数体
void vLog(const char* message);

inline void iLog(const char* message);
#endif
