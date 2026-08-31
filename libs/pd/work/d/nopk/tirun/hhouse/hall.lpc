#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
    ::create();
    set_smell("default", "The smell of old books fills the air.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
      "This room is small and circular, the walls composed entirely of shelves filled "
      "with books.  There is only one visible way out of this cramped library.  "
      "There seems to be no reason for this library to be hidden.  Books line the "
      "walls in every direction.  Any book imagined could probably be found here.");
    set_items(
      (["walls" : "All around are shelves of books and books.",
	"books" : "You could probably find any book you wanted if you searched."]) );
    set_exits( ([ "out" : ROOMS"hhouse/2" ]) );
}


void init() {
    ::init();
    add_action("search", "search");
}

void reset() {
    ::reset();
    remove_pre_exit_function("north");
    remove_exit("north");
}

int search(string str) {

    write("What is the name of the book you want to search for?");
    input_to("pull_book");
    return 1;
}

int test_north() {

    if(get_object(ROOMS"hhouse/elevator")->query_down()) {
	write("The way north drops down into a deep hole.  A series of ropes drop down into the hole.");
	return 0;
    }
    return 1;
}

void pull_book(string str) {

    if(str == "Chimaera" || str == "chimaera") {
	write("As you pull the book, something in the wall clicks and part of the wall swings open!");
	say("As "+this_player()->query_cap_name()+" pulls on a book, part of the wall swings open!");
	add_exit(ROOMS"hhouse/elevator", "north");
	add_pre_exit_function("north", "test_north");
	return;
    }

    write("After searching around a bit you find a book named "+capitalize(str)+".\n\n");
    say(this_player()->query_cap_name()+" searches around and finds a book.");
    write("You read it a bit and learn about "+str+".\n");
}
