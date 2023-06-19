#include <stdio.h>
#include "c_study.h"


/* 通过状态机实现文件单词的统计 */
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

/* 通讯录 */
/*
1.添加一个人员        | 人员如何存储（内存、文件） 链表
2.打印所有人员        | 人员信息 （姓名 电话）
3.删除一个人员        | 
4.查找一个人员        | 
5.保存文件            | 
6.加载文件            | 
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
    //   //strsep 的函数实现
    //}

    test_sds();
}

bool
select_db(
    sint32 fd
)
{
    sds    cmd;

    //如果是dbnum == 0; return;

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
