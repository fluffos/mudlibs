#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^WHITE%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "thief" &&
      tp->query_skill("stealing") >= 15*6)
    return 1;
  return 0;
}

int is_knife(object *blah) { return (blah->query_type() == "knife" ? 1 : 0); }

int ok_cast(object tp, object tgt) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("Alright, you got it.\n");

  if (sizeof(filter(tp->query_wielded(),"is_knife",this_object())) != sizeof(tp->query_wielded()))
    FAIL("You need to use a knife for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_snatch(string str) {
  object tp=this_player();
  object tgt;
  object item, *inv;

  int dex, knife, stealing;
  int tdex, tdef, tsteal;
  int cost, dmg;

  string limb;
  
  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  dex=tp->query_stats("dexterity");
  knife=tp->query_skill("knife");
  stealing=tp->query_skill("stealing");
  stealing+=tp->query_skill("stealth")*2/3;
  
  tdex=tgt->query_stats("dexterity");
  tdef=tgt->query_skill("defense");
  tsteal=tgt->query_skill("perception");
  tsteal+=tgt->query_property("snatch");
  
  dmg=dex*2+knife*2+random(tp->query_level()+10);
  dmg-=tdef/3;
  cost=dmg/9;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-cost);

  if (tdex*2/3 > dex) {
    message("combat",COL+"You take a swing at "+tgt->query_cap_name()+
                     " with your knife, but miss."+RES,tp);
    message("combat",COL+tp->query_cap_name()+" swings "+tp->query_possessive()+
                     " knife at "+tgt->query_cap_name()+", but misses."+RES,
                     environment(tp),({tp,tgt}));
    message("combat",COL+tp->query_cap_name()+" swings "+tp->query_possessive()+
                     " knife at you, but misses."+RES,tgt);
  }
  else {
    limb=tgt->return_target_limb();
    message("combat",COL+"You swing your knife at "+tgt->query_cap_name()+
                     " and slice "+tgt->query_objective()+" in the "+limb+"!"+RES,tp);
    message("combat",COL+tp->query_cap_name()+" swings "+tp->query_possessive()+
                     " knife at you and slices you in the "+limb+"!"+RES,tgt);
    message("combat",COL+tp->query_cap_name()+" swings "+tp->query_possessive()+
                     " knife at "+tgt->query_cap_name()+" and slices "+
                     tgt->query_objective()+" in the "+limb+"!"+RES,
                     environment(tp),({tp,tgt}));
    tgt->do_damage(limb,dmg);

    if (sizeof(inv=all_inventory(tgt)) == 0) {
      message("combat",COL+tgt->query_subjective()+" doesn't have anything to steal!"+RES,tp);
    }
    else {
      item=inv[random(sizeof(inv))];
      message("combat",COL+tp->query_cap_name()+" seems to quickly grab at "+tgt->query_cap_name()+"."+RES,
                       environment(tp),({tp,tgt}));
      if (tsteal > stealing) {
        message("combat",COL+"You try to snatch "+item->query_short()+
                         " from "+tgt->query_cap_name()+", but "+tgt->query_subjective()+
                         " sees your attempt!"+RES,tp);
        message("combat",COL+"You catch "+tp->query_cap_name()+" trying to steal something, "
                         "but you're too quick for "+tp->query_objective()+"."+RES,tgt);
      }
      else {
        message("combat",COL+"While "+tgt->query_cap_name()+" is distracted by the pain, "
                         "you snatch "+item->query_short()+" from him!"+RES,tp);
        item->set_theft(1);
        if(item->move(tp)) {
          message("drop","It is too heavy, and you drop it.",tp);
          message("drop",tp->query_cap_name()+" drops "+item->query_short()+".",environment(tp),tp);
          item->move(environment(tp));
        }
        item->set_theft(0);
        tgt->set_property("snatch",stealing/2 + tgt->query_stats("intelligence") + tsteal/3);

      }

    }
  }
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <snatch [living]>\n"
    "Thieves can attack someone and try to steal an item at the same time.\n"
    "Beware, as even the dumbest of targets will only fall for it a few times.",
    this_player());
}

