
#include <std.h>
#include <rest.h>

#define PEEL_PROP "bananapeel_trip_time"
#define PEEL_TIME 20

inherit OBJECT;

int set_owner(string);
void trip_up(object);

object owner;
int hit;

void create() {
  ::create();
  set_name("banana peel");
  set_id( ({ "peel", }) );
  set_short("%^YELLOW%^a banana peel%^RESET%^");
  set_long("A sad looking empty peel. It looks pretty slippery.");
  set_weight(1);
  owner = 0;
  hit = 0;
}

void init() {
  ::init();
  add_action("set_owner", "drop");
  set_heart_beat(1);
}

int set_owner(string str) {
  object tp = this_player();
  object to = this_object();

  if (str && present(str, tp) == to) {
    owner=tp;
    hit = owner->query_stats("charisma")*2 +
          owner->query_skill("entertainment")/2;
    if (hit > 200) hit = 200+((hit-200)/3);
    if (hit > 350) hit = 350;
  }

  return 0;
}

void heart_beat() {
  object to = this_object();
  object env = environment(to);
  object *livs;
  int canhit = hit;

  if (!env || !env->is_room()) return;
 
  livs = filter(all_inventory(env), (: $1->is_living() :) );

  if (!sizeof(livs)) {
    set_heart_beat(0);
    return;
  }

  livs = filter(livs, (: (objectp($1->query_current_attacker()) && !$1->query_rest_type()) :) );
  livs -= ({ owner });

  if (!hit || !owner) canhit = 120;
  canhit += random(60);

  foreach (object tgt in livs) {
    int miss = tgt->query_stats("dexterity") +
               tgt->query_skill("perception")/2;
    if (canhit > miss && random(100) < 50 && (int)tgt->query(PEEL_PROP)+PEEL_TIME < time()) {
      trip_up(tgt);
      break;
    }
  }

}

void trip_up(object tgt) {
  message("info", "You suddenly slip on "+query_short()+" and fall!", tgt);
  message("info", tgt->query_cap_name()+" slips on "+
      query_short()+" and falls down!",
      environment(tgt), tgt);
  tgt->set_rest_type(SIT);
  tgt->set_paralyzed(2+random(2), "You're still recovering from that fall.");
  tgt->set(PEEL_PROP, time());
  this_object()->remove();
}

