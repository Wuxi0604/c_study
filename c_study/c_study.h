#ifndef C_STUDY_H
#define C_STUDY_H

#include "basetypes.h"
#include "dlist.h"

/* ���ʵĸ�������OUT->IN�Ĵ��� */
#define OUT     0      //�ָ�������
#define IN      1      //�ַ�����
#define INIT    OUT    //��ʼ��ΪOUT

#define MAX_PHONE_LEN  11 //�绰���볤��

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
