
#include <std.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n");

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"

#define TAUNT_PROP "taunt_abil_time"
#define TAUNT_TIME 50
#define TAUNT_OB DIR_CLASS_CMDS+"/obj/taunt_ob"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "jester" &&
      tp->query_level() >= 9) return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <taunt who>\n\n"
    "A good entertainer can annoy his audience too, "
    "making them drop their guard a bit while they go after him.",
    this_player());
}

int can_cast(object tp, object tgt) {
  
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your mischief.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (sizeof(tp->query_attackers()))
    FAIL("You can't do that while fighting!");

  if (!tgt)
    FAIL("Taunt who?");

  if (tp == tgt)
    FAIL("Neener neener neener.");

  if (tp->query_sp() < 50)
    FAIL("You're too tired.");

  if ((int)tgt->query(TAUNT_PROP)+TAUNT_TIME > time())
    FAIL(capitalize(tgt->query_subjective())+
         " seems unimpressed.");

  return 1;
}

int cmd_taunt(string str) {
  object tp=this_player();
  object env = environment(tp);
  object tgt;
  object ob;
  int chr, level, wis, time, bonus;

  if (!abil()) return 0;

  if (str) tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  chr=tp->query_stats("charisma");
  level=tp->query_level();
  wis=tgt->query_stats("wisdom");

  bonus = chr*2/3 + level - wis*2/3;

  message("info", "You "+COL+"run around"+RES+" "+tgt->query_cap_name()+
      ", "+COL+"shouting"+RES+" and "+COL+"taunting"+RES+
      " "+tgt->query_objective()+"!",tp);
  message("info", tp->query_cap_name()+" "+COL+"runs around"+RES+" you, "
      ""+COL+"shouting"+RES+" and "+COL+"taunting"+RES+"!", tgt);
  message("info", tp->query_cap_name()+" "+COL+"runs around"+RES+" "+
      tgt->query_cap_name()+", "+COL+"shouting"+RES+" and "+
      COL+"taunting"+RES+" "+
      tgt->query_objective()+"!", env, ({tp, tgt}) );

  if (bonus < 5 || !tgt->kill_ob(tp)) {
    message("info", "You shrug it off and ignore the taunting.", tgt);
    message("info", tgt->query_cap_name()+" shrugs it off.", env, tgt);
  }

  else {
    // time in rounds
    time = 3 + level/3;
    if (time > 6) time = 6 + (time-6)/2;

    tgt->add_skill_bonus("defense", -bonus, time*2);
    tgt->add_skill_bonus("attack", bonus, time*2);
    tgt->set(TAUNT_PROP, time());

    message("info", "%^RED%^You feel the need to hurt "+
      tp->query_objective()+" badly!%^RESET%^", tgt);

    ob=new(TAUNT_OB);
    if (!ob)
      FAIL("An error occurred, please contact a staff member.");

    ob->set_id( ({ "taunt_abil_ob" }) );
    ob->set_owner(tp);
    ob->set_rounds(time);
    ob->move(tgt);

  }

  tp->set_disable(2);
  tp->add_sp(-(chr/3+wis/3+level/3));

  return 1;
}

