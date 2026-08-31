
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

// in rounds
#define SIDESTEP_DELAY 3
#define SIDESTEP_PROP "sidestep_abil_time"

inherit DAEMON;

int do_sidestep(object, object, string, string);

string *ignore_sidestep = ({
  "pain", "wound", "unknit", "turn", "lifewarp", "dispell",
  "whirlwind", "fog", "pressure", "tremble",
});
string *fail_sidestep = ({
  "shimmer",
});

int abil() {
  object tp = this_player();
  if (tp && member_array(tp->query_subclass(),
      ({ "jester", "swashbuckler" }) ) != -1 &&
      tp->query_skill("defense") >= 13*5)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <sidestep>\n\n"
    "A quick step to avoid most blows.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("You're already dead.");

  if (!tp->clean_up_attackers())
    FAIL("You are not fighting anyone.");

  if (tp->query(SIDESTEP_PROP) > time())
    FAIL("You can't do that again so soon.");

  if (tp->query_rest_type())
    FAIL("You have to stand up first!");

  if (tp->query_sp() < 40)
    FAIL("You are too tired.");

  return 1;
}

int cmd_sidestep(string str) {
  object tp = this_player();
  object env = environment(tp);
  int rounds;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  rounds = 1+random(2);
  if (tp->query_skill("perception") >= 120) rounds += 1;

  tp->set_reaction( (: do_sidestep :) );
  tp->set_reaction_time(rounds*2);
  tp->set(SIDESTEP_PROP, (rounds+SIDESTEP_DELAY)*2);
  tp->add_sp(-2);

  message("combat", "You prepare to sidestep the next attack.", tp);

  return 1;
}

int do_sidestep(object target, object attacker, string verb, string type) {
  string *types;
  int dodge;

  // can only sidestep single target attacks
  if (member_array("attack", types) == -1 ||
      member_array("area", types) != -1 ||
      member_array(verb, ignore_sidestep) != -1)
        return 0;

  // attempting to sidestep and failing turns it off, as well as a successful sidestep
  target->set_reaction(0);

  if (member_array(verb, fail_sidestep) != -1 ||
      member_array("no sidestep", types) != -1) {
        message("combat", "You try to sidestep the attack, but get hit anyway!", target);
        target->add_sp(-10);
        return 0;
  }

  types = explode(type, ",");
  dodge = target->query_stats("dexterity")*3;
  dodge += target->query_skill("defense");

  if (member_array("magic", types) != -1) {
    dodge -= attacker->query_stats("wisdom")*7;
    dodge -= attacker->query_stats("intelligence")*2;
  }
  else {
    dodge -= attacker->query_stats("dexterty")*3;
    dodge -= attacker->query_skill("attack");
    dodge -= attacker->query_skill("agility")/4;
  }

  if (dodge < 1) {
    message("combat", "You try to sidestep the attack, but it is too quick!", target);
    target->add_sp(-15);
    return 0;
  }

  message("combat", "You sidestep the attack!", target);
  message("combat", target->query_cap_name()+" sidesteps the attack!",
    environment(target), target);
  target->add_sp(-20);
  return 1;
}
