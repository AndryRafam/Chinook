SRC:= $(wildcard Source/Cipher/* .c) \
	 $(wildcard Source/Print/* .c)

MAIN:= $(wildcard Main/* .c)

OBJECTS:= $(SRC:.c=.o) $(MAIN:.c=.o)

LDFLAGS:= -lssl -lcrypto

EXE: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) 
