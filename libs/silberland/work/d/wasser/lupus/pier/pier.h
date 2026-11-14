#include <defines.h>

#define BS(str) break_string((str), 78, "", 1)

#define PIER(x)   "/d/wasser/lupus/pier/" + x
#define MAU(x) "/d/wasser/lupus/mauritius/" + x
#define PIERAUS(x)	"/d/wasser/woody/fischerdorf/room/weg5" + x
#define PIER_HZ	"/d/wasser/lupus/hochzeit/room/empfang"

#define PNPC(x)    PIER("npc/") + x
#define POBJ(x)    PIER("obj/") + x
#define PROOM(x)   PIER("room/") + x

#define TP	this_player()
#define TPNAM	TP->name()
#define TPPRO	TP->QueryPronoun()
