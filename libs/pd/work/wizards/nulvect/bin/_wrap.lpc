#include <std.h>
#include <effect_cl.h>

inherit DAEMON;

void end_wrap(class Effect);

int abil() {
  object tp = this_player();
  if (tp && tp->query_race() == "dragon" &&
      tp->query_skill("tail") >= 13*5)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <wrap [on | off]>\n\n"
    "Dragons are able to wrap their tails around their bodies, protecting "
    "them from attacks. Unfortunately it is very hard to attack with the "
    "tail in the way.",
    this_player() );
}

int can_cast(object tp, string onoff) {

  if (!tp) return 0;

  if (tp->query_busy())
    return notify_fail("You are busy.");

  switch (onoff) {
    case "on":
      if (tp->query_effect("tailwrap"))
        return notify_fail(
          "You already have your tail wrapped around you."
        );
    break;

    case "off":
      if (!tp->query_effect("tailwrap"))
        return notify_fail(
          "You have not wrapped your tail around yourself yet."
        );
    break;

    default:
      return notify_fail("Syntax: <wrap [on | off]>");
  }

  return 1;
}

int cmd_wrap(string str) {
  object tp = this_player();
  object env = environment(tp);
  class Effect wrap;

  if (!can_cast(tp, str)) return 0;

  switch (str) {
    case "on":
      wrap = new(class Effect);

      wrap->name = "tailwrap";
      wrap->castername = tp->query_name();
      wrap->caster = tp;
      wrap->target = tp;
      wrap->desc = "Your tail is wrapped around you, providing protection.";
      wrap->endfunc = (: end_wrap :);
      wrap->endmessages = ({
        "You unwrap your tail from your body.",
        tp->query_cap_name()+" unwraps "+tp->query_possessive()+
          " tail from "+tp->query_possessive()+" body."
      });       

      wrap->misc = ({
        tp->query_skill("tail"),
        tp->query_skill("tail")*2/3,
        5,
      });

      tp->add_skill_bonus("defense", wrap->misc[0]);
      tp->add_skill_bonus("tail", -(wrap->misc[1]));
      tp->add_combat_round_bonus(-(wrap->misc[2]));

      tp->add_effect(wrap);

      message("info", "You wrap your tail around yourself protectively.",
        tp);
      message("info", tp->query_cap_name()+" wraps "+tp->query_possessive()+
        " tail around "+tp->query_possessive()+"self.", env, tp);
    break;

    case "off":
      tp->remove_effect("tailwrap");
    break;
  }

  tp->set_disable();

  return 1;
}

void end_wrap(class Effect wrap) {
  object tp = wrap->caster;
  if (!tp) return;
  tp->add_skill_bonus("defense", -(wrap->misc[0]));
  tp->add_skill_bonus("tail", wrap->misc[1]);
  tp->add_combat_round_bonus(wrap->misc[2]);
}

