base = $(shell dirname `pwd`)
export ICON_IPL:=$(shell dirname $(base))/ipl
export IPATH:=$(base)/lib $(base)/parser $(ICON_IPL)/lib
ufiles = filearg.u  fileargclass.u  main.u  symbolinfo.u  symboltable.u  util.u

all: unidep

clean:
	rm -f unidep *.u uniclass.dir uniclass.pag 

%.u: %.icn
	unicon -c $*

deps:
	$(base)/bin/unidep *.icn

unidep: $(ufiles)
	unicon -o unidep $(ufiles)
	cp unidep ../../bin

### Autogenerated dependencies
filearg.u : filearg.icn
fileargclass.u : fileargclass.icn
main.u : main.icn
symbolinfo.u : symbolinfo.icn
symboltable.u : symboltable.icn
util.u : util.icn
