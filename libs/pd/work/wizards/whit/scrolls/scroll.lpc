#include <std.h>

inherit OBJECT;

void create() {
::create();
set_name("Scroll of teleportation");
set_long("This is a scroll of teleportation");
set_short("teleportation scroll");
set_long("This is a scroll of teleportation.  You may set it "
"to whatever room you want.  To see what place this scroll is "
"set to type <query scroll>.  You may cast scroll to teleport.");
set_weight(5);
}

int query_auto_load() {
if(this_player()->query_level()>20) return 1;
return 0;
}

void init() {
::init();
add_action("query", "query");
add_action("cast", "cast");
}

int query(string str) {
if(!str) return notify_fail("Query what?\n");
if(str != "scroll") return notify_fail("Query what?\n");

restore_object("/wizards/whit/scrolls/"+this_player()->query_name());
return 1;
}
