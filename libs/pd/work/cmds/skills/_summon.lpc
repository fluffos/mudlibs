
#include <std.h>
#include <dirs.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^YELLOW%^"
#define COL2 "%^BOLD%^%^BLACK%^"

#define FAIL(s) return notify_fail(s+"\n")

#define SUMMON_DIR DIR_CLASS_CMDS+"/obj/summon/"
#define SUMMON_PROP "summon_spell_info"
#define SUMMON_DELAY 30

inherit DAEMON;

mapping demons = ([
 "nightmare" : 40,
 "imp" : 50,
 "kalkydri" : 65,
 "assassin" : 80,
]);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "kataan" &&
   tp->query_skill("summoning") >= 40)
    return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
   "Syntax: <summon [demon]>\n"
   "        <summon list>\n\n"
   "Kataans may summon minor demons from the Abyss. "
   "They may then <command> them to do their bidding, but an unskilled "
   "summoner could lose control.\n"
   "Commanding a demon to <reveal powers> will show any special "
   "abilities it may have, and they can be forced to <return> to "
   "the Abyss when their task is completed.",
   this_player() );
}

int can_cast(object tp, string str) {
  mixed *info;

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("The demons ignore your pitiful call.");

  if (!strlen(str))
    FAIL("Summon what?");

  if (str != "list")
    if (!demons[str] ||
     tp->query_skill("summoning") < demons[str])
      FAIL("You do not know how to summon that.");

  if (str != "list" && sizeof(info = tp->query(SUMMON_PROP))) {
    if (info[0])
      FAIL("You cannot control more than one demon at a time.");
    if (info[1] + SUMMON_DELAY > time())
      FAIL("The demons ignore your pitiful call.");
  }

  if (str != "list" && tp->query_mp() < demons[str])
    FAIL("Your magic power is too low.");

  return 1;
}

int cmd_summon(string str) {
  object tp = this_player();
  object env = environment(tp);
  object ob;
  string *list;
  int req, cost;

  if (!spell()) return 0;

  if (!can_cast(tp, str)) return 0;

  if (str == "list") {
    list = keys(filter(demons, (:
       $3->query_skill("summoning") >= $2
      :), tp));
    list = sort_array(list, (:
      $3[$1] > $3[$2] ? 1 : -1
     :), demons );
    list = map(list, (: "  "+capitalize($1) :) );
    message("info",
     "  %^BOLD%^%^WHITE%^Known Demons%^RESET%^\n"
     "%^BOLD%^%^BLUE%^+=+=+=+=+=+=+=+=%^RESET%^\n"+
     implode(list, "\n")+"\n", tp);
    return 1;
  }

  req = demons[str];
  cost = req;
  cost += random(cost/2);

  if (tp->query_mp() < cost)
    FAIL("Your magic power is too low.");

  tp->set_magic_round(1);
  tp->add_mp(-cost);

  if (random(req/2) > random(tp->query_skill("summoning"))) {
    message("magic", "You fail to summon anything.", tp);
    return 1;
  }

  ob = new(SUMMON_DIR+str);
  if (!ob)
    FAIL("An error occurred, please contact a staff member.");

  message("magic", COL+"You summon forth "+indefinite_article(str)+
   " from the Abyss!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" summons forth "+
   indefinite_article(str)+" from the Abyss!"+RES,
   env, tp);

  tp->set(SUMMON_PROP, ({ ob, time() }));
  //  ob->set_name(str+" "+tp->query_name());
  ob->set_owner(tp);
  ob->add_assist(tp);
  ob->move(env);

  message("magic", COL2+ob->query_summon_msg()+RES, env);

  tp->add_skill_points("summoning", req/2);

  return 1;
}
