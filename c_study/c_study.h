#ifndef C_STUDY_H
#define C_STUDY_H

#include "basetypes.h"
#include "dlist.h"
#include "sds.h"

/* 单词的个数等于OUT->IN的次数 */
#define STATUS_OUT     0             //分隔符进入
#define STATUS_IN      1             //字符进入
#define STATUS_INIT    STATUS_OUT    //初始化为OUT

#define MAX_PHONE_LEN  11 //电话号码长度

typedef schar phonenum_t[MAX_PHONE_LEN + 1];
typedef struct person_struct person_t;
struct person_struct
{
    sysname_t  name;
    phonenum_t phone;
    DLIST_NODE_T(person_t) link;
};

typedef DLIST_T(person_t) lst_person;

#endif
