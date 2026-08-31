#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "beach" : 1]));
    set_short("South Anga Street");
    set_listen("default", "Loud clanging and hammering can be heard from the weaponsmiths'.");
    set_smell("default", "The air is heavy with smelted iron.");
    set_long("Anga Street shows heavy signs of usage, by feet and carts carrying large loads of %^BOLD%^%^BLACK%^Iron%^RESET%^ and %^BOLD%^%^GREEN%^Seaweed%^RESET%^. Far north, bright lights mark the public square. Off to the south is the way to the %^BOLD%^%^BLACK%^Iron Mines%^RESET%^. A door is east of here, with a sign sitting outside the building it enters.");
    set_night_long("Anga Street shows heavy signs of usage, by feet and carts carrying large loads of %^BOLD%^%^BLACK%^Iron%^RESET%^ and %^BOLD%^%^GREEN%^Seaweed%^RESET%^. Far north, bright lights mark the public square even through the darkness. Lamps are lit to the south, while a door and a sign can just be made out east of here.");
    set_items((["mines" : "The %^BOLD%^%^BLACK%^Iron mines%^RESET%^ of NuShae are legendary for their fine deposits of Iron Ore, easily made into weapons and armour for the fighting members of the guardians of NuShae.", "lights" : "The bright lights mark the presence of the NuShae Public Square.", "street" : "Many ditches and holes mark the street, showing clear signs of heavy use by heavy loads.", "door" : "It is the entrance to a store.", "sign" : "A roughly made sign, there is something to read on it."]));
    set_exits( (["north" : ROOMS "t3", "south" : ROOMS "iron2", "east" : ROOMS "wstore"]) );
}

void init() {
  ::init();
    add_action("read", "read");
}
int read(string str) {
  if(!str)
    if(str != "sign") return 0;
    write("%^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^ %^BOLD%^%^BLACK%^Weapons Store%^RESET%^. All are welcome to come trade inside.");
    return 1;
}

void reset() {
    ::reset();
     if (children(MOB"crab")==({})||
         sizeof(children(MOB"crab"))==1)
            new(MOB "crab")->move(this_object());
}
