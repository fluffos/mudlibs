#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")
#define FAIL1(s) message("info", s, this_player()); return 1;

#define VAPOR_PROP "vaporform_abil"
#define VAPOR_DELAY 60*10
#define VAPOR_DELAY_PROP "vaporform_delay"
#define VAPOR_CMD_ID "vaporform_command_id"
#define CMD_OB "/cmds/skills/obj/command"

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^WHITE%^"
#define COL2 RES+"%^WHITE%^"

inherit DAEMON;

int do_cmd(string str);
int do_trueform(string str);

string *disallow = ({
  "jab", "claw", "swoop", "drink", "torpor",
  "bloodrave", "crescent", "headbutt", "shadowform", "stealth",
  "trance", "celerity", "fly", "bump", "aim",
  "causticblood", "lupineform", "batform", "tenebration", "vaporform",
  "regrowth", "conceal", "mist", "shadowstep", "snowball", "preserve",
  "bash", "hack", "impale", "shoot", "slash", "stab", "whip",
  "kill",
});

int spell() {
  object tp = this_player();
  if (tp && tp->query_class() == "vampire" && tp->query_level() >= 3)
    return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <vaporform>\n\n"
    "A vampire can turn himself into a cloud of vapor. "
    "In this state he cannot attack or be attacked, but he is "
    "immune to the effects of sunlight. "
    "He can return to his <trueform> at any time.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query(VAPOR_PROP))
    FAIL("You are already in that form.");

  if (tp->query(VAPOR_DELAY_PROP)+VAPOR_DELAY > time())
    FAIL("Your body cannot transform again so soon.");
  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy fighting!");

  if (tp->query_mp() < 60)
    FAIL("Your magic is too low.");

/*
  if (VAMPIRE_D->query_sunlight(tp))
    FAIL("The sunlight interferes with your transformation!");
*/

  return 1;
}

int cmd_vaporform(string str) {
  object tp = this_player();
  object env = environment(tp);
  object ob;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  message("magic", COL+"Your body "+
    COL2+"f"+COL+"o"+COL2+"r"+COL+"m"+COL2+"s"+COL+" into "+
    COL2+"v"+COL+"a"+COL2+"p"+COL+"o"+COL2+"r"+COL+".", tp);

  message("magic", COL+tp->query_cap_name()+"'s body "+
    COL2+"f"+COL+"o"+COL2+"r"+COL+"m"+COL2+"s"+COL+" into "+
    COL2+"v"+COL+"a"+COL2+"p"+COL+"o"+COL2+"r"+COL+".", env, tp);

  tp->add_mp(-(60+random(25)));
  tp->set(VAPOR_PROP, 1);
  tp->set_property("passive", 1);
  tp->set_disquised_short("A cloud of vapor");
  
  if (ob = new(CMD_OB)) {
    ob->set_id( ({ VAPOR_CMD_ID }) );
    ob->set_command(disallow);
    ob->set_function(this_object(), "do_cmd");
    ob->move(tp);
    ob = 0;
    ob = new(CMD_OB);
    ob->set_command("trueform");
    ob->set_function(this_object(), "do_trueform");
    ob->move(tp);
  }
  

  return 1;
}

int do_cmd(string str) {
  object tp = this_player();
  if (!tp) return -1;
  FAIL1("Your current form does not allow you to do that.");
}

int do_trueform(string str) {
  object tp = this_player();
  object env = environment(tp);
  if (!tp) return -1;
  if (!env) return -1;
/*
  if (VAMPIRE_D->query_sunlight(tp)) {
    FAIL1("The sunlight interferes with your transformation!");
  }
*/

  message("magic", COL+"Your body "+
    COL2+"b"+COL+"e"+COL2+"c"+COL+"o"+COL2+"m"+COL+"e"+COL2+"s"+COL+
    " "+RES+"flesh"+COL+" again."+RES, tp);
  message("magic", COL+tp->query_cap_name()+"'s body "+
    COL2+"b"+COL+"e"+COL2+"c"+COL+"o"+COL2+"m"+COL+"e"+COL2+"s"+COL+
    " "+RES+"flesh"+COL+" again."+RES, env, tp);

  tp->add_mp(-(10+random(10)));
  tp->set(VAPOR_PROP, 0);
  tp->set(VAPOR_DELAY_PROP, time());
  tp->remove_property("passive");
  tp->remove_disquised_short();
  present(VAPOR_CMD_ID, tp)->remove();

  return -1;
}
