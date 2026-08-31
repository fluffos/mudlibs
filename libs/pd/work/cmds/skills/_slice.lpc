
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define PCOL "%^YELLOW%^"
#define KCOL RES+"%^RED%^"

#define FAIL(s) return notify_fail(s+"\n");

#define BACKSTAB_PROP "backstab_abil_time"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp &&
      (tp->query_subclass() == "kataan" &&
      tp->query_skill("projectile") >= 6*11 &&
      tp->query_skill("attack") >= 4*11) ||
      (tp->query_class() == "rogue" &&
      tp->query_skill("knife") >= 5*11 &&
      tp->query_skill("attack") >= 5*11))
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <slice [whom]>\n\n"
    "An attack where the user slices horizontally with his weapons "
    "to hit his opponent's body.",
    this_player() );
}

int can_cast(object tp, object tgt, string cl, object *weps) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are dead.");

  switch (cl) {
    case "kataan":
      if (!sizeof(weps))
        FAIL("You need to use a spear for that.");
    break;
    case "rogue":
      if (sizeof(weps) < 2)
        FAIL("You need to use two knives for that.");
    break;
    default:
  }

  if (tp->query_rest_type())
    FAIL("You cannot do that until you stand up.");

  if (!tgt)
    FAIL("Slice whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("You cannot attack yourself.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_slice(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  int dmg, cost, rank;
  int att;
  string cl, type;
  string *skills, *stats;
  string other;
  mixed tmp;

  if (!abil()) return 0;
  
  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str, env);

  if (tp->query_subclass() == "kataan") {
    cl="kataan";
    type="projectile";
    skills = ({"attack", type, type});
    stats = ({"strength", "dexterity"});
  }
  else {
    cl="rogue";
    type="knife";
    skills = ({"attack", type, type, "agility", "double wielding"});
    stats = ({"strength", "dexterity", "dexterity"});
  }
  
  weps = filter(tp->query_wielded(),
    function (object w, string t) {
      if (w->query_type() == t) return 1;
      return 0;
    }, type);
  
  if (!can_cast(tp, tgt, cl, weps)) return 0;
  
  att = tp->query_skill("attack");
  if (att >= 30*5)
    rank = 3;
  else if (att >= 18*5)
    rank = 2;
  else
    rank = 1;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    stats,
    ({"strength", "dexterity"}) );

  dmg += weps[0]->query_wc()*7.5;

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 105 / 100;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-(cost+random(cost/11)));
  tp->set_disable();

  switch (cl) {
    case "kataan":
      message("combat", "You "+PCOL+"slice"+RES+" your "+weps[0]->query_name()+
                        " quickly "+
                        PCOL+"b"+RES+"a"+PCOL+"c"+RES+"k "+
                        PCOL+"a"+RES+"n"+PCOL+"d "+
                        RES+"f"+PCOL+"o"+RES+"r"+PCOL+"t"+RES+"h "+
                        PCOL+"ac"+RES+"ro"+PCOL+"ss"+RES+" "+
                        tgt->query_cap_name()+"'s body!", tp);
      message("combat", tp->query_cap_name()+" "+PCOL+"slices"+RES+
                        " "+tp->query_possessive()+" "+weps[0]->query_name()+
                        " quickly "+
                        PCOL+"b"+RES+"a"+PCOL+"c"+RES+"k "+
                        PCOL+"a"+RES+"n"+PCOL+"d "+
                        RES+"f"+PCOL+"o"+RES+"r"+PCOL+"t"+RES+"h "+
                        PCOL+"ac"+RES+"ro"+PCOL+"ss"+RES+
                        " your body!", tgt);
      message("combat", tp->query_cap_name()+" "+PCOL+"slices"+RES+
                        " "+tp->query_possessive()+" "+weps[0]->query_name()+
                        " quickly "+
                        PCOL+"b"+RES+"a"+PCOL+"c"+RES+"k "+
                        PCOL+"a"+RES+"n"+PCOL+"d "+
                        RES+"f"+PCOL+"o"+RES+"r"+PCOL+"t"+RES+"h "+
                        PCOL+"ac"+RES+"ro"+PCOL+"ss"+RES+
                        " "+tgt->query_cap_name()+"'s body!",
                        env, ({tp, tgt}) );
    break;
    case "rogue":
      if (sizeof(tmp = (mixed *)tp->query(BACKSTAB_PROP)) == 2 && tmp[0] == time() && tmp[1] == tgt)
        tmp = 9;
      else
        tmp = 7;
      dmg = dmg * tmp / 10;
      if (weps[0]->query_name() == weps[1]->query_name()) other = "other ";
      else other = "";
      message("combat", "You "+KCOL+"slice"+RES+" your "+weps[0]->query_name()+
                        " quickly "+
                        KCOL+"ac"+RES+"ro"+KCOL+"ss"+RES+
                        " "+tgt->query_cap_name()+"'s body, then turn and "+
                        KCOL+"slice"+RES+" "+tgt->query_objective()+" "+
                        KCOL+"again"+RES+" with your "+other+weps[1]->query_name()+
                        "!", tp);
      message("combat", tp->query_cap_name()+" "+KCOL+"slices"+RES+" "+
                        tp->query_possessive()+" "+weps[0]->query_name()+
                        " quickly "+
                        KCOL+"ac"+RES+"ro"+KCOL+"ss"+RES+
                        " your body, then turns and "+
                        KCOL+"slices"+RES+" you "+
                        KCOL+"again"+RES+" with "+
                        tp->query_possessive()+" "+other+weps[1]->query_name()+
                        "!", tgt);
      message("combat", tp->query_cap_name()+" "+KCOL+"slices"+RES+" "+
                        tp->query_possessive()+" "+weps[0]->query_name()+
                        " quickly "+
                        KCOL+"ac"+RES+"ro"+KCOL+"ss"+RES+
                        " "+tgt->query_cap_name()+"'s body, then turns and "+
                        KCOL+"slices"+RES+" "+tgt->query_objective()+" "+
                        KCOL+"again"+RES+" with "+
                        tp->query_possessive()+" "+other+weps[1]->query_name()+
                        "!",
                        env, ({ tp, tgt }) );
      if (tp->query_subclass() == "thug" || tp->query_subclass() == "assassin")
        if (random(100) < 23 && !tgt->query_bleeding())
          tgt->add_bleeding(dmg/25+random(20+weps[0]->query_wc()*5));
    break;
    default:
  }
  tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_SLASH, 0, tp);
  
  return 1;
}
