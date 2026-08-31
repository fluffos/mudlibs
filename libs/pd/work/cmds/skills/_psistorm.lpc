#include <std.h>
#include <daemons.h>
#include <effect_cl.h>
#include <damage.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 "%^BOLD%^%^BLUE%^"
#define COL3 "%^BOLD%^%^WHITE%^"

inherit DAEMON;

void do_hit(class Effect);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 30*6 &&
      tp->query_skill("magic attack") >= 30*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <psistorm>\n\n"
    "An advanced sorceror releases a storm of psionic force that lifts and "
    "throws everything around them at a high rate of speed. The storm will "
    "last a short while.",
    this_player() );
}

int can_cast(object tp) {

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your powers in this state.");

  if (tp->query_effect("psistorm"))
    FAIL("You are still controlling a psistorm!");

  if (tp->query_mp() < 150)
    FAIL("Too low on magic.");

  return 1;
}

int can_target(object tp, object tgt) {

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_psistorm(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *ai, *tgts, *items;
  class Effect psi;
  int rounds;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  ai = all_inventory(env) - ({ tp });

  /*
  tgts = filter(ai, (:
    $1->is_living() &&
    can_target($2, $1) &&
    !PARTY_D->same_party($1, $2) &&
    $1->query_owner() != $2 &&
    (object)$1->query_riding() != $2 &&
    (object)$2->query_riding() != $1
  :), tp);
  */

  tgts = filter(ai - query_allies(tp), (:
    $1->is_living() &&
    can_target($2, $1)
  :), tp);

  items = filter(ai, (:
    !$1->is_living() &&
    !$1->query_prevent_get() &&
    $1->get()
  :) );

  tp->add_mp(-(50+random(100)));
  tp->set_magic_round(2);

  message("magic", COL+"You gather your psionic energy."+RES, tp);

  switch (tp->query_skill("psionics")) {
    case 60*6 .. 500*6: rounds = 5; break;
    case 50*6 .. (60*6)-1: rounds = 4; break;
    case 40*6 .. (50*6)-1: rounds = 3; break;
    default: rounds = 2;
  }

  psi = new(class Effect);
  psi->hide = 1;
  psi->name = "psistorm";
  psi->caster = tp;
  psi->castername = tp->query_name();
  psi->target = tp;
  psi->desc = "You are controlling a storm of psionic energy!";
  psi->func = (: do_hit :);
  psi->endfunc = (: do_hit :);
  psi->maxhits = rounds;
  psi->interval = 1;
  psi->startroom = file_name(env);
  psi->misc = ({ tgts, items });

  tp->add_effect(psi);

  return 1;
}

void do_hit(class Effect psi) {
  object tp = psi->caster;
  mixed *info = psi->misc;
  object *tgts = info[0];
  object *items = info[1];
  int hit = psi->numhits;
  object env;
  string room = psi->startroom;
  string storm;

  if (!tp || !(env = environment(tp))) {
    psi->endfunc = 0;
    tp->remove_effect(psi);
    tp->set_magic_round(0);
    return;
  }

  if (file_name(env) != room) {
    message("info", "Your spell is interrupted!", tp);
    psi->endfunc = 0;
    tp->remove_effect(psi);
    tp->set_magic_round(0);
    return;
  }

  tgts = filter(tgts, (: $1 && file_name(environment($1)) == $2 :), room);
  if (!sizeof(tgts)) {
    psi->endfunc = 0;
    tp->remove_effect(psi);
    tp->set_magic_round(0);
    return;
  }
  items = filter(items, (: $1 && file_name(environment($1)) == $2 :), room);

  // only set_magic_round to disable all spellcasting through hit #2
  // extra hits will let caster do other things, including cast other spells
  if (hit == 1) {
    storm = COL2+"ps"+COL3+"ion"+COL2+"ic "+COL2+"st"+COL3+"o"+COL2+"rm";

    message("magic", COL+"You unleash a "+storm+COL+"!"+RES, tp);
    message("magic", COL+tp->query_cap_name()+" unleashes a "+storm+"!"+RES,
      env, tp);

    tp->set_magic_round(2);
  }

  foreach (object tgt in tgts) {
    int dmg, cost, rand;
    string into;
    object *temp, ob;
    
    if (!tp->kill_ob(tgt)) continue;

    dmg = BALANCE3_D->get_damage(tp, tgt, 3,
      ({ "psionics", "psionics", "magic attack" }),
      ({ "intelligence", "intelligence", "wisdom" }),
      ({ "intelligence", "wisdom" }) );

    dmg = dmg * 130 / 100;
    dmg = dmg - random(dmg / (6 - hit));

    cost = BALANCE3_D->get_cost(dmg, 3, "mp") * 70 / 100;

    if (tp->query_mp() < cost) {
      message("info", "Your spell falters as your magical reserves fail.", tp);
      message("info", tp->query_cap_name()+"'s spells falters.", env, tp);
      psi->endfunc = 0;
      tp->remove_effect(psi);
      return;
    }

    tp->add_mp(-cost);

    message("magic", COL2+"The "+COL3+"st"+COL2+"o"+COL3+"rm"+COL2+
                     " lifts you up and "+COL+"slams"+COL2+
                     " you into the ground!"+RES, tgt);
    message("magic", COL2+"The "+COL3+"st"+COL2+"o"+COL3+"rm"+COL2+
                     " lifts "+tgt->query_cap_name()+" up and "+
                     COL+"slams"+COL2+
                     " "+tgt->query_objective()+" into the ground!"+RES,
                     env, tgt);

    tgt->do_damage("random", dmg, DAMAGE_PHYSICAL | DAMAGE_IMPACT, 0, tp);

    temp = items + tgts - ({ tgt });
    rand = sizeof(temp) + 1;
    rand *= 2;
    rand = random(rand);
    
    // extra collision damage
    if (rand < sizeof(temp)) {
      ob = temp[rand];
      if (ob->is_living()) {
        into = ob->query_cap_name();
        dmg = 30 + ob->query_stats("constitution") * 7 / 10;
      }
      else {
        into = indefinite_article(ob->query_name());
        dmg = 30 + ob->query_weight()*4;
      }

      into = capitalize(into);
      message("magic", COL2+"You crash into "+tgt->query_cap_name()+"!", ob);
      message("magic", COL2+into+" crashes into you!", tgt);
      message("magic", COL2+into+" crashes into "+tgt->query_cap_name()+"!",
        env, ({ tgt, ob }) );

      tgt->do_damage("random", dmg, DAMAGE_PHYSICAL | DAMAGE_IMPACT, 0, tp);
      ob->do_damage("random", dmg, DAMAGE_PHYSICAL | DAMAGE_IMPACT, DAMAGE_NONLETHAL, tp);
    } // end extra collision damage

  } // end foreach

}

