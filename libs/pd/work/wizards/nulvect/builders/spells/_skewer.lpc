#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan" &&
      tp->query_skill("projectile") >= 55*5)
    return 1;
  return 0;
}

int is_proj(object *blah) { return (blah->query_type() == "projectile" ? 1 : 0); }

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
    FAIL("How foolish.\n");

  if (sizeof(filter(tp->query_wielded(),"is_proj",this_object())) != sizeof(tp->query_wielded()))
    FAIL("You cannot perform this attack properly with anything but a spear.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_skewer(string str) {
  object tp=this_player();
  object tgt;

  int strong, dex, att, proj;
  int tdex, tdef;
  int cost, dmg;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  strong=tp->query_stats("strength");
  dex=tp->query_stats("dexterity");
  att=tp->query_skill("attack");
  proj=tp->query_skill("projectile");
  
  tdex=tgt->query_stats("dexterity");
  tdef=tgt->query_skill("defense");

  dmg=strong*4+dex*2+att*2/3+proj*4/3+random(tp->query_level()+10);
  dmg-=tdex/2+tdef/3;
  cost=dmg/10;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-cost);

  if (tdex+tdef > dex+proj) {
    message("combat",COL+"You try to skewer "+tgt->query_cap_name()+
                     " with your spear, but miss."+RES,tp);
    message("combat",COL+tp->query_cap_name()+" tries to skewer "+tgt->query_cap_name()+
                     " with "+tp->query_possessive()+" spear, but misses."+RES,environment(tp),({tp,tgt}));
    message("combat",COL+tp->query_cap_name()+" tries to skewer you"
                     " with "+tp->query_possessive()+" spear, but misses."+RES,tgt);
  }
  else {
    message("combat",COL+"You thrust your spear at "+
                     tgt->query_cap_name()+" and skewer "+tgt->query_possessive()+" flesh!"+RES,tp);
    message("combat",COL+tp->query_cap_name()+" thrusts "+tp->query_possessive()+" spear at "+
                     tgt->query_cap_name()+" and skewers "+tgt->query_possessive()+" flesh!"+RES,
                     environment(tp),({tp,tgt}));
    message("combat",COL+tp->query_cap_name()+" thrusts "+tp->query_possessive()+" spear at "+
                     "you and skewers your flesh!"+RES, tgt);
    tgt->do_damage(tgt->return_target_limb(),dmg);
    
    if (tgt->query_hp() < 1) {
      message("combat",COL+"You twist the spear inside "+tgt->query_cap_name()+
                       "'s body and rip it out, leaving a bloody gaping wound."+RES,tp);
      message("combat",COL+tp->query_cap_name()+" twists the spear inside "+tgt->query_cap_name()+
                       "'s body and rips it out, leaving a bloody gaping wound."+RES,
                       environment(tp),({tp,tgt}));
      message("combat",COL+tp->query_cap_name()+" twists the spear inside your body "
                       "and rips it back out, leaving a bloody gaping wound."+RES,tgt);
      tgt->add_hp(-50);
    }
  }

  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <skewer [living]>\n"
    "An advanced thrusting attack with a spear, one of the kataan's specialties.",
    this_player());
}

