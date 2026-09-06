#include <object.h>

/**
 * This object is not currently functional. It was begun as an attempt to
 * create a unified object for both grappling and entangle effects. This was
 * not a good idea and as such, I will be developing the grapping object
 * separately and then readdressing this object when the time comes.
 * - al [10/10/04]
 */

int strength;
string bond_desc;
		
void on_move() {
   if (!environment()->query_is_living())
      destruct(this_object());
}

/// \return This object's name, "hunger_ob"
string query_name() {
   return "entangle_ob";
}

/// \return this_object() if \a str is "hunger_ob", false (0) otherwise.
object id(string str) {
   if( str == "entangle_ob" ) return this_object();
   else return 0;
}

/// \return True, indicating that this object has stat bonus information.
int query_use_bonuses() {
   return 1;
}

/// \return The number of points of dexterity to add (a negative number, since this is a "curse").
int query_dex_bonus() {
   return strength * -1 / 2;
}

int query_spd_bonus() {
   return strength * -1 / 3;
}

/// When the player quits, just get rid of this object.
void on_suspend() {
   destruct(this_object());
}

int query_strength() { return strength; }
void set_strength(int x) { strength = x; }
void add_strength(int x) { strength += x; }

string query_bond_desc() { return bond_desc; }
void set_bond_desc(string str) { bond_desc = str; }

object query_victim() { return victim; }
void set_victim(object who) {
   move(victim);
   victim = who;
}

void init() {
   ::init();
   if ( victim ) {
      if ( environment(this_object()) != victim )
         destruct(this_object());
      else {
         add_action("do_struggle","struggle");
         command( "struggle", environment(this_object()) );
      }
   }
}

string query_action_name() { return "Struggle" };

int do_struggle() {
   this_player()->push_action( ({ 500, this_object(), this_player(), ST_STANDING, 0 }) );
}

void on_action(object target, mixed param) {
   this_player()->add_endurance(query_dex_bonus());
   this_player()->add_readiness(-500 - strength * 2);
   if ( this_player()->stat_check("str",strength) ) {
      this_player()->msg_local("~CACT~Name ~verbbreak free from "+bond_desc+"!~CDEF");
      destruct(this_object());
   } else {
      this_player()->msg_local("~CACT~Name ~verbstruggle against "+bond_desc+"!~CDEF");
      command("struggle",this_player());
   }
}
