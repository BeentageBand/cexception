export CXX=gcc
export CPP=g++
export TEST_DEPS=gmock_main gtest gmock
export DEPS=
ifdef BEENTAGE_DIR_ROOT
export OUT=$(BEENTAGE_DIR_ROOT)/out
else
export OUT=$(realpath .)/out
endif
export LDFLAGS=$(shell pkg-config --libs --static $(DEPS) $(TEST_DEPS))
export CXXFLAGS=-std=gnu++11 $(shell pkg-config --cflags $(DEPS) $(TEST_DEPS)) -I $(OUT)/include/
export CFLAGS=-std=gnu11 $(shell pkg-config --cflags $(DEPS) $(TEST_DEPS))  -I $(OUT)/include/
export SUBDIRS=cexception
ifndef test
test=dummy-test
endif

TEST_LDFLAGS=$(shell pkg-Config --libs --static $(TEST_DEPS))

.PHONY: all clean install test $(SUBDIRS:%=%-all) $(SUBDIRS:%=%-clean) tst-all tst-clean

all : install test

install : $(OUT)/bin $(OUT)/lib $(SUBDIRS:%=%-all)
	-mkdir -p ../build/include ../build/lib;
	-cp -f $(OUT)/lib/*.a ../build/lib/;
	-cp -rf $(OUT)/include/* ../build/include/;

clean : $(SUBDIRS:%=%-clean) tst-clean

clobber : clean
	-rm -rf $(OUT)

test : tst-all
	@tst/unit-test;

$(OUT) $(OUT)/bin $(OUT)/lib $(OUT)/include/cexception: 
	-mkdir -p $@;

$(SUBDIRS:%=%-all) tst-all : 
	-make all -C $(@:%-all=%);

$(SUBDIRS:%=%-clean) tst-clean : 
	-make clean -C $(@:%-clean=%);
