
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"

#define COL2 RES+"%^RED%^"
#define COL3 "%^YELLOW%^"

inherit DAEMON;

int SKILL_REQ = 25*5;
mapping wep_types = ([
  "blade" : "%^BOLD%^%^WHITE%^",
  "flail" : "%^MAGENTA%^",
  "projectile" : "%^YELLOW%^",
]);

void do_puncture_hit(mixed *args);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("attack") >= 25*6 &&
      tp->query_skill("ferocity") >= 25*6 &&
      // if any of the weapon types are >= SKILL_REQ
      sizeof(filter(keys(wep_types), (: $2->query_skill($1) >= $(SKILL_REQ) :), tp)))
         return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <puncture [victim]>\n\n"
    "After stabbing or entangling his foe, an antipaladin can cause Abyssal "
    "thorns to sprout from his weapon, which cause terrible bleeding and "
    "internal damage.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are in no state to do that.");

  if (!tgt)
    FAIL("Puncture who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("Such a waste of power.");

  if (!sizeof(weps))
    FAIL("You are not wielding a suitable weapon!");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  if (tp->query_mp() < 100)
    FAIL("Too low on magic.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_puncture(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, wep;
  object *weps;
  string type, wepname, limb;
  string mymsg, yourmsg, theirmsg;
  string COL;
  int rank, sp_cost, mp_cost, dmg, bleed, bodydam, dtype;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = tp->query_wielded();
  weps = filter(weps, (:
    $3[$1->query_type()] &&
    $2->query_skill($1->query_type()) >= SKILL_REQ
  :), tp, wep_types);

  if (!can_cast(tp, tgt, weps)) return 0;

  wep = weps[random(sizeof(weps))];
  type = wep->query_type();
  wepname = remove_article(strip_color(replace_string(wep->query_short(), " (wielded)", "")));
  limb = tgt->return_target_limb();
  COL = wep_types[type];

  switch (tp->query_level()) {
    case 1..24:
    case 25..34:
      rank = 2;
    break;

    case 35..49:
      rank = 3;
    break;

    default:
      rank = 4;
  }

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "attack", type, "ferocity", "magic attack" }),
    ({ "strength" }),
    ({ "wisdom" }) );

  dmg = dmg * 110 / 100;
  bleed = dmg * 20 / 100;
  bodydam = 3;
  if (!tgt->is_player())
    bodydam *= tgt->query_level();
  bodydam = dmg / bodydam;

  sp_cost = BALANCE3_D->get_cost(dmg, rank, "sp");
  if (tp->query_sp() < sp_cost)
    FAIL("You are too tired.");

  mp_cost = BALANCE3_D->get_cost(dmg+bleed+bodydam, rank, "mp");
  if (tp->query_mp() < mp_cost)
    FAIL("Too low on magic.");

  tp->add_sp(-sp_cost);
  tp->set_disable(1);
  tp->kill_ob(tgt);

  switch (type) {
    case "blade":
    case "projectile":
      dtype = DAMAGE_PIERCE;
      message("combat", "You "+COL2+"stab"+RES+" your "+COL+wepname+COL2+
                        " deep "+RES+"into "+tgt->query_cap_name()+
                        "'s "+limb+"!", tp);
      message("combat", tp->query_cap_name()+" "+COL2+"stabs"+RES+" "+
                        tp->query_possessive()+" "+COL+wepname+COL2+
                        " deep "+RES+"into your "+limb+"!", tgt);
      message("combat", tp->query_cap_name()+" "+COL2+"stabs"+RES+" "+
                        tp->query_possessive()+" "+COL+wepname+COL2+
                        " deep "+RES+"into "+tgt->query_cap_name()+
                        "'s "+limb+"!", env, ({ tp, tgt }) );
    break;

    case "flail":
      dtype = wep->query_damage_type();
      bodydam = bodydam * 60 / 100;
      bleed = bleed * 170 / 100;
      message("combat", "You "+COL2+"whip"+RES+" "+tgt->query_cap_name()+
                        " with your "+COL+wepname+RES+", "+COL2+"tangling"+RES+
                        " it around "+tgt->query_possessive()+" "+limb+"!",
                        tp);
      message("combat", tp->query_cap_name()+" "+COL2+"whips"+RES+" you"
                        " with "+tp->query_possessive()+" "+COL+wepname+RES+
                        ", "+COL2+"tangling"+RES+
                        " it around your "+limb+"!",
                        tgt);
      message("combat", tp->query_cap_name()+" "+COL2+"whips"+RES+
                        " "+tgt->query_cap_name()+
                        " with "+tp->query_possessive()+" "+COL+wepname+RES+
                        ", "+COL2+"tangling"+RES+
                        " it around "+tgt->query_cap_name()+"'s "+limb+"!",
                        env, ({ tp, tgt }) );

    break;
  }

  yourmsg = COL3+"Large twisted "+COL2+"thorns"+COL3+" sprout from the "+
            COL+wepname+COL3+", puncturing through your skin!"+RES;
  mymsg = COL3+"Large twisted "+COL2+"thorns"+COL3+" sprout from the "+
          COL+wepname+COL3+", puncturing through "+
          tgt->query_cap_name()+"'s skin!"+RES;
  theirmsg = mymsg;

  tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | dtype, 0, tp);

  call_out("do_puncture_hit", 2, ({
    tp, tgt, dmg, bleed, bodydam, mp_cost, limb, mymsg, yourmsg, theirmsg
  }) );

  return 1;
}

void do_puncture_hit(mixed *args) {
  object tp = args[0];
  object tgt = args[1];
  int dmg = args[2];
  int bleed = args[3];
  int bodydam = args[4];
  int mp_cost = args[5];
  string limb = args[6];
  string mymsg = args[7];
  string yourmsg = args[8];
  string theirmsg = args[9];
  object env;

  if (!tp || !tgt) return;

  env = environment(tp);

  if (!env || environment(tgt) != env) {
    message("info", "Your foe has escaped!", tp);
    return;
  }

  if (env->query_property("no magic") || env->query_property("no attack")) {
    message("info", "Some force prevents your magic!", tp);
    return;
  }

  if (!tgt->query_is_limb(limb)) {
    message("info", "You retrieve your weapon from "+tgt->query_cap_name()+"'s "
                    "severed "+limb+".", tp);
    return;
  }

  if (tp->query_mp() < mp_cost) {
    message("info", "Too low on magic.", tp);
    return;
  }

  tp->add_mp(-mp_cost);
  tp->set_magic_round(1);

  message("magic", mymsg, tp);
  message("magic", yourmsg, tgt);
  message("magic", theirmsg, env, ({ tp, tgt }) );

  tgt->do_damage(limb, dmg, DAMAGE_FAITH | DAMAGE_PIERCE, DAMAGE_NO_SEVER, tp);
  tgt->do_damage(limb, bodydam, DAMAGE_FAITH | DAMAGE_PIERCE | DAMAGE_UNHOLY, DAMAGE_NO_HP | DAMAGE_NO_SEVER, tp);
  tgt->add_bleeding(bleed);

}

