#!/bin/bash

if [ $1 == 'E' ]; then
    #-E 预处理 生成.i文件 对字符串文件中的宏定义进行处理 同时删除注释行
    g++ src/*.cpp -E
elif [ $1 == 'S' ]; then
    #-S 编译 生成.s文件 编译是.i文件进行语法分析 词法分析等 生成汇编语言的程序 
    g++ src/*.cpp -S
elif [ $1 == 'C' ]; then
    #-C 汇编 生成.o文件 将汇编程序转换成电脑可以识别的二进制文件
    g++ src/*.cpp -C
else
    #-o 链接 生成可执行文件 链接静态库 生成可执行文件
    g++ src/*.cpp -o target
fi
