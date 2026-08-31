
#include <std.h>

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("faith") >= 25*6)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <paralyze [whom]>\n\n"
    "A prayer for faithful clerics. If answered, the gods will cause "
    "the cleric's foe to be completely paralyzed for a short time. "
    "This power is only granted periodically.",
    this_player());
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no magic"))
    FAIL("You cannot use that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");
  
  if (!tgt)
    FAIL("Paralyze whom?\n");

  if (!living(tgt))
    FAIL("Ok, it's paralyzed.\n");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");
  
  if (tgt->query_paralyzed() || tp->query("paralyze_spell_wait"))
    FAIL("You pray to the gods.\n"
         "The gods refuse to answer.\n");

  return 1;
}

int cmd_paralyze(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int rounds, cost;
  
  if (!spell()) return 0;

  if (str && str != "")
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();
  
  if (!can_cast(tp,tgt)) return 0;

  rounds = 1;
  rounds += tp->query_skill("faith")/65 + tp->query_stats("wisdom")/30;
  rounds -= tgt->query_stats("wisdom")/18;
  rounds += random(2);
  if (rounds > 4) rounds = 4+(rounds-4)/2;
  if (rounds > 8) rounds = 8;
  if (rounds < 1) rounds = 1;

  cost = rounds*50 + random(tp->query_level());
  if (cost > 500)
    cost = 500 + (cost-500)/20 + random(tp->query_level()/3);

  if (tp->query_mp() < cost)
    FAIL("Not enough magic.\n");

  tp->add_mp(-cost);
  tp->set_magic_round(1);
  tp->set("paralyze_spell_wait",1);
  call_out("para_wait", (rounds+7)*2, ({tp}) );

  message("magic", "You pray to the gods.", tp);
  message("magic", tp->query_cap_name()+" mutters a prayer.", env, tp);
  message("magic", COL+"Your body suddenly becomes paralyzed!"+RES, tgt);
  message("magic", COL+tgt->query_cap_name()+" suddenly stops moving!"+RES,
                   env, tgt);
  
  tgt->set_paralyzed(rounds*2, "Your body has been paralyzed.");
  
  return 1;
}

void para_wait(mixed *args) {
  object tp=args[0];

  if (!tp) return;

  tp->set("paralyze_spell_wait",0);
}

