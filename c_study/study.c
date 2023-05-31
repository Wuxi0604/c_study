#include <stdio.h>
#include "c_study.h"


/* ͨ��״̬��ʵ���ļ����ʵ�ͳ�� */
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

/* ͨѶ¼ */
/*
1.���һ����Ա        | ��Ա��δ洢���ڴ桢�ļ��� ����
2.��ӡ������Ա        | ��Ա��Ϣ ������ �绰��
3.ɾ��һ����Ա        | 
4.����һ����Ա        | 
5.�����ļ�            | 
6.�����ļ�            | 
*/