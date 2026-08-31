// Author (??)
// Help added by Brian (1/28/92)
// rehack to check kill_ob first before continuing with kill and PK labeling
// by Valodin, Feb 13, 1993
// minor changes by Bohemund, Jan 22, 1993
// kill all and kill all <type> enabled by inferno, 7/23/00
//
// completely rewritten by Nulvect 2010-11-02

#include <std.h>

#define COL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;
 
int try_to_kill(object tp, object liv);

void help() {
  message("info",
    "Syntax: <kill [living]>\n"
    "        <kill all>\n"
    "        <kill all [type]>\n\n"
    "This command is used to initiate combat with the "
    "living being(s) you specify. Once combat begins you may "
    "only end it by running away or if one of you dies. "
    "Attacking city guards or players may have dire consequences.\n\n"
    "See book on playerkilling in library\n"
    "See also: death, wimpy, wimpydir, follow, party\n",
    this_player() );
}

int cmd_mykill(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *victims;
  string type;
  int multi, success;

  if (env->query_property("no attack"))
    return notify_fail("Some force prevents your violence.");
 
  if (tp->query_ghost())
    return notify_fail("You may not attack anyone as a ghost.");

  if (tp->query_busy())
    return notify_fail("You are busy doing something else.");

  if (!str)
    return notify_fail("Kill what?");

  if (str == "all") {
    victims = filter(all_inventory(env),
      (: $1->is_living() && !$1->query_invis() :)
    );
    victims -= tp->query_allies();

    if (!sizeof(victims))
      return notify_fail("There is nobody here to attack!");

    multi = 1;
  }

  else if (sscanf(str, "all %s", type) == 1) {
    victims = filter(all_inventory(env),
      (: $1->is_living() && !$1->query_invis() && $1->id($2) :), type
    );
    victims -= tp->query_allies();

    if (!sizeof(victims))
      return notify_fail("There are no "+pluralize(type)+" here!");

    multi = 1;
  }
  
  else {
    object tgt = present(str, env);

    if (!tgt)
      return notify_fail("You don't see that here.");
    
    if (!tgt->is_living())
      return notify_fail("That is not alive.");
    
    if (tgt == tp)
      return notify_fail("Kill yourself?");

    victims = ({ tgt });
  }

  if (multi) {
    if (!wizardp(tp))
      victims = filter(victims, (: !wizardp($1) :) );
  }

  foreach (object liv in victims) {
    int ret = try_to_kill(tp, liv);

    if (ret) {
      success++;
      message("combat", COL+tp->query_cap_name()+" attacks you!"+RES, liv);
      message("combat", COL+"You attack "+liv->query_cap_name()+"!"+RES, tp);
      message("combat", COL+tp->query_cap_name()+" attacks "+
                        liv->query_cap_name()+"!"+RES, env, ({ tp, liv }) );
    }

  }

  // try_to_kill uses notify_fail, so just return 0 here and player will get
  // the last fail message
  if (!success)
    return 0;

  return 1;
}

int try_to_kill(object tp, object liv) {
  if (liv->query_ghost())
    return notify_fail("You cannot attack ghosts.");

  if (liv->query_property("passive"))
    return notify_fail("A strange force prevents your attack.");
  
  // this func sends a message() for some stupid reason...
  return tp->kill_ob(liv);

}

