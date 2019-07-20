SRC:= $(wildcard Cipher/* .c) \
	 $(wildcard Print/* .c) \
	 $(wildcard Main/* .c)

OBJECTS:= $(SRC:.c=.o)

LDFLAGS:= -lssl -lcrypto

exe: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) 

clean:
	rm -f $(OBJECTS) exe
