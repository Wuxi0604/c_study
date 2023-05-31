#ifndef DLIST_H
#define DLIST_H

#include "basetypes.h"

#define DLIST_T(TYPE)			\
struct							\
{								\
	uint32 count;				\
	TYPE*  start;				\
	TYPE*  end;					\
}						 

#define DLIST_NODE_T(TYPE)		\
struct							\
{								\
	TYPE* prev;					\
	TYPE* next;					\
}

typedef struct dlst_node_struct dlst_node_t;
struct dlst_node_struct
{
	void* data;
	void* flag;
	DLIST_NODE_T(dlst_node_t) link;
};

typedef DLIST_T(dlst_node_t) dlst_t;

#define DLIST_INIT(DLIST)		\
do								\
{								\
	(DLIST).count = 0;			\
	(DLIST).start = NULL;		\
	(DLIST).end   = NULL;		\
} while (0)						


#define DLIST_NODE_INIT(LINK, NODE)		 \
do										 \
{										 \
	((NODE)->LINK).prev = NULL;			 \
	((NODE)->LINK).next = NULL;			 \
} while (0)

#define DLIST_ADD_FIRST(LINK, DLIST, NODE)			  \
do													  \
{													  \
	ASSERT(NODE);									  \
													  \
	((DLIST).count)++;								  \
	((NODE)->LINK).next = (DLIST).start;			  \
	((NODE)->LINK).prev = NULL;						  \
	if ((DLIST).start != NULL)						  \
	{												  \
		(((DLIST).start)->LINK).prev = (NODE);		  \
	}												  \
													  \
	(DLIST).start = (NODE);							  \
													  \
	if ((DLIST).end == NULL)						  \
	{												  \
		(DLIST).end = (NODE);						  \
	}												  \
} while (0)

#define DLIST_ADD_LAST(LINK, DLIST, NODE)			  \
do													  \
{													  \
	ASSERT(NODE);									  \
													  \
	((DLIST).count)++;								  \
	((NODE)->LINK).prev = (DLIST).end;				  \
	((NODE)->LINK).next = NULL;						  \
	if ((DLIST).end != NULL)						  \
	{												  \
		(((DLIST).end)->LINK).next = (NODE);		  \
	}												  \
	(DLIST).end = (NODE);							  \
													  \
	if ((DLIST).start == NULL)						  \
	{												  \
		(DLIST).start = (NODE);						  \
	}												  \
} while (0)

#define DLIST_REMOVE(LINK, DLIST, NODE)										   \
do																			   \
{																			   \
	ASSERT(NODE);															   \
	ASSERT((DLIST).count > 0);												   \
																			   \
	((DLIST).count)--;														   \
	if (((NODE)->LINK).next != NULL)										   \
	{																		   \
		((((NODE)->LINK).next)->LINK).prev = ((NODE)->LINK).prev;			   \
	}																		   \
	else																	   \
	{																		   \
		(DLIST).end = ((NODE)->LINK).prev;									   \
	}																		   \
																			   \
	if (((NODE)->LINK).prev != NULL)										   \
	{																		   \
		((((NODE)->LINK).prev)->LINK).next = ((NODE)->LINK).next;			   \
	}																		   \
	else																	   \
	{																		   \
		(DLIST).start = ((NODE)->LINK).next;								   \
	}																		   \
	((NODE)->LINK).next = NULL;												   \
	((NODE)->LINK).prev = NULL;												   \
} while (0)

#define DLIST_GET_NEXT(LINK, NODE) (((NODE)->LINK).next)

#define DLIST_GET_PREV(LINK, NODE) (((NODE)->LINK).prev)

#define DLIST_GET_LEN(LIST) (LIST).count

#define DLIST_GET_FIRST(LIST) (LIST).start

#define DLIST_GET_LAST(LIST) (LIST).end

#endif
