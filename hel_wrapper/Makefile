CC  = g++
OPT = -O3
LIBS = -lntl -lgmp -lm -lrt
HEL_LIB = ../hel_lib
AES_NI = ../aes_ni
FLAGS = -c -fPIC --std=c++11 -Wall -Winvalid-pch -Wnon-virtual-dtor
LINK_FLAGS = -Wl,--no-undefined -Wl,--as-needed -Wl,-O1 -shared -fPIC -Wl,--start-group -Wl,-soname,libhel.so -lntl -lgmp -Wl,--end-group
AES_TYPE := aes_simple

ifeq ($(AES_TYPE), aes_ni)
	AES_SRC = $(AES_NI)/aes_ni.cpp
	EXTRA_FLAGS = -msse2 -msse -march=native -maes -o aes.o
else
	AES_SRC = $(HEL_LIB)/aes.cpp
	EXTRA_FLAGS =
endif

all: hel_example

install: libhel.so
	cp libhel.so /usr/local/lib/libhel.so

uninstall:
	rm -rf /usr/local/lib/libhel.so

libhel.so: hel_wrapper.o hel_execute.o hel_enum.o hel_histo.o hel_init.o hel_util.o aes.o scores_example_data.o scores_example.o
	$(CC) -o libhel.so hel_wrapper.o scores_example.o scores_example_data.o hel_execute.o hel_enum.o hel_histo.o hel_init.o hel_util.o aes.o $(LINK_FLAGS)

hel_example: main_example.o libhel.so
	$(CC) -o hel_example $(OPT) main_example.o libhel.so $(LIBS)

hel_wrapper.o: hel_wrapper.cpp hel_wrapper.h
	$(CC) $(OPT) $(FLAGS) hel_wrapper.cpp $(LIBS)

main_example.o: $(HEL_LIB)/main_example.cpp  $(HEL_LIB)/scores_example.h  $(HEL_LIB)/hel_execute.h  $(HEL_LIB)/hel_enum.h  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h  $(HEL_LIB)/aes.h 
	$(CC) $(OPT) $(FLAGS)  $(HEL_LIB)/main_example.cpp  $(LIBS)

hel_execute.o: $(HEL_LIB)/hel_execute.cpp  $(HEL_LIB)/hel_execute.h  $(HEL_LIB)/hel_enum.h  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h  $(HEL_LIB)/aes.h 
	$(CC) $(OPT) $(FLAGS) $(HEL_LIB)/hel_execute.cpp  $(LIBS)

hel_enum.o: $(HEL_LIB)/hel_enum.cpp  $(HEL_LIB)/hel_enum.h  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) $(FLAGS) $(HEL_LIB)/hel_enum.cpp  $(LIBS)

hel_histo.o: $(HEL_LIB)/hel_histo.cpp  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) $(FLAGS)  $(HEL_LIB)/hel_histo.cpp  $(LIBS)

hel_init.o: $(HEL_LIB)/hel_init.cpp  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) $(FLAGS) $(HEL_LIB)/hel_init.cpp  $(LIBS)

scores_example.o: $(HEL_LIB)/scores_example.cpp  $(HEL_LIB)/scores_example_data.cpp  $(HEL_LIB)/scores_example.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) $(FLAGS) $(HEL_LIB)/scores_example.cpp  $(LIBS)

scores_example_data.o: $(HEL_LIB)/scores_example_data.cpp  $(HEL_LIB)/scores_example.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) $(FLAGS) $(HEL_LIB)/scores_example_data.cpp  $(LIBS)

hel_util.o: $(HEL_LIB)/hel_util.cpp  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) $(FLAGS) $(HEL_LIB)/hel_util.cpp  $(LIBS)

aes.o: $(AES_SRC)  $(HEL_LIB)/aes.h 
	$(CC) $(OPT) $(FLAGS) $(EXTRA_FLAGS) $(AES_SRC)  $(LIBS)

clean: 
	rm -f test *.o *.so hel_example


