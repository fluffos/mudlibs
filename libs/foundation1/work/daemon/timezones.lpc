//	/bin/daemon/timzone.c
//	from the Nightmare mudlib
//	a timezone daemon
//	created by Descartes of Borg
// bug in show_tzone_list() fixed by Pallando 93-06-04

mapping timezones;

void load_zones();

void load_zones() {
  if( !timezones )  // Line added by Pallando for efficiency
    timezones = ([
        "NZT":([ "offset":16, "name": "New Zealand Standard Time" ]),
	"AET":([ "offset": 15, "name": "Australian Eastern Time" ]),
	"AWT": ([ "offset":3, "name": "Australian Western Time" ]),
        "MT": ([ "offset":9, "name": "Moscow Time" ]),
        "MEZ": ([ "offset": 7, "name" : "Middle European Zone" ]),
	"CET": ([ "offset": 7, "name": "Central European Time" ]),
	"GMT": ([ "offset": 6, "name": "Greenwich Mean Time" ]),
	"BST": ([ "offset": 5, "name": "British Summer Time" ]),
	"AST": ([ "offset": 2, "name": "Atlantic Standard Time" ]),
	"EST": ([ "offset": 1, "name": "Eastern Standard Time" ]),
	"CST": ([ "offset": 0, "name": "Central Standard Time" ]),
	"MST": ([ "offset": -1, "name": "Mountain Standard Time" ]),
	"PST": ([ "offset": -2, "name": "Pacific Standard Time" ]),
    ]);
}

int query_tzone(string str)
 {
    int offset;

    load_zones();
    if(!str) return time();
    if(!timezones[str]) offset = 0;
    else offset = timezones[str]["offset"] * 3600;
    return time() + offset;
}

void show_tzone_list()
{
    string *tz;
    int i;

    load_zones();
    tz = keys(timezones);
    for(i=0; i<sizeof(tz); i++) {
 write(tz[i]+": "+timezones[tz[i]]["name"]+"\n");
    }
}
