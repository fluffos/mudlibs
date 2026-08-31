#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s);

inherit DAEMON;

mapping strengths = ([
  "lightly" : 2,
  "moderately" : 12,
  "strongly" : 35
]);

void help() {
  message("help",
    "Syntax: <boost [whom] ["+implode(keys(strengths), "/")+"]>\n\n"
    "Allows you to boost someone's stamina.",
  this_player());
}

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "cleric") return 1;
  if (tp && tp->query_level() >= 5 && member_array(tp->query_subclass(),
      ({"paladin","antipaladin","blue","kataan"}) ) != -1)
        return 1;
  return 0;
}

string type() { return "healing"; }

int can_cast(object tp, object tgt, string how) {
  object env;

  if (!tp) return 0;

  env=environment(tp);
  
  if (env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");

  if (tp->query_ghost())
    FAIL("You cannot cast spells while dead.\n");

  if (!tgt)
    FAIL("Boost whom?\n");

  if (!living(tgt))
    FAIL("Try healing something that's alive.\n");

  if (member_array(how, keys(strengths)) == -1)
    FAIL("Boost how?\n");
  
  return 1;
}

int cmd_boost(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  string tmp, how;
  string cl;
  int s;

  int amount=0, cost, healing, wisdom;
  string thing, what;
  
  if (!spell()) return 0;
  
  // look at the last word
  if (sizeof(str) && (s = strsrch(str, " ", -1)) != -1) {
    tmp = str[0..s-1];
    how = str[s+1..];
  }
  else
    tmp = str;
  if (tmp == "me" || tmp == "myself") tgt=tp;
  else if (sizeof(tmp)) tgt=present(tmp, env);
  if (!sizeof(how)) how = "moderately";
  
  if (!can_cast(tp, tgt, how)) return 0;
  
  healing =tp->query_skill("healing")*2/3;
  healing += tp->query_skill("belief")/4;
  healing += tp->query_skill("faith")/6;
  wisdom = tp->query_stats("wisdom");
  
  for (int i=strengths[how]+random(3); i>0; i--)
      amount += random(wisdom/3 + 5) + healing/10;
  
  cost = amount/3;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic power.\n");
    
  tp->set_magic_round(1);

  tp->add_mp(-cost);
  
  if (tp == tgt) tp->add_skill_points("healing", amount/20);
  else tp->add_skill_points("healing", amount/10);

  cl = tp->query_subclass();

  switch (cl) {
    case "paladin": case "antipaladin":
      tgt->add_sp(amount/3);
    break;
    default:
      tgt->add_sp(amount/2);
  }

  switch (cl) {
    case "paladin": case "antipaladin": case "cleric":
      thing = "prayer";
      what = "a prayer of healing";
    break;
    case "kataan": case "blue":
      thing = "magic";
      what = "a spell of healing";
    break;
    default:
      thing = "nonsense";
      what = "nonsense";
  }
  
  if(tp == tgt) {
    message("magic", COL+"You boost your own power through "+thing+"."+RES, tp);
    message("magic", COL+tp->query_cap_name() + " mutters "+what+"."+RES, env, tp);
  }
  else {
    message("magic", COL+"You boost "+tgt->query_cap_name()+"'s power through "+thing+"."+RES, tp);
    message("magic", COL+tp->query_cap_name()+" boosts your power through "+thing+"."+RES, tgt);
    message("magic", COL+tp->query_cap_name()+" mutters "+what+"."+RES, env, ({tp, tgt}) );
    tp->add_alignment(amount/10);
  }

  return 1;
}

