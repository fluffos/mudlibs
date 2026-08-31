
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^GREEN%^"
#define COLC COL+"%^B_RED%^"

inherit DAEMON;

string *trylimbs = ({ "head", "torso", "body", "arm", "horn", "front .+ leg" });

int abil() {
  object tp = this_player();
  if (tp->query_subclass() == "monk" &&
      tp->query_skill("attack") >= 5*27 && tp->query_skill("melee") >= 6*27)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <axekick [whom]>\n\n"
    "With this attack, the user first extends his leg straight up, "
    "then brings it down on an opponent, using his heel to cause damage.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your legs are not solid enough to do any damage.");

  if (!tgt)
    FAIL("Axekick whom?");

  if (!tgt->is_living())
    FAIL("You kick it.");

  if (tgt == tp)
    FAIL("You kick your leg straight up and manage to kick yourself in the face!\n"
         "Congratulations.");

  if (!tp->query_mobile())
    FAIL("Your body is hurt too badly to use kicking attacks!");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 60)
    FAIL("You are too tired.");

  return 1;
}

int cmd_axekick(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int dmg, cost, perc;
  string *limbs;
  string limb, mylimb;
  string mymsg, yourmsg, theirmsg;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 3,
    ({ "attack", "melee", "melee", "melee" }),
    ({ "strength", "dexterity", "dexterity" }),
    ({ "strength", "dexterity" }) );

  perc = COMBAT_D->combo(tp, "axekick");
  dmg = dmg * perc / 100;

  cost = dmg/8;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-cost);
  tp->set_disable();
  tp->kill_ob(tgt);

  limbs = regexp(tgt->query_limbs(), implode(trylimbs, "|"));
  limb = limbs[random(sizeof(limbs))];

  limbs = filter(tp->query_walking_limbs(), (: $2->query_is_limb($1) :), tp);
  mylimb = limbs[random(sizeof(limbs))];

  if (perc > 100) {
    mymsg = COL+"You "+COLC+"jump into the air"+COL+", "+
            COL2+"flip"+COL+" forward, and "+COLC+"hammer"+
            COL+" your "+mylimb+" into "+tgt->query_cap_name()+"!"+RES;

    yourmsg = COL+tp->query_cap_name()+" "+COLC+"jumps into the air"+COL+", "+
              COL2+"flips"+COL+" forward, and "+COLC+"hammers"+
              COL+" "+tp->query_posessive()+" "+mylimb+
              " into your "+limb+"!"+RES;

    theirmsg = COL+tp->query_cap_name()+" "+COLC+"jumps into the air"+COL+", "+
               COL2+"flips"+COL+" forward, and "+COLC+"hammers"+
               COL+" "+tp->query_posessive()+" "+mylimb+
               " into "+tgt->query_cap_name()+"!"+RES;
  }
  else {
    mymsg = COL+"You "+COL2+"lift"+COL+" your "+mylimb+" up, "
            "then bring it down "+COL2+"hard"+COL+" on "+tgt->query_cap_name()+
            "'s "+limb+"!";
    yourmsg = COL+tp->query_cap_name()+" "+COL2+"lifts"+COL+" "+
              tp->query_possessive()+" "+mylimb+" up, "
              "then brings it down "+COL2+"hard"+COL+" on your "+limb+"!";
    theirmsg = COL+tp->query_cap_name()+" "+COL2+"lifts"+COL+" "+
               tp->query_possessive()+" "+mylimb+" up, "
               "then brings it down "+COL2+"hard"+COL+" on "+
               tgt->query_cap_name()+"'s "+limb+"!";
  }

  message("combat", mymsg, tp);
  message("combat", yourmsg, tgt);
  message("combat", theirmsg, env, ({ tp, tgt }) );

  tgt->do_damage(limb, dmg);

  return 1;
}
