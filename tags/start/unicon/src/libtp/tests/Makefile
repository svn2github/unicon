# Generated automatically from Makefile.in by configure.

SHELL = /bin/sh

subdirs = tests uri
top_srcdir = ..
srcdir = .
prefix = /usr/local
exec_prefix = ${prefix}
bindir = $(exec_prefix)/bin
infodir = $(prefix)/info
libdir = $(prefix)/lib/gnudl
mandir = $(prefix)/man/man1

CC = gcc

RM = rm -f
AR = ar
RANLIB = ranlib
SHTOOL = shtool/shtool

CPPFLAGS = 
LDFLAGS = 
LIBS = -lnsl 

INCLUDES = -I../uri -I..
DEFINES = -DHAVE_CONFIG_H
CFLAGS = $(CPPFLAGS) -Wall -Werror -Wno-unused -ggdb $(DEFINES) $(INCLUDES)

LDLIBS = ../libtp.a $(LIBS)

PROGS = daytime fing hhead pop testuri wtrace
OBJS = daytime.o fing.o hhead.o pop.o testuri.o wtrace.o
SRCS = daytime.c fing.c hhead.c pop.c testuri.c wtrace.c

all: Makefile $(PROGS)

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(PROGS) Makefile

daytime: daytime.o ../libtp.a
	$(CC) -o daytime daytime.o $(LDFLAGS) $(LDLIBS)

fing: fing.o ../libtp.a
	$(CC) -o fing fing.o $(LDFLAGS) $(LDLIBS)

hhead: hhead.o ../libtp.a
	$(CC) -o hhead hhead.o $(LDFLAGS) $(LDLIBS)

pop: pop.o ../libtp.a
	$(CC) -o pop pop.o $(LDFLAGS) $(LDLIBS)

testuri: testuri.o ../libtp.a
	$(CC) -o testuri testuri.o $(LDFLAGS) $(LDLIBS)

wtrace: wtrace.o ../libtp.a
	$(CC) -o wtrace wtrace.o $(LDFLAGS) $(LDLIBS)

Makefile: Makefile.in $(top_srcdir)/config.status
	cd $(top_srcdir) && $(SHELL) ./config.status

config.status: $(top_srcdir)/configure 
	cd $(top_srcdir && $(SHELL) ./config.status --recheck

$(top_srcdir)/configure: $(top_srcdir)/configure.in
	cd $(top_srcdir) && $(AUTOCONF)
