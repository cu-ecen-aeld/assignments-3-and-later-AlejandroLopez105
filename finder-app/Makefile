CC=gcc


all: writer
writer: writer.o
ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
	$(CROSS_COMPILE)$(CC) -o writer writer.o
else
	$(CC) -o writer writer.o
endif

app_bin=writer writer.o
clean:
	rm -f $(app_bin)
