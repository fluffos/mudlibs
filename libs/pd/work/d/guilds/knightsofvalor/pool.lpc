#include <std.h>
inherit ROOM;
void create() {
 ::create();
   set_short("The Pool of the Archangel");
   set_long("The pool is full of clear and warm water, with a %^BOLD%^%^YELLOW%^holy light%^RESET%^ shining into it.  The light flickers around the water, covering every area of the pool occasionally.  There is a wonderful feeling of being in this pool, as if the holy light fills your soul with goodness.  There are white stone steps leading out of the pool.");
   set_properties(([ "no attack" : 1, "no magic" : 1, "no bump" : 1,
     "no steal" : 1, "no teleport" : 1, "indoors" : 1, "light" : 2 ]));
   set_items(([
     "water" : "The water is covered by a holy light.",
     "pool"  : "The pool is made completely from white marble.",
     "steps" : "Flawless white marble steps lead out of the small pool.",

   ]));
   set_exits(([ "out" : "/d/guilds/knightsofvalor/poolroom" ]));
   set_heart_beat(1);
}

void init() {
 ::init();
   set_heart_beat(1);
}

void heart_beat() {
   object *all = ({ });
   int i;
   all = all_inventory(this_object());
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_living()) continue;
       tell_object(all[i], "%^BOLD%^%^WHITE%^The %^YELLOW%^holy light%^WHITE%^ enters your soul, making you happy for a moment.");
       all[i]->add_alignment(1);
   }
}
