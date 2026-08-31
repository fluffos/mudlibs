
#include <std.h>
#include <effect_cl.h>
#include <dirs.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 RES+"%^MAGENTA%^"

#define CMD_OB DIR_CLASS_CMDS+"/obj/command"

#define COMPEL_PROP "compel_spell_data"
#define COMPEL_DELAY 30


inherit DAEMON;

mixed *outlaw_hook(mixed *args);
void remove_hooks(object tgt);
void mob_attack(object tp, object tgt);

string *not_allowed = ({
  // commands that should only willingly be used
  "suicide", "quit", "remort", "marry", "divorce",
  "improve", "train", "study", "advance", "drop all",
  // teleport and fast move abilities
  "fly", "return", "gate", "corona", "teleport",
  // use up a ton of mp and/or are dangerous to the caster
  "fireworks", "snowball", "resurrect", "morph", "rage",
  // this would get complicated
  "compel",
});

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 40*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <compel [victim] to [action]>\n\n"
    "A powerful spell that can force someone to perform a specific action.\n"
    "Only a powerful sorceror can mold someone's mind this way, and only a "
    "few times before the mind builds up a resistance. The victim will be a "
    "little disoriented after regaining control.\n\n"
    "%^BOLD%^%^RED%^Warning:%^RESET%^ The caster will be held responsible for "
    "anything done using this spell, including PK, stealing, and rules "
    "infractions!",
    this_player() );
}

int can_cast(object tp, object tgt, string cmd) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your powers in this state.");

  if (!tgt)
    FAIL("Compel who?");

  if (tp == tgt)
    FAIL("Or you could just do it.");

  if (!cmd || !strlen(cmd))
    FAIL("Compel "+tgt->query_objective()+" to do what?");

  if (!tp->ok_to_kill(tgt))
    FAIL("Some force prevents your mischief.");

  if (tgt->query_delay("compel"))
    FAIL(capitalize(tgt->query_subjective())+
         " has become resistant to your psionics.");

  if (tgt->is_player() && tgt->query_level() < 20)
    FAIL("A benevolent force protects "+tgt->query_possessive()+" mind.");

  if (wizardp(tgt) && !wizardp(tp))
    FAIL("You would surely be punished for such insolence!");

  if (tp->query_mp() < 150)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_compel(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string tgtname, action, cmd, args;
  int cost, compel_resist, tgtwis, defend;
  mixed *data;

  if (!spell()) return 0;

  if (str && sscanf(str, "%s to %s", tgtname, action) == 2) {
    if (!sscanf(action, "%s %s", cmd, args)) {
      cmd = action;
      args = 0;
    }
    tgt = present(tgtname, env);
  }

  if (!can_cast(tp, tgt, cmd)) return 0;

  tgtwis = tgt->query_stats("wisdom");

  cost = 100 + tgtwis + random(10);
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  tp->add_mp(-cost);
  tp->set_magic_round(1);

  data = tgt->query(COMPEL_PROP);
  if (!data || sizeof(data) < 3)
    data = ({ 0, 0, 0 });

  compel_resist = data[0];
  defend = tgtwis - tp->query_stats("intelligence");
  if (member_array(tgt, tp->query_attackers()) != -1) {
    defend = defend * 125 / 100;
    compel_resist = compel_resist * 125 / 100;
  }

  if (defend >= (20+random(30)) ||
      member_array(cmd, not_allowed) != -1 ||
      member_array(action, not_allowed) != -1) {
        message("magic", COL+"Your psionic compulsion fails utterly!"+RES, tp);
        mob_attack(tp, tgt);
        return 1;
  }

  message("magic", COL+"You "+COL2+"compel"+COL+" "+tgt->query_cap_name()+
                   " to "+COL2+action+COL+"."+RES, tp);
  message("magic", COL+"A shimmer of "+COL2+"power"+COL+" flits from "+
                   tp->query_cap_name()+" into "+tgt->query_cap_name()+"."+RES,
                   env, ({ tp, tgt }) );

  switch (compel_resist) {
    case 0..33:
      message("magic", COL+"A memory of something you meant to do "
                       "comes to you."+RES, tgt);
    break;
    case 34..66:
      message("magic", COL+"A sudden urge to do something fills "
                       "your mind."+RES, tgt);
    break;
    case 67..99:
      message("magic", COL+"The need to carry out some action suddenly "
                       "takes over your senses."+RES, tgt);
    break;
    default:
      message("magic", COL+"You feel forced to perform a task."+RES, tgt);
  }

  if (compel_resist < 100) {
    if (defend < 0) defend = 5;
    compel_resist += tgtwis * (100+defend) / 100;
  }
  else {
    tgt->set_delay("compel", time()+COMPEL_DELAY);
    compel_resist = 0;
    mob_attack(tp, tgt);
  }

  data[0] = compel_resist;
  data[1] = tp;
  data[2] = (: outlaw_hook :);

  tgt->set(COMPEL_PROP, data);

  tgt->add_hook("add_outlaw", data[2] );
  tgt->add_hook("set_outlaw", data[2] );
  tgt->add_hook("caught_theft", data[2] );
  call_out("remove_hooks", 4, tgt);

  tgt->force_me(cmd+ ( args ? " "+args : "" ) );
  if (tgt->query_disable() < 2)
    tgt->set_disable(2);

  tp->add_skill_points("psionics", cost);

  return 1;
}

mixed *outlaw_hook(mixed *args) {
  string type = args[0];
  int amt = args[1];
  object victim = this_player();
  mixed *data = victim->query(COMPEL_PROP);
  object caster = data[1];

  if (!caster) return args;

  caster->add_outlaw(type, amt);
  return 0;
}

void remove_hooks(object tgt) {
  mixed *data;
  if (!tgt) return;
  data = tgt->query(COMPEL_PROP);
  tgt->remove_hook("add_outlaw", data[2] );
  tgt->remove_hook("set_outlaw", data[2] );
  tgt->remove_hook("caught_theft", data[2] );
  data[1] = 0;
  data[2] = 0;
  tgt->set(COMPEL_PROP, data);
}

void mob_attack(object tp, object tgt) {
  if (tgt->is_monster() && tp->is_player())
    tgt->kill_ob(tp);
}
