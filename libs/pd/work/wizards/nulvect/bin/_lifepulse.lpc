//   _mheal.c
//   Author:  Hanse (with original code from _heal.c made by Descartes)
//   Date: 8-Nov-92
//   Modified by Bohemund to restrict it for use only by clerics,
//   ansi was added as well.
//   Date: 10-Jan-94
//
//   name change to lifepulse + other minor changes
//   by Nulvect 2006-10-05

#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s)

inherit DAEMON;

void send_messages(object tp, object ob, string limb);


void help() {
  message("help",
    "Syntax: <lifepulse [player] (limb | all)>\n\n"
    "A special healing spell. Lifepulse sends a cleric's healing powers "
    "out over a distance to heal a player.",
    this_player() );
}

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("healing") >= 24*6)
        return 1;
  return 0;
}

string type() { return "healing"; }

int can_cast(object tp, object tgt) {
  object env;
  
  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no magic"))
    FAIL("Some force prevents you from casting that.\n");

  if (tp->query_ghost())
    FAIL("You seem to be dead.\n");
  
  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");
  
  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");
  
  if (!tgt)
    FAIL("Heal whom?\n");

  if (tp == tgt || environment(tgt) == env)
    FAIL("This spell is only for healing over long distances.\n");

  if (!interactive(tgt))
    FAIL(capitalize(tgt->query_possessive())+" soul seems to be disconnected.\n");


  return 1;
}

int cmd_lifepulse(string str) {
    string whom, limb;
    int amount, cost, healing, i, wisdom;
    object tp, ob;
    string *limbs;

    if (!spell()) return 0;

    tp=this_player();

    if (str && str != "")
      ob = find_player(str);
    if (!ob && sscanf(str, "%s %s", whom, limb) == 2)
      ob = find_player(whom);

    if (!can_cast(tp, ob)) return 0;

    healing = (int)tp->query_skill("healing");
    healing += tp->query_skill("conjuring");
    healing += tp->query_skill("belief")/2;
    wisdom = (int)tp->query_stats("wisdom");
    amount = random(wisdom) + (healing/2);
    
    if (!limb)
      cost = 22;
    else if (limb == "all")
      cost = 44;
    else if (member_array(limb, (string *)ob->query_limbs()) == -1) {
      limb=0;
      cost=22;
    }
    else
      cost = 14;

    cost += random(amount/3);

    if((int)tp->query_mp() < cost)
        FAIL("Too low on magic power.\n");
        
    tp->add_mp(-cost);
    tp->add_skill_points("healing", amount/5);
    tp->add_alignment(amount/5);
    this_player()->set_magic_round(1);
    tp->add_exp(random((amount/5)+2));

    if(!limb) {
        ob->add_hp(amount);
        send_messages(tp, ob, 0);
    }
    else if(limb == "all") {
        limbs = (string *)ob->query_limbs();
        for(i=0; i<sizeof(limbs); i++) {
            ob->heal_limb(limbs[i], (amount / 2));
        }
        ob->add_hp(amount / 2);
        send_messages(tp, ob, limb);
    }
    else {
        ob->heal_limb(limb, amount);
        send_messages(tp, ob, limb);
    }
    return 1;
}
void send_messages(object tp, object ob, string limb) {
  message("magic", COL+"You send a "+
    COL2+"pu"+COL+"l"+COL2+"se"+COL+" of "+
    COL2+"e"+COL+"nerg"+COL2+"y"+COL+
    " out towards "+ob->query_cap_name()+".", tp);
    
  message("magic",
    COL+"A "+COL2+"pu"+COL+"l"+COL2+"se"+COL+" of "+
    COL2+"e"+COL+"nerg"+COL2+"y"+COL+" flies out from "+
    tp->query_cap_name()+"."+RES, environment(tp), tp);

  message("magic",
    COL+"A "+COL2+"pu"+COL+"l"+COL2+"se"+COL+" of healing "+
    COL2+"e"+COL+"nerg"+COL2+"y"+COL+" surrounds "+
    (limb?"your "+limb:"you")+".", ob);

  message("magic",
    COL+"A "+COL2+"pu"+COL+"l"+COL2+"se"+COL+" of "+
    COL2+"e"+COL+"nerg"+COL2+"y"+COL+" surrounds "+ob->query_cap_name()+".",
    environment(ob), ob);
}
