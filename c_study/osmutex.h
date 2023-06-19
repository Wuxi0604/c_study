#ifndef _OS_MUTEX_H
#define _OS_MUTEX_H

#include "basetypes.h"

#ifdef WIN32

#else
#include <pthread.h>
#endif

typedef struct os_mutex_struct os_mutex_t;
struct os_mutex_struct
{
#ifdef WIN32
    RTL_CRITICAL_SECTION cs;
#else
    pthread_mutex_t pmutex;
#endif
};

void
os_mutex_create(os_mutex_t* mutex)
{
    ASSERT_NULL(mutex);

#ifdef WIN32
    InitializeCriticalSection(&mutex->cs);
#else
    pthread_mutex_init(&mutex->pmutex);
#endif
}

void
os_mutex_enter(os_mutex_t* mutex)
{
#ifdef WIN32
    EnterCriticalSection(&mutex->cs);
#else
    pthread_mutex_lock(&mutex->pmutex);
#endif
}

void
os_mutex_exit(os_mutex_t* mutex)
{
#ifdef WIN32
    LeaveCriticalSection(&mutex->cs);
#else
    pthread_mutex_unlock(&mutex->pmutex);
#endif
}

void
os_mutex_free(os_mutex_t* mutex)
{
#ifdef WIN32
    DeleteCriticalSection(&mutex->cs);
#else
    pthread_mutex_destroy(&mutex->pmutex);
#endif
}

#endif
