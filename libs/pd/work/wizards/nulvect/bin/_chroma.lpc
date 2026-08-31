
#include <std.h>

#define RES "%^RESET%^"
#define COL RES+"%^ORANGE%^"
#define COL2 "%^BOLD%^%^MAGENTA%^"
#define COL3 "%^BOLD%^%^GREEN%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

mapping colors = ([
  "blue" : "%^BOLD%^%^BLUE%^",
  "red" : "%^BOLD%^%^RED%^",
  "yellow" : "%^YELLOW%^",
  "green" : "%^BOLD%^%^GREEN%^",
  "purple" : "%^BOLD%^%^MAGENTA%^",
  "white" : "%^BOLD%^%^WHITE%^",
  "black" : "%^BOLD%^%^BLACK%^"
]);

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "wizard" &&
      tp->query_skill("conjuring") >= to_int(23*4.5) &&
      tp->query_skill("wizardry") >= 23*6)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  string tmp="";
  foreach (string k in keys(colors))
    tmp += colors[k]+k+RES+", ";
  tmp = tmp[0..<3];
  message("help",
    "Syntax: <chroma [color] [item]>\n\n"
    "A spell that changes the color of something by forcing "
    "ancient magic through it.\n"
    "The following colors are possible:\n"
    "  "+tmp,
    this_player() );
}

int can_cast(object tp, object item, string col) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your spell fails.");

  if (!col)
    FAIL("What color?");
  if (member_array(col, keys(colors)) == -1)
    FAIL("This spell cannot create such a color.");

  if (!item)
    FAIL("Chroma what?");
  
  return 1;
}

int cmd_chroma(string str) {
  object tp=this_player();
  object env=environment(tp);
  object item;
  int cost;
  string col, what;
  string short, tmp, paren;

  if (!spell()) return 0;

  if (str && sscanf(str, "%s %s", col, what) == 2)
    item=present(what, tp);
  
  if (!can_cast(tp, item, col)) return 0;

  cost = 100;
  
  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->set_magic_round(1);
  tp->add_mp(-(cost-random(cost/7)));

  short = strip_color(item->query_short());
  if (sscanf(short, "%s (%s)", tmp, paren) == 2)
    short = tmp;
  item->set_short(colors[col] + short + RES);
  item->set_long(colors[col] + strip_color(item->query_long()) + RES);

  message("magic",
    COL+"Sw"+COL2+"i"+COL3+"rl"+COL+"ing magic "+
    COL2+"sur"+COL3+"rou"+COL2+"nds"+COL+
    " your "+item->query_name()+" for a moment."+RES, tp);
  message("magic",
    COL+"Sw"+COL2+"i"+COL3+"rl"+COL+"ing magic "+
    COL2+"sur"+COL3+"rou"+COL2+"nds"+COL+
    " "+tp->query_cap_name()+"'s "+item->query_name()+
    " for a moment."+RES, env, tp);

  return 1;
}

