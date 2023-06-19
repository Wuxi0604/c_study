#include <stdio.h>
#include "c_study.h"


/* ͨ��״̬��ʵ���ļ����ʵ�ͳ�� */
uint32
word_count(
    schar* filename
)
{
    schar  c;
    uint32 status = STATUS_INIT;
    uint32 word = 0;
    FILE* fp = fopen(filename, "r");
    if (!fp)
        return UINT32_UNDEFINED;

    while (c = fgetc(fp) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            status = STATUS_OUT;
        }
        else
        {
            ASSERT(status == STATUS_OUT);
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


static
schar* 
prompt(
    schar* line, 
    uint32 size
)
{
    schar* retval;
    do
    {
        printf(">>");
        retval = fgets(line, size, stdin);
    } while (retval && *line == '\n');

    line[strlen(line) - 1] = '\0';

    return retval;
}


void test_sds()
{
    sds s;
    s = sdsempty();
    s = sdscat(s, "test_sds");
    s_debug("s: %s \n", s);

    sdsfree(s);
}

#define INPUT_BUFFER 1024

sint32
main(
    sint32 argc, 
    schar** argv
)
{
    schar line[INPUT_BUFFER] = { 0 };

    //while (prompt(line, INPUT_BUFFER))
    //{
    //   //strsep �ĺ���ʵ��
    //}

    test_sds();
}

bool
select_db(
    sint32 fd
)
{
    sds    cmd;

    //�����dbnum == 0; return;

    cmd = sdsempty();
    cmd = sdscatprintf(cmd, "SELECT %d\r\n", 6);

    cmd = sdscatlen(cmd, cmd, sdslen(cmd));

    sdsfree(cmd);
    return TRUE;
}

static void sds_oom_abort(schar* module_name)
{
    ASSERT(module_name);
    fprintf(stderr, "%s : Out of Memery, abort\n", module_name);
    abort();
}
