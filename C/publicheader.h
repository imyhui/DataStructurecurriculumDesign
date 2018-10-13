#ifndef PUBLICHEADER_H_INCLUDED
#define PUBLICHEADER_H_INCLUDED

#include<iostream>
#include<queue>

#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()等
#include<limits.h> // INT_MAX等
#include<stdio.h> // EOF(=^Z或F6),NULL
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h> // floor(),ceil(),abs()
#include<process.h> // exit()
#include<stdarg.h>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1
#define TRUE 1
#define FALSE 0
#define UNDERFLOW 4
typedef int ElemType;
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE

#endif // PUBLICHEADER_H_INCLUDED

