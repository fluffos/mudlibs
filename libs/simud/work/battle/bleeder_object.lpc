#include <battle.h>
#include <object.h>
#include <saveload.h>

int strength;   // how much toxin/acid/etc... remains. specifically, how
      //   many total points of damage remain.
int speed;   // how fast the toxin/acid/etc... works. specifically, the
      //   hp damage of each hit.
string hit_msg;   // message the player gets every time they take damage
      //   from the bleeder
string end_msg;   // message they get when the bleeder dissipates
string type;   // type of damage bleeder inflicts
object victim;   // poor sap who gets to endure this agony
int count;   // used to count heart beats

int query_is_bleeder() { return 1; }

object id( string s ) { if( s == "Bleeder_object" ) return this_object(); return 0; }

string query_name() { return "Bleeder_object"; }

int on_get( object ob ) { return MOVE_OK_FLAG; }

void set_hit_msg( string x );
void set_end_msg( string x );
void set_dam_type( string x );
void set_strength( int x );
void set_speed( int x );

void create() {
  ::create();
  set_hit_msg("You twitch in agony as the poison courses through your veins.");
  set_end_msg("You feel wonderful relief as the poison dissipates.");
  set_dam_type("poison");
  set_strength(20);
  set_speed(2);
}

void end() {
  if (victim)
    msg_object(victim,"~CBRT"+end_msg+"~CDEF");
  set_heart_beat(1);
  destruct(this_object());
}

void heart_beat() {
  int damage;

  count++;
  if (count % 3 != 1)
    return;

  if (victim) {
    if (strength <= 0 || victim->query_dead()) {
      end();
      return;
    }

    strength -= speed;
    // last little tick shouldn't do more damage than strength remaining
    if (strength < 0)
      speed -= -strength;

    msg_object(victim,"~CWRN"+hit_msg+"~CDEF");
    // Calculate how much it hurts.
    damage = speed;
    switch (type) {
       // bleeding is bleeding, it dehydrates you quite badly
       case "wound":
       case "edged":
       case "piercing":
          victim->set_env_var("cause_of_death"," has bled to death.");
          victim->add_drink( -speed * 2 );
          break;

       // armour that protects against poison, disease, alignment,
       // temperature, and electrical damage also protects against
       // bleeders
       case "poison":
          victim->set_env_var("cause_of_death"," has died of poisoning.");
          damage -= victim->query_ac(type) - victim->query_base_ac();
          break;

       case "disease":
          victim->set_env_var("cause_of_death"," succumbed to disease.");
          damage -= victim->query_ac(type) - victim->query_base_ac();
          break;

       case "fire":
       case "holy":
       case "unholy":
          victim->set_env_var("cause_of_death"," has burnt to death.");
          damage -= victim->query_ac(type) - victim->query_base_ac();
          break;

       case "electrical":
          victim->set_env_var("cause_of_death"," has been electrocuted.");
          damage -= victim->query_ac(type) - victim->query_base_ac();
          break;

       case "ice":
          victim->set_env_var("cause_of_death"," has frozen to death.");
          damage -= victim->query_ac(type) - victim->query_base_ac();
          break;

       // natural resistance to acid helps, but armour doesn't
       case "acid":
          victim->set_env_var("cause_of_death"," was melted by acid.");
          damage -= victim->query_ac_mod(type);
          break;
    }

    if( !this_object() ) return; // Killing victim kills bleeders, ne?
    if (victim->query_hp() - damage < 1) {
      // just kill them off and be done with it
      victim->die();
    } else {
      // minimum of one point of damage, no healing
      victim->add_hp( (damage > 1 ? -damage : -1) );
    }
  }
  else
    destruct( this_object() ); // can't have bleeder object in the wild
}

object query_victim() { return victim; }
void set_victim(object target) {
  this_object()->move(target);
  victim = target;
  set_heart_beat(1);
  count = 0;
}

string query_type() { return type; }

void on_death(object target) {
   if( victim == target )
      end();
}

int query_strength() { return strength; }
void set_strength(int x) {
  if (victim) {
    // no sense in making a bleeder that big, eh?
    if (x < victim->query_max_hp())
      strength = x;
    else
      strength = victim->query_max_hp();
  } else
    strength = x;
}
void add_strength(int x) { set_strength(strength+x); }

int query_speed() { return speed; }
void set_speed(int x) {
  if (x > 0 && x <= 10)
    speed = x;
  else if (x > 0)
    speed = 10;
  else
    speed = 1;
}
void add_speed(int x) { set_speed(speed+x); }

void set_dam_type(string x) { type = lower_case(x); }

void set_hit_msg(string x) { hit_msg = x; }
void set_end_msg(string x) { end_msg = x; }
