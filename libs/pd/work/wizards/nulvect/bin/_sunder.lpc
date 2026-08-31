#include <std.h>
#include <daemons.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^WHITE%^"
#define MCOL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "white" &&
      tp->query_alignment() >= 0 &&
      tp->query_skill("faith") >= 34*5 &&
      (tp->query_skill("tail") >= 34*5 || tp->query_skill("claw") >= 34*5))
        return 1;
  return 0;
}

int ok_cast(object tp, object tgt) {
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("Thwack.\n");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_sunder(string str) {
  object tp=this_player();
  object tgt;
  string limb;
  int tpalign, tgtalign, aligndiff;
  int cost, dmg;
  int rank;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;

  // this ranges from 3000 to 0 now
  tpalign=tp->query_alignment()+1500;
  tgtalign=tgt->query_alignment()+1500;
  aligndiff=tpalign-tgtalign;
  
  if (tp->query_skill("tail") == tp->query_skill("claw")) {
    if (random(100) < 50) limb="tail";
    else limb="claw";
  }
  else if (tp->query_skill("tail") > tp->query_skill("claw"))
    limb="tail";
  else
    limb="claw";
  
  if (tpalign >= 2900) rank=4;
  else if (tpalign >= 2600) rank=3;
  else if (tpalign >= 2200) rank=2;
  else rank=1;
  
  dmg=BALANCE_D->get_damage(tp, tgt, rank,
      ({ limb, limb, "faith", "faith", "faith", "magic attack", "conjuring" }),
      ({ "wisdom", "wisdom", "strength" }),
      ({ "wisdom" }) );

  if (aligndiff > 0)
    dmg = dmg * (1.0+((to_float(aligndiff)/550)/10));
  if (aligndiff < 0)
    dmg = dmg + aligndiff/2;
  
  cost=tp->query_skill("faith");
  cost+=tp->query_skill(limb);
  cost+=tp->query_stats("wisdom");
  cost=(cost/3)*1.2;
  
  if (tp->query_sp() < cost/3)
    FAIL("You are too tired.\n");
  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.\n");
  
  tp->set_disable(1);
  if (dmg < 10) {
    message("info", "You try to sunder "+tgt->query_cap_name()+
                    ", but the holy powers won't come to you.",tp);
    tp->add_mp(-(cost/3));
    return 1;
  }
  
  tp->add_sp(-(cost/3+random(cost/25)));
  tp->add_mp(-(cost+random(cost/20)));

  if (tgtalign <= 1000 &&
      rank >= 3 &&
      tp->query_stat_bonus("dexterity") == 0) {
        tp->add_stat_bonus("dexterity", tp->query_skill("faith")/5, tp->query_level());
        message("info", MCOL+"You roar ferociously at the vileness of "+
                        tgt->query_cap_name()+"!"+RES, tp);
        message("info", MCOL+tp->query_cap_name()+" roars ferociously in outrage!"+RES,
                        environment(tp), tp);
  }

  message("info", COL+"You form a glowing lance of "+MCOL+"white light"+RES+
                  " on your "+limb+" and stab it into "+tgt->query_cap_name()+
                  "'s body!"+RES, tp);
  message("info", COL+tp->query_cap_name()+" forms a glowing lance of "+MCOL+
                  "white light"+RES+" on "+tp->query_possessive()+" "+limb+
                  " and stabs it into your body!", tgt);
  message("info", COL+tp->query_cap_name()+" forms a glowing lance of "+MCOL+
                  "white light"+RES+" on "+tp->query_possessive()+" "+limb+
                  " and stabs it into "+tgt->query_cap_name()+"'s body!",
                  environment(tp), ({tgt,tp}) );

  tgt->do_damage("torso",dmg);
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <sunder [living]>\n"
    "The holy white dragon can call the powers of goodness to enhance "

    "his natural weapons, making a lance of pure light on his tail or claws. "
    "The strength of this weapon is extremely dependent on the goodness of "
    "the user and the vileness of the target. Especially wicked opponents "
    "are further thwarted by the extra speed the user gains.",
    this_player());
}

