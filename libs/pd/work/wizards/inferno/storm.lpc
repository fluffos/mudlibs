#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("here");
   set_long("there");
   set_heart_beat(1);
}

void reset() {
 ::reset();
   if (query_night() && !present("igor", this_object()))
     new("/wizards/inferno/igor")->move(this_object());
}

void init() {
 ::init();
   set_heart_beat(1);
}

void clean(object ob) {
   message("info", ob->query_cap_name()+" fades into nothing.", this_object());
   ob->remove();
}

void heart_beat() {
   int i, check;
   object *ob = ({ }), you;

   if (!query_night()) {
     if ((you = present("igor", this_object())))
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
