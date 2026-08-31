
#include <std.h>

#define RES "%^RESET%^"
#define COL RES+"%^CYAN%^"
#define COL2 "%^BOLD%^%^RED%^"

#define FAIL(s) return notify_fail(s+"\n")

#define BLOODWEB_PROP "bloodweb_spell_info"

inherit DAEMON;

object *who = ({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("magic defense") >= 33*4 &&
      tp->query_skill("necromancy") >= 33*6)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <bloodweb [whom]>\n\n"
    "Creates a magically charged web of the caster's blood "
    "around the target. The fine web serves as protection.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;
  
  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You have no blood as a ghost.");

  if (!tgt)
    FAIL("Cast it around whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt->query(BLOODWEB_PROP))
    FAIL((tgt==tp?"You are":capitalize(tgt->query_subjective())+" is")+
         " already surrounded by a blood web.");
  
  return 1;
}

int cmd_bloodweb(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int cost, rounds, prot;
  int tmp;

  if (!spell()) return 0;

  if (str == "me")
    tgt = tp;
  else if (str)
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;


  rounds = 20;
  tmp = (tp->query_stats("wisdom")-50)/3;
  if (tmp < 1) tmp=0;
  tmp += (tp->query_skill("magic defense")-130)/6;
  if (tmp < 1) tmp=0;
  rounds += tmp;
  if (rounds > 60) rounds = 60+(rounds-60)/3.4;

  prot = 2;
  tmp = (tp->query_stats("intelligence")-50)/9;
  if (tmp < 1) tmp=0;
  tmp += (tp->query_skill("necromancy")-200)/25;
  if (tmp < 1) tmp=0;
  prot += tmp;
  if (prot > 4) prot = 4+(prot-4)/2.25;

  cost = rounds*4.2 + prot*32;

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");
  if (tp->query_hp() <= cost)
    FAIL("You are lacking in blood.");

  tp->add_mp(-(cost+random(cost/5)));
  tp->add_hp(-(cost-random(cost/6)));
  tp->set_magic_round(2);
  
  tgt->set(BLOODWEB_PROP, ({tp, time()+rounds*2, prot}) );
  tgt->add_magic_protection( ({0, prot, 0}) );
  who += ({ tgt });
  set_heart_beat(4);
  
  message("magic",
    COL2+"Blood fl"+COL+"o"+COL2+"ws and forms a fine "+
    COL+"sh"+COL2+"i"+COL+"mm"+COL2+"e"+COL+"r"+COL2+"i"+COL+"ng"+COL2+
    " web around "+(tgt==tp?"you":tgt->query_cap_name())+"."+RES, tp);
  
  message("magic",
    COL2+"Blood fl"+COL+"o"+COL2+"ws and forms a fine "+
    COL+"sh"+COL2+"i"+COL+"mm"+COL2+"e"+COL+"r"+COL2+"i"+COL+"ng"+COL2+
    " web around "+tgt->query_cap_name()+"."+RES, env, ({tp, tgt}) );

  if (tgt != tp)
    message("magic",
      COL2+"Blood fl"+COL+"o"+COL2+"ws and forms a fine "+
      COL+"sh"+COL2+"i"+COL+"mm"+COL2+"e"+COL+"r"+COL2+"i"+COL+"ng"+COL2+
      " web around you."+RES, tgt);
  
  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    if (!p) who -= ({p});
    else {
      mixed *info = p->query(BLOODWEB_PROP);
      if (sizeof(info) < 3)
        who -= ({p});
      else if (info[1] < time()) {
        p->add_magic_protection( ({0, -info[2], 0}) );
        p->set(BLOODWEB_PROP, 0);
        who -= ({p});
        message("magic", COL+"The web of "+
                         COL2+"blood"+COL+" disappears."+RES, p);
        message("magic", COL+"The web of "+COL2+"blood"+COL+
                         " around "+p->query_cap_name()+" disappears."+RES,
                         environment(p), p);
      }
      else if (random(100) < 9) {
        message("magic", COL2+"The web "+
          COL+"sh"+COL2+"i"+COL+"mm"+COL2+"e"+COL+"rs"+COL2+
          " around you.", p);
      }
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}

