#include <std.h>

inherit MONSTER;

int my_hp;
object owner;
int flag;

void wink_out();

void create() {
  ::create();
  set_body_type("human");
  flag = 0;
}

void set_up(object who, int dur, int pow) {
  set_name((string)who->query_name());
  set_short((string)who->query_short());
  set_long("This is a mirror image of "+(string)who->query_name()+".");
  set_id((string *)who->query_id());
  set("race", (string)who->query_race());
  set_level((int)who->query_level());
  owner = who;
  my_hp = 2+random(pow+1);
  call_out("wink_out", dur);
  return;
}

varargs void heart_beat(int flag) {
  object att;

  if(!owner) {
    wink_out();
    return;
  }
  if(my_hp < 0) {
    wink_out();
    return;
  }
  att = (object)owner->query_current_attacker();
  if(att && !flag) {
    if(random(100) >= ((int)att->query_stats("intelligence") / 2))
      att->kill_ob(this_object(), 1);
  }
  if(flag)
    ::heart_beat(flag);
  return;
}

int do_damage(string limb, int dam) {
  if(dam <= 0) return dam;
  my_hp--;
  return dam;
}

void set_fumble() { flag = 1; }

void add_hp(int hp) {
  if(hp >= 0) return;
  my_hp--;
  return;
}

void heal(int x) {
  if(x >= 0) return;
  my_hp--;
  return;
}

void wink_out() {
  message("info", "%^GREEN%^%^BOLD%^A mirror image of "+capitalize(query_name())+
      " winks out of existence.", environment());
  remove();
  return;
}



void add_exp(int x) {
  if(owner) owner->add_exp(x);
  return;
}
