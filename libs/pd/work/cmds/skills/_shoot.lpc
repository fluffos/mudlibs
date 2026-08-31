
#include <std.h>
#include <daemons.h>
#include <rooms.h>
#include <damage_types.h>
#include <damage.h>

#define TYPE "ranged"
#define FAIL(s) return notify_fail(s)
#define COL "%^GREEN%^"
#define RES "%^RESET%^"

string type() { return "weapon"; }

int abil() {
  object tp=this_player();
  if (tp && tp->query_skill("ranged") >= 20)
    return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <shoot [living] [direction]>\n\n"
    "A basic attack with a bow and arrow. You can shoot somebody in "
    "the same room, but it's much harder to get a good shot.\n"
    "Anyone with sufficient skill can learn this.",
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
    FAIL("Shoot whom?\n");

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.\n");
  
  if (tgtenv->query_property("no attack"))
    FAIL("You cannot shoot into that place.\n");

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

int cmd_shoot(string str) {
  object tp=this_player();
  object tgt;
  object tpenv=environment(tp);
  object tgtenv;
  object *weps;
  object *quivers;
  string dir, tmp, revdir;
  int dam, cost, rank;
  int attackme=0;

  if (!abil()) return 0;

  if (!str || str == "") {
    tgt=tp->query_current_attacker();
    tgtenv=tpenv;
  }
  else if (sscanf(str, "%s %s", tmp, dir) == 2 &&
           tpenv->query_exit(dir) != ROOM_VOID) {
             tgtenv = load_object(tpenv->query_exit(dir));
             tgt = present(tmp, tgtenv);
  }
  else {
    tgt=present(str, tpenv);
    tgtenv=tpenv;
  }

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );

  quivers = filter(all_inventory(tp), (: ($1->is_quiver() && $1->query_arrows()) :) );
  
  if (!can_cast(tp, tgtenv, tgt, weps, quivers)) return 0;

  quivers[0]->use_arrow();

  if (tp->query_skill(TYPE) >= 75) rank=2;
  else rank=1;

  dam = BALANCE3_D->get_damage(tp, tgt, rank,
      ({TYPE, "attack", "perception"}),
      ({"dexterity"}) );

  dam = dam * 1.5;

  if (dam > 400) dam=400+random(tp->query_level()*2);

  if (tp->query_rest_type())
    dam = dam*2/3;
  
  /*
  cost = dam/9;
  */
  cost = BALANCE3_D->get_cost(dam, rank, "sp")/2;

  if (tgtenv != tpenv) {
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
      attackme = 1 + tgt->query("shoot_abil_attacks");
      attackme += random(1+tgt->query_skill("perception")/55);
      tgt->set("shoot_abil_attacks",1+tgt->query("shoot_abil_attacks"));
    }
    switch (tmp) {
      case "up": tmp = "above"; break;
      case "down": tmp = "below"; break;
      case "enter": tmp = "the entrance"; break;
      case ROOM_VOID: tmp = "out of nowhere"; break;
      default: tmp = "the "+tmp;
    }
  }
  else {
    tmp="";
    dam = dam*4/7;
  }

  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");
  
  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  if (dam < 10) {
    if (sizeof(tmp)) {
      message("info","You shoot an arrow "+dir+" at "+tgt->query_cap_name()+
                     ", but miss.", tp);
      message("info",tp->query_cap_name()+" shoots an arrow "+dir+".", tpenv, tp);
      message("info","An arrow flies in from "+tmp+" and sticks into "
                     "the ground.", tgtenv);
    }
    else {
      message("info","You shoot an arrow at "+tgt->query_cap_name()+
                     ", but miss.", tp);
      message("info",tp->query_cap_name()+" shoots an arrow at you, "
                     "but misses.", tgt);
      message("info",tp->query_cap_name()+" shoots an arrow at "+
                     tgt->query_cap_name()+", but misses.", tpenv, ({tp,tgt}) );
    }
  }
  else {
    if (sizeof(tmp)) {
      message("info","You "+COL+"shoot"+RES+" an arrow "+dir+" at "+
                     tgt->query_cap_name()+"!",tp);
      message("info","An arrow "+COL+"flies"+RES+" in from "+tmp+" and "
                     "sticks into you!", tgt);
      message("info","An arrow "+COL+"flies"+RES+" in from "+tmp+" and "
                     "sticks into "+tgt->query_cap_name()+"!", tgtenv, tgt);
    }
    else {
      message("info","You "+COL+"shoot"+RES+" an arrow into "+
                     tgt->query_cap_name()+"!", tp);
      message("info",tp->query_cap_name()+" "+COL+"shoots"+RES+" an arrow "
                     "into you!", tgt);
      message("info",tp->query_cap_name()+" "+COL+"shoots"+RES+" an arrow "
                     "into "+tgt->query_cap_name()+"!", tpenv, ({tp,tgt}) );
    }
    tgt->do_damage(tgt->return_target_limb(), dam, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);
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

