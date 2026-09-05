#include "/obj/ansi.h"
#define ROOM    "/players/reflex/lib/std/random/room"
inherit ROOM;

query_no_fight(){ return 1; }
void create() {
if(!present("monk_book", this_object())){
move_object(clone_object("/players/maledicta/closed/w/OBJ/trainer_monk.c"), this_object());
}
::create();
    set_short(BOLD+"A Library"+NORM);
    set_long(BOLD+
        "A library of the temple monks.\n"+NORM+
	"The reading room is circular and the shelves cover all the outer\n"+
	"walls completely around the circumference of the room. The\n"+
        "shevels are filled with books and many are on the tables throughout\n"+
        "the room. On a pedestal at the far end of the room rests a large book.\n"+
	"The ceiling is domed, and is covered in a painting depicting\n"+
	"the stars and the universe, while the floor is simple and made of\n"+
	"wood. North is the arch leading back into the passageway.\n");
    set_items(([
        "shelving" :
        "These wooden shelves are full of books from top to bottom.\n", 
        "ceiling" :
        "The ceiling shows the night sky in great detail.\n",
        "tables" :
        "Large wooden tables arranged randomly.\n",
        "walls" :
        "The walls are covered with shelving filled with books\n",
        "books" :
        "Many ancient books are on the shelves filling them.\n",
        "pedestal" :
        "This is a large pedestal engraved with phrases written in Latin.\n",
	"painting" :
	"This painting depicts the night sky.\n",
        ]));
    set_smells(([
	"default" :
	"There is the smell of old paper.\n",
	]));
    set_sounds(([
	"default" :
	"It is very quiet here.\n",
	]));
    set_exits(([
        "north" : "/room/temple/1",
        ]));
    set_light(1);
}
