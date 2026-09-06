#include <sys/rtlimits.h>

inherit "/inherit/stopwatch";

int icreature;       // iterator
object *creatures;   // list of livings to decay
int csz;             // number of livings to decay
int rate;            // mobs to tick per heartbeat
int overflow;

void do_hunger_tick(int till_next_hour) {
   if( pointerp(creatures) ) {
      overflow++;

      if (overflow > 5) {
         // make sure we are actually processing hunger ticks
         set_heart_beat(1);
         debug("Hunger tick overload, skipping a cycle");
         return;
      }
   } else {
      creatures = ({ });
   }

   foreach( string lname : all_living_names() ) {
      if( !stringp(lname) ) continue;

      creatures += all_living(lname);
   }

   icreature = 0;
   csz = sizeof(creatures);
   debug("Starting hunger tick, with " + csz + " livings.", "hunger");

   set_heart_beat(1);
}

int query_batch_size() {
   return csz;
}

int query_batch_progress() {
   return icreature;
}

/* process a batch of creatures */
/* we use dynamic resource measurement to time ourselves for great adaption */

/* don't go over half max eval_cost, to avoid TLE induced NSDFs */
/* don't go over half a second of wall time, to avoid lag-based performance impairment */
void heart_beat()
{
   int quota;
   int starttime = utime()[0];

   stopwatch_start();

   for (; icreature < csz && get_eval_cost() > 5000000 && stopwatch_read() < 500000; ) {
      object creature = creatures[icreature++];
      quota++;

      if (!objectp(creature)) {
         continue;
      }

      catch(creature->decay_food_and_drink());
   }

   if (icreature >= csz) {
      debug("Finished hunger tick", "hunger");
      creatures = 0;
      overflow = 0;

      icreature = -1;
      csz = -1;
      set_heart_beat(0);
   } else {
      debug("Still more mobs to tick: " + (csz - icreature), "hunger");
   }
}

/*
 * Decrease the food and drink levels on all livings in the mud. Normal
 * players and mobs will lose 4 of each every game hour. Other factors can
 * affect the rate at which individual food and drink levels decay.
 */
void hunger_tick() {
   int till_next_hour = "/daemon/time"->query_time_until_hour();
   remove_call_out("hunger_tick");
   call_out("hunger_tick", till_next_hour );

   catch( do_hunger_tick(till_next_hour) );
}

void create() {
   debug("GPFault's new hunger daemon starting");
   call_out("hunger_tick", "/daemon/time"->query_time_until_hour() );
}
