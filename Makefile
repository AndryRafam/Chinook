SRC:= $(wildcard Cipher/* .c) \
	 $(wildcard Tools/Print/* .c) \
	 $(wildcard Tools/Randomize/* .c) \
	 $(wildcard Test/* .c)

OBJECTS:= $(SRC:.c=.o)

LDFLAGS:= -lssl -lcrypto

exe: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) 

clean:
	rm -f $(OBJECTS) exe
