#ifndef BASETYPE_H
#define BASETYPE_H

#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <dirent.h>
#endif

#if defined(WIN32) && !defined(__cpluscplus)
#define INLINE __inline
#endif

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif

#define true  1
#define false 0

typedef signed char		    sint8;
typedef unsigned char		uint8;
typedef short				sint16;
typedef unsigned short		uint16;
typedef int					sint32;
typedef unsigned int		uint32;
typedef uint8				byte;
typedef char                schar;
typedef FILE                file_t;

typedef sint32              bool_t;

#ifndef __cplusplus
typedef int bool;
#endif

#ifdef WIN32
typedef __int64				   sint64;
typedef unsigned long long int uint64;
#else
typedef long long int          sint64;
typedef unsigned long long int uint64;
#endif

#ifdef BIT64
typedef sint64 sint6432;
typedef uint64 uint6432;
#else
typedef sint32 sint6432;
typedef uint32 uint6432;
#endif


#if defined(WIN32)
#define SINT64_MAX			(sint64)0X7FFFFFFFFFFFFFFF
#define SINT64_MIN			((sint64)(-0X7FFFFFFFFFFFFFFF) - (sint64)1)
#define SINT64_UNDEFINED	(sint64)0XFFFFFFFFFFFFFFFF
#else
#define SINT64_MAX          0X7FFFFFFFFFFFFFFFLL
#define SINT64_MIN          (-OX7FFFFFFFFFFFFFFFLL - 1LL)
#define SINT64_UNDEFINED    0XFFFFFFFFFFFFFFFFLL
#endif

#ifdef UINT32_MAX
#undef UINT32_MAX
#endif

#ifdef UINT16_MAX
#undef UINT16_MAX
#endif

#define UINT32_MAX	     (uint32)(-2)
#define UINT32_UNDEFINED (uint32)(-1)
#define SINT32_MAX       (sint32)2147483647
#define SINT32_MIN       (-2147483647 - 1)

#define UINT16_MAX       (uint16)(-2)
#define UINT16_UNDEFINED (uint16)(-1)
#define SINT16_MAX       (sint16)32767
#define SINT16_MIN       (-32768)

#define BYTE_UNDEFINED   (byte)(-1)

typedef sint32 code_t;

#define BYTE_SIZE   1
#define UINT16_SIZE 2
#define UINT32_SIZE 4
#define UINT64_SIZE 8

#ifdef WIN32
typedef SYSTEMTIME      systemtime_t;

typedef HANDLE		    file_handle_t;
typedef HANDLE		    dir_handle_t;
typedef WIN32_FIND_DATA dir_entry_t;
typedef OVERLAPPED      flock_t;

#define INVALID_OS_DIR_HANDLE ((dir_handle_t) - 1)

typedef HANDLE          os_event_t;
#else
typedef struct timeval  systemtime_t;
//typedef pid_t           t_pid;

typedef uint32					file_handle_t;
typedef DIR*					dir_handle_t;
typedef dirent*					dir_entry_t;
typedef flock					flock_t;

#define INVALID_OS_DIR_HANDLE	NULL
#define IO_THREAD_PER_GROUP     1

typedef struct os_event_struct
{
	bool_t           isset;
	pthread_mutex_t  mutex; /* 互斥变量句柄 */
	pthread_cond_t   cond;  /* 条件变量句柄 */
} os_event_t;

#endif

#define INVALID_OS_FILE_HANDLE ((file_handle_t) - 1)

#define MAX_PATH_LEN 256
#define MAX_NAME_LEN 128

typedef schar pathname_t[MAX_PATH_LEN + 1];
typedef schar sysname_t[MAX_NAME_LEN + 1];

typedef struct local_time_struct
{
	sint32 year;
	uint32 mon;
	uint32 day;
	uint32 hour;
	uint32 min;
	uint32 sec;
	uint32 msec;
	uint32 usec;
} local_time_t;

#ifdef ASSERT_ENABLE
#define ASSERT(EXP)																		 \
if (!(EXP))																				 \
{																						 \
	fprintf(stderr, "Program crashed at file : %s line : %d\n", __FILE__, __LINE__);	 \
	{																					 \
		sint32 assert_i = 0;															 \
		sint32 assert_zero = 0;															 \
		assert_i = assert_i / assert_zero;												 \
	}																					 \
	exit(EXIT_FAILURE);																	 \
}
#else
#define ASSERT(EXP)																		 \
{																						 \
}
#endif


#endif
