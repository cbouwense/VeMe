CFLAGS = -g -std=c99 -Iinclude/

veme: $(wildcard src/*.c)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) veme

run:
	./veme

.PHONY: run clean
