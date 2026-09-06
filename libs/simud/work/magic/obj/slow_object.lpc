#include <object.h>
#include <battle.h>

void set_duration( int x );
void set_speed( int x );

int speed;	// amount of readiness to remove each heartbeat
int duration;	// remaining duration of the spell, in heartbeats
object victim;	// who is this affecting?

string query_name() {
  return "slow_object";
}

void create() {
  ::create();
  set_duration(20);
  set_speed(25);
}

void end() {
  if (victim)
    msg_object(victim,"~CBRTYou feel yourself speed back up to normal.~CDEF");
  destruct(this_object());
}

void heart_beat() {
  if (victim) {
    duration--;
    if (!duration || victim->query_dead())
      end();
    if (victim->query_readiness() < victim->readiness_required() &&
        victim->query_readiness() > speed)
      victim->add_readiness(-speed);
  }
  else
    destruct( this_object() ); // can't have this object in the wild
}

object query_victim() { return victim; }
void set_victim(object target) {
  move_object(this_object(),target);
  victim = target;
  msg_object(victim,"~CBRTYou feel yourself begin to slow down.~CDEF");
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
  if (x > 0 && x <= 250)
    speed = x;
  else if (x > 0)
    speed = 250;
  else
    speed = 25;
}
void add_speed(int x) { set_speed(speed+x); }

int query_is_slow() { return 1; }
