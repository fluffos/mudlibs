
#include <std.h>
#include <id4.h>

#define HP 10000000

inherit MONSTER;

mapping hits = ([ ]);
int totaldam = 0;

void set_totaldam(int x) { totaldam = x; }

void create() {
  ::create();
  set_name("ice");
  set_id( ({ "iceblock", "ice" }) );
  set_property("no bump", 1);
  set_short("a giant block of ice");
  set_long("Deep inside the ice, the shape of a dragon can be seen.");
  set_gender("neuter");
  set_race("ice");
  add_limb("ice", "FATAL", HP, 0, 20);
  set_level(50);
  set_exp(0);
}

int is_invincible() { set_paralyzed(30, "You are ice.", "You can move."); return 0; }

/*
string return_limb() { return "ice"; }
string return_target_limb() { return "ice"; }
string *query_limbs() { return ({ "ice" }); }
*/

void heart_beat() {
  set_paralyzed(30, "You are ice.", "You can move.");
  ::heart_beat();
  if (!this_object()) return;
  heal_limb("ice", 6000);
  if (totaldam > HP && sizeof(filter(all_inventory(environment()), (: $1->is_player() :) ))) {
    object dragon;
    string name;
    string *k;
    k = keys(hits);
    k = sort_array(k, (:
      ($3[$1] > $3[$2] ? -1 : 1)
    :), hits);
    name = k[0];
    dragon = new(MOBS+"red_dragon");
    dragon->move(environment());
    dragon->set_people(k);
    dragon->start();
	environment()->set_property("finished_quest", 1);
    this_object()->remove();
  }
}

void count(int x) {
  object tp = this_player();
  string name;
  if (x < 1) return;
  if (!tp && userp(previous_object()))
    tp = previous_object();
  if (!tp) return;
  name = tp->query_name();
  totaldam += x;
  if (!hits[name])
    hits[name] = 0;
  hits[name] += x;
}

void add_hp(int x) { count(-x); }

void do_damage(string limb, int x) { count(x); }

void damage(int x) { count(x); }
