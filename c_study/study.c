#include <stdio.h>
#include "c_study.h"


/* 通过状态机实现文件单词的统计 */
uint32
word_count(
    schar* filename
)
{
    schar  c;
    uint32 status = INIT;
    uint32 word = 0;
    FILE* fp = fopen(filename, "r");
    if (!fp)
        return UINT32_UNDEFINED;

    while (c = fgetc(fp) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            status = OUT;
        }
        else
        {
            ASSERT(status == OUT);
            word++;
        }
    }
    return word;
}

/* 通讯录 */
/*
1.添加一个人员        | 人员如何存储（内存、文件） 链表
2.打印所有人员        | 人员信息 （姓名 电话）
3.删除一个人员        | 
4.查找一个人员        | 
5.保存文件            | 
6.加载文件            | 
*/