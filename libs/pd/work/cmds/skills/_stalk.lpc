#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BLUE%^"

#define STALK_PROP "stalk_abil_info"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && (
       (tp->query_subclass() == "assassin" && tp->query_skill("stealth") >= 28*5) ||
       (tp->query("wolf") || tp->query("lion") )
     ) )
       return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <stalk [who]>\n\n"
    "Allows you to follow somebody in secret.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (tp->query_busy())
    FAIL("You're busy doing something else.");

  if (tp->query_ghost())
    FAIL("You are already as quiet as the dead.");
  
  if (!tgt)
    FAIL("Stalk who?");

  if (!living(tgt))
    FAIL("That thing isn't going to move around much.");

  if (tgt == tp)
    FAIL("Try as you might, you can't seem to get behind yourself.");

  if (tp->query_rest_type())
    FAIL("You ned to stand up first.");

  if (tp->clean_up_attackers())
    FAIL("There's no time to stalk someone, you are fighting!");

  if (tp->query_sp() < 30)
    FAIL("You're too tired to stalk anyone.");

  foreach (string l in tp->query_walking_limbs())
    if (member_array(l, tp->query_severed_limbs()) != -1)
      FAIL("You can't stalk anyone without your "+l+"!");

  return 1;
}

int cmd_stalk(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int perc, stealth;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  perc = tgt->query_skill("perception");
  perc += tgt->query_stats("intelligence")*3;
  perc += tgt->query_stats("dexterity")*2;

  stealth = tp->query_skill("stealth");
  stealth += tp->query_stats("charisma")*3;
  stealth += tp->query_stats("dexterity")*2;
  if (tp->query("lion") || tp->query("wolf"))
    stealth += tp->query_skill("nature");
  
  if (perc > stealth) {
    message("info", tgt->query_cap_name()+" catches you "
                    "trying to follow "+tgt->query_objective()+"!", tp);
    message("info", "You catch "+tp->query_cap_name()+
                    " trying to follow you!", tgt);
    message("info", "You notice "+tp->query_cap_name()+
                    " trying to follow "+tgt->query_cap_name()+".",
                    env, ({ tp, tgt }) );
  }
  else {
    message("info", "You begin to "+COL+"stalk"+RES+" "+
                    tgt->query_cap_name()+".", tp);
    tp->set(STALK_PROP, tgt);
    tp->add_stealth(stealth/2);
    tp->add_skill_points("stealth", stealth/5);
    tp->add_sp(-(15+random(6)));
    tgt->add_follower(tp);
  }

  return 1;
}

