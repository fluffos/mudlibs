#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Whit's house");
    set_long("The house seems bigger on the inside than what it does on "
      "the outside.  A fairly large couch sits in the middle of the "
      "room.  A small table sits beside a huge recliner sitting along "
      "the western wall.  The cathedral ceiling add to the huge "
      "expansion of the house.  An arch door to the north leads "
      "to the kitchen along with one to the south that leaves out.");
    set_exits(([
	"south":"/d/tirun/square",
	"north":"/d/tirun/houses/whit/kitchen"
      ]));
    set_smell("default", "A sweet aroma is coming from the north");
    set_items(([
	"couch":"You look over the couch to make sure its a couch.  "
	"After awhile you come to the bright conclusion it is a "
	"couch,  a plain, simple blue couch.",
	({"table","small table"}):"Its a table,  its made out of wood "
	"and built with the finest of fixings.",
	({"recliner","huge recliner"}):"This is Whit's most prized possesion.  "
	"he sits many of hours sitting in it figuring out what to do next.  "
	"And also the biggest stumper of all,  black or white?",
	({"door","arch door"}):"Its a door.  Ever been to mudding school?",
      ]));
}

