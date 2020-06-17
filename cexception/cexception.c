#include "cexception.h"
#include <stdlib.h>

#include <assert.h>

struct CException * CException_Current = NULL;

void CException_throw(int const exception, char const * const message)
{
   /* no exception context saved, exit program */
   if(! CException_Current ) exit(exception);

   CException_Current->msg = message;
   longjmp(CException_Current->context, exception);
}

void CException_push(struct CException * const context)
{
  context->next = CException_Current;
  CException_Current = context;
}

struct CException * CException_pop(void)
{
  struct CException * const popable = CException_Current;
  CException_Current = CException_Current->next;
  return popable;
}
