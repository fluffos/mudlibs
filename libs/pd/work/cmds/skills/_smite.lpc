#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s)

#define RES "%^RESET%^"
#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define COL3 "%^BOLD%^%^RED%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "paladin" &&
      tp->query_skill("attack") >= 6*40 &&
      tp->query_skill("valor") >= 6*40 &&
      tp->query_skill("faith") >= 4*40)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <smite [foe]>\n\n"
    "A paladin can smite his evil enemy with a final devastating blow.\n"
    "Be wary, for this will not work on those aligned with good.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Alas, you are but a ghost!");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers!");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (!tgt)
    FAIL("Smite who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("How dishonorable.");

  if (tgt->query_alignment() > 500)
    FAIL(tgt->query_cap_name()+" is aligned with goodness!");

  if (!sizeof(weps))
    FAIL("You are not wielding anything!");

  if (tp->query_sp() < 100)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+"!");

  return 1;
}

int cmd_smite(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *weps;
  object wep;
  int dmg, spcost, mpcost, mod, dis;
  string wepname;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = tp->query_wielded();

  if (!can_cast(tp, tgt, weps)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "attack", "valor", "faith" }),
    ({ "strength", "dexterity" }),
    ({ "strength", "wisdom" }) );

  // range: 20 to about 201%
  mod = -((tgt->query_alignment() - 500)/11) + 20;
  dmg = dmg * mod / 100;

  // range: 50 to 375
  dmg += tp->query_alignment() / 4;

  spcost = BALANCE3_D->get_cost(dmg, 4, "sp") * 120 / 100;
  mpcost = BALANCE3_D->get_cost(dmg, 4, "mp") * 200 / 100;

  if (tp->query_sp() < spcost)
    FAIL("You are too tired.");
  if (tp->query_mp() < mpcost)
    FAIL("Too low on magic.");

  tp->kill_ob(tgt);

  wep = weps[random(sizeof(weps))];
  wepname = remove_article(strip_color(wep->query_short()));

  message("combat", COL+"You hold your "+wepname+" up to the heavens and it "+
    COL2+"glows"+COL+"!"+RES, tp);
  message("combat", COL+tp->query_cap_name()+" holds "+tp->query_possessive()+
    " "+wepname+" up to the heavens and it "+
    COL2+"glows"+COL+"!"+RES, env, tp);

  if (tgt->query_hp() > tgt->query_max_hp()*40/100 || dmg < tgt->query_hp()) {
    message("combat", "You swing with all your might, but miss your foe!\n"+
                      COL+"You are thrown off balance!"+RES, tp);
    message("combat", tp->query_cap_name()+" swings with all "+
      tp->query_possessive()+" might, but misses!", env, tp);
    spcost /= 2;
    mpcost /= 2;
    dis = 2+random(2);
  }
  else {
    message("combat", "You swing with all your might and "+COL+"SMITE"+RES+
      " "+tgt->query_cap_name()+" with a devastating blow!", tp);
    message("combat", tp->query_cap_name()+" swings with all "+
      tp->query_possessive()+" might and "+COL+"SMITES"+RES+
      " you with a devastating blow!", tgt);
    message("combat", tp->query_cap_name()+" swings with all "+
      tp->query_possessive()+" might and "+COL+"SMITES"+RES+
      " "+tgt->query_cap_name()+" with a devastating blow!", env, ({ tp, tgt }) );
    message("combat", COL3+"A spray of blood shoots forth as "+
      tgt->query_cap_name()+" is "+
      COL2+"cleaved"+COL3+" in two!", env, tgt);
    message("combat", COL3+"A spray of blood shoots forth as you are "+
      COL2+"cleaved"+COL3+" in two!", tgt);
    tgt->do_damage(tgt->query_torso(), dmg*3,
      DAMAGE_PHYSICAL | DAMAGE_FAITH | DAMAGE_HOLY | wep->query_damage_type(),
      DAMAGE_BYPASS_ARMOUR, tp);
    dis = 1;
  }

  tp->set_disable(dis);
  tp->add_sp(-spcost);
  tp->add_mp(-mpcost);

  return 1;
}

