#include <std.h>
#include <rain.h>
inherit ROOM;

object board;

void create() {
 ::create();
   set_properties(([ "light" : 2,  "night light" : 2,  "no steal" : 1,
        "no bump" : 1, "no magic" : 1, "no castle" : 1, "no attack":1, "town":1 ]));
   set_listen("default", "You hear much talking.");
   set_short("Arborlon square");
   set_long("The elven fortress's square. This is a "
            "place where people come to trade, do business "
            "or even chat. There is a great statue in the middle "
            "of the square. To the west is the merchant district, "
            "and to the east there is the residential district.");
    set_exits((["north" : ROOMS"village3",
		"east" :  ROOMS "home3",
		"west" :  ROOMS "mpath3"]));
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "elven board" }) );
    board->set_max_posts(80);
    board->set_location("/d/nopk/standard/rain_forest/square");

    board->set("short", "Elven board");
    board->set("long", "This board is for all the elfs to post\n");
    board->set_board_id("board");
}

void reset() {
 ::reset();
    if(!present("statue"))
      new(OBJ "statue")->move(this_object());
    if (!present("peasant"))
      new(MOB "peasant2")->move(this_object());

}

