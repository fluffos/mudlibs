#include <guild.h>
inherit ROOM;

void create() {
    ::create();
    set_name("Black Force Guild Meeting Room");
    set_long("This is the main meeting hall of all the guild "
      "members. Here many discussions arouse about pk missions and "
      "other evil plots. A table rests in the center of the room "
      "surrounded by enough chairs for all the members. There are some "
      "papers laying on the table. There is a large sphere here that "
      "the guildmasters use to initiate new members.");
    set_properties( (["light" : 3, "night light" : 2, 
	"indoors" : 1, "no attack" : 1, 
	"no magic" : 1, "no bump" : 1, 
	"no steal" : 1]) );
    set_exits(([
	"west" : ROOMS"blackforce/hall",
      ]) );
    set_items( ([ "table" : "It is covered with paperwork.",
	"paperwork" : "The papers are about possible members. "
	"Farther in the pile is paperwork about pk missions.",
	"sphere" : "The sphere illuminates the room.",
      ]) );
}

