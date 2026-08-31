
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp &&
      (tp->query_class() == "fighter" ||
      member_array(tp->query_subclass(),
        ({"thug","thief","monk","druid","jester"}) ) != -1) &&
      tp->query_skill("melee") >= 30 &&
      tp->query_skill("attack") >= 30)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <headbutt [whom]>\n\n"
    "A basic unarmed fighting ability. "
    "You slam your head into the head of your opponent. "
    "Fighters and a few others learn this.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your head would pass right through!");

  if (!tgt)
    FAIL("Headbutt whom?");

  if (!living(tgt))
    FAIL("You unleash a headbutt on it, and wind up with a headache.");

  if (tgt == tp)
    FAIL("That is completely impossible.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_headbutt(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, rank, cost;
  int myhit, mystr, hisdodge, hisstr;
  string COL2 = "%^BOLD%^%^BLUE%^";
  string *skills;

  if (!abil()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_skill("melee") >= 40*5) rank=3;
  else if (tp->query_skill("melee") >= 20*5) rank=2;
  else rank=1;

  skills = ({ "attack", "attack", "melee", "melee", "melee" });
  switch (tp->query_subclass()) {
    case "warrior": case "ranger":
      skills += ({ "discipline" });
      COL2 = "%^GREEN%^";
    break;
    case "berserker":
      skills += ({ "melee", "ferocity" });
      COL2 = "%^ORANGE%^";
    break;
    case "antipaladin":
      skills += ({ "ferocity" });
      COL2 = "%^YELLOW%^";
    break;
    case "paladin":
      skills += ({ "valor" });
      COL2 = "%^YELLOW%^";
    break;
    case "thief":
      skills += ({ "agility" });
      COL2 = "%^BLUE%^";
    break;
    case "thug": case "monk":
      skills += ({ "melee" });
      COL2 = "%^ORANGE%^";
    break;
    case "jester":
      skills += ({ "entertainment" });
      COL2 = "%^BOLD%^%^GREEN%^";
    break;
    case "druid":
      COL2 = "%^BOLD%^%^GREEN%^";
    break;
    default:
  }

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    ({ "strength", "strength", "strength", "dexterity" }),
    ({ "strength" }) );

  cost = dmg/6.2;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->set_disable();
  
  myhit = tp->query_stats("dexterity");
  myhit += tp->query_skill("attack");
  hisdodge = tgt->query_stats("dexterity");
  hisdodge += tgt->query_skill("defense");
  if (rank > 1) {
    myhit += random(tp->query_skill("discipline")/3);
    myhit += random(tp->query_skill("agility")/3);
    myhit += random(tp->query_skill("entertainment")/4);
    hisdodge += random(tgt->query_skill("agility")/3);
  }
  
  mystr = tp->query_stats("strength");
  mystr += tp->query_stats("constitution");
  hisstr = tgt->query_stats("strength");
  hisstr += tgt->query_stats("constitution");

  if (myhit+random(15) < hisdodge) {
    message("combat", "You try to headbutt "+tgt->query_cap_name()+
      ", but miss.", tp);
    message("combat", tp->query_cap_name()+" tries to headbutt you, "
      "but misses.", tgt);
    message("combat", tp->query_cap_name()+" tries to headbutt "+
      tgt->query_cap_name()+", but misses.", env, ({tp, tgt}) );
    cost /= 3;
  }
  else {
    
    message("combat", "You bring your "+
      COL+"h"+COL2+"e"+COL+"a"+COL2+"d"+COL+" b"+COL2+"a"+COL+"c"+COL2+"k"+RES+
      " and "+COL2+"slam"+RES+" your forehead into "+tgt->query_cap_name()+
      "'s head!", tp);
    message("combat", tp->query_cap_name()+" brings "+tp->query_possessive()+" "+
      COL+"h"+COL2+"e"+COL+"a"+COL2+"d"+COL+" b"+COL2+"a"+COL+"c"+COL2+"k"+RES+
      " and "+COL2+"slams"+RES+" "+tp->query_possessive()+" forehead into "
      "your head!", tgt);
    message("combat", tp->query_cap_name()+" brings "+tp->query_possessive()+" "+
      COL+"h"+COL2+"e"+COL+"a"+COL2+"d"+COL+" b"+COL2+"a"+COL+"c"+COL2+"k"+RES+
      " and "+COL2+"slams"+RES+" "+tp->query_possessive()+" forehead into "+
      tgt->query_cap_name()+"'s head!", env, ({tp, tgt}) );

    // not strong enough, hurt the user a bit...
    if (mystr+random(25) < hisstr) {
      message("combat", "Your head rings with pain!", tp);
      message("combat", tp->query_cap_name()+" looks pained from the blow.",
        env, tp);
      tp->do_damage("head", dmg/6);
      tgt->do_damage("head", dmg/4);
    }

    else {
      tgt->do_damage("head", dmg);
    }

    tp->add_skill_points("melee", 10+random(dmg/12));
  }

  tp->add_sp(-(cost+random(cost/12)));

  return 1;
}

