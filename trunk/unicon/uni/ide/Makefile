# makefile for v2-gui Unicon IDE

BASE=../..
include ../Makedefs

export IPATH:=$(UNI)/lib $(UNI)/unicon $(UNI)/gui $(UNI)/xml $(ICON_IPL)/lib
export LPATH:=$(UNI)/gui $(ICON_IPL)/incl $(ICON_IPL)/gincl  $(ICON_IPL)/mincl

# nothing to configure here yet

WUC=$(UC) -G
UFLAGS=-s -c -u
UFLAGS2=-s -c

SRC=ui.icn ide.icn hfiledialog.icn buffertextlist.icn buffertabset.icn \
	buffertabitem.icn mainbar.icn modified.icn preferences.icn \
	templates.icn definitions.icn uproject.icn \
	classbrowser.icn tree.icn imgs.icn utags.icn matchparen.icn \
	qu_replace.icn online.icn about.icn is_binary.icn ptyDispatcher.icn \
	shelletl.icn funclookup.icn 

OBJ=ui.u ide.u hfiledialog.u buffertextlist.u buffertabset.u buffertabitem.u \
	mainbar.u modified.u preferences.u templates.u definitions.u \
	uproject.u classbrowser.u imgs.u utags.u matchparen.u qu_replace.u \
	online.u about.u is_binary.u ptyDispatcher.u shelletl.u funclookup.u\


ui:	$(OBJ)
ifdef EXE
	$(WUC) -o ui $(OBJ)
else
	$(UC) -o ui $(OBJ)
endif
	$(CP) ui$(EXE) ../../bin

funclookup.u: funclookup.icn
	$(UC) $(UFLAGS) funclookup


ide.u: ide.icn
	$(UC) $(UFLAGS) ide

hfiledialog.u: hfiledialog.icn
	$(UC) $(UFLAGS) hfiledialog

online.u: online.icn
	$(UC) $(UFLAGS) online

about.u: about.icn
	$(UC) $(UFLAGS) about

is_binary.u: is_binary.icn
	$(UC) $(UFLAGS) is_binary

buffertextlist.u: buffertextlist.icn ../gui/editabletextlist.icn
	$(UC) $(UFLAGS) buffertextlist

buffertabitem.u: buffertabitem.icn
	$(UC) $(UFLAGS) buffertabitem

buffertabset.u: buffertabset.icn
	$(UC) $(UFLAGS) buffertabset

matchparen.u: matchparen.icn
	$(UC) $(UFLAGS)  matchparen

preferences.u: preferences.icn
	$(UC) $(UFLAGS)  preferences

mainbar.u: mainbar.icn
	$(UC) $(UFLAGS) mainbar

templates.u: templates.icn
	$(UC) $(UFLAGS) templates

definitions.u: definitions.icn
	$(UC) $(UFLAGS) definitions

uproject.u: uproject.icn
	$(UC) $(UFLAGS) uproject

qu_replace.u: qu_replace.icn
	$(UC) $(UFLAGS) qu_replace

ptyDispatcher.u: ptyDispatcher.icn
	$(UC) $(UFLAGS) ptyDispatcher

shelletl.u: shelletl.icn
	$(UC) $(UFLAGS) shelletl

#idol.u: idol.icn
#	$(UC) $(UFLAGS2) idol

#preproce.u: preproce.icn
#	$(UC) $(UFLAGS2) preproce

#yyerror.u: yyerror.icn
#	$(UC) $(UFLAGS2) yyerror

#unicon.u: unicon.icn
#	$(UC) $(UFLAGS2) unicon

classbrowser.u: classbrowser.icn  imgs.u
	$(UC) $(UFLAGS2) classbrowser

#tree.u: tree.icn
#	$(UC) $(UFLAGS2) tree

utags.u: utags.icn
	$(UC) $(UFLAGS2) utags

ui.u: ui.icn
	$(UC) $(UFLAGS) ui

ui.exe: ui

clean:
	$(RM) *.u uniclass.dir uniclass.pag ui$(EXE)