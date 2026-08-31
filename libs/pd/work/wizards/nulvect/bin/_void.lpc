
#include <std.h>

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define VOID_CAST_PROP "void_spell_caster"
#define VOID_VICT_PROP "void_spell_victim"

inherit DAEMON;

object *cast = ({});
object *vict = ({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "black" &&
      tp->query_skill("magic attack") >= 5*35 &&
      tp->query_skill("wizardry") >= 5*35 &&
      tp->query_skill("conjuring") >= 3*35 &&
      tp->query_skill("magic defense") >= 3*35)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <void [whom]>\n\n"
    "A spell of utter darkness. Voiding someone empties part of their "
    "life force into the surrounding area, and a strong caster can then "
    "make use of it as a shield for himself.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your magic fails to take hold.");

  if (!tgt)
    FAIL("Void whose life force?");

  if (!living(tgt))
    FAIL("That is not alive!");

  if (tgt == tp)
    FAIL("That would not be a good idea.");

  if (sizeof((int)tgt->query(VOID_VICT_PROP)))
    FAIL(capitalize(tgt->query_subjective())+
         " has already had "+tgt->query_possessive()+
         " life force voided.");

  return 1;
}

int cmd_void(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int con, dex, ac, rounds, cost;
  int prev, max;
  mixed *tmp;
  
  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  con = tp->query_stats("intelligence")*3/5;
  con += tp->query_skill("wizardry")/15;
  con -= tgt->query_stats("wisdom")*2/3;
  if (con < 5) con=5;
  
  dex = tp->query_stats("intelligence")/6;
  dex += tp->query_skill("conjuring")/11;
  dex -= tgt->query_stats("wisdom")/3;
  if (dex < 1) dex=1;

  rounds = tp->query_skill("magic attack");
  rounds += tp->query_skill("magic defense");
  rounds += tp->query_stats("wisdom")*2;
  rounds /= 19;
  if (rounds < 5) rounds=5;
  if (rounds > 30) rounds=30+(rounds-30)*2/3;

  tmp = tp->query(VOID_CAST_PROP);
  if (!sizeof(tmp))
    tmp = ({});

  ac = 1+con/13+random(con/12);
  ac -= sizeof(tmp)*2;
  if (ac < 0) ac = 0;
  
  cost = 100 + con + dex + rounds*6 + sizeof(tmp)*65;

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->add_mp(-(cost-random(cost/9)));
  tp->set_magic_round(1);

  message("magic", COL+"A dark v"+COL2+"o"+COL+"i"+COL2+"d"+COL+
                   " su"+COL2+"rr"+COL+"ounds "+tgt->query_cap_name()+"!",
                   env, tgt);
  message("magic", COL+"A dark v"+COL2+"o"+COL+"i"+COL2+"d"+COL+
                   " su"+COL2+"rr"+COL+"ounds you!"+RES+"\n"+
                   COL2+"You feel your l"+COL+"ife"+COL2+" force "
                   "e"+COL+"mp"+COL2+"t"+COL+"yi"+COL2+"ng away..."+RES, tgt);
  if (ac) {
    tp->add_magic_protection( ({0, ac, 0}) );
    message("magic", COL2+"You d"+COL+"r"+COL2+"aw "+tgt->query_possessive()+
                     " emp"+COL+"ti"+COL2+"ed life force into a "+
                     COL+"shi"+COL2+"e"+COL+"ld"+COL2+" around you.", tp);
  }
  
  tgt->add_stat_bonus("constitution", -con);
  tgt->add_stat_bonus("dexterity", -dex);
  tgt->set(VOID_VICT_PROP, ({ time()+rounds*2, con, dex }) );

  // this is on purpose, it's an array of arrays
  tmp += ({ ({ time()+rounds*2, ac }) });

  tp->set(VOID_CAST_PROP, tmp);

  if (member_array(tp, cast) == -1)
    cast += ({ tp });
  vict += ({ tgt });

  set_heart_beat(5);
  
  return 1;
}

void heart_beat() {
  foreach (object who in cast) {
    mixed *tmp;
    if (!who) {
      cast -= ({ who });
      continue;
    }
    tmp = who->query(VOID_CAST_PROP);
    foreach (mixed *arr in tmp) {
      int time = arr[0];
      int ac = arr[1];
      if (time() >= time) {
        who->add_magic_protection( ({0, -ac, 0}) );
        tmp -= ({ arr });
      }
    }
    who->set(VOID_CAST_PROP, tmp);
    if (!sizeof(tmp)) {
      cast -= ({ who });
      message("magic", COL+"Your sh"+COL2+"iel"+COL+"d of life force "
                       "d"+COL2+"issi"+COL+"pates completely."+RES, who);
    }
  }
  foreach (object who in vict) {
    mixed *arr;
    int time;
    int con;
    int dex;
    if (!who) {
      vict -= ({ who });
      continue;
    }
    arr = who->query(VOID_VICT_PROP);
    time = arr[0];
    con = arr[1];
    dex = arr[2];
    if (time() >= time) {
      who->add_stat_bonus("constitution", con);
      who->add_stat_bonus("dexterity", dex);
      who->set(VOID_VICT_PROP, 0);
      vict -= ({ who });
      message("magic", COL2+"Your l"+COL+"if"+COL2+"e f"+COL+"or"+COL2+"ce "
                       "is slowly restored."+RES, who);
    }
  }
  if (!(sizeof(cast) || sizeof(vict))) set_heart_beat(0);
}

