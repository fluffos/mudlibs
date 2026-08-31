#include <std.h>
#include <marsh.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([
      "light" : 2,
      "indoors" : 1,
    ]) );
    set_short(
      ""
    );
    set_long(
   "You should not be here!!!!."
    );
    set_exits( ([
    ]) );
    set_items( ([
    ]) );
    set_smell("default",
      ""
    );
    set_listen("default",
      ""
    );
}

void init() {
 ::init();
   set_heart_beat(1);
}

void clean(object ob) {
   ob->remove();
}

void heart_beat() {
   int i, check;
   object *ob = ({ }), you;

   if (!query_night()) {
     if ((you = present("lizardman", this_object())))
       clean(you);
   }
   if (!query_night()) {
     if ((you = present("spear", this_object())))
       clean(you);
   }
   if (query_night()) {
     if ((you = present("cockroach", this_object())))
       clean(you);
   }
   ob = all_inventory(this_object());
   i = sizeof(ob);
   check = 0;
   while (i--) {
     if (ob[i]->is_player())
       check = 1;
   }
   if (!check) {
     set_heart_beat(0);
     return;
   }
}
