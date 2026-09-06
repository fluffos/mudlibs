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

// Note: if you're going to change this, look at the code below where it is
//       used, just to make sure your change is having the desired effect.
// Acius: Massively nerfed to keep things under control after an earlier
// bug fix. The world needs to remain playable when all spawns hit their
// population cap!
#define HARD_MAX_POP 40

#define SKELLINGTON "/monsters/skeleton"
#define MAX_SKELLINGTONS 250

//#define SPAWN_DELAY 300

string spawn_src;

int query_invis() {
   return 1;
}

void create() {
   ::create();
//   call_out("spawn_tick", SPAWN_DELAY+random(SPAWN_DELAY));
   spawn_src = "/monsters/wolf";
}

string query_name() {
   return "spawn_src";
}

string query_specific() {
   return "spawn_src";
}

object id( string s ) {
   if( s == "spawn_src" )
      return this_object();
   else
      return 0;
}

/// \returns a random number in the top 3/4 of the range 0..max
int range(int max) {
   int bottom = max / 4;
   return bottom + random(max - bottom);
}

int count_spawns() {
   int c = 0;
   object ob;
   foreach( ob : clones("/obj/spawn") )
      c += (ob->query_spawn_src() == spawn_src);
   return c;
}

/**
 * Some silly math to calculate maximum population given a number of spawns.
 */
int max_population(int spawns) {
   int x = 1 + (5 * spawns);
   return min( HARD_MAX_POP, x );
   /** This is the math to actually produce the above switch statement.
    *
   int m = 0, val = 50, min_val = 25;
   while( m <= HARD_MAX_POP && spawns > 0 ) {
      m += val;
      val = (val > min_val) ? val - 5 : val;
      spawns--;
   }
   return m;
   */
}

void spawn_tick() {
   object ob;
   int pop, spawns, max;
   string fname = spawn_src;

   if( !environment(this_object()) ) return;
   remove_call_out("spawn_tick");
//   call_out( "spawn_tick", SPAWN_DELAY + random(SPAWN_DELAY) );

   // pumpkin lord's revenge
   if( localtime()[4] == 9 && random(100) < 50 ) {   // 0-indexed, oct+
      fname = SKELLINGTON;
      max = MAX_SKELLINGTONS;
   } else {
      spawns = count_spawns();
      max = max_population(spawns);
   }
   pop = sizeof(all_clones(fname));
   // Don't spawn over the max.
   if( pop >= max ) return;

   // The following if statement does NOT WORK. Try it for
   // a population of zero -- nothing will EVER spawn.
//   if( (50+random(50)) > (100*pop/max) ) return;

   foreach( ob : all_inventory(environment(this_object())) )
      if( load_object(load_name(ob)) == load_object(fname) ) return;

   ob = clone_object( fname );
   if( !ob ) return;

   // mobs spawn fully healed
   ob->set_hp(ob->query_max_hp());
   ob->set_mana(ob->query_max_mana());
   ob->set_endurance(ob->query_max_endurance());
   ob->set_food(ob->query_max_food() * 3 / 4);
   ob->set_drink(ob->query_max_drink() * 3 / 4);

   // mobs also need some skills if their author forgot to give them
   if( !sizeof(ob->query_skills()) ) {
      ob->set_skill( "combat.dodging", 5 * range(ob->query_stat("spd")) );
      ob->set_skill( "combat.weapon.unarmed", 5 * range(ob->query_stat("str")) );
   }


   ob->move( environment(this_object()) );
   if( query_coord() == 0 )
      ob->set_coord( environment()->query_map_xdim()/2, environment()->query_map_ydim()/2, 0 );
   else
      ob->set_coord( query_coord() );
   ob->validate_position();
   "/daemon/counter"->add_count( "spawn_count_" + fname, 1 );
   debug( fname + " @ "+get_location(environment()), "spawn" );
}

void set_spawn_src( string s ) {
   spawn_src = s;
}

string query_spawn_src() {
   return spawn_src;
}

void reset() {
   spawn_tick();
}
