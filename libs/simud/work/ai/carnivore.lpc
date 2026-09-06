// New arnivore AI - completely event driven and functional. Yay!
// - Al [Oct 6, '04]
// Updated so carnivores don't leave skins lying around
// - Al [Jul 10, '05]

inherit "/ai/module";

object prey;

int do_devour( object prey, int walk );

void set_prey( object what ) { prey = what; }
object query_prey() { return prey; }

string query_module_name() {
   return "carnivore";
}

void on_hunger() {
   object *obs, mob = environment(this_object());

   // don't switch targets if already killing
   if ( prey && environment(prey) == environment(mob) )
      return;

   // check for meat in inventory
   obs = filter( all_inventory(mob), (: $1->query_is_edible() && !($1->query_invis()):) );

   if ( sizeof(obs) ) {
      while( sizeof(obs) ) {
         int i = random(sizeof(obs));

         object meat = obs[i];
         obs -= ({ meat });

         int q = meat->query_quantity();
         if (q < 1)
            q = 1;

         for(int j = 0; j < q; j++) {
            if (!command( "eat " + meat->query_name(), mob )) {
               return;
            }
         }
      }
   }

   // todo:  collect meat from environment if possible
   // need to be cautious of unreachables.

   // find edible mobs
   obs = filter(all_inventory(environment(mob)), (: $1->query_product_aspect() && $1->query_race() != mob->query_race() :) );
   if ( !sizeof(obs) ) {
      mob->wander();
      return;
   }
   prey = obs[random(sizeof(obs)-1)];

   if ( prey->query_dead() ) {
      /* prey is already dead, scavenge it */
      if (!do_devour( prey, 1 )) {
         emote( "Growls grumpily, failing to reach prey" );
         /* can't reach it, wander */
         mob->wander();
         return;
      }
   } else {
      command( "kill " + prey->query_name(), mob );
   }
}

void on_thirst() {
   object *graze_list = all_inventory(environment(environment()));

   graze_list = filter( graze_list, (: $1->query_is_drinkable() :) );
   if( sizeof(graze_list) && random(10) ) {
      string graze_name = graze_list[random(sizeof(graze_list))]->query_name();
      command( "drink " + graze_name, environment() );
   } else
      environment()->wander();
}

int do_devour(object what, int walk) {
   // make sure they can butcher well ;)
   environment()->set_skill("craft.butcher",50);
   if (walk) {
      if (!command( "walk to " + what->query_name(), environment() )) {
         return 0;
      }
   }
   environment()->push_action( ({ 500, load_object("/bin/monster/devour"), what, ST_STANDING, 0 }) );
   return 1;
}

void on_death(object who) {
   if ( who == prey )
      do_devour(prey, 1);
}
