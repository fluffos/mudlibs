#include <battle.h>

int strength;	// total amount of readiness to cost the victim
int speed;	// how many readiness to lose a hb
object victim;	// target object

create() {
  set_strength(100);
  set_speed(10);
  set_heart_beat(1);
}

heart_beat() {
  int damage;
  if (victim) {
    if (strength <= 0 || victim->query_dead())
      destruct(this_object());

    victim->add_readiness(-speed);
    strength -= speed;
  }
  if (strength)
    set_heart_beat(1);
}

object query_victim() { return victim; }
set_victim(object target) {
  move_object(this_object(),target);
  victim = target;
}

int query_strength() { return strength; }
void set_strength(int x) { strength = x; }
void add_strength(int x) { set_strength(strength+x); }

int query_speed() { return speed; }
void set_speed(int x) { speed = x; }
void add_speed(int x) { set_speed(speed+x); }
