#include <std.h>
#include <vampq.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("Book of Vampire's");
    set("id", ({"book", "book of vampires", "book_of_vampires"}) );
    set_short("%^BOLD%^%^BLACK%^Book of Vampire's%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Fringed around the edges, this book looks ancient. A soft %^RESET%^%^RED%^glow%^BOLD%^%^BLACK%^ surrounds the book. There is an inscription on the first page that can be read.%^RESET%^");
    set_weight(1);
}
void init() {
    ::init();
    add_action("read", "read");
}
int read(string str) {
    if(!str)
	return notify_fail("Read what?\n");

    switch(str) {
    case "inscription":
	write("%^BOLD%^%^RED%^'%^WHITE%^To those who wish to find out more about this book: \n %^RESET%^ \n %^BOLD%^%^WHITE%^Only one can read this and tell you where to go.%^RESET%^ \n %^BOLD%^%^WHITE%^He dwells in the area of the false,%^RESET%^ \n %^BOLD%^%^WHITE%^In the room of knowledge,%^RESET%^ \n %^BOLD%^%^WHITE%^In the land of the %^BLACK%^demon god%^WHITE%^.%^RESET%^ \n %^BOLD%^%^WHITE%^Find him, and you'll be on the right path.%^RED%^'%^RESET%^");
	break;
    case "page 1":
	write("%^BOLD%^%^RED%^This page cannot be read by just anybody.%^RESET%^");
	break;
    case "page 2":
	write("%^BOLD%^%^RED%^This page cannot be read by just anybody.%^RESET%^");
	break;
    case "page 3":
	write("%^BOLD%^%^RED%^This page cannot be read by just anybody, wonder who could read it...%^RESET%^");
	break;
    case "page 4":
	write("%^BOLD%^%^RED%^Hmm where is he?%^RESET%^");
	break;
    case "page 5":
	write("%^BOLD%^%^RED%^Maybe you should go find the person you need!%^RESET%^");
	break;
    case "page 6":
	write("%^BOLD%^%^RED%^CLOSE THE STUPID BOOK AND GO FIND HIM!FOR THE LOVE OF DRACULA!%^RESET%^");
	break;
    default: return notify_fail("Syntax: <read page #>\n");
    }
    return 1;
}
