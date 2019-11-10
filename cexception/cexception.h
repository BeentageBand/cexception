#ifndef CEXCEPTION_H_
#define CEXCEPTION_H_

#include <setjmp.h>

#ifndef __STDC__
#error "cexception.h needs ISO C compiler"
#endif 

#define _try_catch(try_block, catch_block) \
  _try try_block \
  _catch catch_block \
  _end_try

/** _try
 *  try block from try-catch structure
 *  logic flows until exception is thrown
 */
#define _try \
char const * exception_message = NULL; \
struct CException local_context; \
CException_push(&local_context); \
int const exception = setjmp(CException_Current->context); \
if(0 == exception) { \

/** _catch
 * Starts catch block
 */
#define _catch \
  (void)CException_pop(); \
} else { \
    switch (exception) { \
      default:

/** _any
 * goes first after _catch
 * catches any exception not defined with _exception
 */
#define _any (void)CException_pop();

/** _exception
 * catches specific exception
 */
#define _exception(e) \
    break; case e: _any

/** _finally
 * goes at the end of _any/_exception
 * logic is executed even an exception was thrown
 */
#define _finally \
    break; } /* ends switch */ \
  } /* ends if */ \

/** _end_try
 * goes at the very end of the try-catch block
 */
#define _end_try \
  if (&local_context == CException_Current) { \
      CException_throw(exception, exception_message); \
  } \

#ifdef DEBUG_THROW
#define _throw(except) \
Dbg_Fault("Exception thrown = %s - %d",  STR(except), (int)(except)) \

#else
#define _throw(e, message) \
  exception_message = message; \
  CException_throw((int)(e), exception_message);

#endif /*DEBUG_THROW*/


#ifdef __cplusplus
extern "C" {
#endif

struct CException
{
   struct CException * next;
   char const * msg;
   jmp_buf context;
};

extern struct CException * CException_Current;

extern void CException_throw(int const except, char const * const message);

extern void CException_push(struct CException * const context);
extern struct CException * CException_pop(void);

#ifdef __cplusplus
}
#endif

#endif /*CEXCEPTION_H_*/
