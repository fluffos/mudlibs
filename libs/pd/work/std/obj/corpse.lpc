#include <std.h>

// BAG instead of CONTAINER for the put and get commands
inherit BAG;

#define HEARTBEAT 3

#ifdef HEARTBEAT
#define DECAY_TIME 72/HEARTBEAT
#else
#define DECAY_TIME 90
#endif

#define PLAYER_DECAY_TIME DECAY_TIME*3

mapping corpse_info = ([
  "body" : ([]),
  "fingers" : 5,
  "gender" : "neuter",
  "race" : "human",
  "body_type" : "human",
  "preserved" : 0,
  "decay" : 0,
  "decay_time" : 0,
  "max_decay_time" : DECAY_TIME,
]);

mapping necromancy_info = ([
  "max_hp" : 100,
  "max_mp" : 200,
  "level" : 1,
  "class" : "child",
  "subclass" : "none",
  "stats" : ([]),
  "skills" : ([]),
  "player" : 0,
  "name" : "nobody"
]);


void set_body(mapping b);
mapping query_body();
void set_fingers(int num);
int query_fingers();
void set_gender(string g);
string query_gender();
void set_race(string r);
string query_race();
string query_old_race();
void set_body_type(string bt);
string query_body_type();
void set_preserved(int x);
void preserve_me();
int query_preserved();
void set_decay(int x);
int query_decay();
void set_hp(int hp);
int query_hp();
void set_old_hp(int num);
int query_old_hp();
void set_mp(int mp);
int query_mp();
void set_level(int lev);
int query_level();
void set_class(string c);
string query_class();
void set_subclass(string c);
string query_subclass();
void set_stats(mapping st);
void copy_stats(object ob);
mapping query_stats();
void set_skills(mapping sk);
mapping query_skills();
void set_player_corpse(int x);
void is_player_corpse(int x);
int query_player_corpse();
void set_name(string n);
string query_name();
void copy_body(object ob);
object make_undead();
void decay();
void loot(object tp);
int remove();
int query_corpse();

void create() {
  ::create();
  set_name("nobody");
  set_weight(100);
  set_max_internal_encumbrance(0);
  set_prevent_get("You would not touch the bloodied remains!");
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


void set_body(mapping b) { corpse_info["body"] = b; }
mapping query_body() { return corpse_info["body"]; }

void set_fingers(int num) { corpse_info["fingers"] = num; }
int query_fingers() { return corpse_info["fingers"]; }

string query_gender() { return corpse_info["gender"]; }
void set_gender(string g) { corpse_info["gender"] = g; }

// backwards compat:
string query_old_race() { return query_race(); }
string query_race() { return corpse_info["race"]; }
void set_race(string r) { corpse_info["race"] = r; }

void set_body_type(string bt) { corpse_info["body_type"] = bt; }
string query_body_type() { return corpse_info["body_type"]; }

// backwards compat:
void preserve_me() { set_preserved(1); }
void set_preserved(int x) { corpse_info["preserved"] = x; }
int query_preserved() { return corpse_info["preserved"]; }

int query_decay() { return corpse_info["decay"]; }
void set_decay(int x) { corpse_info["decay"] = x; }               


// backwards compat:
int query_old_hp() { return query_hp(); }
// backwards compat:
void set_old_hp(int num) { set_hp(num); }
int query_hp() { return necromancy_info["hp"]; }
void set_hp(int hp) { necromancy_info["hp"] = hp; }

int query_mp() { return necromancy_info["mp"]; }
void set_mp(int mp) { necromancy_info["mp"] = mp; }

int query_level() { return necromancy_info["level"]; }
void set_level(int lev) { necromancy_info["level"] = lev; }

string query_class() { return necromancy_info["class"]; }
void set_class(string c) { necromancy_info["class"] = c; }

string query_subclass() { return necromancy_info["subclass"]; }
void set_subclass(string c) { necromancy_info["subclass"] = c; }

void set_stats(mapping st) { necromancy_info["stats"] = st; }
mapping query_stats() { return necromancy_info["stats"]; }
void copy_stats(object ob) {
  mapping all=([]);
  foreach (string stat in ob->query_all_stats())
    all[stat] = ob->query_stats(stat);
  set_stats(all);
}

void set_skills(mapping sk) { necromancy_info["skills"] = sk; }
mapping query_skills() { return necromancy_info["skills"]; }

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
  set_id( ({ "corpse", "remains", "corpse of "+n }) );
  set_short("the corpse of "+capitalize(n));
  set_long("This is the dead body of "+capitalize(query_name())+".");
  ::set_name("corpse of "+n);
}


// this is called when someone dies
void copy_body(object ob) {
  if (!living(ob)) return;
  set_body(ob->query_body_mapping());
  set_fingers(ob->query_fingers());
  set_hp(ob->query_max_hp());
  set_mp(ob->query_mp());
  set_level(ob->query_level());
  set_class(ob->query_class());
  set_subclass(ob->query_subclass());
  set_skills(ob->query_skills());
  //set_stats(ob->query_base_stats());
  copy_stats(ob);
  set_gender(ob->query_gender());
  set_race(ob->query_race());
  set_body_type(ob->query_body_type());
  set_name(ob->query_name());
  set_player_corpse((userp(ob)?1:0));
}

object make_undead() {
  object mon=new(MONSTER);
  //object mon=new(UNDEAD);
  if (mon) {
    mon->set_race(query_race());
    mon->set_gender(query_gender());
    mon->set_body_type(query_body_type());
    //mon->set_body(query_body());
    //mon->set_fingers(query_fingers());
    mon->set_name(::query_name());
    mon->set_level(query_level());
    mon->set_class(query_class());
    mon->set_subclass(query_subclass());
    mon->set_skills(query_skills());
    mon->set_base_stats(query_stats());
    mon->set_property("decay", query_decay());
    mon->set_property("undead", 1);
    if (query_decay()) {
      foreach (string st in mon->query_all_stats())
        mon->add_stat_bonus(st, -(mon->query_base_stats()[st]/4));
      foreach (string sk in keys(mon->query_skills()))
        mon->add_skill_bonus(sk, -(mon->query_base_skill(sk)/4));
      foreach (string limb in mon->query_limbs())
        mon->heal_limb(limb, -(mon->query_max_dam(limb)/3));
    }
    all_inventory(this_object())->move(mon);
    remove();
  }
  return mon;
}

void decay() {
  if (query_preserved()) return;
  
  set_decay(query_decay()+1);

  if (query_decay() == 1)
    set_short("the somewhat decayed corpse of "+capitalize(query_name()));
  
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
          "You find "+amt+" "+curr+" coin"+(amt>1?"s":"")+" on the body.", tp);
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
        message("info", "You take "+ob->query_short()+" from the corpse.", tp);
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

int query_corpse() { return 1; }


