/*
** FILE:    _monsters.c
** PURPOSE: This command give an ordered list of all the monsters in the
**          summoning registry, organized by level.
** CREDITS:
**    20 Mar 2000  Cyanide created the file.
*/

#define LOG_FILE "/open/reg_monsters"

#include <daemons.h>
#include "/u/c/cyanide/debug.h"

inherit DAEMON;

void create() {
    mapping map;
    int sz, sz2, i, j, tmplvl;
    string *mkeys, tmpstr;

    seteuid(getuid());

    rm(LOG_FILE);
    map = CATALOG_D->dump_catalog();
    mkeys = keys(map);
    sz = sizeof(mkeys);

    // We use this to sort the array from lowest to highest.
    for (i=0; i<sz; i++) {
	mkeys = keys(map);
	sz2 = sizeof(mkeys);
	tmplvl = 99999999;

	for (j=0; j<sz2; j++) {
	    if (map[mkeys[j]] <= tmplvl) {
		tmpstr = mkeys[j];
		tmplvl = map[tmpstr];
	    }
	}

	map_delete(map, tmpstr);
	write_file(
	  LOG_FILE, 
	  sprintf("%45s : %d\n", tmpstr, tmplvl)
	);
    }

    write_file(LOG_FILE, "\n"+sz+
      " monsters in summoning registry.");   

    CATALOG_D->create();
}

int cmd_catalog( string args ) {
    if (!file_exists(LOG_FILE) || args=="-R")
	create();

    TP->more(LOG_FILE);

    return 1;
}

string help() {
    return (    
      "This command give an ordered list of all the monsters in "+
      "the summoning\nregistry, organized by level.\n"
      +"Noth that for the purposes of summoning level, factors such "+
      "as magic resistance and damage type resistance are not counted,"+
      "since they are not retained when summoned.\n"
    );
}
