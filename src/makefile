bin = ../bin/
include = ../include/
binary = veme
code = $(binary).c

all: $(include)veme.h $(code)
	gcc $(code) -o $(bin)$(binary) -I$(include) -g -std=c99

run:
	$(bin)veme
