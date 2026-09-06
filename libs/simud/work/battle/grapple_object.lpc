#include <object.h>

/**
 * This object is placed on the victim of a grappling attack.
 *
 * It imposes dex and speed penalties and should hopefully prevent the bearer
 * or the grappler from walking.
 *
 * Specifically, the process of walking should check if one is either grappling
 * or being grappled before we even consider pathfinding.
 */

int limb;	// the limb with which the victim is being held
object victim;	// who is being thus held?
object holder;	// who is doing the holding? - for lack of a better name
		
string query_name() {
   return "grapple_ob";
}

object id(string str) {
   if( str == "grapple_ob" ) return this_object();
   else return 0;
}

int query_use_bonuses() {
   return 1;
}

int query_strength() {
   if (!holder)
      return 1;
   return holder->query_stat("str");
}

int query_dex_bonus() { return query_strength() * -1 / 2; }
int query_spd_bonus() { return query_strength() * -1 / 3; }

object query_victim() { return victim; }
void set_victim(object who) { victim = who; }

int query_limb() { return limb; }
string query_limb_name() { return holder->query_bp_name(limb); }
void set_limb(int x) { limb = x; }

object query_holder() { return holder; }
void set_holder(object who) { holder = who; }

void do_setup(int l, object h, object v) {
   mapping grappling;
   move(v);
   set_limb(l);
   set_holder(h);
   set_victim(v);

   grappling = h->query_env_var("grappling");
   if (!mappingp(grappling))
      grappling = ([]);
   grappling[l] = v;
   h->set_env_var("grappling",grappling);
}

void do_release() {
   if (holder && victim) {
      mapping grappling = holder->query_env_var("grappling");
      grappling -= ([ limb ]);
      set_actor(holder);
	  set_target(victim);
      if (!holder->query_dead()) {
         msg_object(holder,"~CBRTYou lose your grip on ~targ with your "+query_limb_name()+".~CDEF");
         msg_object(victim,"~CBRT~Name ~verblet go of ~targ.");
      }
      holder->set_env_var("grappling",grappling);
   }
   destruct(this_object());
}

void on_suspend() {
   do_release();
}

void on_move() {
   if (victim && environment() != victim)
      do_release();
}

void init() {
   ::init();
   if ( victim) {
      if ( environment(this_object()) != victim ) {
         do_release();
      } else {
         command( "struggle", victim );
      }
   }
}
