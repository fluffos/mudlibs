#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^YELLOW%^The Pool of the Archangel%^RESET%^");
   set_long("%^BOLD%^The still silver water does not ripple at all. Though the "
     "water is liquid, it does not get you wet at all. The pool water restores "
     "goodness in the hearts of those who wade in it. Light shines off the "
     "surface of the pool, illuminating the entire room surrounding it. Marble "
     "steps lead out of the water.");
   set_properties(([ "no attack" : 1, "no magic" : 1, "no bump" : 1,
     "no steal" : 1, "no teleport" : 1, "indoors" : 1, "light" : 2 ]));
   set_items(([
     "water" : "The warm silver water is wet to the touch, but does not get you "
               "yourself wet at all.",
     "pool"  : "Those within the pool will have the good in their heart restored.",
     "room"  : "The surrounding room is made mostly of marble.",
     "steps" : "Marble steps lead out of the silver pool to the temple.",
   ({"light", "surface" }) : "The light relecting off the surface of the pool is "
               "the cause of the room's complete illumination."
   ]));
   set_exits(([ "out" : "/wizards/inferno/angel/west" ]));
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
       tell_object(all[i], "%^YELLOW%^Your heart is light and joyful for a "
         "moment.");
       all[i]->add_alignment(1);
   }
//   if (!t) set_heart_beat(0);
}
