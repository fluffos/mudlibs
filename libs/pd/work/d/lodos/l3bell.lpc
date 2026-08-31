#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Balancing on top of a bell");
   set_long("You have foolishly leaped onto the large golden bell hanging "
     "at the top of the temple's bell tower. Every now and again the bell "
     "will swing, and you must frantically gain your balance again. If you "
     "look at it optimistically, it's only a matter of minutes before you "
     "plummet to your death. Pesimistically.. well, we dont want to think "
     "about that. A single thick rope holds the bell in place three floors "
     "above the temple floor. A large wooden circle far below you doesn't "
     "look like the most stable of places to land, either. If you continue "
     "along your foolhardy path, you might as well untie the rope!");
   set_items(([
     "rope"  : "The only thing holding the bell up.",
     "bell"  : "It could easily rock when you least expect it, sending you "
               "hurtling downwards.",
     "ground": "A large wooden circle down below.",
     "down"  : "Eek, you regret looking down immediatly."
   ]));
   set_properties(([ "no teleport" : 1, "light" : 2, "night light" : 2, "indoors" : 1 ]));
   set_exits(([
     "off" : ROOMS"l3m5"
   ]));
}

int unleash_bell(string str) { // O! the horror
   object *all;
   int i;
   if (!str) return 0;
   if (str != "bell" && str != "rope" && str != "the rope" &&
       str != "the bell") return 0;
   write("Fool! You plummet downwards to your demise along with the bell!");
   say(this_player()->query_cap_name()+" unties the rope holding the bell "
     "up! Immediatly you begin to fall!!", this_player());
   all = all_inventory(this_object());
   i = sizeof(all);
   while (i--) {
     all[i]->move(ROOMS"l1m5");
   }
   environment(this_player())->set_bell(0);
   environment(this_player())->add_exit(ROOMS"lb1m5", "down");
   new(OBJ"bell")->move(environment(this_player()));
   tell_room(environment(this_player()), "A huge bell has been untied and "
     "quickly falls, smashing a hole through the wooden floor!", ({ }));
   return 1;
}

void init() {
 ::init();
   add_action("unleash_bell", "untie");
}
