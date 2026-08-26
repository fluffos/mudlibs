// Friendly poison object, with credit given to Durak@Shadow's Edge
// for the basic idea & the skeleton.
// Balkalarre, Thursday, July 4th, 1996.
// Decided to add a few things.
// Balkalarre, Friday, July 5th, 1996.
#include <mudlib.h>

inherit OBJECT;

#define POISON_MESSAGE_CHANCE 70
#define DEBUG

object Player;
int Duration, Damage, Interval, Number, Effect;
void extra_look();

void create() {
    Number = Effect = 1;
    Duration = Interval = 10;
    Damage = 20;
    set("id", "POISON_OBJECT");
    set("prevent_drop", 1);
}

void init() {
  call_out("Poison", Interval);
  if (this_player() == environment())
  extra_look();
}

void Poison() {
    if (((Player = environment(this_object())) 
         && this_player() != Player) || !Player ||
      Player->query_ghost()) {
    while(remove_call_out("Poison") != -1);
    remove();
    return;
  }
  if (!Effect) {
    while (remove_call_out("poison") != -1);
    return;
  }
  if (!Player->query_linkdead()) {
    if (random(100) < POISON_MESSAGE_CHANCE) {
      tell_object(Player, "You feel the effects of a poison strike "
       "your body.\n");
     tell_room(environment(Player),
        sprintf("%s convulses with pain.\n", 
     Player->query_name()), Player);
  }
// I'd certainly like to set a player's death message here.

#ifdef DEBUG
tell_object(Player, "*** You've just been hit by poison.\n");
tell_object(Player, 
  sprintf("*** Dur: %d, Dam: %d, Int: %d, Num: %d.\n",
    Duration, Damage, Interval, Number)); 
#endif

  Player->receive_damage((Damage / 2) + random(Damage / 2) + 1);
  if (!Player || Player->query_ghost()) {
    if (this_object()) remove();
    return;
  }
  Duration -= 1;
  }
  if (Duration > 0) call_out("Poison", Interval);
  else {
    tell_object(Player, "You overcome the effects of a poison.\n");
    remove();
  }
}

int set_interval (int i) { if (intp(i)) return (Interval = i); }
int set_duration (int i) { if (intp(i)) return (Duration = i); }
int set_damage (int i) { if (intp(i)) return (Damage = i); }

int add_number (int n) {
  if (intp(n))  {
    Number += n;
    extra_look();
    return Number;
   }
}

int query_interval() { return Interval; }
int query_duration() { return Duration; }
int query_damage() { return Damage; }
int query_number() { return Number; }

mixed query_auto_load()  {
    return 
    sprintf("%s:%d %d %d %d %d", base_name(this_object()),
      Duration, Damage, Interval, Number, Effect);
}

void init_arg (mixed str) { 
    sscanf(str, "%d %d %d %d %d", Duration, Damage, 
      Interval, Number, Effect);
}

void destroy_effects() { Effect = 0; }

void extra_look() {
    set("extra_look", 
      sprintf( "%s has been poisoned%s",
       environment()->query_name(),
      (Number > 1) ? sprintf(" %s times.\n", (string) Number) : ".\n"
      ));
}

mapping configure_poison (mapping map) {
    if (intp(map["Duration"])) Duration = map["Duration"];
    if (intp(map["Damage"])) Damage = map["Damage"];
    if (intp(map["Interval"])) Interval = map["Interval"];
    if (intp(map["Number"])) Number = map["Number"];
    if (intp(map["Add_Number"])) {
      Number += map["Add_Number"];
      extra_look();
    }
}
