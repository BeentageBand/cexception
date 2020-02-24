SRCS=$(wildcard *.c)
LIBS=libexception.a
INCS=$(wildcard *.h)

.PHONY : all clean $(MAKECMDGOALS:%=%.cmd)

all : install

install: ../$(OUT)/include/cexception/ $(LIBS:%=../$(OUT)/lib/%) $(INCS:%=../$(OUT)/include/cexception/%)
	@echo "install cexception.."

clean : 
	@echo "clean all-tst"
	rm -rf *.o *.lib

$(LIBS) : $(SRCS:.c=.o)
	@echo "compiling $(LIBS)";
	$(AR) -rcs $@ $^;

$(LIBS:%=../$(OUT)/lib/%): $(LIBS)
	cp -sf $(realpath $^) $@;

../$(OUT)/include/cexception/%.h : %.h
	cp -sf $(realpath $^) $@;

../$(OUT)/include/cexception : 
	-mkdir -p $@;

%.o : %.c
	$(CXX) $(CFLAGS) $(SUBDIRS:%= -I ../%) -o $@ -c $^
