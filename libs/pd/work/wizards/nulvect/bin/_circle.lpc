#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^RED%^"
#define COL2 "%^BLUE%^"

#define CIRCLE_PROP "circle_abil_time"
#define CIRCLE_DELAY 30
#define BACKSTAB_PROP "backstab_abil_time"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "assassin" &&
      tp->query_skill("agility") >= 40*6 &&
      tp->query_skill("murder") >= 50*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <circle [opponent]>\n\n"
    "One good stab deserves another, so skilled assassins "
    "have learned how to circle around even wary opponents "
    "to get a second good thrust at their backs. It takes "
    "a lot of energy to circle, and few would ever fall for "
    "it more than once, but it can be quite deadly.",
    this_player());
}

int can_cast(object tp, object tgt, object *weps) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You circle around the room like a poultergeist.");

  if (!tgt)
    FAIL("Circle around whom?");

  if (!sizeof(weps))
    FAIL("You need to use a knife for that.");

  if (!living(tgt))
    FAIL("You circle around it and stab it viciously!\n"
         "It doesn't seem to care.");

  if (tgt == tp)
    FAIL("You turn around and around trying to get to your own back, "
         "but somehow you never quite catch it.");

  if (tp->query_rest_type())
    FAIL("You can't crawl that fast!");

  if (tp->query_sp() < 200)
    FAIL("You are too tired for such a quick attack.");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You cannot attack link-dead players.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_circle(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *weps;
  int def, agil, dmg, cost, wc;
  string limb, kname, lname;
  string *limbs;
  mixed tmp;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "knife" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "attack", "knife", "double wielding", "murder", "agility", "agility" }),
    ({ "dexterity" }),
    ({ "dexterity", "strength", "intelligence" })
  );

  dmg *= 1.1;

  cost = log(pow(dmg, 5))+dmg/30;

  if (tp->query_sp() < cost)
    FAIL("You are too tired for such a quick attack.");

  tp->set_disable();
  tp->add_alignment(-1);

  weps = sort_array(weps,
    (: $1->query_wc() > $2->query_wc() ? 1 : 0 :)
  );
  kname = weps[0]->query_name() || "knife";
  wc = weps[0]->query_wc();

  dmg += (wc-7)*50;

  def = tgt->query_stats("dexterity")*3/4;
  def += random(tgt->query_stats("intelligence")/2);
  def += tgt->query_skill("agility");
  def += tgt->query_skill("defense")*4/3;
  def += tgt->query_skill("perception");
  def -= (sizeof(tgt->query_attackers())-1)*75;
  
  // you can't just keep circling over and over
  if (tmp = (int)tgt->query(CIRCLE_PROP)) {
    tmp = tmp+CIRCLE_DELAY - time();
    if (tmp > 0)
      def += tmp*10;
  }

  agil = tp->query_stats("dexterity");
  agil += tp->query_skill("agility");
  agil += tp->query_skill("attack")/2;
  agil += tp->query_skill("stealth");
  agil += random(tp->query_skill("murder")/4);
  agil -= (sizeof(tp->query_attackers())-1)*75;

  if (tp->query_invis())
    agil += 150;

  // right after backstab hits
  if (sizeof(tmp = (mixed *)tp->query(BACKSTAB_PROP)) == 2 &&
      tmp[0] == time() && tmp[1] == tgt) {
        agil += 200;
        dmg *= 1.25;
        message("combat", "As "+tgt->query_cap_name()+" starts to turn, "
                          "you "+COL2+"sp"+COL+"i"+COL2+"n "
                          "a"+COL+"roun"+COL2+"d"+RES+"!", tp);
  }
  else
    message("combat", "You "+COL+"ci"+COL2+"rcl"+COL+"e"+RES+
                      " around be"+COL2+"hin"+RES+"d "+
                      tgt->query_cap_name()+".", tp);

  if (def > agil) {
    message("combat", tgt->query_cap_name()+" sidesteps your attack.", tp);
    message("combat", tp->query_cap_name()+" tries to circle behind you, "
                      "but you sidestep "+tp->query_possessive()+" attack.", tgt);
    cost /= 2;
  }
  else {
    // get a limb with one of these words in the name
    if (sizeof(limbs = regexp(tgt->query_limbs(), "head|torso|abdomen|body")))
      limb = limbs[random(sizeof(limbs))];
    else
      limb = tgt->return_target_limb();
    switch (limb) {
      case "torso": lname = "back"; break;
      case "head": lname = "neck"; break;
      default: lname = limb;
    }
    message("combat", "You t"+COL+"hrus"+RES+"t your "+kname+
                      " "+COL+"into"+RES+" "+tgt->query_possessive()+
                      " "+lname+"!", tp);
    message("combat", tp->query_cap_name()+" t"+COL+"hrus"+RES+"ts "+
                      a_or_an(kname)+" "+kname+" "+COL+"into"+RES+
                      " your "+lname+"!", tgt);
    message("combat", tp->query_cap_name()+" t"+COL+"hrus"+RES+"ts "+
                      a_or_an(kname)+" "+kname+" "+COL+"into"+RES+
                      " "+tgt->query_cap_name()+"'s "+lname+"!",
                      env, ({ tp, tgt }) );
    tgt->do_damage(limb, dmg);
    tgt->add_bleeding(dmg/6);
  }

  tp->add_skill_points("agility", cost*3);
  tp->add_sp(-cost);
  tgt->set(CIRCLE_PROP, time());

  return 1;
}
