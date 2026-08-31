#include <std.h>

// BAG instead of CONTAINER for the put and get commands
inherit BAG;

#define HEARTBEAT 3

#ifdef HEARTBEAT
#define DECAY_TIME 30/HEARTBEAT
#else
#define DECAY_TIME 30
#endif

#define PLAYER_DECAY_TIME DECAY_TIME*2

mapping corpse_info = ([
  "preserved" : 0,
  "decay" : 0,
  "decay_time" : 0,
  "max_decay_time" : DECAY_TIME,
]);

mapping necromancy_info = ([
  "player" : 0,
  "name" : "nobody"
]);


void set_preserved(int x);
void preserve_me();
int query_preserved();
void set_decay(int x);
int query_decay();
void set_player_corpse(int x);
void is_player_corpse(int x);
int query_player_corpse();
void set_name(string n);
string query_name();
void copy_body(object ob);
void decay();
void loot(object tp);
int remove();
int query_corpse();

void create() {
  ::create();
  set_name("nobody");
  set_weight(1);
  set_max_internal_encumbrance(0);
  set_prevent_get("The ashes slip through your fingers.");
  // larger the number, the less often the heart_beat actually goes off
  set_heart_beat(HEARTBEAT);
}

void heart_beat() {
  if (++corpse_info["decay_time"] >= corpse_info["max_decay_time"]) {
    decay();
    corpse_info["decay_time"] = 0;
  }
}

// needed so bags can go in corpses
varargs int receive_objects(object ob) { return 1; }



// backwards compat:
void preserve_me() { set_preserved(1); }
void set_preserved(int x) { corpse_info["preserved"] = x; }
int query_preserved() { return corpse_info["preserved"]; }

int query_decay() { return corpse_info["decay"]; }
void set_decay(int x) { corpse_info["decay"] = x; }               


// backwards compat:
void is_player_corpse(int x) { set_player_corpse(x); }
void set_player_corpse(int x) {
  necromancy_info["player"] = x;
  if (x) corpse_info["max_decay_time"] = PLAYER_DECAY_TIME;
}
int query_player_corpse() { return necromancy_info["player"]; }

string query_name() { return necromancy_info["name"]; }
void set_name(string n) { 
  necromancy_info["name"] = n;
  set_id( ({ "ash", "remains", "ashes", "pile", "pile of ashes", "pile of ash" }) );
  set_short("a pile of ashes");
  set_long("Some black ashes.");
  ::set_name("pile of ashes");
}


// this is called when someone dies
void copy_body(object ob) {
  if (!living(ob)) return;
  set_name(ob->query_name());
  set_player_corpse((userp(ob)?1:0));
}

void decay() {
  if (query_preserved()) return;
  
  set_decay(query_decay()+1);

  if (query_decay() == 1)
    set_short("scattered ashes");

  if (query_decay() >= 2) {
    // this is to help reduce the number of objects lying around
    if (!query_player_corpse())
      all_inventory(this_object())->remove();
    remove();
  }
}

void loot(object tp) {
  if (!tp || !living(tp)) return;

  foreach (object ob in all_inventory(this_object())) {
    if (ob->is_money_pile()) {
      foreach (string curr in ob->query_currencies()) {
        int amt=ob->query_money(curr);
        if (amt < 1) continue;
        message("info",
          "You find "+amt+" "+curr+" coin"+(amt>1?"s":"")+" in the ashes.", tp);
        tp->add_money(curr, ob->query_money(curr));
      }
      ob->remove();
      if (ob) destruct(ob);
    }
    else {
      // this happens here so you can't pick up an ob with the same name and start
      // looting into it by accident
      string bagname=tp->query_property("autobag");
      object bag;
      if (bagname) bag=present(bagname, tp);

      if (ob->move(tp))
        message("info", "You are too overburdened to take "+ob->query_short()+".", tp);
      else {
        message("info", "You take "+ob->query_short()+" from the ashes.", tp);
        if (bagname) {
          if (!bag)
            message("info", "You do not have a "+bagname+".", tp);
          else if (ob->move(bag))
            message("info", "The "+bag->query_short()+" is full.", tp);
          else
            message("info", "You put "+ob->query_short()+" in "+bag->query_short()+".", tp);
        }
      }
    }
  }
}

int remove() {
  all_inventory(this_object())->move(environment(this_object()));
  return ::remove();
}

int query_corpse() { return 2; }


