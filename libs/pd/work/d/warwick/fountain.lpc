#include <std.h>

inherit OBJECT;
mapping uses;
void create() {
   ::create();
   uses=([]);
   set_name("fountain");
   set_short("a mythical fountain");
   set_long("This is a large fountain.  Water shoots out of the top of "
     "it, falling down into the bowl at the bottom.  The water is clear "
     "and blue, and looks rather refreshing.");
   set_prevent_get("It's stuck to the floor!");
}

void init() {
   ::init();
   add_action("drink", "drink");
}

int drink(string s) {
   object tp = this_player();
   int amt = 0;
   int healed = 0;
   
   if(!s || (s != "fountain" && s != "water")) return notify_fail("Drink what?\n");
   
   if( tp->query_disable() )
        return notify_fail("You are too busy to do that.\n");
   
   if(!uses) uses = ([]);
   if(!uses[tp->query_name()]) uses[tp->query_name()] = (int)0;
   if(uses[tp->query_name()] > 5) return notify_fail("The water has no effect.\n");
   
   // If your vitals are above 1/2, too bad, no healing
   if( tp->query_hp() >= (tp->query_max_hp() / 2) &&
       tp->query_mp() >= (tp->query_max_mp() / 2) &&
       tp->query_sp() >= (tp->query_max_sp() / 2) )
   {
       message("info", "You are too healthy for the fountain to help you.", tp);
       return 1;
   } 
   
   // Only change HP if it's for the better
   amt = (tp->query_max_hp() / 4) + random((tp->query_max_hp() / 4));
   if( amt > tp->query_hp() )
   {
       tp->set_hp(amt);
       healed = 1;
   }
   
   // Only change SP if it's for the better
   amt = (tp->query_max_sp() / 4) + random((tp->query_max_sp() / 4));
   if( amt > tp->query_sp() )
   {
       tp->set_sp(amt);
       healed = 1;
   }
   
   // Only change MP if it's for the better
   amt = (tp->query_max_mp() / 4) + random((tp->query_max_mp() / 4));
   if( amt > tp->query_mp() )
   {
       tp->set_mp(amt);
       healed = 1;
   }
   
   // Only para them and add a use if it actually did something.
   if( healed )
   {
       uses[tp->query_name()]++;
       write("You drink the water and are overcome with energy.");
       say(tp->query_cap_name()+" takes a drink and is paralyzed for a moment.");
       tp->set_paralyzed(5, "You are overcome by the energy.", "The energy releases you.");
   }
   else
   {
       message("info", "The water was cool and refreshing... but that's all.", tp);
       message("info", tp->query_cap_name() + " drinks the water in the fountain.",
            environment(tp), tp);
       tp->set_disable(1);
   }
   
   return 1;
}

