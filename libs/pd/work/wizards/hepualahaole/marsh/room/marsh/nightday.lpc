#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("swamp",1);
    set_short("Marsh");
    set_day_long(
     "The surrounding area is just one giant mud hole.  There are "           "occasional trees here and there."
    );
    set_night_long(
      "Guided only by moonlight, what used to be a boring marsh land, "
      "now it got interesting.  Dark shapes with beady red eyes are "
      "off in the night."
    );
    set_items(([
        "marsh" : "There are bones sticking out of the mud and dead trees.",
        "mud" : "Mixture of dirt and water, mostly water.",
        "eyes" : "Red eyes glowing everywhere.",
        "shapes" : "As one shooshes by..you noticed a tail.",
    ]));
    set_smell("default", "It smells of muddy waters.");
    set_listen("default", "Sounds of creatures splashing in a distance");
    set_exits( ([
       "north" : MARSH "marsh19",
       "northeast" : MARSH "marsh20",
       "northwest" : MARSH "marsh18",
       "south" : MARSH "marsh11",
       "east" : MARSH "marsh15",
       "west" : MARSH "marsh13",
    ]) );
    set_heart_beat(1);
}
void reset() {
 ::reset();
   if (query_night() && !present("lizardman", this_object()))
     new(MOB"lizardman")->move(this_object());
   if (!present("cockroach", this_object()))
     new(MOB"cockroach")->move(this_object());
}
void init() {
 ::init();
   set_heart_beat(1);
}
void clean(object ob) {
   message("info", ob->query_cap_name()+" leaves west.", this_object());
   ob->remove();
}
void heart_beat() {
   int i, check;
   object *ob = ({ }), you;
   if (!query_night()) {
     if ((you = present("lizardman", this_object())))
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
