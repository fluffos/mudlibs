
#include <std.h>
#include <dirs.h>
#include <effect_cl.h>

#define RES "%^RESET%^"
#define COL "%^WHITE%^"
#define COL2 "%^CYAN%^"

#define OPENPALM_STOP_ID "openpalm_abil_stop_cmd"
#define CMD_OB DIR_CLASS_CMDS+"/obj/command"

#define FAIL(s) return notify_fail(s+"\n")

int do_stop(string);

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" && tp->query_skill("defense") >= 15*5)
    return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <openpalm>\n\n"
    "This style of unarmed fighting allows the user to more easily dodge "
    "and deflect blows at the expensive of power. "
    "One can <stop> using it at any time.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Why bother?");

  if (tp->query_effect("open palm"))
    FAIL("You are already using the open palm style.");

  return 1;
}

int cmd_openpalm(string str) {
  object tp = this_player();
  object env = environment(tp);
  int defense, strength;
  class Effect palm;
  object stopcmd;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  if (!(stopcmd = new(CMD_OB)))
    FAIL("An error occurred, please contact a staff member.");

  stopcmd->set_id( ({ OPENPALM_STOP_ID }) );
  stopcmd->set_command("stop");
  stopcmd->set_function(this_object(), "do_stop");
  stopcmd->move(tp);

  defense = tp->query_base_skill("defense")/2;
  strength = -(tp->query_base_stats()["strength"]*2/5);

  if (tp->query_effect("iron fist")) {
    tp->remove_effect("iron fist");
    tp->set_disable(2);
  }
  else
    tp->set_disable(1);

  tp->add_sp(-(3+random(4)));

  palm = new(class Effect);
  palm->name = "open palm";
  palm->target = tp;
  palm->caster = tp;
  palm->castername = tp->query_name();
  palm->desc = "You are using the open palm style of fighting.";
  palm->endmessages = ({

    COL+"You stop using the "+COL2+"open palm"+COL+" style."+RES,
  });
  palm->misc = ({ stopcmd, defense, strength });
  palm->endfunc = function(class Effect palm) {
    object tp = palm->caster;
    mixed *info = palm->misc;
    object stopcmd = info[0];
    int defense = info[1];
    int strength = info[2];

    if (stopcmd) stopcmd->remove();
    tp->add_skill_bonus("defense", -defense);
    tp->add_stat_bonus("strength", -strength);
  };

  message("info", COL+"You begin using the "+COL2+"open palm"+COL+
                  " fighting style."+RES, tp);

  tp->add_skill_bonus("defense", defense);
  tp->add_stat_bonus("strength", strength);
  tp->add_effect(palm);

  return 1;
}

int do_stop(string str) {
  object tp = this_player();
  class Effect palm;

  if (tp && str) {
    switch (str) {
      case "using open palm":
      case "using openpalm":
      case "using open palm style":
      case "using openpalm style":
      case "open palm":
      case "openpalm":
      case "open palm style":
      case "openpalm style":
        palm = tp->query_effect("open palm");
        if (palm) {
          tp->remove_effect(palm);
          return 1;
        }
    }
  }

  FAIL("Stop what?");
}

