
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL RES+"%^BLUE%^"
#define COL2 "%^ORANGE%^"
#define COL3 "%^RED%^"

#define CHOKE_PROP "choke_abil_who"
#define CHOKE_OB "/cmds/skills/obj/choke_struggle_ob"
#define CHOKE_OB_ID "choke_struggle_ob"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

object *who = ({});

int do_some_choking(object tp);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thug" &&
      tp->query_skill("murder") >= 30*5 &&
      tp->query_skill("melee") >= 30*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <choke [who]>\n\n"
    "Coming up from behind, some rogues choose to use brute force to simply "
    "choke their victims to death.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You flail about helplessly.");

  if (!tgt)
    FAIL("Choke who?");

  if (!living(tgt))
    FAIL("That thing isn't alive.");

  if (!tgt->query_is_limb("head"))
    FAIL(capitalize(tgt->query_subjective())+" doesn't have a head.");

  if (tp == tgt)
    FAIL("Well, that's one way to kill yourself.");

  if (tp->clean_up_attackers())
    FAIL("You have lost the element of surprise!");

  if (tp->query_rest_type())
    FAIL("You need to stand up first.");

  if (tp->query_riding())
    FAIL("You can't sneak around while riding.");

  if (sizeof(tp->query_riders()))
    FAIL("You can't sneak around with people riding on your back.");

  if (sizeof(filter(tp->query_wielded(), (: $1->query_type() != "knife" :) )) )
    FAIL("Your weapons would get in the way.");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_choke(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int hit = 0;
  int miss = 0;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  hit += tp->query_stats("dexterity");
  hit += tp->query_skill("stealth");
  hit += tp->query_skill("agility")*3/2;
  hit += tp->query_skill("murder")/2;
  if (tp->use_stealth(20))
    hit += 20;
  
  miss += tgt->query_stats("dexterity")*2/3;
  miss += tgt->query_stats("intelligence")/4;
  miss += tgt->query_stats("wisdom")/3;
  miss += tgt->query_skill("perception");
  miss += tgt->query_skill("defense");

  who += ({ tp });

  if (tgt->query_skill("perception") + tgt->query_skill("intelligence")*2/3 >
      tp->query_skill("stealth")*1.5 + tgt->query_stats("dexterity")) {
        miss += 40;
        message("combat", tp->query_cap_name()+" attempts to sneak behind "
                          "you unnoticed!", tgt);
  }

  if (hit > miss)
    tp->set(CHOKE_PROP, ({ tgt, 1 }) );
  else
    tp->set(CHOKE_PROP, ({ tgt, 0 }) );

  tp->set_paralyzed(20, "You are trying to sneak up on someone.");

  message("info", "You "+COL+"sneak"+RES+" around "+COL+"behind"+RES+" "+
                    tgt->query_cap_name()+".", tp);

  set_heart_beat(1);

  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    mixed *prop;
    object vic, ob;
    if (p) {
      prop = p->query(CHOKE_PROP);
      if (!sizeof(prop)) {
        p->set_paralyzed(0, "You are catching your breath.");
        who -= ({ p });
      }
      else if (!do_some_choking(p)) {
        if (!sizeof(prop)) {
          p->set_paralyzed(0, "You are catching your breath.");
          who -= ({ p });
        }
        vic = prop[0];
        if (objectp(vic)) {
          vic->set_paralyzed(0);
          if (ob = present(CHOKE_OB_ID, vic))
            ob->remove();
        }
        p->set_paralyzed(0, "You are catching your breath.");
        p->set(CHOKE_PROP, ({ }) );
        who -= ({ p });
      }
    }
    if (!p)
      who -= ({ p });
  }
  if (!sizeof(who)) set_heart_beat(0);
}

int do_some_choking(object tp) {
  object env, tgt, ob;
  mixed *arr;
  int mystr, mydex, myatt, mymurd, mymelee;
  int yourstr, yourdex, yourdef;
  int dmg, cost, count, escape;

  if (!tp || sizeof(arr = (mixed)tp->query(CHOKE_PROP)) < 2) return 0;

  if (!(env = environment(tp))) return 0;

  tgt = arr[0];
  count = arr[1];

  if (!tgt || !environment(tgt) || environment(tgt) != env)
    return 0;

  if (!tp->kill_ob(tgt)) return 0;

  // he caught us sneaking up
  if (count == 0) {
    message("combat", "As you start to grab "+tgt->query_cap_name()+
                      "'s neck, "+tgt->query_subjective()+
                      " twists out of your grasp!", tp);
    message("combat", "You notice "+tp->query_cap_name()+" try to sneak "
                      "up behind you, and twist out of "+
                      tp->query_possessive()+" grasp!", tgt);
    tp->set_disable();
    tp->add_sp(-25);
    return 0;
  }

  dmg = BALANCE3_D->get_damage(tp, tgt, 3,
    ({ "melee", "melee", "murder", "murder", "attack" }),
    ({ "strength", "strength", "strength", "dexterity" }),
    ({ "strength", "dexterity" }) );

  dmg *= 0.75;

  if (count == 1)
    cost = 50;
  else
    cost = (dmg+count*50)/9.5;

  if (tp->query_sp() < cost) {

    message("combat", tgt->query_cap_name()+" slips out of "
                      "your grasp as your strength declines.", tp);
    message("combat", "You feel "+tp->query_cap_name()+"'s grasp weaken, "
                      "and you slip away quickly!", tgt);
    message("combat", tgt->query_cap_name()+" slips out of "+
                      tp->query_cap_name()+"'s grasp!", env, ({ tp, tgt }) );

    tp->set_disable();
    tgt->set_disable();

    return 0;
  }

  if (count == 1) {
    message("combat", "You grab "+tgt->query_cap_name()+"'s neck and "+
                      COL2+"ch"+COL3+"o"+COL2+"ke"+RES+" "+
                      tgt->query_objective()+" as hard as you can!", tp);
    message("combat", tp->query_cap_name()+" wraps "+tp->query_possessive()+
                      " arm around your neck and starts to "+
                      COL2+"ch"+COL3+"o"+COL2+"ke"+RES+" you!", tgt);
    message("combat", tp->query_cap_name()+" wraps "+tp->query_possessive()+
                      " arm around "+tgt->query_cap_name()+"'s neck and starts to "
                      COL2+"ch"+COL3+"o"+COL2+"ke"+RES+" "+
                      tgt->query_objective()+"!", env, ({ tp, tgt }) );
    ob = new(CHOKE_OB);
    ob->setup(tp, tgt);
    ob->move(tgt);
  }
  else {
    message("combat", tp->query_cap_name()+" "+COL2+"ch"+COL3+"o"+COL2+"kes"+RES+" "+
                      tgt->query_cap_name()+" harder!", env, ({ tp, tgt }) );
    if (random(500) < 300 && !userp(tgt)) tgt->force_me("struggle");
  }

  dmg = dmg*(100+count*10)/100;

  tp->add_sp(-(cost));
  tp->set_paralyzed(8, "You "+COL2+"ch"+COL3+"o"+COL2+"ke"+RES+" "+
                        tgt->query_cap_name()+" as hard as you can!");
  tgt->set_paralyzed(8, tp->query_cap_name()+" "+
                         COL2+"ch"+COL3+"o"+COL2+"kes"+RES+" you harder!");
  tgt->add_hp(-(dmg*2/3));
  tgt->do_damage("head", dmg/3);

  if (percent(tgt->query_hp(), tgt->query_max_hp()) < 25.0)
    message("combat", COL+"You feel the world slipping away."+RES, tgt);
  else {
    escape = absolute_value(count - 5);
    if (userp(tgt))
      escape -= 2;
    if (escape < -1) escape = -1;
    escape = (tgt->query_stats("strength")*5/4 + tgt->query_stats("dexterity")*3/4 + random(35)) / (escape+2);
    if (userp(tgt))
      escape *= 1.25;
    escape = escape - ((tp->query_stats("strength") + tp->query_stats("dexterity")) * 35/100);
    if (escape > 0) {
      message("combat", tgt->query_cap_name()+" breaks out of your grasp!", tp);
      message("combat", "You break out of "+tp->query_cap_name()+"'s grasp!", tgt);
      message("combat", tgt->query_cap_name()+" breaks out of "+
                        tp->query_cap_name()+"'s grasp!", env, ({ tp, tgt }) );
      return 0;
    }
  }

  tp->set(CHOKE_PROP, ({ tgt, count+1 }) );
  
  return 1;
}
