#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("marsh",1);
    set_short("Swamp waters");
    set_long(
      " In the swampy-waters, swimming."
          );
    set_items(([
        "water" : "Mixture of blue and brown.",
        "hole" : "It is directly under you, looks like a tunnel.",
    ]));
    set_listen("default", "Burbles of air bubbles escaping upwards.");
    set_exits( ([
"dive" : WATER "hole",
"out" : MARSH "mar7",
    ]) );
}
void init()
{
 ::init();
 add_action("Fdive", "dive");
 add_action("Fout", "out");
}
int Fdive()
{
 write("You take a deep breath, and do a graceful mermaid dive.");
 return 0;
}
int Fout()
{
 write("You head for the shore.");
 return 0;
}

