CC  = g++
OPT = -O3
LIBS = -lntl -lgmp -lm -lrt
HEL_LIB = ../hel_lib

all: libhel

install: libhel
	cp libhel.so /usr/local/lib/libhel.so

uninstall:
	rm -rf /usr/local/lib/libhel.so

libhel: hel_wrapper.o hel_execute.o hel_enum.o hel_histo.o hel_init.o hel_util.o aes.o scores_example_data.o scores_example.o
	$(CC) -shared -Wl,-soname,libhel.so -o libhel.so hel_wrapper.o scores_example.o scores_example_data.o hel_execute.o hel_enum.o hel_histo.o hel_init.o hel_util.o aes.o $(LIBS)

#test: main_example.o hel_execute.o hel_enum.o hel_histo.o hel_init.o hel_util.o aes.o scores_example_data.o scores_example.o
	#$(CC) -o test $(OPT) main_example.o scores_example.o scores_example_data.o hel_execute.o hel_enum.o hel_histo.o hel_init.o hel_util.o aes.o $(LIBS)

hel_wrapper.o: hel_wrapper.cpp hel_wrapper.h
	$(CC) $(OPT) -c -fPIC hel_wrapper.cpp $(LIBS)

main_example.o: $(HEL_LIB)/main_example.cpp  $(HEL_LIB)/scores_example.h  $(HEL_LIB)/hel_execute.h  $(HEL_LIB)/hel_enum.h  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h  $(HEL_LIB)/aes.h 
	$(CC) $(OPT) -c -fPIC  $(HEL_LIB)/main_example.cpp  $(LIBS)

hel_execute.o: $(HEL_LIB)/hel_execute.cpp  $(HEL_LIB)/hel_execute.h  $(HEL_LIB)/hel_enum.h  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h  $(HEL_LIB)/aes.h 
	$(CC) $(OPT) -c -fPIC $(HEL_LIB)/hel_execute.cpp  $(LIBS)

hel_enum.o: $(HEL_LIB)/hel_enum.cpp  $(HEL_LIB)/hel_enum.h  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) -c -fPIC $(HEL_LIB)/hel_enum.cpp  $(LIBS)

hel_histo.o: $(HEL_LIB)/hel_histo.cpp  $(HEL_LIB)/hel_histo.h  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) -c -fPIC  $(HEL_LIB)/hel_histo.cpp  $(LIBS)

hel_init.o: $(HEL_LIB)/hel_init.cpp  $(HEL_LIB)/hel_init.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) -c -fPIC $(HEL_LIB)/hel_init.cpp  $(LIBS)

scores_example.o: $(HEL_LIB)/scores_example.cpp  $(HEL_LIB)/scores_example_data.cpp  $(HEL_LIB)/scores_example.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) -c -fPIC $(HEL_LIB)/scores_example.cpp  $(LIBS)

scores_example_data.o: $(HEL_LIB)/scores_example_data.cpp  $(HEL_LIB)/scores_example.h  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) -c -fPIC $(HEL_LIB)/scores_example_data.cpp  $(LIBS)

hel_util.o: $(HEL_LIB)/hel_util.cpp  $(HEL_LIB)/hel_util.h  $(HEL_LIB)/hel_struct.h 
	$(CC) $(OPT) -c -fPIC $(HEL_LIB)/hel_util.cpp  $(LIBS)

aes.o: $(HEL_LIB)/aes.cpp  $(HEL_LIB)/aes.h 
	$(CC) $(OPT) -c -fPIC $(HEL_LIB)/aes.cpp  $(LIBS)

clean: 
	rm -f test *.o *.so


