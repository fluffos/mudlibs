#include <std.h>
inherit ROOM;
void create() {
::create();
set_name("house builder");
set_long("This is the local carpenter's house.  Not much is in this plain house.  "
"By the looks of it, the house is brand new.  A desk sits in the middle of the room "
"with a sign sitting on the top of it.");
set_short("Builders House");
set_exits(([
"east" : "/d/tirun/sveros1",
]));
set_items(([
"sign" : "Perhaps you should read it.",
"desk" : "A sign is on top of it.",
]));
}
void init() {
::init();
add_action("purchase", "purchase");
}
int purchase(string str) {
if(!str) return notify_fail("Purchase what?\n");
if(str != "house") return notify_fail("Purchase what?\n");
if(this_player()->query_money("gold") < 75000 ) return 
notify_fail("You are too poor for a house.\n");
write("You apply for a house.\n");
write("A piece of paper appears on top of the desk.  You reach out and take the paper.");
this_player()->add_money("gold", -75000);
new("/d/tirun/whit/paperwork")->move(this_player());
return 1;
}
int read(string str) {
if(!str || str != "sign") return notify_fail("Read what?\n");
write("To buy a house:  A house is 75,000 Gold.  You will recieve paperwork on "
"the house.  You will than take your paperwork to a location that you would like to "
"build your house.  You will than mark the paperwork and the builder will start to "
"build your house.\n");
return 1;
}
