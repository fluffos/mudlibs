#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^BLACK%^"
#define MCOL "%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan" &&
      tp->query_skill("projectile") >= 20*5 &&
      tp->query_skill("faith") >= 20*6 &&
      tp->query_skill("magic attack") >= 20*5)
    return 1;
  return 0;
}

int is_proj(object *blah) { return (blah->query_type() == "projectile" ? 1 : 0); }

int is_undead(object tgt) {
  if (member_array(tgt->query_race(),
      ({"vampire","lich","zombie","ghost","wraith","wight",
      "spirit","undead","corpse","skeleton"})) != -1) {
    return 1;
  }
  return 0;
}

int ok_cast(object tp, object tgt) {
  int s;
  
  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("How foolish.\n");

  if ((s=sizeof(filter(tp->query_wielded(),"is_proj",this_object()))) < 1 ||
      s != sizeof(tp->query_wielded()))
    FAIL("You cannot perform this attack properly with anything but a spear.\n");
  
  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy with combat to take aim.\n");
  
  if (tgt->is_undead())
    FAIL("The undead have no blood to drain.\n");

  if (member_array("torso",tgt->query_limbs()) == -1)
    FAIL("You can't find anything to aim for on that.");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_bloodlance(string str) {
  object tp=this_player();
  object tgt;

  int strong, wis, faith, ma, proj;
  int twis, tdex, tmd;
  int spcost, mpcost, dmg, absorb;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  strong=tp->query_stats("strength");
  wis=tp->query_stats("wisdom");
  
  faith=tp->query_skill("faith");
  ma=tp->query_skill("magic attack");
  proj=tp->query_skill("projectile");

  twis=tgt->query_stats("wisdom");
  tdex=tgt->query_stats("dexterity");
  
  tmd=tgt->query_skill("magic defense");

  dmg=strong*2/3+proj/4+random(tp->query_level()+10);
  dmg-=tdex/4;

  absorb=wis*2+faith/2+ma/2+random(tp->query_level()+5);
  absorb-=twis/3+tmd/3;
  
  spcost=dmg/7;
  mpcost=absorb/6;
  
  if (tp->query_sp() < spcost)
    FAIL("You are too tired.\n");
  
  if (tp->query_mp() < mpcost)
    FAIL("You don't have enough magic.\n");

  tp->set_disable(1);
  tp->add_sp(-spcost);
  tp->add_mp(-mpcost);

  tgt->set_paralyzed(2,"Demonic powers hold you.","The demonic powers release you.");
  
  message("combat",COL+"You take aim and jab your spear into "+
                   tgt->query_cap_name()+"'s heart!",tp);
  message("combat",COL+tp->query_cap_name()+" suddenly jabs "+tp->query_possessive()+
                   " spear into "+tgt->query_cap_name()+"'s heart!"+RES,
                   environment(tp),({tp,tgt}));
  message("combat",COL+tp->query_cap_name()+" suddenly jabs "+tp->query_possessive()+
                   " spear into your heart!"+RES, tgt);
  tgt->do_damage("torso",dmg);

  message("magic",MCOL+"Rivulets of blood flow back along the shaft of your spear "
                  "and strengthen you!"+RES,tp);
  message("magic",MCOL+"Rivulets of blood flow out of your wound and into "+
                  tp->query_cap_name()+"!"+RES,tgt);
  message("magic",MCOL+"Rivulets of blood flow out of "+tgt->query_cap_name()+
                  " and into "+tp->query_cap_name()+"!"+RES,
                  environment(tp),({tp,tgt}));
  tgt->damage(absorb);
  tp->add_hp(absorb);
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <bloodlance [living]>\n"
    "Using a combination of his spear and demonic magic, a kataan can drain the life force "
    "from his enemies. This power requires a precise hit, so it can't be used during battle.",
    this_player());
}

