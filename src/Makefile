
# C compiler to use
CC = g++

#-std=c++0x
# Any special flags you want to pass to the compiler
MYFLAGS = -O3 -std=c++2a -DXP_UNIX -I/usr/local/include -Wformat-security -Wformat -Wpointer-arith -Wcast-align -Wredundant-decls \
 		-L/usr/local/lib \
              -I/usr/local/lib/pkgconfig/../../include -I/usr/local/include

#flags for profiling (see hacker.doc for more information)
PROFILE =

BINDIR = ../bin

CPPFLAGS = -ggdb3 $(MYFLAGS) $(PROFILE)

LIBS = -lstdc++ -ldl

OBJDIR = obj

EXECUTABLE = access_log_parser

OBJFILES =	access_date.o \
		access_log_parser.o \
		command_line_arguments.o \
		main.o \

OBJFILES := $(patsubst %.o,$(OBJDIR)/%.o,$(OBJFILES))

$(OBJDIR)/%.d: %.cpp
	$(SHELL) -ec '$(CC) -MM $(CPPFLAGS) $< | \
	sed '\''s,\($*\)\.o[ :]*,$(OBJDIR)\/\1.o $@ : ,g'\'' > $@'

default: access_log_parser

-include $(OBJFILES:.o)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CPPFLAGS) -c	$<	-o $@

all:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)
	$(MAKE) $(BINDIR)/$(EXECUTABLE)

access_log_parser:
	$(MAKE) $(BINDIR)/$(EXECUTABLE)

$(BINDIR)/access_log_parser : $(OBJFILES)
	$(CC) -o $(BINDIR)/$(EXECUTABLE) $(PROFILE) $(OBJFILES) $(LIBS)

clean:
	rm -f $(OBJFILES) *~

full:
	clean
	all
