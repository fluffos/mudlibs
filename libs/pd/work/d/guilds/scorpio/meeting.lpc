#include <guild.h>
inherit ROOM;

void create() {
    ::create();
    set_name("Scorpio Guild Meeting Room");
    set_long("This is the main meeting hall of all the guild "
      "members. Here many discussions arise about pk missions and "
      "other evil plots. A table rests in the center of the room "
      "surrounded by enough chairs for all the members. There are some "
      "papers laying on the table.");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );
    set_exits(([
	"west" : ROOMS"scorpio/hall",
      ]) );
    set_items( ([ "table" : "It is covered with paperwork.",
	"paperwork" : "The papers are about possible members. "
	"Farther in the pile is paperwork about pk missions.",
	"sphere" : "The sphere illuminates the room.",
      ]) );
}

