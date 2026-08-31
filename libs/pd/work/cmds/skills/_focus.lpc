#include <std.h>
#include <effect_cl.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s);

#define CMD_OB DIR_CLASS_CMDS+"/obj/command"
#define FOCUS_STOP_ID "focus_abil_stop_cmd"

inherit DAEMON;

string *allowed_skills = ({
  "axe", "blade", "blunt", "flail", "knife", "projectile",
});

int do_stop(string str);
int add_sp_hook(int x);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "warrior" &&
      tp->query_skill("attack") >= 20*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <focus on [type]>\n\n"
    "This allows a warrior to focus himself on using one weapon type "
    "especially well, so that his basic attacks with it will be better.\n"
    "This concentration will increase your stamina loss, but you can "
    "<stop focusing> at any time.",
    this_player() );
}

int can_cast(object tp, string type) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You should focus on becoming alive again, first.");

  if (tp->query_effect("focus"))
    FAIL("You are already focusing!");

  if (!type || !strlen(type))
    FAIL("Focus on what?");

  if (member_array(type, allowed_skills) == -1)
    FAIL("You cannot focus on that.");

  if (tp->query_skill(type) < 20*6)
    FAIL("You are not yet skilled enough to focus on that type of weapon.");

  return 1;
}

int cmd_focus(string str) {
  object tp = this_player();
  object env = environment(tp);
  class Effect focus;
  object stopcmd;

  if (!abil()) return 0;

  if (str) {
    sscanf(str, "on %s", str);
  }

  if (!can_cast(tp, str)) return 0;

  if (!(stopcmd = new(CMD_OB)))
    FAIL("An error occurred, please contact a staff member.");

  stopcmd->set_id( ({ FOCUS_STOP_ID }) );
  stopcmd->set_command("stop");
  stopcmd->set_function(this_object(), "do_stop");
  stopcmd->move(tp);

  focus = new(class Effect);
  focus->name = "focus";
  focus->caster = tp;
  focus->castername = tp->query_name();
  focus->target = tp;
  focus->desc = "You are focusing on your "+str+" skills.";
  focus->endmessages = ({
    "You stop focusing on your "+str+" skills.",
    tp->query_cap_name()+" seems to lose "+tp->query_possessive()+" focus.",
  });
  focus->misc = ({ str, stopcmd, (: add_sp_hook :) });
  focus->endfunc = function(class Effect focus) {
    mixed *info = focus->misc;
    object stopcmd = info[1];

    if (stopcmd) stopcmd->remove();

    focus->caster->remove_hook("add_sp", info[2]);
  };

  tp->add_effect(focus);
  tp->add_hook("add_sp", focus->misc[2]);

  message("info", "You focus on your "+str+" skills.", tp);
  message("info", tp->query_cap_name()+" seems to focus for a moment.",
    env, tp);

  tp->set_disable(2);
  
  return 1;
}

int do_stop(string str) {
  object tp = this_player();

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp && str) {
    switch (str) {
      case "focus":
      case "focusing":
        tp->set_disable(2);
        tp->remove_effect("focus");
        return 1;
    }
  }

  FAIL("Stop what?");
}

int add_sp_hook(int x) {
  if (x < 0)
    x = x * 130 / 100;
  return x;
}

