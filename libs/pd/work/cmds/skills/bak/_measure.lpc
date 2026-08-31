#include <std.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^MAGENTA%^"
#define RES "%^RESET%^"

inherit DAEMON;

string *allowed = ({"speed", "wit", "brawn", "charm", "fortitude", "sagacity"});
string *adjectives = ({ "far", "somewhat", "a bit" });
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
    "Syntax: measure ["+implode(allowed, " | ")+"] [living]\n\n"
    "This gypsy spell lets them compare the attributes of others "
    "against themselves by peering into their subject's future.",
    this_player() );
}

int can_cast(object tp, object tgt, string which) {
  object env;
  
  if (!tp) return 0;

  env = environment(tp);

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");
  
  if (env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (!tgt)
    FAIL("Measure whom?\n");
  
  if (!living(tgt))
    FAIL("You're faster than it is, but it seems to outclass you in wits.\n");

  if (tgt == tp)
    FAIL("You're exactly equal.\n");

  if (member_array(which, allowed) == -1)
    FAIL("That is not something you can learn this way.\n");
  
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

  if (str && sscanf(str, "%s %s", which, str) == 2)
    tgt=present(str, env);

  if (!can_cast(tp, tgt, which))
    return 0;

  switch (which) {
    case "speed": stat="dexterity"; break;
    case "wit": stat="intelligence"; break;
    case "brawn": stat="strength"; break;
    case "charm": stat="charisma"; break;
    case "fortitude": stat="constitution"; break;
    case "sagacity": stat="wisdom"; break;
  }

  clair = 120 - (tp->query_skill("clairvoyance")-120);
  if (clair < 0) clair=0;
  
  if (tp->query_mp() < 180)
    FAIL("You are too low on magical energy.\n");
  
  diff = tp->query_stats(stat) - tgt->query_stats(stat);
  diff += random(clair)-random(clair);
  
  if (diff < -100)
    msg = "is incomparably greater than";
  else if (diff < -50)
    msg = "far surpasses";
  else if (diff < -20)
    msg = "is superior to";
  else if (diff < -5)
    msg = "is a bit higher than";
  else if (diff >= -5 && diff <= 5)
    msg = "is the same as";
  else if (diff > 100)
    msg = "is unimaginably scant compared to";
  else if (diff > 50)
    msg = "falls laughingly short of";
  else if (diff > 20)
    msg = "is inferior to";
  else if (diff > 5)
    msg = "is a bit lower than";
  
  msg = "You learn that "+tgt->query_cap_name()+"'s "+
        which+" "+msg+" your own.";

  message("magic", COL+"You peer into "+tgt->query_possessive()+
                   " future..."+RES,tp);
  message("magic", COL+tp->query_cap_name()+" seems to peer through "+
                   tgt->query_cap_name()+"."+RES, env, ({tp, tgt}));
  message("magic", COL+tp->query_cap_name()+" seems to peer through you."+RES, tgt);
  tp->add_mp(-(180+random(clair+30)));
  tp->set_magic_round(1);
  call_out("do_measure", 2, ({tp, msg}) );

  return 1;
}

void do_measure(mixed *args) {
  object tp=args[0];
  string msg=args[1];

  if (!tp || !sizeof(msg)) return;

  message("magic", COL+msg+RES, tp);

}

/*
string query_examine(object tp, object tgt) {
  return query_output(tp, tgt, 1);
}

string query_output(object tp, object tgt, int short) {
  string *ret = ({});

  foreach (string stat in keys(statdescs)) {
    int tmp = tp->query_stats(stat) - tgt->query_stats(stat);
    int adj, comp;

    if (tmp > 0) comp = 0;
    if (tmp == 0) comp = 1;
    if (tmp < 0) comp = 2;

    tmp = absolute_value(tmp);

    if (tmp > 50)
      adj = 0;
    else if (tmp > 20)
      adj = 1;
    else if (tmp > 5)
      adj = 2;
    if (short) {
      if (comp == 1) continue;
      ret += ({ statdescs[stat][comp] });
    }
    else {
      ret += ({ adjectives[adj] + " " + statdescs[stat][comp] });
    }
  }

  return "You are " + list(ret, 0, "and") + " than "+tgt->query_cap_name()+".";
}
*/
