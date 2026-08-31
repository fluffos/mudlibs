#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "beach" : 1]) );
    set_short("North Anga Street");
    set_smell("default", "Toughened leather and fashioned coral can be smelt around here.");
    set_listen("default", "The noise of the busy public square is washed away by the sounds of armoursmiths.");
    set_long("Anga Street is a commonly used street, armoursmiths and %^MAGENTA%^Coral%^RESET%^ tenders, the strange stone pavement seems worn away, but reliable. To the north is the path towards the delicate %^MAGENTA%^Coral beds%^RESET%^. Bright lights signal the position of the public square to the south.");
    set_night_long("Anga Street is destered, except for the odd animal here and there. A soft glow of lamps can be seen to the north, while the bright lights of the public square are obvious to the south.");
    set_items((["beds" : "The beds of %^MAGENTA%^Coral%^RESET%^, grown and cared for by experts of Coral growth, the Coral is made into armour for any citizen who wishes it...and can pay for it.", "lights" : "The bright lights mark the presence of the NuShae Public Square.", "street" : "Either well kept or only light loads burden this way, the street is relatively sound."]));
    set_exits( (["north" : ROOMS "coral1", "south" : ROOMS "t1"]) );
}

void reset() {
    ::reset();
     if (children(MOB"squid")==({})||
         sizeof(children(MOB"squid"))==1)
            new(MOB "squid")->move(this_object());
}
