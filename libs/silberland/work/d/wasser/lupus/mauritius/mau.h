#include <defines.h>

#define BS(str) break_string((str), 78, "", 1)

#define MAU(x) "/d/wasser/lupus/mauritius/" + x
#define PIER(x)	"/d/wasser/lupus/pier/" + x
#define HZ(x)	"/d/wasser/lupus/hochzeit/" + x

#define MAUNPC(x)    MAU("npc/") + x
#define MAUOBJ(x)    MAU("obj/") + x
#define MAUROOM(x)   MAU("room/") + x

#define TP	this_player()
#define TPNAM	TP->name()
#define TPPRO(x)	TP->QueryPronoun( x )
#define TO   this_object()
#define CTPN capitalize(this_player()->name())


#define TELLL(x) if(find_player("lupus"))tell_object(find_player("lupus"),x)
