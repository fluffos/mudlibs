
#include <std.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

#define CHECK "protect_spell"

#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("magic defense") >= 15*5 &&
      tp->query_skill("belief") >= 15*6)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <protect (whom)|(all)>\n\n"
    "This defensive spell will protect the caster's party. "
    "Clerics can also spread it out to everyone in the room, "
    "or protect just a single person.",
    this_player() );
}

int can_cast(object tp, object *tgts, int multi) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no magic"))
    FAIL("Some force prevents you from casting that.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (tp->query_ghost())
    FAIL("You are far too dead to do that.\n");

  if (!sizeof(tgts)) {
    if (multi) {
      FAIL("Everyone here is already protected.\n");
    }
    else {
      FAIL("Protect whom?\n");
    }
  }

  if (!tgts[0])
    FAIL("Protect whom?\n");

  if (!living(tgts[0]))
    FAIL("That is not alive.\n");

  if (tgts[0]->query(CHECK))
    FAIL((tgts[0]==tp?"You are":tgts[0]->query_cap_name()+" is")+
         " already protected.\n");

  return 1;
}

int cmd_protect(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;
  int cost, time, strong;
  int multi=0;
  string party=(string)tp->query_party();
  string my, your, their;

  if (!spell()) return 0;
  
  if (!str || str == "") {
    tgts = filter(all_inventory(env),
      function (object who, string party) {
        string p;
        if (party && userp(who) && !(who->query(CHECK)) &&
            p=who->query_party() && p == party)
              return 1;
        return 0;
      }, party) + ({tp});
    my = "your party";
    your = "the party";
    their = tp->query_possessive()+" party";
    multi=1;
  }
  else if (str == "all") {
    tgts = filter(all_inventory(env),
      (: $1->is_living() && !($1->query(CHECK)) :) );
    my = your = their = "everyone";
    multi=1;
  }
  else {
    if (str == "me" || str == "myself") {
      tgts = ({tp});
    }
    else {
      tgts = ({present(str, env)});
    }
  }

  if (!can_cast(tp, tgts, multi)) return 0;

  time = 30+tp->query_skill("magic defense")/3;
  time += random(time/4);

  // every 8 levels of maxed md and belief, gain one more point
  strong = tp->query_skill("belief")/2;
  strong += tp->query_skill("magic defense");
  strong -= (15*5)+(15*6/2);
  strong /= 64;
  
  if (strong < 1) strong = 1;
  if (strong > 5) strong = 5;

  strong += random(2);

  cost = time*5 + strong*15;
  cost *= 1.0+((sizeof(tgts)-1)*0.2);
  cost *= 0.55;

  if (tp->query_mp() < cost)
    FAIL("You do not have enough magic for that.\n");

  tp->set_magic_round(1);
  tp->add_mp(-(cost-random(cost/11)));

  if (!my || !your || !their) {
    if (tp == tgts[0]) {
      my = "yourself";
      their = tp->query_objective()+"self";
    }
    else
      my = their = tgts[0]->query_cap_name();
    your = "you";
  }
  
  message("magic", COL+"You create a wall of protection around "+my+"."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" creates a wall of protection "
                   "around "+your+"."+RES, tgts, tp);
  message("magic", COL+tp->query_cap_name()+" creates a wall of protection "
                   "around "+their+"."+RES, env, tgts+({tp}));

  tp->add_skill_points("magic defense", strong*3);
  
  tgts->add_magic_protection( ({0, strong, time}) );
  tgts->set(CHECK,1);
  call_out("remove_protect", time, tgts);
  
  return 1;
}

void remove_protect(object *tgts) {
  if (!sizeof(tgts)) return;
  message("magic", COL+"The protective wall around you vanishes.\n"+RES, tgts);
  tgts->set(CHECK,0);
}

