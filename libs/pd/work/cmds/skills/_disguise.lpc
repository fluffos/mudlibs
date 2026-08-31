
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BLUE%^"
#define RES "%^RESET%^"

#define COMMAND_OB "/cmds/skills/obj/command"
#define DISGUISE_ID "disguise_ob_id"

inherit DAEMON;

void remove_disguise(object tp);

object *who = ({});

int abil() {
  object tp = this_player();
  if (tp && member_array(tp->query_subclass(),
      ({ "assassin", "thief", "scout" }) ) != -1 &&
      tp->query_skill("stealth") >= 150)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <disguise as [whom]>\n\n"
    "Allows you to disguise yourself as someone else in the room. "
    "It will stay in place until you get too tired or <drop disguise>.",
    this_player() );
}

int can_cast(object tp, object tgt) {
  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (strlen(tp->query_disguised_short()))
    FAIL("You are already disguised.");

  if (!tgt || tgt->query_invis() || !tgt->query_short())
    FAIL("Disguise as whom?");

  if (!living(tgt))
    FAIL("You can only disguise yourself as another living thing.");

  if (wizardp(tgt) && !wizardp(tp))
    FAIL("The gods would surely strike you down for such insolence.");

  if (tp == tgt)
    FAIL("You already look like yourself.");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 100)
    FAIL("You are too tired to disguise yourself.");

  return 1;
}

int cmd_disguise(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object cmd;
  int cost, time, stealth;
  string name;
  string *ids;

  if (!abil()) return 0;

  if (str && sscanf(str, "as %s", name) != 1)
    name = str;

  if (name)
    tgt = present(name, env);

  if (!can_cast(tp, tgt)) return 0;

  stealth = tp->query_skill("stealth");
  stealth += tp->query_stats("charisma")*4;
  stealth += tp->query_stats("intelligence")*2;
  stealth -= tgt->query_stats("charisma")*6;

  if (stealth < 125+random(75)) {
    cost = 20+random(6);
    message("info", "You fail to disguise yourself.", tp);
  }
  else {
    if (!(cmd = new(COMMAND_OB)))
      FAIL("An error occurred, please contact an immortal.");

    cost = 40+random(11);
    message("info", "You "+COL+"slyly"+RES+" disguise yourself as "+
                    capitalize(name)+".", tp);
    tp->set_disguised_short(tgt->query_short());
    ids = tgt->query_id() + ({ tgt->query_name() });
    ids -= tp->query_id() + ({ tp->query_name(), "monster" });
    tp->set_disguised_id(ids);
    if (stealth >= 250+random(50)) {
      tp->set_disguised_name(tgt->query_cap_name());
      tp->set_disguised_long(tgt->query_long());
    }
    who += ({ tp });
    set_heart_beat(2);
    cmd->set_id( cmd->query_id() + ({ DISGUISE_ID }) );
    cmd->set_command( ({ "stop", "drop" }) );
    cmd->set_function(this_object(), "stop_disguise");
    cmd->set_notify("notify_disguise");
    cmd->move(tp);
  }

  tp->set_disable();
  tp->add_sp(-cost);

  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    if (!p) who -= ({ p });
    else {
      if (random(100) < 90) p->add_sp(-(1+random(2)));
      if (sizeof(p->query_attackers())) p->add_sp(-1);
      if (p->query_sp() < 50 || p->query_hp() < p->query_max_hp()/3 || !interactive(p)) {
        message("info", "You are too tired to keep up your disguise.", p);
        remove_disguise(p);
        who -= ({ p });
      }
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}

int stop_disguise(string str) {
  object tp = this_player();
  object env = environment(tp);

  if (str != "disguise")
    FAIL(capitalize(query_verb())+" what?");

  message("info", "You take off your disguise.", tp);
  remove_disguise(tp);
  who -= ({ tp });

  return -1;
}

void notify_disguise(object killer, object victim) {
  if (member_array(victim, who) != -1) {
    who -= ({ victim });
    remove_disguise(victim);
  }
}

void remove_disguise(object tp) {
  object *obs;
  if (!tp) return;
  tp->remove_disguised_short();
  tp->remove_disguised_long();
  tp->remove_disguised_name();
  tp->remove_disguised_id();
  if (sizeof(obs = filter(all_inventory(tp), (: $1->id(DISGUISE_ID) :) ) ))
    obs->remove();
}
