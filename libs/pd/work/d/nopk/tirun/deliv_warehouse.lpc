#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1, "no steal" : 1 ]));
    set_short("Tirun Delivery");
    set_long(
      "A new recently built warehouse, everything is made of new ceadar planks. A large "
      "counter keeps anyone from moving deeper into the building. Packages of all shapes "
      "and sizes are stacked neatly on and behind the counter. A sign hangs on the wall. " 
      );
    set_night_long(
      "Dark and abandoned, the warehouse is deserted at night. Shadows in the dark corners "
      "of the room may be packages but it is hard to tell without the proper light. A closed "
      "sign hangs on the counter." 
      );
    set_items(([
        "packages" : "Packages wrapped in waxxed cloth to keep them dry.",   
        "planks" : "Freshly cut ceadar planks.",
        "shadows" : "Box shaped objects barely discernable in the dark.",
        "sign" : "A new sign, you may try reading it.",
        "counter" : "A new counter spanning from the north wall to the south wall."
      ]));
    set_exits(([
        "out" : ROOMS"pier1"
      ]));
    set_smell("default", "It smells of fresh cut cedar.");
    set_listen("default", "Waves lapping against the docks outside can be heard.");
    set_heart_beat(1);
}
void reset() {
    ::reset();
    // the following two lines are for day mobs
    if (!query_night() && !present("headmaster", this_object())) {
        new(ROOMS"delivery/headmaster")->move(this_object());
    }
}
void init() {
    ::init();
    set_heart_beat(1);
    add_action("read", "read");
}
void move(object ob) {
    message("info", "%^BOLD%^%^GREEN%^"+ob->query_cap_name()+" leaves east.%^RESET%^", this_object());
    ob->move(ROOMS"delivery/removeroom");
}
void heart_beat() {
    int i, check;
    object *ob = ({ }), you;
    if (query_night()) {
        if ((you = present("headmaster", this_object())))
            move(you);
    }
    ob = all_inventory(this_object());
    i = sizeof(ob);
    check = 0;
    while (i--) {
        if (ob[i]->is_player())
            check = 1;
    }
    if (!check) {
        set_heart_beat(0);
        return;
    }
}
int read(string str)
{
 if (!str || str=="") return 0;
 if (str!="sign") return 0;
 write("Rules for deliveries. Anyone is welcome to make deliveries. In return for your time, "
       "you will be rewarded with pay and experience. However, anyone that uses speedwalk "
       "programs, teleport spells, or other instant move techniques will be punished and banned "
       "from making deliveries. The warehouse is closed at night. If you do not bring in your "
       "receipt before we close, please return it in the morning.");
 return 1;
}
