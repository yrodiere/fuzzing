SUBDIRS=$(shell find . -mindepth 1 -maxdepth 1 -type d)
EXEC_FILES=$(addsuffix /exec, $(SUBDIRS)) 

CC=../bunny/bunny-gcc

all: $(EXEC_FILES)

%/exec: %/src.c | %/in %/out
	$(CC) -o $@ $<

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

