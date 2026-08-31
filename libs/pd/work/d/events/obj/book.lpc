#include <std.h>

inherit OBJECT;

int lock;

void create() {
    ::create();
    set_name("book of shadows");
    set_long("The book is bound in thick, leather binding.  Several "
      "strange letters are on the cover.  A silver lock prevents "
      "anyone from opening the book.");
    set_id(({ "book", "book of shadows" }));
    set_short("Book of Shadows");
    lock = 1;
}

void init() {
    ::init();
    add_action("read", "read");
    add_action("lock", "lock");
    add_action("unlock", "unlock");
}

int read(string str) {
    if(!str || str != "book") {
	write("Read what?\n");
	return 1;
    }
    if(lock) {
	write("The book is locked.\n");
	return 1;
    }
    if(this_player()->query_race() != "demon") {
	write("A burst of flame comes out of the book preventing "
	  "you from viewing it.\n");
	return 1;
    }
    write("The pages inside the book are blank,  but as you flip "
      "further into the pages of the book you feel the sensation "
      "to bring it to someone.\n");
    write("\nAt the end of the book it contains one word:  Malfesto");
    return 1;
}

int lock(string str) {
    write("The book is already locked.\n");
    return 1;
}

int unlock(string str) {
    write("You do not have the power to unlock the book.\n");
    return 1;
}


