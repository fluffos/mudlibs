#include <std.h>
inherit DAEMON;

void send_messages(object tp, object ob, string clas, string limb);

int spell() {
  object tp=this_player();
  if(!tp) return 0;
  if ((tp->query_subclass() == "cleric" ||
       tp->query_subclass() == "blue") &&
      tp->query_level() >= 6 &&
      tp->query_skill("healing") >= 15) { return 1; }
  return 0;
}

string type() { return "attack"; }

int cmd_rot(string str) {
  string whom, limb, clas;
  int amount, cost, healing, i;
  object tp, ob;
  string *weakness, *strengths;
    
  tp = this_player();
  
  if (!spell())
    return 0;

  if(tp->query_ghost())
    return notify_fail("You cannot cast that while you're dead.\n");

  if(!str || str == "" || sscanf(str, "%s %s", whom, limb) != 2)
    return notify_fail("Correct syntax: <rot [who] [limb]>\n");
  
  if(whom == "me" || whom == "myself") ob = tp;
  else ob = present(whom, environment(tp));
  if(!ob)
    return notify_fail("Rot whom?\n");

  if (tp->query_disable())
    return notify_fail("You are busy.\n");

  if(environment(tp)->query_property("no attack"))
    return notify_fail("A magic force prevents your power.\n");

  if (!alignment_ok(tp) && !(tp->is_monster()))
    return notify_fail("You have betrayed the source of your powers.\n");
  
  healing = (int)tp->query_skill("healing");
  clas = (string)tp->query_subclass();

  if(!living(ob))
      return notify_fail("What? Rot that?\n");
  
  if (tp != ob && !(tp->kill_ob(ob))) {
    message("magic",ob->query_cap_name()+" can't be attacked by you yet.",tp);
    return 1;
  }
  
  strengths = (string *)ob->query_property("strengths");
  if(strengths && member_array("magic", strengths) != -1) {
    message("magic",ob->query_cap_name()+" resists your magic!",tp);
    return 1;
  }

  weakness = (string *)ob->query_property("weakness");
  if(!weakness) weakness = ({});

  if(limb == "all") cost = 200;
  else if(member_array(limb, (string *)ob->query_limbs()) == -1)
      return notify_fail((ob==tp?"You do":ob->query_subjective()+" does")+" not have a "+limb+".\n");
  else if(limb == "head" || limb == "torso") cost = 90;
  else cost = 35;
  cost = cost/2 + random(cost/2);

  if((int)tp->query_mp() < cost)
    return notify_fail("Too low on magic power.\n");
  
  tp->add_mp(-cost);
  tp->set_disable();
  tp->set_magic_round();

  if(limb == "all")
    amount = (healing - (int)ob->query_skill("magic defense"))/3;
  else
    amount = (healing - (int)ob->query_skill("magic defense"))/2;
  
  if(member_array("magic", weakness) != -1)
    amount += random(20);

  tp->add_skill_points("healing", amount * 2);

  if((int)ob->query_alignment() < -140)
    tp->add_alignment(amount/10);
  else
    tp->add_alignment(-5);

  if(limb == "all") {
    foreach (string onelimb in ob->query_limbs())
      ob->heal_limb(onelimb, -(amount/2));
    send_messages(tp, ob, clas, limb);
  }
  else {
    if (limb == "head" || limb == "torso")
      ob->heal_limb(limb, -(random(amount)));
    else
      ob->heal_limb(limb, -amount);
    send_messages(tp, ob, clas, limb);
  }

  return 1;
}

void send_messages(object tp, object ob, string clas, string limb) {
  string what, thing;

  switch (clas) {
    case "cleric":
      thing = "prayer";
      what = "a prayer of deathly rot";
      break;
    case "blue":
      thing = "magic";
      what = "a spell of deathly rot";
      break;
    default:
      thing = "nonsense";
      what = "nonsense";
  }

  if(tp == ob) {
    message("magic","You rot your own limbs through "+thing+".",tp);
    message("magic",tp->query_cap_name() + " mutters "+what+".",
      environment(tp), tp);
  }
  else {
    message("magic","You rot "+ob->query_cap_name()+"'s "+limb+
      " through "+thing+".", tp);
    message("magic",tp->query_cap_name()+" rots your "+limb+
      " through "+thing+".", ob);
    message("magic",tp->query_cap_name()+" mutters "+what+".",
      environment(tp), ({tp,ob}) );
  }
}


void help() {
  write("Syntax: <rot [enemy] [limb]>\n\n"
    "Brings a plague of rotting wounds onto the named limb of your\n"
    "opponent.  Casters of this spell should be careful indeed!  For\n"
    "the casting of this spell against the wrong people also rots\n"
    "the moral fiber which forms the base of your powers!\n"
    "Note: <all> can be used in place of <limb>\n"
  );
}

