//      /std/monster.c
//      from the Nightmare mudlib
//      inheritable code for npc's
//      created by Descartes of Borg september 1992
//      added set_unique() - seeker
#include <std.h>
#include <move.h>
#include <objects.h>
#include <daemons.h>
#include <rest.h>

inherit LIVING;

static int heart_beat_on;
int level, patrol, pon, pcnt, unique;
string *pdirs;
int Undead;
static int speed;
static int moving;
mapping says, emotes, speech;
string body_type;
private static mixed __Die;
int swarm;
string *Spells;
int SpellChance;

void set_level(int x);
int query_level();
void adjust_vitals(mapping);
void adjust_stats(mapping);
void adjust_skills();
void set_undead(int x);
int query_undead();
void set_swarm(int x);
int query_swarm();
void do_swarm();
varargs void die(mixed killer);
void set_unique(int x);
int test_heart();
void set_spell_chance(int x);
void set_spells(string *arr);
void set_race(string str);
void set_patrol(int x, string *dirs);
void do_patrol();
void move_around();
string return_chat();
string return_achat();
void set_emotes(int x, string *arr, int att);
mixed query_aggressive();
void set_aggressive(mixed arg);
void check_aggressive(object);

void create() {
  living::create();
  emotes = ([]);
  says = ([]);
  speech = ([]);
  enable_commands();
  seteuid(getuid(this_object()));
  init_limb_data();
  init_stats();
  init_skills(0);

  init_living();
  set_heart_beat(heart_beat_on = 1);
  speed = 0;
  set_gender("neuter");
  Undead = 0;
  Spells = ({});
  SpellChance = 0;
}
void heart_beat() {
  object to = this_object();
  string pre;
  string msg;
  string lang;
  string *langs;

  living::heart_beat();
  if (!to) return;

  if (!test_heart()) {
    set_heart_beat(heart_beat_on = 0);
    return;
  }

  if (swarm)
     do_swarm();
  if (!to) return;

  if (to->query_current_attacker()) {
    switch (to->query_rest_type()) {
      case SLEEP:
        to->force_me("wake");
      break;
      case SIT: case REST: case LAY:
        to->force_me("stand");
      break;
      default:
    }
    pre = "attack ";
  }
  else {
    pre = "";
    if (pdirs)
      do_patrol();
    if (!to) return;
  
    if (speed && moving >= speed)
      move_around();
    else
      moving++;
    if (!to) return;
  }

  if (to->query_rest_type() != SLEEP) {
    if (emotes[pre+"chance"] > random(100)) {
      msg = emotes[pre+"msg"][random(sizeof(emotes[pre+"msg"]))];
      message("emote", msg, environment(to), ({ to }) );
    }
    else if (says[pre+"chance"] > random(100)) {
      msg = says[pre+"msg"][random(sizeof(says[pre+"msg"]))];
      command("say "+msg);
    }
  
    if (sizeof(langs = keys(speech))) {
      lang = langs[random(sizeof(langs))];
      if (speech[lang][pre+"chance"] > random(100)) {
        msg = speech[lang][pre+"msg"][random(sizeof(speech[lang][pre+"msg"]))];
        command("speak in "+lang+" "+msg);
      }
    }
  }

}
void init() {
  ::init();

  if (!heart_beat_on)
    set_heart_beat(heart_beat_on = 1);

  check_aggressive(this_player());
}

void add_exp(int x) { return; /* do nothing */ }

int query_undead() { return Undead; }
void set_undead(int x) { Undead = x; }

void set_level(int x) {
  string race = this_object()->query_body_type() || this_object()->query_race();
  string cl = this_object()->query_class();
  string subcl = this_object()->query_subclass();
  mapping stat_percs = ([
    "strength" : 0,
    "dexterity" : 0,
    "constitution" : 0,
    "charisma" : 0,
    "intelligence" : 0,
    "wisdom" : 0,
  ]);

  if (!x || x < 1) x = 1;
  level = x;

  set_exp(ADVANCE_D->query_exp_for_level(level));

  foreach (string stat, int perc in stat_percs) {
    // ADVANCE_D returns "70" to mean a 30% discount
    stat_percs[stat] = 100 + (100 - ADVANCE_D->query_stat_mod(cl, subcl, race, stat))/2;
  }

  // use copy(stat_percs) if passing the mapping outside of this file
  adjust_stats(stat_percs);
  adjust_skills();
  adjust_vitals(stat_percs);
  augment_body(level);

  set_overall_ac(level + 9);
  if (RACE_D->query_undead(race)) set_undead(1);
  foreach (string prop, mixed value in RACE_D->query_properties(race))
    this_object()->set_property(prop, value);
}

int query_level() { return level; }

void adjust_vitals(mapping stat_percs) {
  if (level < 20)
    set_max_hp( 70 + level*30);
  else {
    set_max_hp( level*(level-3)*2 );
  }

  set_max_hp(query_max_hp() * stat_percs["constitution"] / 100);

  set_max_mp(query_max_hp() * (stat_percs["intelligence"]+stat_percs["wisdom"])/200);

  set_max_sp(level*20 * stat_percs["dexterity"] / 100);

  set_hp(query_max_hp());
  set_mp(query_max_mp());
  set_sp(query_max_sp());
}

void adjust_stats(mapping stat_percs) {
  int base;

  if (level < 20)
    base = 15 + level/3;
  else
    base = level * 110 / 100;

  foreach (string stat, int perc in stat_percs) {
    set_stats(stat, base*perc/100 + random(5) - random(5) );
  }
}

void adjust_skills() {
  // normal skill init should be fine here
  this_object()->init_skills(0);
}

// aggressive means attack players when they enter the room
// can be an int, in which case if player's cha is less they will be attacked
// can be a string, which is the name of a function to call in this_object()
mixed query_aggressive() { return query("aggressive"); }
void set_aggressive(mixed arg) {
  if (!( intp(arg) || stringp(arg) )) return;
  set("aggressive", arg);
}
void check_aggressive(object tp) {
  mixed tmp;

  if (!tp) return;
  if (!tp->is_player()) return;

  if (tp->query_invis()) {
    if (wizardp(tp) || random(101) < tp->query_level())
      return;
  }

  if (tp->query_ghost())
    return;

  if (tmp = query_aggressive()) {
    if (intp(tmp) && tmp > tp->query_stats("charisma"))
      kill_ob(tp, 0);
    else if(stringp(tmp))
      call_other(this_object(), tmp);
  }
}

// swarm means attack any player who is in combat
void set_swarm(int x) { swarm = x; }
int query_swarm() { return swarm; }
void do_swarm() {
  object to = this_object();
  object *killme;

  if (!environment(to)) return;
  if (to->query_rest_type() == SLEEP) return;

  killme = filter(all_inventory(environment(to)),
    (: ($1->is_player() && $1->query_current_attacker() &&
       member_array($1, $(to)->query_attackers()) == -1) :) );

  foreach (object pl in killme) {
    to->force_me("kill "+pl->query_name());
    to->kill_ob(pl);
    // kill command might not work if disabled, etc
  }

}


// This was added to prevent reduction of mob's naturally inflated hp
void fix_vital_bonus() { return; }

void set_unique(int x) { unique = x; }

int query_heart() { return query_heart_beat(); }
void restart_heart() { set_heart_beat(1); }

void set_name(string str) {
   set_living_name(str);
   ::set_name(str);
   if(query_level() < 1) set_level(1);
}
varargs void die(mixed killer) {

  if (intp(killer)) killer = this_object()->query_current_attacker();

  if (!objectp(killer)) killer = 0;

  if (functionp(__Die)) {
    if (!((int)((*__Die)(killer)))) return;
  }

  if (!this_object()) return;

  set_heart_beat(0);

  // exp is given in living::die(), but is calculated in ADVANCE_D
  living::die(killer);

  if (stringp(__Die))
    message("other_action", __Die, environment(this_object()),
      ({ this_object() }) );
  else
    message("other_action", capitalize(query_name())+
      " drops %^RED%^dead%^RESET%^ before you.",
      environment(this_object()), ({ this_object() }));

  this_object()->remove();
}

int query_npc() { return 1; }
void set_id(string *str)
{
 if (query_property("no monster") != 1)
       str += ({ "monster" });
 ::set_id(str);
}
varargs void move_player(mixed dest, string message) {
   object prev;
   string here,going,temp1,temp2,temp3;
   prev = environment(this_object());
   here = file_name(prev);
   if (stringp(dest)) {
     if (sscanf(dest,"/%s",temp1)!=1) {
       sscanf(here,"/%s",temp1);
       going = "";
       while(sscanf(temp1,"%s/%s",temp2,temp3)==2) {
         going = going + "/"+temp2;
         temp1 = temp3;
       }
       temp1 = dest;
       if (file_size(going+"/"+temp1+".c") != -1) {
         dest = going+"/"+temp1;
       }
     }
   }
   if(move(dest) == MOVE_OK) {
      message("min", query_cap_name() + " arrives.", environment(), this_object());
      message("mout", query_cap_name() + " leaves " + message + ".", prev);
      }
}
/* Call_out taken out of move_around by Hanse 1/4/93 */
void move_around() {
  string *exits;
  string exit;
  string file;
  object room;
  object env;
  int ok = 0;
  if (!this_object() || !(env = environment())) return;

  exits = env->query_exits();
  if (!exits || !sizeof(exits)) return;

  do {
    exit = exits[random(sizeof(exits))];
    exits -= ({ exit });
    file = env->query_exit(exit);
    room = find_object(file);
    // wander protection will not work for cloned rooms (such as in instances)
    //   because we have no way to load the files correctly
    //   (ie, with correct instance IDs)
    if (!room && strsrch(file, "#") == -1)
      room = load_object(file);
    if (room && room->query_property("no wander"))
      ok = 0;
    else
      ok = 1;
  } while (!ok && sizeof(exits));

  if (ok)
    command(exit);

  moving = 0;
}
// Set_Patrol by seeker May 26 2000
void set_patrol(int x, string *dirs)
{
 
 if (!x)
   return;
 if (!dirs)
   return;
 pon = 0;     // direction currently on..
 pcnt = 0;    // game ticks waiting for move
 pdirs = dirs; // directions
 patrol = x;  // speed of patrolling
}
void do_patrol()
{
 if (pcnt < patrol)
   {
    pcnt++;
    return;
   }
 pcnt = 0;
 command(pdirs[pon]);
 pon++;
 if (pon > sizeof(pdirs)-1)
  {
   pon = 0;
  }
}
void set_moving(int i) { moving = i; }
void set_speed(int i) { speed = i; }
    
string query_short()
{
 string seeker;
 int i;
 seeker = ::query_short();
 i = to_int(percent(query_hp(), query_max_hp()));
 if (i < 35)
   {
    seeker += " (dying)";
   } else
 if (i < 65)
   {
    seeker += " (bleeding)";
   } else
 if (i < 95)
   {
    seeker += " (injured)";
   }
      
 if (sizeof(query_riders())) seeker += " (ridden by "+query_riders_list()+")";

 return seeker;
}

// Added by Valodin, June 28, 1993
// changed by Nulvect 2010-07-27
// -- note, can probably make this more efficient in the future
// -- by skipping the loop and just setting the body mapping directly
// Sets up the limbs based on body type
void set_body_type(string type) {
  mapping body;

  body_type = type;

  init_limb_data();
  body = RACE_D->body(this_object());

  foreach (string limb, mapping limbdata in body) {
    add_limb(
      limb,
      limbdata["limb_ref"],
      limbdata["max_dam"],
      0, // current damage
      limbdata["ac"]
    );
    if (limbdata["wieldable"] == 1) {
      add_wielding_limb(limb);
    }
  }

  set_fingers(RACE_D->query_fingers(type));

  if (!this_object()->query_class()) {
    this_object()->set_class(RACE_D->query_class(type));
    this_object()->set_subclass(RACE_D->query_subclass(type));
  }
}
string query_body_type()
{
  return body_type;
}
void set_spell_chance(int x) {
  if (x < 0)
    x = 0;
  if (x > 100)
    x = 100;
  SpellChance = x;
}
void set_spells(string *arr) {
  Spells = copy(arr);
}
int query_spell_chance() { 
  return SpellChance;
}
string *query_spells() {
  return ( sizeof(Spells) ? copy(Spells) : ({}) );
}
string get_random_spell() {
  if (!sizeof(Spells))
    return 0;
  return Spells[random(sizeof(Spells))];
}
// These two functions remain for backwards Nightmare 1.* and 2.* compat
void set_chats(int x, string *arr) { set_emotes(x, arr, 0); }
void set_achats(int x, string *arr) { set_emotes(x, arr, 1); }
void set_emotes(int x, string *arr, int att) {
    emotes[(att ? "attack chance" : "chance")] = x;
    emotes[(att ? "attack msg" : "msg")] = arr;
}
void set_says(int x, string *arr, int att) {
    says[(att ? "attack chance" : "chance")] = x;
    says[(att ? "attack msg" : "msg")] = arr;
}
void set_speech(int x, string lang, string *arr, int att) {
    speech[lang] = ([ (att ? "attack chance" : "chance"): x,
      (att ? "attack msg" : "msg"): arr ]);
}
string query_race() { return query("race"); }
int test_heart() {
    object env;
    object *inv;
    int i;
   if( (query_mp() < query_max_mp()) || (query_hp() < query_max_hp()) ||
      (query_sp() < query_max_sp()) ) return 1;
    if(!(env = environment(this_object()))) return 0;
    if (query_hp() < 1) return 1;
    if(query_current_attacker() || speed || patrol) return 1;
    i = sizeof(inv = all_inventory(env));
    while(i--) 
      if(interactive(inv[i]) || inv[i]->query("aggressive") || inv[i]->query_property("keepheartbeat")) return 1;
    return 0;
}
int query_heart_status() { return heart_beat_on; }
void receive_message(string cl, string msg) {
   if( this_object()->query("posessed") )
      message("info", "%^RED%^%%%^RESET%^ "+msg, this_object()->query("posessed"), 0);
   if ( function_exists("catch_tell", this_object() ) )
     this_object()->catch_tell(msg);
}
void set_languages(string *langs) {
    int i;
    
    i = sizeof(langs);
    while(i--) set_lang_prof(langs[i], 10);
}
void set(string str, mixed val) {
    ::set(str, val);
    if(str == "race") LANG_D->init_languages(this_object());
}
void set_die(mixed val) {
   if(functionp(val) && geteuid(this_object()) != geteuid(val)) return;
    __Die = val;
}
mixed query_die() { return __Die; }
void set_race(string str) { set("race", str); }

int is_monster() { return 1; }

mixed *local_commands() {
  return commands();
}
