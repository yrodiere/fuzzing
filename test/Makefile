SUBDIRS=$(shell find . -mindepth 1 -maxdepth 1 -type d)
CC=../bunny/bunny-gcc

all: $(addsuffix /exec, $(SUBDIRS))

%/exec: %/src.c | %/in %/out
	$(CC) -o $@ $<

%/in:
	mkdir $@

%/out:
	mkdir $@

.PHONY: clean mrproper

clean:
	rm -f */*.o

mrproper: clean
	rm -f */exec

