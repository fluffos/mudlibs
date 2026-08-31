#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "beach" : 1]));
    set_short("North Anga Street");
    set_smell("default", "Toughened leather and fashioned coral can be smelt around here.");
    set_listen("default", "The soft humming of weavers can be heard floating around.");
    set_long("Anga Street is a commonly used street, armoursmiths and %^MAGENTA%^Coral%^RESET%^ tenders, the strange stone pavement seems worn away, but reliable. To the north the path for the %^MAGENTA%^Coral beds%^RESET%^ becomes more clear, while to the south the bright lights of the public square start to fade. Just west of here, a door and a sign can be made out in the day's light.");
    set_night_long("Anga Street is destered, except for the odd animal here and there. The soft glow of lamps is seen clearly to the north, while bright lights spear the dark night. The outline of a door and a sign can be barely made out to the west.");
    set_items((["beds" : "The beds of %^MAGENTA%^Coral%^RESET%^, grown and cared for by experts of Coral growth, the Coral is made into armour for any citizen who wishes it...and can pay for it.", "lights" : "The bright lights mark the presence of the NuShae Public Square.", "door" : "It leads to the insides of a shop.", "sign" : "Hand crafted by a skilled hand, with something to read upon it."]));
    set_exits( (["north" : ROOMS"coral2", "west" : ROOMS"astore", "south" : ROOMS"t2"]) );
}

void init() {
  ::init();
    add_action("read", "read");
}
int read(string str) {
  if(!str)
    if(str != "sign") return 0;
    write("%^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^ %^ORANGE%^Armour Store%^RESET%^. All are welcome to come trade inside.");
    return 1;
}

void reset() {
    ::reset();
     if (children(MOB"rshark")==({})||
         sizeof(children(MOB"rshark"))==1)
            new(MOB "rshark")->move(this_object());
}
