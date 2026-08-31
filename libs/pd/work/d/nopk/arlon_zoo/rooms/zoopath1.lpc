#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Near the Entrance");
    set("long",	"You are traveling along a path in the zoo.  To the south is the "+
      "main entrance and the messageboard.  To the north is a sign giving directions"+
      " to the major exhibits.  Trinket shops and other booths line the path here.");
    set_items(
      (["sign" : "It's further north and gives directions to the different exhibits.",
	"booths" : "They line the path selling various things to the visitors.",
	"shops" : "They are selling trinkets to the visitors."
      ]) );
    set_exits( ([ "north" : ROOMS + "zoopath2", 
	"south" : ROOMS + "zooentrance" ]) );
}
