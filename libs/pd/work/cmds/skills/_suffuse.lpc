
#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define COL3 "%^YELLOW%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("healing") >= 45*6 &&
      tp->query_skill("belief") >= 45*6)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <suffuse (all)>\n"
    "Suffuse heals the injuries of the caster's party. He can also "
    "choose to heal everyone in the room.",
    this_player() );
}

int can_cast(object tp, object *tgts, string all) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.");

  if (!sizeof(tgts)) {
    if (all != "all") {
      FAIL("There are no companions here to suffuse.");
    }
    else {
      FAIL("There is nobody here to suffuse.");
    }
  }

  return 1;
}

int cmd_suffuse(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;
  int cost, amt;
  string party;

  if (!spell()) return 0;
    
  party = (string)tp->query_party();

  if (str == "all")
    tgts = filter(all_inventory(env), (: $1->is_living() :) );
  else
    tgts = filter(all_inventory(env),
      function (object what, string party) {
        string p;
        if (sizeof(party) && what->is_player() && sizeof(p=what->query_party()) && p == party) return 1;
        return 0;
      }, party);

  tgts -= ({tp});

  if (!can_cast(tp, tgts, str)) return 0;

  amt = tp->query_skill("healing");
  amt += tp->query_skill("belief")/2;
  amt += tp->query_stats("wisdom")*2;
  amt *= 0.67;
  amt -= random(amt/10);

  //cost = amt/5.2;
  cost = amt/3.3;

  foreach (object tgt in tgts) {

    if (tp->query_mp() < cost) {
      if (tgt == tgts[0]) {
        FAIL("You need more magic for that.");
      }
      else {
        message("magic", "You run out of magic for healing.", tp);
        break;
      }
    }

    tp->set_magic_round(1);
    tp->add_mp(-cost);

    message("magic", COL+"Your "+COL2+"hea"+COL+"l"+COL3+"ing"+COL+" powers "+
                     COL2+"suf"+COL3+"fuse"+COL+" "+tgt->query_cap_name()+
                     " with life."+RES, tp);
    message("magic", COL+tp->query_cap_name()+"'s "+COL2+"hea"+COL+"l"+COL3+
                     "ing"+COL+" powers "+
                     COL2+"suf"+COL3+"fuse"+COL+" you with life."+RES, tgt);

    if (tgt->query_hp() < tgt->query_max_hp()*95/100) {
      tp->add_skill_points("healing", 10+amt/50);
      if (tgt->is_player()) {
        tp->add_exp(100+amt*2+tgt->query_level()*15);
      }
    }

    tgt->add_hp(amt+random(amt/11));
    
  }

  if (str != "all")
    message("magic", COL+tp->query_cap_name()+"'s "+COL2+"hea"+COL+"l"+COL3+
                     "ing"+COL+" powers "+COL2+"suf"+COL3+"fuse"+COL+" "+
                     tp->query_possessive()+" party with life."+RES,
                     env, tgts+({tp}) );
  
  return 1;
}
