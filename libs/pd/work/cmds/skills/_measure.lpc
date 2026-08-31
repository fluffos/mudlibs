#include <std.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^MAGENTA%^"
#define RES "%^RESET%^"

inherit DAEMON;

string query_examine(object tp, object tgt);
string query_output(object tp, object tgt, int short);

string *adjectives = ({ "far", "somewhat", "a bit" });
string *allstats = ({
  "strength", "constitution",
  "dexterity", "charisma",
  "intelligence", "wisdom",
});
mapping statdescs = ([
  "strength" : ({ "stronger", "as strong as", "weaker" }),
  "constitution" : ({ "sturdier", "as sturdy as", "more frail" }),
  "dexterity" : ({ "faster", "as fast as", "slower" }),
  "charisma" : ({ "more charming", "as charming as", "less charming" }),
  "intelligence" : ({ "smarter", "as smart as", "more ignorant" }),
  "wisdom" : ({ "more prudent", "as prudent as", "more foolish" }),
]);

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "gypsy" &&
      tp->query_skill("clairvoyance") >= 20*6)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  message("help",
    "Syntax: measure [living]\n\n"
    "This gypsy spell lets them compare the attributes of others "
    "against themselves by peering into their subject's future.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;
  
  if (!tp) return 0;

  env = environment(tp);

  if (tp->query_busy())
    FAIL("You are busy.\n");
  
  if (env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (!tgt)
    FAIL("Measure whom?\n");
  
  if (!living(tgt))
    FAIL("You're faster than it is, but it seems to outclass you in wits.\n");

  if (tgt == tp)
    FAIL("You're exactly equal.\n");

  return 1;
}

int cmd_measure(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int clair;
  int diff;
  string stat, which, msg;

  if (!spell())
    return 0;

  if (str)
    tgt=present(str, env);

  if (!can_cast(tp, tgt))
    return 0;

  message("magic", COL+"You peer into "+tgt->query_possessive()+
                   " future..."+RES,tp);
  message("magic", COL+tp->query_cap_name()+" seems to peer through "+
                   tgt->query_cap_name()+"."+RES, env, ({tp, tgt}));
  message("magic", COL+tp->query_cap_name()+" seems to peer through you."+RES, tgt);

  message("magic", query_output(tp, tgt, 0), tp);

  tp->add_mp(-(100+random(30)));
  tp->set_magic_round(1);

  return 1;
}

string query_examine(object tp, object tgt) {
  tp->add_mp(-(100+random(30)));
  return query_output(tp, tgt, 1);
}

string query_output(object tp, object tgt, int short) {
  string *ret = ({});
  int clair = 120 - (
    (tp->query_skill("clairvoyance")-120) + tp->query_stats("wisdom")
  );
  if (clair < 0) clair=0;

  foreach (string stat in allstats) {
    int diff = tp->query_base_stats(stat) - tgt->query_base_stats(stat);
    int adj, comp;

    diff += random(clair)-random(clair);

    if (diff > -5 && diff < 5) {
      /* comp = 1; */
      continue;
    }
    else if (diff > 0) comp = 0;
    else if (diff < 0) comp = 2;

    diff = absolute_value(diff);

    if (diff > 35)
      adj = 0;
    else if (diff > 10)
      adj = 1;
    else
      adj = 2;

    if (short) {
      if (comp == 1) continue;
      ret += ({ statdescs[stat][comp] });
    }
    else {
      if (comp == 1)
        ret += ({ statdescs[stat][comp] });
      else
        ret += ({ adjectives[adj] + " " + statdescs[stat][comp] });
    }

  }//end foreach

  return "Your future sight reveals that you are "+
         list(ret) + " than "+tgt->query_cap_name()+".";
}

