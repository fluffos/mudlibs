#include <std.h>
//coded by Wraith
inherit ROOM;
void init() {
::init();
add_action("hall", "hall");
}
void create() {
    ::create();
     set_name("Acheron Helgrath subhall");
     set_short("Acheron Helgrath subhall");
     set_long("%^BOLD%^%^BLUE%^Welcome to the entrance of The Acheron Helgrath subhall. The door ahead is well "
"%^BOLD%^%^BLUE%^lit buy two %^BOLD%^%^RED%^f%^YELLOW%^lamin%^RED%^g%^RESET%^%^BOLD%^%^BLUE%^ torches. Above the door is the guild "
"%^BOLD%^%^BLUE%^symbol etched in %^BOLD%^%^YELLOW%^gold%^RESET%^%^BOLD%^%^BLUE%^. The letters A C H E R O N have been "
"%^BOLD%^%^BLUE%^carved over the top of the symbol.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
        "no teleport" : 1,
]));
 set_exits( (["hall" : "/d/guilds/acheron/helhall", 
              "out" : "/d/helgrath/rooms/wilndursquare"]) );


    set_items( ([
        "door"  : "This door looks to be well carved and inlaid with several designs.",
        "torch" : "%^RESET%^%^ORANGE%^Fl%^BOLD%^%^YELLOW%^ami%^RESET%^%^ORANGE%^ng%^RESET%^ torches have been hung on either side of the door.",
      ]) );

}

int hall() {
if(this_player()->query_guild()!="acheron" && !wizardp(this_player())) {
notify_fail("A gust of wind prevents you from entering.");
say("A gust of wind blows as "+this_player()->query_cap_name()+" tries "
"to leave into the hall but fails.");
return 1;
}
this_player()->move_player("/d/guilds/acheron/helhall");
return 1;
}
