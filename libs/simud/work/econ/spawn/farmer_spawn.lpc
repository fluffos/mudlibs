/**
 * A spawn point. This object churns out copies of a given mob type every so
 * often at the location where it is placed. The behavior has changed a great
 * deal since this object was initially launched as a "temporary" measure
 * several years ago.
 *
 * I am tweaking the math further. Current considerations are now as follows:
 *   + Mobs will not spawn if there is another mob of the same race already
 *     in the room (so placing multiple spawn points in the same room doesn't
 *     have any effect).
 *   + The total population of any given mob type is capped. Placing more
 *     spawns increases the maximum allowed population by 25-50 per spawn up
 *     to a hard maximum of 250 (HARD_MAX_POP).
 *   + If population is over 50% of the calculated maximum, spawns will have
 *     a random chance of simply not firing.
 *
 * - al [may 4, '06]
 *
 * For historical sake, here's the original comment:
 *   // A temp object used to spawn monsters at a given
 *   // point. Only spawns when no creatures are around.
 */

#include <object.h>
#include <saveload.h>
#include <coord.h>

int query_invis() {
   return 1;
}

void create() {
   ::create();
}

string query_name() {
   return "farmer_src";
}

string query_specific() {
   return "farmer_src";
}

object id( string s ) {
   if( s == "farmer_src" )
      return this_object();
   else
      return 0;
}

int has_farmer()
{
   object farmhouse = environment(environment());

   object *farmer_ai = filter(
      deep_inventory(farmhouse),
      (: load_name($1) == "/ai/farmer" :)
   );

   return sizeof(farmer_ai);
}

void reset() {
   if (!clonep(this_object())) {
      return;
   }
   if (has_farmer()) {
      return;
   }

   object farmer = clone_object( "/monsters/human" );
   farmer->set_hp(farmer->query_max_hp());
   farmer->set_mana(farmer->query_max_mana());
   farmer->set_endurance(farmer->query_max_endurance());
   farmer->set_food(farmer->query_max_food() * 3 / 4);
   farmer->set_drink(farmer->query_max_drink() * 3 / 4);
   farmer->move( environment() );
   farmer->set_home( this_object() );
   farmer->validate_position();
   filter( all_inventory(environment()),
   	(: load_name($1) == "/obj/work_spot" :) )
   	->apply_for_job(farmer);
   command( "walk random", farmer );
}
