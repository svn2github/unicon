BASE=../..
include ../makedefs

.PHONY: all clean deps

UFILES=border.u button.u buttongroup.u checkbox.u checkboxgroup.u \
	checkboxmenuitem.u circulate.u clipboard.u component.u componentscrollarea.u \
	dialog.u dispatcher.u drawscrollarea.u displayscrollarea.u \
	drag.u dropdown.u editabletextlist.u editlist.u editspin.u \
	event.u filedialog.u filterlistener.u guiprocs.u \
	icon.u iconbutton.u image.u label.u line.u \
	linebasedscrollarea.u list.u listspin.u menu.u menubar.u \
	menubutton.u menucomponent.u menuseparator.u node.u \
	overlayitem.u overlayset.u panel.u popupmenu.u progressbar.u \
	rangespin.u scrollarea.u scrollbar.u selectablescrollarea.u \
	sizer.u slider.u spin.u \
	staticspin.u submenu.u tabitem.u table.u tablecolumn.u tabset.u \
	textbutton.u textdisplay.u textfield.u textlist.u textmenuitem.u \
	ticker.u toggle.u toggleiconbutton.u toggletextbutton.u \
	toolbar.u tree.u

all: $(UFILES)

clean:
	$(RM) *.u uniclass.dir uniclass.pag 

deps:
	$(UNIDEP) *.icn -f deps.out -nb

deps.out: ;

include deps.out
