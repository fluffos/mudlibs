
#include <std.h>
#include <dirs.h>
#include <effect_cl.h>

#define RES "%^RESET%^"
#define COL "%^WHITE%^"
#define COL2 "%^BLUE%^"

#define IRONFIST_STOP_ID "ironfist_abil_stop_cmd"
#define CMD_OB DIR_CLASS_CMDS+"/obj/command"

#define FAIL(s) return notify_fail(s+"\n")

int do_stop(string);

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" && tp->query_skill("attack") >= 15*5)
    return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <ironfist>\n\n"
    "This style of unarmed fighting allows the user to make more powerful "
    "strikes at the expensive of flexibility. "
    "One can <stop> using it at any time.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Why bother?");

  if (tp->query_effect("iron fist"))
    FAIL("You are already using the iron fist style.");

  return 1;
}

int cmd_ironfist(string str) {
  object tp = this_player();
  object env = environment(tp);
  int attack, dexterity;
  class Effect fist;
  object stopcmd;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  if (!(stopcmd = new(CMD_OB)))
    FAIL("An error occurred, please contact a staff member.");

  stopcmd->set_id( ({ IRONFIST_STOP_ID }) );
  stopcmd->set_command("stop");
  stopcmd->set_function(this_object(), "do_stop");
  stopcmd->move(tp);

  attack = tp->query_base_skill("attack")/3;
  dexterity = -(tp->query_base_stats()["dexterity"]*2/5);

  if (tp->query_effect("open palm")) {
    tp->remove_effect("open palm");
    tp->set_disable(2);
  }
  else
    tp->set_disable(1);

  tp->add_sp(-(3+random(4)));

  fist = new(class Effect);
  fist->name = "iron fist";
  fist->target = tp;
  fist->caster = tp;
  fist->castername = tp->query_name();
  fist->desc = "You are using the iron fist style of fighting.";
  fist->endmessages = ({
    COL+"You stop using the "+COL2+"iron fist"+COL+" style."+RES,
  });
  fist->misc = ({ stopcmd, attack, dexterity });
  fist->endfunc = function(class Effect fist) {
    object tp = fist->caster;
    mixed *info = fist->misc;
    object stopcmd = info[0];
    int attack = info[1];
    int dexterity = info[2];

    if (stopcmd) stopcmd->remove();
    tp->add_skill_bonus("attack", -attack);
    tp->add_stat_bonus("dexterity", -dexterity);
  };

  message("info", COL+"You begin using the "+COL2+"iron fist"+COL+
                  " fighting style."+RES, tp);

  tp->add_skill_bonus("attack", attack);
  tp->add_stat_bonus("dexterity", dexterity);
  tp->add_effect(fist);

  return 1;
}

int do_stop(string str) {
  object tp = this_player();
  class Effect fist;

  if (tp && str) {
    switch (str) {
      case "using iron fist":
      case "using ironfist":
      case "using iron fist style":
      case "using ironfist style":
      case "iron fist":
      case "ironfist":
      case "iron fist style":
      case "ironfist style":
        fist = tp->query_effect("iron fist");
        if (fist) {
          tp->remove_effect(fist);
          return 1;
        }
    }
  }

  FAIL("Stop what?");
}

