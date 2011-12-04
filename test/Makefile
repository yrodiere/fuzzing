SUBDIRS=$(shell find . -mindepth 1 -maxdepth 1 -type d)
EXEC_FILES=$(addsuffix /exec, $(SUBDIRS)) 

CC=../bunny/bunny-gcc
CFLAGS=-I/usr/include/libxml2
LDFLAGS=-lxml2

all: $(EXEC_FILES)

%/exec: %/src.c | %/in %/out
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $<

%/in:
	mkdir $@

%/out:
	mkdir $@

.PHONY: clean mrproper

clean:
	rm -f */*.o
	find */out/ -mindepth 1 -maxdepth 1 | xargs -r rm -rf

mrproper: clean
	rm -f */exec

