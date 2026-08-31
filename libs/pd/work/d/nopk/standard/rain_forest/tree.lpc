#include <std.h>
#include <rain.h>
inherit ROOM;

void create()
{
 ::create();
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
 set_short("In a tree");
 set_long(
"A giant tree house. It "
"looks to be made out of branches and leaves. The view from the tree is spactacular. ");
 set_listen("default", "You hear monkeys making noise.");
 set_smell("default", "The humid air stifils your senses.");

 set_property("light", 1);
 set_property("night light", 1);
 set_exits( ([ "down" : ROOMS"path",
/*               "enter" : ROOMS"house" */
]) );
}
