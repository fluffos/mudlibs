#include <std.h>
#include <tirun.h>
inherit HALL;

void create() {
    object board;
    ::create();
    set_type("clergy");
    set_short("Clergy Hall");
    set_long(
      "The Clergy Hall is a place of worship and prayer to all forms of "
      "divinity; good, evil, and neutral. The only exit from the hall is north, "
      "into the entrance of the Clergical Temple. The ceiling of the temple gives "
      "the illusion that it stretches endlessly into the sky."
    );
    set_items(([
	"ceiling" : "A master's paint job, it is hard to focus on any part of the "
	"ceiling.",
	"exit"    : "The exit from this room is west.",
	"hall"    : "A hall of worship and religion."
      ]));
    set_exits(([
	"north" : ROOMS"clergy/clergy_join"
      ]));
    this_object()->set_type("clergy", "none");
    board = new(BBOARD);
    board->set_name("board");
    board->set_id( ({ "board", "clergy board" }) );
    board->set_max_posts(80);
    board->set_location(ROOMS"clergy_hall");
    board->set("short", "The board of religion");  
    board->set("long", "This board is here for all Clergy to post on.\n");
    board->set_board_id("clergy_board");
}
