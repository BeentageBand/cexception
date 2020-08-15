/*
 * cexception-test.cc
 *
 *  Created on: Oct 25, 2019
 *      Author: roalanis
 */

#include "gtest/gtest.h"

#include "cexception/cexception.h"

enum Exception {
  NoException = 0,
  BadAllocException
};

TEST(try_catch, smoke_block)
{
  _try_catch({

  }, _any {

  } _finally {

  });

}

TEST(setjmp, smoke_no_longjmp)
{
  jmp_buf context;
  int const e = setjmp(context);
  ASSERT_EQ(NoException, e);
}

TEST(setjmp, smoke_longjmp)
{
  jmp_buf context;
  int const e = setjmp(context);

  if (0 == e) {

      longjmp(context, BadAllocException);
      FAIL();
  } else {
      ASSERT_EQ(BadAllocException, e);
  }
}

TEST(Exception, Catch_BadAllocException)
{
  bool pass_catch = false;
  bool pass_finally = false;
  _try {
    _throw(BadAllocException, "BadAllocException");
    FAIL();
  } _catch
    _exception(BadAllocException) {
    pass_catch = true;
    } _finally {
      pass_finally = true;
    }
  _end_try;

  ASSERT_TRUE(pass_catch);
  ASSERT_TRUE(pass_finally);
}

TEST(Exception, try_NoThrow)
{
  bool pass_finally = false;
  _try {

  } _catch
    _any {
      FAIL();
    } _finally {
      pass_finally = true;
    }
  _end_try;

  ASSERT_TRUE(pass_finally);

}


TEST(Exception, Catch_Any)
{
  bool pass_any = false;

  _try {
    _throw(BadAllocException, "BadAllocException");
  } _catch
    _any {
    pass_any = true;
  } _finally {

  }

  _end_try

  ASSERT_TRUE(pass_any);
}
