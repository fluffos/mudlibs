
#include <std.h>
#include <daemons.h>

#define COL "%^BLUE%^"
#define COL2 "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "thug" &&
      tp->query_skill("melee") >= 6*22 &&
      tp->query_skill("murder") >= 5*22)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <snap [living]>\n\n"
    "An attempt to sneak behind someone and snap his neck.\n"
    "This can only be done when you're not in combat.",
    this_player() );
}

string type() { return "attack"; }

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("You can't do that as a ghost.\n");

  if (environment(tp)->query_property("no attack"))
    FAIL("You may not attack here.\n");

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");

  if (!tgt)
    FAIL("Snap whose neck?\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tgt == tp)
    FAIL("You grab at your own neck, but just look stupid doing it.\n");

  if (sizeof(tp->query_wielded()))
    FAIL("Your weapons make it impossible to snap anybody's neck.\n");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting!\n");

  if (member_array(tgt, tp->query_hunted()) != -1)
    FAIL("You have lost the element of surprise!\n");

  if (!(tgt->query_is_limb("head")))
    FAIL(tgt->query_subjective()+" does not have a neck.\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");
  
  return 1;
}

int cmd_snap(string str) {
  object tp=this_player();
  object tgt;
  int caught=0;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, environment(tp));

  if (!can_cast(tp, tgt)) return 0;
  
  if (tgt->query_skill("perception") + tgt->query_stats("wisdom") >
      tp->query_skill("stealth") + tp->query_stats("dexterity")/3) {
        message("combat", tp->query_cap_name()+" attempts to sneak behind "
                          "you unnoticed!", tgt);
        caught = tgt->query_skill("perception")-tp->query_skill("stealth");
        if (caught < 10) caught=10;
  }

  tp->set_paralyzed(1, "You are concentrating on snapping "+
                       tgt->query_cap_name()+"'s neck!");

  message("combat", "You "+COL+"sneak"+RES+" around "+COL+"behind"+RES+" "+
                    tgt->query_cap_name()+".", tp);

  tp->add_alignment(-5);
  
  call_out("do_dmg", 2, ({tp, tgt, caught}) );

  return 1;

}

void do_dmg(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  int caught=args[2];
  object env;
  int dmg, rank, mod;
  int dex;

  if (!tp) return;
  
  env=environment(tp);

  if (!tgt || environment(tgt) != env ||
      (userp(tgt) && !interactive(tgt))) {
        message("info", "Your target is not here.", tp);
        return;
  }
  
  if (!(tp->kill_ob(tgt))) {
    message("info", "You may not attack "+tgt->query_objective()+".",tp);
    return;
  }
  
  if (tgt->query_stats("dexterity")/2 + random(tgt->query_stats("dexterity")) >
      tp->query_stats("dexterity")+5-caught) {
        message("combat", "You fail to grab "+tgt->query_cap_name()+
                          "'s neck!", tp);
        message("combat", tp->query_cap_name()+" misses an attempt to "
                          "break your neck!", tgt);
        message("combat", tp->query_cap_name()+" misses an attempt to "
                          "break "+tgt->query_cap_name()+"'s neck!", env, ({tp,tgt}) );
        return;
  }

  if (tp->query_level() >= 36)
    rank=4;
  else if (tp->query_level() >= 20)
    rank=3;
  else
    rank=2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
          ({"murder", "melee", "melee", "attack" }),
          ({"strength", "strength", "dexterity"}),
          ({"strength", "dexterity"}) );

  dex = tp->query_stats("dexterity");
  mod = 2.18 + (0.04 * to_float(dex/5));
  if (mod > 3.8) mod = 3.8;

  if (tp->query_level() >= 55)
    mod *= 1.33;

  if (userp(tgt) && userp(tp) &&
      tgt->query_stats("dexterity")*2/3+tgt->query_stats("constitution")*2/3 >
      dex/2+tp->query_stats("strength")/2+tp->query_skill("agility")/5)
        mod *= 0.67;
  else if (tgt->query_level() > tp->query_level()*8/10)
    mod *= 0.9;

  dmg = to_int(to_float(dmg) * mod);

  dmg += random(dex*3);
  dmg -= caught*3;
  
  if (dmg >= tgt->query_hp()) {
    message("combat", "You "+COL+"grab"+RES+" "+tgt->query_cap_name()+"'s head "
                      "and "+COL+"twist"+RES+" it "+COL2+"violently"+RES+"!", tp);
    message("combat", tp->query_cap_name()+" "+COL+"grabs"+RES+" you by the "
                      "head and "+COL+"twists"+RES+" it "+COL2+"violently"+RES+
                      ", causing your neck to "+COL2+"snap"+RES+"!", tgt);
    tgt->do_damage("head", dmg*2);
    message("combat", tgt->query_cap_name()+" appears to go "+COL+"limp"+RES+
                      " and "+COL+"falls"+RES+" to the ground!", env, tgt);

    tgt->set_paralyzed(4, "Your neck is broken!");
    
    tp->add_skill_points("murder", dmg/50);
    tp->add_skill_points("melee", dmg/50);
    tp->add_skill_points("attack", dmg/50);
    
    tp->add_sp(-to_int(mod*7+random(dmg/85)));
  }
  else {
    message("combat", "You "+COL+"grab"+RES+" "+tgt->query_cap_name()+"'s head "
                      "and "+COL+"twist"+RES+", but it doesn't seem to do anything.", tp);
    message("combat", tp->query_cap_name()+" "+COL+"grabs"+RES+" your head and "+
                      COL+"twists"+RES+" it, but nothing happens.", tgt);
    tp->add_sp(-(3+random(3)));
    tp->set_disable();
    tp->add_skill_bonus("defense", -(tp->query_skill("defense")), 2);
  }

  if (tgt->query_hp() < 1)
    tgt->heart_beat();

}

