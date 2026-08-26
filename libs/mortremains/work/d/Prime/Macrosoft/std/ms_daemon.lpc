// This is the little bitty daemon that runs things
// and keeps track of information at the Macrosoft Corp.
// Credits:
//    01 Aug 99  Cyanide created the file.

#include "/u/c/cyanide/debug.h"
#include "macrosoft.h"

void area_announce( string );
int query_power();

inherit DAEMON;

int power;
mapping damages;

void create() {
    seteuid(getuid());
    power = 1;
    damages = ([]);
}

int query_power() { return power; }

void power_off() {
    area_announce(wrap("Suddenly, the lights "+
	"all go dark!"));
    power = 0;
}

void power_on() {
    area_announce(wrap("The lights flicker on as the "+
	"power is restored.") );
    power = 1;
}

void reset_resistances() { damages = ([]); }

void add_resistance ( string type ) {
    if (type=="wizard") return;

    if (undefinedp(damages[type]))
	damages += ([ type : 1 ]);
    else
	damages[type]++;
}

mapping query_resistance() { return damages; }

void area_announce(string str) {
    string bname;
    object *users;
    int i, len;

    users = users();
    i = sizeof(users);

    while (i>0) {
	i--;
	if (environment(users[i]))
	    bname = base_name(environment(users[i]));
	else
	    continue;

	len = strlen(MS_BASE);
	if (strlen(bname) >= len &&
	  bname[0..(len-1)]==MS_BASE)
	    message("tell", str, users[i]);
    }
}



/* EOF */
