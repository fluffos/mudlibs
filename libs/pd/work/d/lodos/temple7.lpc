#include <lodos.h>
#include <std.h>
inherit ROOM;

int book;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("You are now inside of the temple's library. "
            "Several bookshelves line the walls and several "
            "books are scattered about.");
   book = 0;
   set_property("light", 2);
   set_items(([ "walls" : "They are a dark blue in color.",
                "bookshelves" : "They are filled with many strange books.  One "
                  "of these books looks rather out of place.",
                "books" : "They are in a strange language you do not "
                   "understand.  One of the books seems out of place.",
                "tiles" : "The tiles on the ground are a light grey."
            ]));
   set_exits(([ "west" : ROOMS"temple8",
                "north" : ROOMS"temple3" ]));
}

void init() {
   ::init();
   add_action("pull", "pull");
}

int pull(string str) {
   if(str != "book") return 0;
   if(book) return 0;
   write("Perhaps the monks wont mind if you borrow one of their books for awhile.\n");
   new("/d/citrin/obj/quest/book")->move(this_player());
   book=1;
   return 1;
}

void reset() {
 ::reset();
   if (!present("book"))
      new(OBJ"book")->move(this_object());
   book = 0;
}
