#include <object.h>

/** This object is created and put into a hungry creature's inventory
 * whenever they start getting hungry. It creates stats negatives for
 * them the hungrier they become. When the living is no longer hungry,
 * it may destruct this object.
 *
 * Note that this object uses functions identical to Bonus; however,
 * it does not need the editability of the Bonus object, so it isn't
 * inheriting it.
 *
 * The name of this object on the mud is "hunger_ob". You can use this
 * name in "present()" to check for it.
 */

void on_move() {
   if (!environment()->query_is_living())
      destruct(this_object());
}

void on_death(object who) {
	if( who == environment() )
		destruct(this_object());
}

/// \return This object's name, "hunger_ob"
string query_name() {
   return "hunger_ob";
}

/// \return this_object() if \a str is "hunger_ob", false (0) otherwise.
object id(string str) {
   if( str == "hunger_ob" ) return this_object();
   else return 0;
}

/// \return True, indicating that this object has stat bonus information.
int query_use_bonuses() {
   return 1;
}

/// \return The number of points of strength to add (a negative number, since this is a "curse").
int query_str_bonus() {
   int food, drink, bonus;

   food = environment(this_object())->query_food();
   drink = environment(this_object())->query_drink();

   bonus = 0;
   if( food < 0 ) bonus += food / 5;
   if( drink < 0 ) bonus += drink / 5;

   return bonus;
}

/// \return The number of points of dexterity to add (a negative number, since this is a "curse").
int query_dex_bonus() {
   int food, drink, bonus;

   food = environment(this_object())->query_food();
   drink = environment(this_object())->query_drink();

   bonus = 0;
   if( food < 0 ) bonus += food / 10;
   if( drink < 0 ) bonus += drink / 10;

   return bonus;
}

/// \return The number of points of constitution to add (a negative number, since this is a "curse").
int query_con_bonus() {
   int food, drink, bonus;

   food = environment(this_object())->query_food();
   drink = environment(this_object())->query_drink();

   bonus = 0;
   if( food < 0 ) bonus += food / 15;
   if( drink < 0 ) bonus += drink / 15;

   return bonus;
}

/// When the player quits, just get rid of this object.
void on_suspend() {
   destruct(this_object());
}

/// Check if the player has died of hunger yet.
void on_hunger() {
   object victim = environment(this_object());
   if( !victim ) return;
   if( victim->query_real_constitution() + victim->query_constitution_bonus() < 1 ) {
      "/daemon/counter"->add_count(victim->query_name() + "_starve", 1);
	  victim->set_env_var("cause_of_death",(victim->query_food() < victim->query_drink()?"has starved to death.":"has died of thirst."));
      victim->die();
   }
   destruct(this_object());
}
