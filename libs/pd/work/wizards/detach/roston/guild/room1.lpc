#include <std.h>
inherit ROOM;
void init() {
    ::init();

add_action("leap_portal" , "leap");
}
void create() {
   object oi;
   ::create();
   set_name("Dark Souls m_room");
   set_items((["corpses"   : "%^ORANGE%^A pile of roting corpses",
               "blood"  : "%^RED%^Pools of blood all over"]));
   set_properties((["light":2, "night light":3]));
   set_short("Dark Souls");
   set_long("%^BOLD%^%^BLACK%^This is the meeting spot of the "
            "D%^WHITE%^a%^BLACK%^r%^WHITE%^k%^BLACK%^ S%^WHITE%^o"
            "%^BLACK%^u%^WHITE%^l%^BLACK%^s.This is where they come "
            "to go over the kills of the day, or problems that they have "
            "come across. There are tons of corpses all over the floor. "
            "There are pools of %^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^ "
            "all over the ground. The message for all people who are not part of this clan "
            "that happen to get in here is %^WHITE%^You Dont Have To "
            "Fear Us Unless Your Alive%^BLACK%^.%^RESET%^");

   set_exits( ([ "north" : "/wizards/detach/roston/guild/room2",
              "south" : "/wizards/detach/roston/guild/room3",               
              "east" : "/wizards/detach/roston/guild/room5",
              "down" : "/wizards/detach/roston/guild/dungeon" ]));
    oi = new("/std/bboard");
    oi->set_name("Dark Souls Board");
    oi->set_id( ({ "board", "dark board", "souls board" }) );
    oi->set_board_id("Dark_Souls_Board");
    oi->set_max_posts(100);
    oi->set_edit_ok(({"detach"}));
    oi->set_location("/wizards/detach/roston/guild/room1");
    oi->set("short", "%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r"
                     "%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u"
                     "%^WHITE%^l%^BLACK%^s %^WHITE%^B%^BLACK%^o"
                     "%^WHITE%^a%^BLACK%^r%^WHITE%^d");
    oi->set("long", "This board is for the members of Dark souls");
}

void reset() {
     if(!present("guard"))
new("/wizards/detach/roston/guild/guard")->move(this_object());        
     if(!present("statue"))
new("/wizards/detach/roston/guild/statue")->move(this_object());
}                                    
int leap_portal(string what) {
  if (what != "portal") return 0;
this_player()->move_player("/wizards/detach/roston/roston");
    return 1;
}
