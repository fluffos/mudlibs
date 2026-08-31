#include <std.h>
#include <tirun.h>

inherit ROOM;

int candle;

void create() {
    ::create();
    set_smell("default", "Thick dust makes breathing difficult.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
      "This small room is covered with various parchments.  Junk litters the floor, "
      "hiding it from sight.  Steps must be taken carefully to avoid crushing anything "
      "accidentally.  A torn and broken down cot is the only furnishing in this room.  It "
      "does not seem comfortable at all, though.  A single candlestick holder protrudes from "
      "the wall, holding a half-melted candle.  The small doorway leads back into the hallway.");
    set_items(
      (["parchments" : "Some are hastily drawn animals, while others are ingredients of what seem to be potions.",
	"junk" : "Books, bottles, and different apparatus make up the junk strewn across the floor.",
	"cot" : "The cot is old and rickety and most of all, very uncomfortable looking.",
	({"candlestick", "candle"}) : "A small flint and steel mechanism rests next to the candle, worn from much use.",
	"mechanism" : "The flint and steel is used to light the candle.",
	"books" : "Different books on alchemy and rare creatures.",
	"bottles" : "Some empty, some full of multi-colored liquids.",
	"apparatus" : "Stands for bottles, strainers, and some other strange gadgets."]) );
    set_exits( ([ "east" : ROOMS"hhouse/upstairs"]) );
    add_pre_exit_function("east", "go_east");
    candle = 0;
}

void reset() {
    ::reset();
    candle = 0;
}

void init() {
    ::init();
    add_action("light", "light");
}

int light(string str) {
    if(!str)
	return 0;
    if(str != "candle" && str != "candlestick")
	return 0;

    if(candle)
	return notify_fail("The candle is already lit.\n");

    write("You grab the flint and steel and manage to light the candle.");
    say(this_player()->query_cap_name()+" uses a flint to light the candle.");
    call_out("second", 3, this_player());
    candle = 1;
    return 1;
}

void second(object tp) {
    message("info","After a moment, a hidden door in the wall slides open, revealing a book!", this_object());
    message("info","You take the book from it's resting place.", tp);
    message("info",tp->query_cap_name()+" takes the book.", this_object(), tp);
    new(ROOMS"hhouse/diary")->move(this_player());
}

int go_east() {
    write("As you leave the room, you accidently crush a bottle!  Ooops!");
    return 1;
}
