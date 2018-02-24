#------------------------------------------------------------------------------

SOURCE=main.cpp common/node.cpp common/job.cpp common/scheduler.cpp
MYPROGRAM=MesosphereScheduler
MYINCLUDES=include/

CC=g++

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) -I$(MYINCLUDES) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)