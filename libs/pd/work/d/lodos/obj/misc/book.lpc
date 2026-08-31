#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_short("a thick old book");
    set_id(({ "book" }));
    set_name("book");
    set_long("The old, thick, black book has been bound "
      "together by several brown strings. Although "
      "it's pages are numerous, they are all written "
      "in some strange language. All you can make out "
      "is that this book looks like a tome of spells.");
    set_weight(2);
    set_curr_value("copper", 52);
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    if (!str) return 0;
    if (present(str, this_player()) != this_object() &&
      present(str, environment(this_player())) != this_object())
	return 0;
    write("You do not understand a word of it!");
    return 1;
}
