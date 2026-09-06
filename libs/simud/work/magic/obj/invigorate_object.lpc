#include <battle.h>
#include <object.h> // ALL CLONABLE OBJECTS MUST INCLUDE THIS.

int speed;	// amount of readiness to add each heartbeat
int duration;	// remaining duration of the spell, in heartbeats
object victim;	// who is this affecting?

string query_name() {
  return "invigorate_object";
}

// Must have an id() function, or having a name is pointless...
object id(string param) {
   if( param == query_name() ) return this_object(); return 0;
}

void end() {
  if (victim)
    msg_object(victim,"~CBRTYou feel the adrenaline leave your body.~CDEF");
  destruct(this_object());
}

void heart_beat() {
  if (victim) {
    duration--;
    if (!duration || victim->query_dead())
      end();
	if (victim->query_endurance() < victim->query_max_endurance())
      victim->add_endurance(speed);
  }
  else
    destruct( this_object() ); // can't have this object in the wild
}

object query_victim() { return victim; }

void set_victim(object target) {
//  move_object(this_object(),target); // This is NEVER legal.
   move( target ); // This is the only correct way to move objects.
   victim = target;
   msg_object(victim,"~CBRTYou feel adrenaline begin to course through your veins.~CDEF");
   set_heart_beat(1);
}

void on_death(object victim) {
   destruct( this_object() );
}

int query_duration() { return duration; }
void set_duration(int x) { duration = (x>0?x:0); }
void add_duration(int x) { set_duration(duration + x); }

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

void create() {
   ::create();
   set_duration(20);
   set_speed(1);
   set_heart_beat(1); // Of course, or an uninitialized one will never disappear.
}
