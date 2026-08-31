#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "beach" : 1, "no attack" : 1, "no bump" : 1, "no magic" : 1, "no steal" : 1]) );
    set_short("NuShae Public Square");
    set_listen("default", "The hustle and bustle of the square is loud yet sufferable.");
    set_long(
      "%^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^ %^CYAN%^Public Square.%^RESET%^\n"
      "The public square of %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^ is a popular place to be. "
      "Executions were cancelled a long time ago, but yet the citizens "
      "still gather to talk and generally be here. The lights here are "
      "bright, and to the north are the %^MAGENTA%^Coral beds%^RESET%^. To "
      "the south can be seen the roads leading to the %^BOLD%^%^BLACK%^Iron mines%^RESET%^. To the "
      "southeast the %^BOLD%^%^GREEN%^Seaweed farms%^RESET%^ can be seen. To go further "
      "east is to enter the palace of the King and Queen."
      );
    set_items(([
        "room" : "People constantly moving about, animals weave between your feet and the current directs the motion of traffic.", 
        "mines" : "The %^BOLD%^%^BLACK%^Iron mines%^RESET%^ of NuShae are legendary for their fine deposits of Iron Ore, easily made into weapons and armour for the fighting members of the guardians of NuShae.",
        "farms" : "%^BOLD%^%^GREEN%^Seaweed%^RESET%^ in all its abundance can be found farmed to the south.",
        "beds" : "The beds of %^MAGENTA%^Coral%^RESET%^, grown and cared for by experts of Coral growth, the Coral is made into armour for any citizen who wishes it...and can pay for it."
      ]));
    set_exits(([
        "west" : ROOMS "entrance1",
        "north" : ROOMS "t2",
        "east" : ROOMS "t3",
        "south" : ROOMS "t4"
      ]));
}

void reset() {
    ::reset();
     if (children(MOB"turtle")==({})||
         sizeof(children(MOB"turtle"))==1)
            new(MOB "turtle")->move(this_object());
}
