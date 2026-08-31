
#include <std.h>
#include <move.h>

#define TOO_DARK_ROOM -6
#define TOO_DARK_BAG -2

#define GET_SINGLE 1
#define GET_ALL 2
#define GET_FROM 4
#define GET_MULTI 8
#define GET_COINS 16

#define MONEY_ID "pile of coins"

#define FAIL(s) return notify_fail(strip_color(s)+"\n")

inherit DAEMON;

mixed try_to_get_ob(object ob, int flag);

void help() {
  message("help",
    "Command: get\n"
    "Syntax: <get item | number items | (all) [(from) container]>\n\n"
    "This command lets you pick up items or take items out of a container.\n"
    "For example, you can get sword, get 3 swords, get all, "
    "get potion from backpack, or even get 200 gold coins.",
    this_player() );
}

int cmd_get(string str) {
  object tp=this_player();
  object env=environment(tp);
  object from;
  object pile;
  object *what = ({});

  string bagstr, fromshort, inshort;
  string cur;
  string *got = ({});

  int sight;
  int num;
  int flag=0;
  int st;

  if (tp->query_ghost())
    FAIL("You cannot do that in your immaterial state.");
  
  if (!str || str == "")
    FAIL("Get what?");

  sight = total_light(tp) + tp->query_sight_bonus();
  
  // first, figure out just what we're supposed to get, and from where
  
  // get something from container
  if (sscanf(str, "%s from %s", str, bagstr) == 2)
    flag ^= GET_FROM;

  // get 5 swords
  if (sscanf(str, "%d %s", num, str) == 2) {

    // get 1 sword (dumb)
    if (num == 1)
      flag ^= GET_SINGLE;

    else
      flag ^= GET_MULTI;

    // get 500 gold coins
    // get 1 gold coin
    if (sscanf(str, "%s coin%*s", cur) >= 1)
      flag ^= GET_COINS;
  }

  // get all
  else if (str == "all")
    flag ^= GET_ALL;

  // get something
  else
    flag ^= GET_SINGLE;

  
  // ok, now run a bunch of checks to figure out if we actually have
  // the named item(s), the container, enough coins, or whatever
  
  if (flag & GET_FROM) {
    from = present(bagstr, tp);
    if (!from)
      from = present(bagstr, env);
    if (!from)
      FAIL("You do not have "+bagstr+".");
    if (sight < TOO_DARK_BAG)
      FAIL("It is too dark.");
    if (from->query_closed())
      FAIL("It is closed.");
    if (living(from))
      FAIL("You could just ask for it.");
    inshort = "in "+from->query_short();
    fromshort = " from "+from->query_short();
  }
  else {
    if (sight < TOO_DARK_ROOM)
      FAIL("It is too dark.");
    from = env;
    inshort = "here";
    fromshort = "";
  }

  if (flag & GET_COINS) {
    pile = present(MONEY_ID, from);
    
    if (!pile || !pile->is_money_pile())
      FAIL("There are no coins "+inshort+".");

    if ((int)pile->query_money(cur) < num)
      FAIL("There "+(flag & GET_SINGLE ? "is" : "are")+
           " not "+num+" "+str+" "+inshort+".");
  }
  else if (flag & GET_SINGLE) {
    object tmp = present(str, from);
    if (!tmp)
      FAIL("There is no "+str+" "+inshort+".");
    what = ({ tmp });
  }
  else if (flag & GET_MULTI) {
    object tmp;
    // "get -5 swords"
    if (num < 1)
      FAIL("You can't take less than one of something.");
    // "get 200 coins"
    if (str == "coins" || str == "coin")
      FAIL("Get what kind of "+str+"?");
    // first try cutting off "s", then try cutting off "es", then the word itself
    foreach (string s in ({ str[0..<2], str[0..<3], str }) ) {
      // if there are at least num things by that name...
      if (tmp = present(s+" "+num, from)) {
        // ...then grab them all
        for (int i=1; i <= num; i++)
          what += ({ present(s+" "+i, from) });
        break;
      }
    }
    if (!tmp)
      FAIL("There are not "+cardinal(num)+" "+str+" "+inshort+".");
  }
  else if (flag & GET_ALL) {
    what = all_inventory(from);
    what = filter(what, (: !living($1) :) );
    if (!sizeof(what))
      FAIL("There is nothing "+inshort+" to get.");
  }
  
  // if they're sneaking or stealthing and get a single item, don't show it
  if (st=tp->query_property("stealth") && !(flag & GET_ALL || flag & GET_MULTI)) {
    tp->remove_property("stealth");
    tp->set_property("stealth", st/5);
  }
  else
    st=0;

  // alright, we populated all the variables we need by now,
  // so try to actually get these things
  
  if (flag & GET_COINS) {
    //pile->get_money(tp, cur, num);
    pile->add_money(cur, -num);
    tp->add_money(cur, num);

    message("cmd_get", "You get "+num+" "+str+" from the pile.", tp);

    if (!st)
      message("cmd_get", tp->query_cap_name()+" gets "+
                         num+" "+str+" from the pile.", env, tp);

    return 1;
  }

  foreach (object ob in what) {
    mixed ret = try_to_get_ob(ob, flag);
    if (intp(ret)) {
      if (ret == 0) continue;
      else got += ({ ob->query_short() });
    }
    if (stringp(ret))
      message("cmd_get", ret, tp);
  }

  got = consolidate_string(got);

  foreach (string g in got) {
    message("cmd_get", "You get "+g+fromshort+".", tp);
    if (!st)
      message("cmd_get", tp->query_cap_name()+" gets "+
                       g+fromshort+".", env, tp);
  }
  
  return 1;

}

mixed try_to_get_ob(object ob, int flag) {
  int mv;
  int f = flag & GET_ALL || flag & GET_MULTI;

  if (!ob->query_short())
    return f ? 0 : "Get what?";

  if (ob->query_prevent_get())
    return f ? 0 : ob->query_prevent_get();

  if (!ob->get())
    return f ? 0 : "You cannot get that.";

  if (living(ob))
    return f ? 0 : "Get a living creature?";

  mv = ob->move(this_player());

  switch (mv) {
    case MOVE_OK:
      return 1;
    break;

    case MOVE_NO_ROOM:
      return f ? ob->query_short()+": Too heavy." : "You can't carry that!";
    break;

    default:
      return f ? ob->query_short()+": You cannot do that." : "You cannot do that.";

  }

  return 1;
}
   

