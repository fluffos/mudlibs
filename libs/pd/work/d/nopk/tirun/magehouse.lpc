#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Old man's house.");
    set_long(
      "This house belongs to an old man...  He has been frantically searching "
      "his house for quite some time it seems.  "
      "There are piles of old books and scrolls strewn about the floor.  "
      "Apparently the old man here is involved in the magic arts. ");
    set_exits( (["out" : ROOMS"edovin5"]) );
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no attack", 1);
    set_property("no bump", 1);
    set_items(
      (["books" : "Ancient books with old and cryptic writing.",
	"scrolls" : "They are all bound, and it would probably be dangerous to open them.",
	"house" : "If everything wasn't thrown about, the house is very "
	"impressive, considering the outside appearance."
      ]) );
}

void reset() {
    ::reset();
    if(!present("old man"))
new("/d/nopk/tirun/obj/mon/oldman")->move(this_object());
}
