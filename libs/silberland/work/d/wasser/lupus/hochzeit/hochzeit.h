#include <defines.h>

#define BS(str) break_string((str), 78, "", 1)

#define PIER(x)	"/d/wasser/lupus/pier/" + x
#define HZ(x)	"/d/wasser/lupus/hochzeit/" + x
#define HZAUS	PIER("room/plattform-m")

#define HZNPC(x)    HZ("npc/") + x
#define HZOBJ(x)    HZ("obj/") + x
#define HZROOM(x)   HZ("room/") + x

#define HZM	HZOBJ("secure/hzmaster")

#define TP	this_player()
#define TPNAM	TP->name()
#define TPPRO(x)	TP->QueryPronoun( x )
#define TO   this_object()

#define TELLL(x) if(find_player("lupus"))tell_object(find_player("lupus"),x)

#define HZVERZ "/d/wasser/lupus/hochzeit/obj/secure/HZBUCH"
