#include <std.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_north", "north");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The run-down supply shop of Outland");
    set("long",
        "Outlaws from all over Carnage used to do their business selling "
        "and buying ill-gotten goods here at the Outland Supply Shop.  "
	"Unfortunatly, Bertha has been taken off to jail for murder "
        "and theft. The shop is horribly run down now, and the ceiling "
        "and wall boards are rotting and falling apart. It looks like "
        "someone has ransacked the area, looking for something. An "
        "old door hangs, half-way off it's hinges.");
    set_items(([
          "shop" : "You can buy and sell things here.",
          "area" : "The entire shop has been pulled apart.",
          "door" : "Bertha used to keep her supplies back there.",
          "boards" : "They are rotting and falling apart."]));
set_exits( (["south" : "/d/nopk/standard/outlands/dust1",
"north" : "/d/nopk/standard/outlands/storage"]));
}
/*
void reset() {
    ::reset();
      if(!present("bertha")) 
}
*/
int go_north() {
    write("Seeing that Bertha is not here, you head north.");
    say(this_player()->query_cap_name()+" takes advantage of Bertha's absence and heads north.", this_player());
this_player()->move_player("/d/nopk/standard/outlands/storage", "north");
    return 1;
}
