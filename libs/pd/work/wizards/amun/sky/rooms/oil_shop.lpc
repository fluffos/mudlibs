#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_short("Sky Healing Shop");
    set_long("%^BOLD%^%^YELLOW%^Sky Temple Healing Shop%^RESET%^\n"
      "%^BOLD%^%^WHITE%^In this room, are very interesting bottles of oils and ointments, and lily's. The smell from the lily's hang softly in the air, as a breeze comes through. Faishyth, the store owner, stands behind the counter in a daydream as customers come in and out deciding what items to buy. There is a sign sitting on the counter for all to read.%^RESET%^");
    set_exits( ([ "north" : SKYROOM "rs_3" ]) );
}

void reset() {
    ::reset();
    if(!present("faishyth")) 
	new(SKYMOB "faishyth")->move(this_object());
}
