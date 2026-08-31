#include <std.h>
#include <daemons.h>
#include <rest.h>
#include <damage_types.h>
#include <damage.h>

#define TYPE "flail"
#define COL "%^MAGENTA%^"
#define RES "%^RESET%^"
#define FAIL(s) return notify_fail(s)

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && (tp->query_subclass() == "gypsy" ||
             tp->query_subclass() == "antipaladin") &&
      tp->query_skill(TYPE) >= 150 && tp->query_skill("attack") >= 150)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help","\n"
    "Syntax: <flog [living]>\n\n"
    "An advanced flail ability where the user strikes his target several "
    "times with a whip, causing lots of pain.",
    this_player());
}

int ok_cast(object tp, object tgt, object *weps) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("Flog whom?\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You cannot attack yourself.\n");

  if (!sizeof(weps))
    FAIL("You need to use a whip for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_flog(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, limb;
  int rank;
  int wc;
  int hits;
  int dtype, dflags;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );
  
  if (!ok_cast(tp,tgt,weps)) return 0;

  foreach (object w in weps)
    wc += w->query_wc();
  wc = wc / sizeof(weps);
  
  if (tp->query_skill(TYPE) >= 230) rank=4;
  else rank=3;
  
  wep = remove_article(weps[0]->query_name());
  dtype = weps[0]->query_damage_type();
  dflags = weps[0]->query_damage_flags();
  limb = tgt->return_limb();
  tp->set_disable(1);

  hits = 1;
  hits += tp->query_stats("dexterity")/55;
  if (tp->query_skill("ferocity") >= 150)
    hits += (tp->query_skill("ferocity")-150)/60;
  if (tp->query_skill("entertainment") >= 120)
    hits += (tp->query_skill("entertainment")-120)/40;

  for (int hit = 0; hit < hits; hit++) {

    int dmg, cost;

    dmg=BALANCE3_D->get_damage(tp, tgt, rank,
          ({ TYPE, TYPE, TYPE, "attack", "attack", "ferocity", "entertainment" }),
          ({ "strength", "dexterity", "dexterity" }),
          ({ "strength", "dexterity", "dexterity" }) );

    dmg = dmg/(hit < 2 ? 2 : 5);
    
    dmg += wc*2;

    cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 9 / 10;
    
    if (tp->query_sp() < cost) {
      if (hit == 0)
        FAIL("You are too tired.\n");
      else {
        message("combat", "You are too tired to keep flogging "+
                          tgt->query_cap_name()+".", tp);
        return 1;
      }
    }

    tp->add_sp(-(cost+random(cost/10)));

    if (dmg < 20) {
      message("combat","You swing your "+wep+" at "+tgt->query_cap_name()+
                       " but miss.", tp);

      message("combat",tp->query_cap_name()+" swings "+tp->query_possessive()+
                       " "+wep+" at "+
                       tgt->query_cap_name()+" but misses.",
                       environment(tp), ({ tp, tgt }) );
      
      message("combat",tp->query_cap_name()+" swings "+tp->query_possessive()+
                       " "+wep+" at you but misses.", tgt);
    }
    else {
      if (hit == 0) {
        message("combat","You "+COL+"FLOG"+RES+" "+tgt->query_cap_name()+" "
                         COL+"fiercely"+RES+" in the "+limb+"!", tp);
        
        message("combat",tp->query_cap_name()+" "+COL+"FLOGS"+RES+" you "
                         COL+"fiercely"+RES+" in the "+limb+"!", tgt);

        message("combat",tp->query_cap_name()+" "+COL+"FLOGS"+RES+" "+
                         tgt->query_cap_name()+" "+COL+"fiercely"+RES+
                         " in the "+limb+"!", environment(tp), ({tp,tgt}));
      }
      else {
        switch (random(3)) {
          case 0:
            message("combat", "You swing the whip back over your head and "+
                              COL+"FLOG"+RES+" "+tgt->query_objective()+" again!", tp);
            message("combat", tp->query_cap_name()+" swings the whip back over "+
                              tp->query_possessive()+" head and "+COL+"FLOGS"+RES+
                              " you again!", tgt);
            message("combat", tp->query_cap_name()+" swings the whip back over "+
                              tp->query_possessive()+" head and "+COL+"FLOGS"+RES+
                              " "+tgt->query_objective()+" again!", environment(tp), ({tp,tgt}));
          break;

          case 1:
            message("combat", "You pull the whip back quickly and "+
                              COL+"FLOG"+RES+" "+tgt->query_objective()+" again!", tp);
            message("combat", tp->query_cap_name()+" pulls the whip back quickly "
                              "and "+COL+"FLOGS"+RES+" you again!", tgt);
            message("combat", tp->query_cap_name()+" pulls the whip back quickly "
                              "and "+COL+"FLOGS"+RES+
                              " "+tgt->query_objective()+" again!", environment(tp), ({tp,tgt}));
          break;

          case 2:
            message("combat", "You jerk back on the whip and "+
                              COL+"FLOG"+RES+" "+tgt->query_objective()+" again!", tp);
            message("combat", tp->query_cap_name()+" jerks back on the whip "
                              "and "+COL+"FLOGS"+RES+" you again!", tgt);
            message("combat", tp->query_cap_name()+" jerks back on the whip "
                              "and "+COL+"FLOGS"+RES+
                              " "+tgt->query_objective()+" again!", environment(tp), ({tp,tgt}));
          break;
        }
      }
      
      tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | dtype, dflags, tp);

      if (rank == 4 && random(100) < 40 &&
          tp->query_stats("strength")+random(20)-random(20) > tgt->query_stats("constitution")) {
        if (tgt->query_rest_type() == SIT) {
          message("combat","You fall to the ground in agony.", tgt);
          message("combat",tgt->query_cap_name()+" falls to the ground in agony.",
                           environment(tp), tgt);
          tgt->set_rest_type(LAY);
          if (random(100) < 40)
            tgt->set_paralyzed(2, "You are in too much pain to move.");
        }
        else if (!(tgt->query_rest_type())) {
          message("combat","The pain overcomes you and you fall to your knees.", tgt);
          message("combat",tgt->query_cap_name()+" falls to "+
                           tgt->query_possessive()+" knees in pain.", environment(tp), tgt);
          tgt->set_rest_type(SIT);
        }
      }
    }
  }
  
  return 1;
}

