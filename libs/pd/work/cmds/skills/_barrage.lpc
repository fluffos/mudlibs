
#include <std.h>
#include <daemons.h>
#include <rooms.h>
#include <damage_types.h>
#include <damage.h>

#define TYPE "ranged"
#define FAIL(s) return notify_fail(s)
#define COL "%^GREEN%^"
#define RES "%^RESET%^"

string type() { return "attack"; }

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "ranger" &&
      tp->query_skill("ranged") >= 24*6)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <barrage [living] [direction]>\n\n"
    "This move consists of a short series of bow shots fired quickly. "
    "Rangers are the only ones skilled enough to learn this.",
    this_player() );
}

int can_cast(object tp, object tgtenv, object tgt, object *weps, object *quivers) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("You cannot do that as a ghost.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");
  
  if (!tgtenv)
    FAIL("You cannot shoot in that direction.\n");

  if (!tgt)
    FAIL("Shoot arrows at whom?\n");

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.\n");
  
  if (tgtenv->query_property("no attack"))
    FAIL("You cannot shoot into that place.\n");

  if (tgtenv == environment(tp))
    FAIL("You cannot use this ability at short range.\n");

  if (!living(tgt))
    FAIL("You cannot shoot inanimate objects.\n");

  if (tp == tgt)
    FAIL("Come on, that's not even possible.\n");

  if (!sizeof(weps))
    FAIL("You need to use a bow for that.\n");

  if (!sizeof(quivers))
    FAIL("You do not have any quivers with arrows.\n");

  if (!(tp->kill_ob(tgt)))
    FAIL("You cannot attack "+tgt->query_cap_name()+".\n");
  
  return 1;
}

int cmd_barrage(string str) {
  object tp=this_player();
  object tgt;
  object tpenv=environment(tp);
  object tgtenv;
  object *weps;
  object *quivers;
  string dir, tmp, revdir;
  int dam, cost, rank;
  int hits, arrows;
  int attackme=0;
  int x;

  if (!abil()) return 0;

  if (str && sscanf(str, "%s %s", tmp, dir) == 2 &&
      tpenv->query_exit(dir) != ROOM_VOID) {
        tgtenv = load_object(tpenv->query_exit(dir));
        tgt = present(tmp, tgtenv);
  }
  // can't actually hit someone in the same room
  else if (str) {
    tgt = present(str, tpenv);
    tgtenv = tpenv;
  }

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );

  quivers = filter(all_inventory(tp), (: ($1->is_quiver() && $1->query_arrows()) :) );
  
  if (!can_cast(tp, tgtenv, tgt, weps, quivers)) return 0;

  // every 9 levels of maxed discipline and ranged, gain another hit 
  hits = 2;
  if ((x=(tp->query_skill("discipline")+tp->query_skill("ranged"))) > 275)
    hits += (x-275)/99;
  arrows=hits;

  foreach (object q in quivers) {
    for (; arrows > 0 && q->query_arrows(); arrows--)
      q->use_arrow();
    if (arrows == 0) break;
  }

  // if we don't have enough arrows for the number of hits...
  if (arrows > 0) hits = hits-arrows;

  if (hits < 2)
    FAIL("You need at least two arrows.\n");

  if (hits > 3) rank=3;
  else rank=2;

  dam = BALANCE3_D->get_damage(tp, tgt, rank,
      ({TYPE, TYPE, "discipline", "perception"}),
      ({"dexterity","dexterity","dexterity","strength"}),
      ({"dexterity","strength"}) );

  dam = dam * 0.40 * hits;

  dam += weps[0]->query_wc()*3;

  if (tp->query_rest_type())
    dam = dam*2/3;
  
  cost = BALANCE3_D->get_cost(dam, rank, "sp") * 95 / 100;

  tmp = tgtenv->query_direction(base_name(tpenv));
  revdir = tmp;
  if (tgt->query_hp() >= tgt->query_max_hp()*7/8 &&
      dam >= tgt->query_max_hp()*7/8) {
        attackme = 100;
        dam = tgt->query_hp()*2/3;
  }
  else if (dam >= tgt->query_hp() ||
           tgt->query_hp() < tgt->query_max_hp()/3) {
             attackme = 100;
             dam = 0;
  }
  else {
    attackme = 2 + tgt->query("shoot_abil_attacks");
    attackme += random(1+tgt->query_skill("perception")/40);
    tgt->set("shoot_abil_attacks",1+tgt->query("shoot_abil_attacks"));
  }
  switch (tmp) {
    case "up": tmp = "above"; break;
    case "down": tmp = "below"; break;
    case "enter": tmp = "the entrance"; break;
    case ROOM_VOID: tmp = "out of nowhere"; break;
    default: tmp = "the "+tmp;
  }

  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");
  
  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  message("info","You quickly "+COL+"shoot"+RES+" a "+COL+"barrage"+RES+
                 " of "+cardinal(hits)+" arrows "+dir+" at "+
                 tgt->query_cap_name()+"!",tp);
  message("info",tp->query_cap_name()+" "+COL+"shoots"+RES+" a "+COL+"barrage"+RES+
                 " of "+cardinal(hits)+" arrows "+dir+"!", tpenv, tp);
  message("info","A "+COL+"barrage"+RES+" of "+cardinal(hits)+" arrows flies "
                 "in from "+tmp+"!", tgtenv);

  if (dam < 30) {
    message("info","Your arrows seem to miss.", tp);
    message("info","The arrows don't hit anything.", tgtenv);
  }
  else {
    message("info","The arrows "+COL+"stick"+RES+" into you!", tgt);
    message("info","The arrows "+COL+"stick"+RES+" into "+
                   tgt->query_cap_name()+"!", tgtenv, tgt);
    tgt->do_damage("target", dam, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);
  }
  if (!userp(tgt) && revdir != ROOM_VOID && attackme > 1+random(4)) {
    tgt->set("shoot_abil_attacks",100);
    tgt->force_me(revdir);
    tgt->force_me("kill "+tp->query_name());
  }
  if (tgt->query("shoot_abil_remove"))
    remove_call_out(tgt->query("shoot_abil_remove"));
  tgt->set("shoot_abil_remove",call_out("remove_setting", 60*2, ({tgt}) ));
  // the return value of call_out is a special 'handle' which can be used
  // to reference that specific call_out later on
  return 1;
}

void remove_setting(mixed *args) {
  object tgt=args[0];
  if (objectp(tgt)) {
    tgt->set("shoot_abil_attacks",0);
    tgt->set("shoot_abil_remove",0);
  }
}

