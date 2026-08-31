#include <std.h>
#include <daemons.h>

#define TYPE "knife"
#define COL "%^RED%^"
#define RES "%^RESET%^"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_skill(TYPE) >= 25*5 &&
      tp->query_skill("agility") >= 25*6 &&
      tp->query_skill("murder") >= 100 &&
      member_array(tp->query_subclass(), ({"thief","assassin"}) ) != -1)
    // level 25 assassins, 30 thieves
        return 1;
  return 0;
}

int ok_cast(object tp, object tgt, object *weps, string *limbs) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You cannot attack yourself.\n");

  if (!sizeof(weps))
    FAIL("You need to use a knife for that.\n");

  if (!sizeof(limbs))
    FAIL(capitalize(tgt->query_subjective())+
         " doesn't have a hand to aim for!\n");

  if (tgt->query("debilitate_abil"))
    FAIL(capitalize(tgt->query_subjective())+
         " has already been debilitated!\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_debilitate(string str) {
  object tp=this_player();
  object tgt, tgtwep;
  object *weps;
  string wep;
  string *limbs;
  int cost, dmg, rank;
  mapping limbinfo;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );
  
  if (tgt) {
    limbs=tgt->query_limbs_wielded();
    if (!sizeof(limbs))
      limbs=tgt->query_wielding_limbs();
  }

  if (!ok_cast(tp,tgt,weps,limbs)) return 0;

  rank=2;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, "murder", "agility" }),
        ({ "dexterity" }) );
  
  dmg = dmg*2/3;

  cost=dmg/9;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  tgtwep=tgt->query_weapon(limbs[0]);

  if (tp->query_stats("dexterity")*2/3+tp->query_skill("agility")/5+random(20) <
      tgt->query_stats("dexterity")/2+tgt->query_skill("defense")/3) {

    message("combat","You miss your attempt to stab "+tgt->query_cap_name()+
                     " in the hand.", tp);

    message("combat",tp->query_cap_name()+" misses an attempt to stab "+
                     tgt->query_cap_name()+".", environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" misses an attempt to stab you.", tgt);
  }
  else {
    message("combat","You "+COL+"stab"+RES+" your dagger into "+
                     tgt->query_cap_name()+"'s "+COL+limbs[0]+RES+"!", tp);
    
    message("combat",tp->query_cap_name()+" "+COL+"stabs"+RES+" "+
                     tp->query_possessive()+" dagger into your "+
                     COL+limbs[0]+RES+"!\n"
                     "Your "+limbs[0]+" goes limp and numb with pain!", tgt);

    message("combat",tp->query_cap_name()+" "+COL+"stabs"+RES+" "+
                     tp->query_possessive()+" dagger into "+tgt->query_cap_name()+
                     "'s "+COL+limbs[0]+RES+"!", environment(tp), ({ tp, tgt }) );

    if (tgtwep) {
      tgtwep->unequip();
      message("combat", "You drop your "+tgtwep->query_name()+".", tgt);
      message("combat", tgt->query_cap_name()+" drops "+tgt->query_possessive()+
                        " "+tgtwep->query_name()+".", environment(tgt), tgt);
      tgtwep->move(environment(tgt));
    }

    // this should not be this difficult, but since set_wielding_limbs
    // actually only _adds_ wielding limbs, we have to completely remove
    // the hand and recreate it before anyone notices in order to remove
    // the "wieldable" flag

    limbinfo = tgt->query_body_mapping()[limbs[0]];

    // this loop and the ac stuff is just in case something has natural AC on this limb
    foreach (object ar in limbinfo["armour_ob"])
      tgt->remove_armour_from_limb(ar, ({ limbs[0] }) );
    limbinfo["ac"] = tgt->query_ac(limbs[0]);
    
    tgt->remove_limb(limbs[0]);
    tgt->add_limb(limbs[0], limbinfo["limb_ref"], limbinfo["max_dam"], limbinfo["damage"], limbinfo["ac"]);

    foreach (object ar in limbinfo["armour_ob"])
      tgt->equip_armour_to_limb(ar, ({ limbs[0] }) );
    
    tgt->do_damage(limbs[0], dmg);

    // if the hand got severed from damage, don't even bother with this part...
    if (tgt->query_is_limb(limbs[0])) {
      tgt->set("debilitate_abil",1);
      call_out("reenable",60, ({tgt,limbs[0]}) );
    }
    
  }
  
  return 1;
}

void reenable(mixed *args) {
  object tgt=args[0];
  string limb=args[1];
  if (tgt && tgt->query("debilitate_abil") && tgt->query_is_limb(limb)) {
    tgt->set("debilitate_abil",0);
    tgt->add_wielding_limb(limb);
    message("info","You feel like you can use your "+limb+" again.", tgt);
  }
}

void help() {
  message("help","\n"
    "Syntax: <debilitate [living]>\n\n"
    "A nasty ability that assassins and even some thieves practice, "
    "this attack aims to put a dagger through your enemy's hand, "
    "rendering it unable to hold a weapon for a while.",
    this_player());
}

