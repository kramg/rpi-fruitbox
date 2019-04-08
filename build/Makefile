CPP         = g++
CFLAGS      = -O2 -std=c++14 -D_RPI
INC         = -I/opt/vc/include
OBJ         = aat.o
LIBS        = -L/opt/vc/lib/

STATIC_LIBS = allegro-static-5 allegro_audio-static-5 allegro_acodec-static-5

%.o: %.cpp
	$(CPP) -c -o $@ $< $(CFLAGS) $(INC)

./aat: $(OBJ)
	$(CPP) -Wall -o $@ $^ $(CFLAGS) $(LIBS) `pkg-config --libs --static $(STATIC_LIBS)`

.PHONY: clean
clean:
	rm -f aat.o
	rm -f ./aat
	touch Makefile
	touch aat.?pp
