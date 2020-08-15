 ACLOCAL_AMFLAGS = -I m4 --install
# Libraries
lib_LTLIBRARIES = libcexception-1.0.la
libcexception_1_0_la_SOURCES = cexception/cexception.c cexception/cexception.h
libcexception_1_0_la_LDFLAGS = -version-info 0:0:0
include_HEADERS = cexception/cexception.h

check_PROGRAMS = unittest
unittest_SOURCES = tst/cexception-test.cc
unittest_CPPFLAGS = $(libgmock_main_CFLAGS)
unittest_LDADD = $(lib_LTLIBRARIES) $(libgmock_main_LIBS)
unittest_LDFLAGS = -no-install

EXTRA_DIST = m4/NOTES
dist_doc = README.md LICENSE
