
#include <std.h>
#include <daemons.h>
#include <dirs.h>

#define COL "%^BOLD%^%^RED%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define RAMPAGE_PROP "rampage_abil_time"
// how long to last, in rounds
#define RAMPAGE_TIME 5
// delay between uses, in rounds
#define RAMPAGE_DELAY 20
#define RAMPAGE_ABILS ({\
  "jab",\
  "pound",\
  "headbutt",\
  "pummel",\
  "bash",\
  "maul",\
  "pierce",\
  "impale",\
  "stab",\
  "puncture",\
  "whip",\
  "lash",\
  "shoot",\
  "cut",\
  "slash",\
  "warblade",\
  "chop",\
  "hack",\
  "hew",\
})

inherit DAEMON;

void do_penalty(object tp, mapping penalty, int mult);
int query_rampage_time(object tp);
int query_rampage_delay(object tp);


int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "berserker" &&
      tp->query_skill("rage") >= 50*6 &&
      tp->query_skill("ferocity") >= 50*5 &&
      tp->query_skill("attack") >= 50*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <rampage [attack]>\n\n"
    "Allows a truly great berserker to go on a berserk rampage, "
    "hitting everyone in his path with an attack that normally "
    "hits only one foe.",
    this_player() );
}

int can_cast(object tp, string abil) {
  int ram;

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your attack.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");
  
  if (tp->query_ghost())
    FAIL("You're too dead.");

  if (!abil || !strlen(abil))
    FAIL("Rampage with what?");
  
  if (ram=tp->query(RAMPAGE_PROP))
    if (ram <= time() && ram+query_rampage_delay(tp)*2 > time())
      FAIL("You can't go berserk that often.");

  if (member_array(abil, RAMPAGE_ABILS) == -1)
    FAIL("You can't rampage with that.");
  
  return 1;
}

int cmd_rampage(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;
  string party;
  int count=0;
  mapping penalties = ([
    "stats" : ([]),
    "skills" : ([]),
  ]);
  
  if (!abil()) return 0;

  if (!can_cast(tp, str)) return 0;

  party = tp->query_party();
  
  tgts = filter(all_inventory(env),
    function (object ob, string party) {
      if (!living(ob)) return 0;
      if (ob == this_player()) return 0;
      if (ob == this_player()->query_riding()) return 0;
      if (party) {
        if (ob->query_party() == party) return 0;
        if (ob->query_rider() && ob->query_rider()->query_party() == party) return 0;
      }
      return 1;
    }, party);

  if (!sizeof(tgts))
    FAIL("There is no one here to rampage against!");

  if (sizeof(tgts) > 1) {
    foreach (string st in tp->query_all_stats())
      penalties["stats"][st] = tp->query_stats(st)/5;
    foreach (string sk in keys(tp->query_skills()))
      penalties["skills"][sk] = to_int(tp->query_skill(sk)*0.45);
  }

  do_penalty(tp, penalties, -1);
  
  if (!(load_object(DIR_CLASS_CMDS+"/_"+str)->abil())) {
    do_penalty(tp, penalties, 1);
    FAIL("You can't rampage with that.");
  }

  message("combat", "You go "+COL+"BER"+COL2+"S"+COL+"ERK"+RES+
                    " against your enemies!", tp);

  message("combat", tp->query_cap_name()+" goes completely "+
                    COL+"BER"+COL2+"S"+COL+"ERK"+RES+"!", env, tp);
  
  foreach (object tgt in tgts) {
    // kill_ob puts that target at the top of your list, so it becomes
    // your query_current_attacker()
    if (tp->kill_ob(tgt)) {
      if (tp->force_me(str)) {
        count++;
        tp->set_disable(0);
      }
    }
  }

  do_penalty(tp, penalties, 1);

  tp->set_disable();
  if (count)
    if (tp->query(RAMPAGE_PROP) < time())
      tp->set(RAMPAGE_PROP, time()+query_rampage_time(tp)*2);
  
  return 1;
}

void do_penalty(object tp, mapping penalty, int mult) {
  if (!tp || !sizeof(penalty) || !mult) return;

  if (!sizeof(penalty["stats"]))
    penalty["stats"] = ([]);
  if (!sizeof(penalty["skills"]))
    penalty["skills"] = ([]);

  foreach (string st, int amt in penalty["stats"])
    tp->add_stat_bonus(st, amt*mult);
  foreach (string sk, int amt in penalty["skills"])
    tp->add_skill_bonus(sk, amt*mult);
}

int query_rampage_time(object tp) {
  int l=tp->query_level();
  return RAMPAGE_TIME+(l-50)/10;
}

int query_rampage_delay(object tp) {
  int l=tp->query_level();
  return RAMPAGE_DELAY+(l-50)/10;
}

