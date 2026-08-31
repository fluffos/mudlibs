#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s);
#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define MCOL "%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan" &&
      tp->query_skill("projectile") >= 20*6 &&
      tp->query_skill("faith") >= 20*6 &&
      tp->query_skill("magic attack") >= 20*5)
    return 1;
  return 0;
}

string type() { return "attack"; }

int is_undead(object tgt) {
  if (tgt->query_undead() || member_array(tgt->query_race(),
      ({"vampire","lich","zombie","ghost","wraith",
      "spirit","undead","corpse","skeleton","ghoul",
      "wight","ghast",})) != -1)
        return 1;
  return 0;
}

int ok_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;
  
  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("Drain whom?\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("How foolish.\n");

  if (!sizeof(weps))
    FAIL("You need a spear for that.\n");
  
  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy with combat to take aim.\n");
  
  if (is_undead(tgt))
    FAIL("The undead have no blood to drain.\n");

  if (member_array("torso",tgt->query_limbs()) == -1)
    FAIL("You can't find anything to aim for on that.");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_bloodlance(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;

  int spcost, mpcost, absorb;
  int pdmg, mdmg;

  if (!abil()) return 0;

  if (str) tgt=present(str,environment(tp));

  tp->clean_up_attackers();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "projectile" :) );
  
  if (!ok_cast(tp,tgt,weps)) return 0;

  pdmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({"projectile","projectile","attack"}),
    ({"strength","strength","dexterity"}) );

  pdmg /= 2;

  if (tp->query_property("stealth")) {
    pdmg = pdmg*3/2;
    tp->remove_property("stealth");
  }
  if (tp->query_invis())
    pdmg = pdmg*5/3;

  spcost = pdmg/10;

  mdmg = BALANCE3_D->get_damage(tp, tgt, 3,
    ({"faith","magic attack"}),
    ({"wisdom","intelligence"}),
    ({"magic attack"}) );

  mdmg = mdmg*3/4;
  
  absorb = (mdmg/2)+random(mdmg/4);
  
  mpcost = mdmg/5;
  
  if (tp->query_sp() < spcost)
    FAIL("You are too tired.\n");
  
  if (tp->query_mp() < mpcost)
    FAIL("You don't have enough magic.\n");

  tp->set_disable(1);
  tp->add_sp(-spcost);
  tp->add_mp(-mpcost);

  message("combat","You "+COL+"take aim"+RES+" and "+
                   COL2+"j"+RES+"a"+COL2+"b"+RES+
                   " your "+COL+"spear"+RES+" into "+tgt->query_cap_name()+
                   "'s "+COL2+"heart"+RES+"!",tp);
  
  message("combat",tp->query_cap_name()+" suddenly "+
                   COL2+"j"+RES+"a"+COL2+"b"+RES+"s "+tp->query_possessive()+
                   " "+COL+"spear"+RES+" into "+tgt->query_cap_name()+"'s "+
                   COL2+"heart"+RES+"!",
                   environment(tp),({tp,tgt}));
  
  message("combat",tp->query_cap_name()+" suddenly "+
                   COL2+"j"+RES+"a"+COL2+"b"+RES+"s "+tp->query_possessive()+
                   " "+COL+"spear"+RES+" into your "+COL2+"heart"+RES+"!", tgt);
  tgt->do_damage("torso",pdmg);

  if (tp->query_invis()) tp->set_invis();

  if (alignment_ok(tp)) {
    message("magic",MCOL+"Rivulets of blood flow back along the shaft of your spear "
                    "and strengthen you!"+RES,tp);
    message("magic",MCOL+"Rivulets of blood flow out of your wound and into "+
                    tp->query_cap_name()+"!"+RES,tgt);
    message("magic",MCOL+"Rivulets of blood flow out of "+tgt->query_cap_name()+
                    " and into "+tp->query_cap_name()+"!"+RES,
                    environment(tp),({tp,tgt}));

    tgt->set_paralyzed(2,"Demonic powers hold you.","The demonic powers release you.");
    
    // this would be better as a pure hp hit without a limb
    tgt->do_damage("torso", mdmg);
    tp->add_hp(absorb);
  }

  return 1;
}

void help() {
  message("help",
    "Syntax: <bloodlance [living]>\n\n"
    "Using a combination of his spear and demonic magic, a kataan can drain the life force "
    "from his enemies. This power requires a precise hit, so it can't be used during battle.",
    this_player());
}

