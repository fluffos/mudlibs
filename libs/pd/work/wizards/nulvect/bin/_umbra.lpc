
#include <std.h>

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define UMBRA_PROP "umbra_spell_info"

inherit DAEMON;

object *who = ({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 25*6 &&
      tp->query_skill("magic defense") >= 25*4)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <umbra [whom]>\n\n"
    "A dark defensive spell that partially surrounds the target "
    "in a protective darkness. The umbra only covers the more vital "
    "parts of the body normally, but it is much more "
    "responsive when surrounding those with dark hearts.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are too dead to cast that.");

  if (!tgt)
    FAIL("Make an umbra around whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (sizeof(tgt->query(UMBRA_PROP)))
    FAIL((tgt==tp?"You are":capitalize(tgt->query_subjective())+" is")+
      " already surrounded by an umbra.");
  
  return 1;
}

int cmd_umbra(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int amt, time, cost;
  string my, their;
  string *limbs;

  if (!spell()) return 0;

  if (str == "me")
    tgt=tp;
  else if (str)
    tgt=present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  time = 25+tp->query_skill("necromancy")/3;
  if (tgt->query_alignment() < 1000)
    time *= 1.5;
  time += random(tp->query_stats("wisdom")*2+time/7);
  
  amt = 2+(tp->query_skill("magic defense")-25*4)/7;
  if (tgt->query_alignment() < 1000)
    amt += 2;
  amt += random(2+tp->query_stats("intelligence")/45);
  if (amt > 7) amt = 7+(amt-7)/2;
  
  cost = (amt*10)+(time/2);

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");
  tp->set_magic_round(1);
  tp->add_mp(-(cost+random(cost/3)));

  limbs = ({"head","torso","abdomen","horse torso","feline torso"});
  if (tgt->query_alignment() < 1000)
    limbs += ({"right arm","left arm",
               "first arm","second arm","third arm","fourth arm"});
               
  foreach (string limb in limbs) {
    if (tgt->query_is_limb(limb))
      tgt->add_magic_protection(({limb, amt, 0}));
    else
      limbs -= ({limb});
  }

  if (tp == tgt) {
    my = "yourself";
    their = tp->query_objective()+"self";
  }
  else {
    my = their = tgt->query_cap_name();
    message("magic", COL+tp->query_cap_name()+" creates a "+
      COL2+"d"+COL+"a"+COL2+"r"+COL+"k"+COL2+" u"+COL+"m"+COL2+"b"+COL+"r"+COL2+"a"+COL+
      " around you."+RES, tgt);
    tp->add_alignment(1);
  }

  message("magic", COL+"You create a "+
    COL2+"d"+COL+"a"+COL2+"r"+COL+"k"+COL2+" u"+COL+"m"+COL2+"b"+COL+"r"+COL2+"a"+COL+
    " around "+my+"."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" creates a "+
    COL2+"d"+COL+"a"+COL2+"r"+COL+"k"+COL2+" u"+COL+"m"+COL2+"b"+COL+"r"+COL2+"a"+COL+
    " around "+their+"."+RES,
    env, ({tgt, tp}) );

  tgt->set(UMBRA_PROP, ({time()+time, amt, limbs}) );
  who += ({tgt});
  set_heart_beat(2);
    
  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    if (!p) who -= ({p});
    else {
      mixed *info = p->query(UMBRA_PROP);
      if (sizeof(info) < 3)
        who -= ({p});
      else if (info[0] < time()) {
        foreach (string limb in info[2])
          p->add_magic_protection(({limb, -info[1], 0}));
        p->set(UMBRA_PROP, 0);
        who -= ({p});
        message("magic", COL2+"The "+COL+"umbra"+COL2+" around "
          "you dissipates."+RES, p);
        message("magic", COL2+"The "+COL+"umbra"+COL2+" around "+
          p->query_cap_name()+" dissipates."+RES, environment(p), p);
      }
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}


