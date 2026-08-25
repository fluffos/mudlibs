//  /std/obj/undead.c
//  Decaying corpses brought back to life
//  Created by Manny@Nightmare 940921

#include <std.h>

inherit MONSTER;

void remove_me();
void set_master(object who);
string query_master();

int decay_rate;
object master;

create() {
  monster::create();
  decay_rate = 100;
}

void set_zombie_name(string name, int time_left) {
  set_name(name);
  set_short("the undead remains of "+name);
  set_long("The animated remains of "+name);
  set_id( ({ "undead", "undead remains", "remains", "remains of "+name,
      name, "corpse" }));
  call_out("decay", decay_rate, time_left);
}

void decay(int time_left) {
  if(--time_left <= 0)  remove_me(); 
  else call_out("decay", decay_rate, time_left);
}

void remove_me() {
  message("say", "The zombie's body decays into a pile of dust.", 
      environment(this_object()));
  this_object()->remove();
}

void set_decay_rate(int num) { decay_rate = num; }

void set_master(object who) { master = who; }

mixed query_master() { return master; }
