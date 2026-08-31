GENESIS_FILES = MESSAGE README CHANGES appearance.c castle.c \
	chaosdemon.doc config.h \
	dungeon garbage_heap.c inside maze obj outside quest.doc \
	secret_police sheriffs_office.c sp_membership.c store.c thing.c \
	tower vdb1.c walker wiz workroom.c

NANNY_FILES = $(GENESIS_FILES) lith deposit weather.c my_void.c

EXPORT_FILES = $(GENESIS_FILES) deposit weather.c

genesis:
	cd $(HOME)/md/padrone; tar cvf genesis-padrone.tar $(GENESIS_FILES); compress genesis-padrone.tar

nanny:
	cd $(HOME)/md/padrone; tar cvf nanny-padrone.tar $(NANNY_FILES); compress nanny-padrone.tar

export:
	cd $(HOME)/md/padrone; tar cvf export-padrone.tar $(EXPORT_FILES); compress export-padrone.tar
