#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 1, "no teleport" : 1, "no teleport" : 1, "no bump" : 1, "night light" : 1]) );
    set_smell("default", "The tunnel has a fresh and frozen smell to it.");
    set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
    set_short("a large ice cavern");
    set_long(
      "This large cavern is mostly empty. Stalactites drip water down from above. The walls "
      "are slick rocks that are freezing to the touch. The open air here moves in a slight "
      "breeze, chilling everything.");
    set_items(([
	"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
	"snow" : "The ground is covered in a thin layer of snow..",
	"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
	({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
      ]));
    set_exits(([ "west" : ROOMS "/icystuff/34.c"]));
    set_no_clean(1);
}

void reset() {
    object ob, ob2;
    ::reset();
    /*
  if (!present("iceblock") && !query_property("finished_quest")) {
  new(MOBS+"iceblock")->move(this_object());
  }
  */
    if (!present("black portal")) {
	ob = new("//d/events/4thjuly2008/items/black");
	ob->set_destination("/d/events/4thjuly2008/rooms/darkandscary/1");
	ob->move(this_object());
    }
}

