 ACLOCAL_AMFLAGS = -I m4 --install
# Libraries
lib_LTLIBRARIES = libcexception-1.0.la
libcexception_1_0_la_SOURCES = src/cexception.c src/cexception.h
libcexception_1_0_la_LDFLAGS = -version-info 0:0:0
include_HEADERS = src/cexception.h

 bin_PROGRAMS = unittest
 unittest_SOURCES = tst/cexception-test.cc
 unittest_CPPFLAGS = $(libgmock_main_CFLAGS)
 unittest_LDADD = $(lib_LTLIBRARIES) $(libgmock_main_LIBS)

 EXTRA_DIST = m4/NOTES
 dist_doc = README.md LICENSE