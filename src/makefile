# =======================================================================
# Makefile:	Compile and Link C programs with gcc in Unix/Linux/CygWin
# Author:	George Baciu
# Revised:	26 Jan. 2007
# =======================================================================

TOP	= ..
BINDIR	= $(TOP)/bin
LIBDIR	= $(TOP)/lib
SRCDIR	= $(TOP)/src
DATDIR	= $(TOP)/dat
EXEC	= $(BINDIR)/main 
NULL	= 

# -----------------------------------------------------------------------

SRCS	=			\
	$(SRCDIR)/main.c	\
	$(NULL)

DATS	= $(DATDIR)/input.dat

OBJS	= $(SRCS:.c=.o)

LINK	= gcc

CC	= gcc

CFLAGS	= -c

LFLAGS	= -g

LDLIBS	= -lm -lc -ldl

# -----------------------------------------------------------------------

default	:	$(EXEC)


$(EXEC)	:	$(OBJS)
		$(LINK) $(OBJS) $(LFLAGS) $(LDLIBS) -o $(EXEC)

.c.o	:
		$(CC) $(CFLAGS) $<

clear	:	clean
		/bin/rm -rf *.exe
		/bin/rm -rf $(BINDIR)/*.exe

clean	:;	/bin/rm -rf *.o
		/bin/rm -rf $(BINDIR)/*.o

run	:;	$(EXEC) < $(DATS)

