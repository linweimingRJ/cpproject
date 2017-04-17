


override CFLAGS += -Wall -I./include `pkg-config --cflags gtk+-2.0`


LDFLAGS += `pkg-config --libs gtk+-2.0`



		   
OUTPUT	= ui

SRC	= $(shell find -name 'mycp2.c')
#SRC	+= 

OBJ  = $(SRC:%.c=%.o)


all: $(OUTPUT)

$(OUTPUT) : $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(OUTPUT)  $(LDFLAGS)


clean:
	-rm -rf $(OUTPUT) $(OBJ)
