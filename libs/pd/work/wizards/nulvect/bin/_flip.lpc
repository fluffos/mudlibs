
#include <std.h>
#include <daemons.h>
#include <rest.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^WHITE%^"
#define COL2 "%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_level() >= 6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <flip [who]>\n\n"
    "A quick acrobatic attack where you do a backflip and "
    "kick your opponent hard.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You flip around in the air.");

  if (!tgt)
    FAIL("Do a flip at whom?");

  if (!tgt->is_living())
    FAIL("Alas, it would not appreciate your talents.");

  if (tgt == tp)
    FAIL("You do an amazing flip and land on your head.");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_flip(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, dmg, cost;
  string limb, limbdisp;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 20)
    rank = 2;
  else
    rank = 1;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "entertainment", "entertainment", "attack" }),
    ({ "dexterity", "dexterity", "strength" }) );

  dmg = dmg*8/10;

  cost = dmg/10;
  cost += random(cost/6);

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-cost);
  tp->set_disable();

  if (dmg < 10) {
    message("combat", "You flip backwards, miss "+tgt->query_cap_name()+
      ", and fall on your face.", tp);
    message("combat", tp->query_cap_name()+" flips backwards and falls "
      "on "+tp->query_possessive()+" face.", env, tp);
    tp->set_rest_type(LAY);
    return 1;
  }

  if (tgt->query_is_limb("head")) {
    limb = "head";
    limbdisp = "face";
    dmg += random(25);
  }
  else {
    limb = tgt->return_target_limb();
    limbdisp = limb;
  }

  message("combat", "You "+COL+"flip "
    "b"+COL2+"ac"+COL+"kw"+COL2+"ard"+COL+"s"+RES+
    ", kicking "+tgt->query_cap_name()+" in the "+limbdisp+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"flips "
    "b"+COL2+"ac"+COL+"kw"+COL2+"ard"+COL+"s"+RES+
    "and kicks you in the "+limbdisp+"!", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"flips "
    "b"+COL2+"ac"+COL+"kw"+COL2+"ard"+COL+"s"+RES+
    "and kicks "+tgt->query_cap_name()+" in the "+limbdisp+"!",
    env, ({ tp, tgt }) );

  if (random(100) > 60 && limb == "head" &&
      tp->query_stats("dexterity") > tgt->query_stats("constitution") &&
      !tgt->query_rest_type()) {
        message("combat", "Your vision goes blurry and you fall over!", tgt);
        message("combat", tgt->query_cap_name()+" staggers and falls over.",
            env, tgt);
        tgt->set_rest_type(LAY);
        tgt->set_paralyzed(1, "You are dazed.");
  }

  tgt->do_damage(limb, dmg);

  return 1;
}
