
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^YELLOW%^"
#define RES "%^RESET%^"

#define WEAVE COL+"w"+COL2+"e"+COL+"a"+COL2+"v"+COL+"e"+RES

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler" &&
      tp->query_skill("blade") >= 30*6 &&
      tp->query_skill("entertainment") >= 30*3 &&
      tp->query_skill("attack") >= to_int(30*4.5))
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <bladedance [opponent]>\n\n"
    "An intricate show of swordsmanship only performed by skilled "
    "swashbucklers. Its grace and beauty are matched only by its lethality.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're dead.");

  if (!tgt)
    FAIL("Attack who?");

  if (sizeof(weps) < 2)
    FAIL("You must use at least two blades for that!");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("There are more entertaining ways to kill yourself.");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_bladedance(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *alltgts, *weps, *atks;
  int rank, dmg, cost, numextra, numhits, hit, dodge;
  string *bladenames;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blade" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  if (tp->query_level() >= 50) rank = 4;
  else rank = 3;

  weps = sort_array(weps, (: $1->query_wc() > $2->query_wc() ? -1 : 1 :) );
  bladenames = map(weps, (:
    replace_string(remove_article(strip_color($1->query_short())), " (wielded)", "")
  :) );

  alltgts = ({ tgt });
  atks = tp->query_attackers() - ({ tgt });
  numextra = (tp->query_level()-30)/10;
  if (numextra > 2) numextra = 2;
  while (numextra > 0 && sizeof(atks)) {
    if (member_array(atks[0], alltgts) == -1) {
      alltgts += ({ atks[0] });
      atks = atks[1..<1];
      numextra--;
    }
  }

  numhits = 1 + (tp->query_level()-25)/6 + random(3);
  //numhits -= random(numhits/2);
  if (numhits > 7) numhits = 7;
    
  message("combat", "You begin to "+WEAVE+" your "+COL+"blades"+RES+
    " in an "+COL2+"int"+COL+"ric"+COL2+"ate"+RES+" pattern.", tp);
  message("combat", tp->query_cap_name()+" begins to "+WEAVE+" "+
      tp->query_possessive()+" "+COL+"blades"+RES+
    " in an "+COL2+"int"+COL+"ric"+COL2+"ate"+RES+" pattern.", env, tp);

  for (int i = 0; i < numhits; i++ ) {

    object thistgt;
    int wepnum;
    int dtype;

    if (random(100) < 40)
      thistgt = alltgts[random(sizeof(alltgts))];
    else
      thistgt = tgt;

    wepnum = random(sizeof(weps));

    dmg = BALANCE3_D->get_damage(tp, thistgt, rank,
      ({ "blade", "attack", "double wielding" }),
      ({ "strength", "dexterity", "dexterity", "dexterity", }),
      ({ "strength", "dexterity" }) );

    dmg = dmg*75/100;

    //cost = dmg/15 + random(10);
    cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 70 / 100 + random(10);

    if (i == 0) {
      if (tp->query_sp() < cost)
        FAIL("You are too tired.");

      tp->add_sp(-(cost+random(cost/10)));
    }
    else {
      cost /= 5+i;
      if (tp->query_sp() < cost) {
        message("info","You are too tired to continue your bladedance.", tp);
        break;
      }
      tp->add_sp(-cost);
      dmg /= 6+random(i+2);
    }

    dmg += weps[wepnum]->query_wc()*2;

    tp->kill_ob(thistgt);

    hit = tp->query_skill("attack");
    hit += tp->query_skill("entertainment")*(i+2)/(i+1);
    hit += tp->query_stats("dexterity")*2;
    hit += tp->query_stats("charisma");

    dodge = thistgt->query_skill("defense");
    dodge += thistgt->query_skill("agility")/2;
    dodge += thistgt->query_stats("dexterity")*2;

    if (hit < dodge+random(dodge/3)) {
      message("combat", "Your attack misses "+thistgt->query_cap_name()+".", tp);
      message("combat", tp->query_cap_name()+" misses an attack on you.", thistgt);
      message("combat", tp->query_cap_name()+" misses an attack on "+
        thistgt->query_cap_name()+".", env, ({ tp, thistgt }) );
      continue;
    }

    switch (i) {
      case 0:
        dtype = DAMAGE_SLASH | DAMAGE_PIERCE;
        message("combat",
          "You "+COL+"cut"+RES+" "+thistgt->query_cap_name()+
          " with your "+bladenames[wepnum]+"!", tp);
        message("combat",
          tp->query_cap_name()+" "+COL+"cuts"+RES+" you"
          " with "+tp->query_possessive()+" "+
          bladenames[wepnum]+"!", thistgt);
        message("combat",
          tp->query_cap_name()+" "+COL+"cuts"+RES+" "+thistgt->query_cap_name()+
          " with "+tp->query_possessive()+" "+
          bladenames[wepnum]+"!", env, ({ tp, tgt }) );
      break;

      default:
        switch (random(9)) {
          case 0: case 3: case 6:
            dtype = DAMAGE_SLASH;
            message("combat", "You "+COL+"sp"+COL2+"i"+COL+"n"+RES+
              " and sl"+COL2+"i"+RES+"ce "+
              thistgt->query_cap_name()+" with your "+
              bladenames[wepnum]+"!", tp);
            message("combat", tp->query_cap_name()+" "+COL+"sp"+COL2+"i"+COL+"ns"+RES+
              " and sl"+COL2+"i"+RES+"ces you with "+tp->query_possessive()+" "+
              bladenames[wepnum]+"!", thistgt);
            message("combat", tp->query_cap_name()+" "+COL+"sp"+COL2+"i"+COL+"ns"+RES+
              " and sl"+COL2+"i"+RES+"ces "+
              thistgt->query_cap_name()+" with "+tp->query_possessive()+" "+
              bladenames[wepnum]+"!", env, ({ tp, thistgt }) );
          break;

          case 1: case 4: case 7:
            dtype = DAMAGE_SLASH;
            message("combat", "You quickly duck down and "+COL+"sla"+COL2+"s"+COL+"h"+RES+
              " "+thistgt->query_cap_name()+" with a rising cut!", tp);
            message("combat", tp->query_cap_name()+" ducks down and "+
              COL+"sla"+COL2+"s"+COL+"hes"+RES+" you with a rising cut!", thistgt);
            message("combat", tp->query_cap_name()+" ducks down and "+
              COL+"slas"+COL2+"h"+COL+"es"+RES+" "+thistgt->query_cap_name()+
              " with a rising cut!", env, ({ tp, thistgt }) );
          break;

          case 2: case 5: case 8:
            dtype = DAMAGE_PIERCE;
            message("combat", "You bring your "+
              bladenames[wepnum]+" around and "+
              COL+"stab"+RES+" "+thistgt->query_cap_name()+" with the ti"+COL2+"p"+RES+"!",
              tp);
            message("combat", tp->query_cap_name()+" brings "+tp->query_possessive()+
              " "+bladenames[wepnum]+" around and "+
              COL+"stabs"+RES+" you with the ti"+COL2+"p"+RES+"!", thistgt);
            message("combat", tp->query_cap_name()+" brings "+tp->query_possessive()+
              " "+bladenames[wepnum]+" around and "+
              COL+"stabs"+RES+" "+thistgt->query_cap_name()+" with the ti"+COL2+"p"+RES+"!",
              env, ({ tp, tgt }) );
          break;
        }
      break;

      case 6:
        dtype = DAMAGE_SLASH | DAMAGE_PIERCE;
        message("combat", "With a "+COL2+"fl"+COL+"our"+COL2+"ish"+RES+", "
          "you "+COL+"cut"+RES+" "+thistgt->query_cap_name()+" on the cheek!",
          tp);
        message("combat", "With a "+COL2+"fl"+COL+"our"+COL2+"ish"+RES+", "+
          tp->query_cap_name()+" "+COL+"cuts"+RES+" you on the cheek!", thistgt);
        message("combat", "With a "+COL2+"fl"+COL+"our"+COL2+"ish"+RES+", "+
          tp->query_cap_name()+" "+COL+"cuts"+RES+" "+thistgt->query_cap_name()+
          " on the cheek!", env, ({ tp, tgt }) );
      break;
    }

    thistgt->do_damage("target", dmg, DAMAGE_PHYSICAL | dtype, DAMAGE_NO_SEVER, tp);
    
  }

  tp->set_disable();

  return 1;
}

