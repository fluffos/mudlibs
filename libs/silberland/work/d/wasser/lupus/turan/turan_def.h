#include <defines.h>

#define BS(str) break_string((str), 78, "", 1)

#define LUPUS(x) "/players/lupus/" + x
#define MAU(x) "/d/wasser/lupus/mauritius/" + x
#define PIER(x)	"/d/wasser/lupus/pier/" + x
#define HZ(x)	"/d/wasser/lupus/hochzeit/" + x
#define TUR(x) "/d/wasser/lupus/turan/" + x

#define TURNPC(x)    TUR("npc/") + x
#define TUROBJ(x)    TUR("obj/") + x
#define TURROOM(x)   TUR("room/") + x
#define TUR_NORD     LUPUS("workroom")
#define TUR_OST      LUPUS("workroom")
#define TUR_WEST     LUPUS("workroom")
#define TUR_SUED     LUPUS("workroom")

#define TP	this_player()
#define TPNAM	TP->name()
#define TPPRO(x)	TP->QueryPronoun( x )
#define TO   this_object()

#define TELLL(x) if(find_player("lupus"))tell_object(find_player("lupus"),"---\n"+x+"\n---\n")
