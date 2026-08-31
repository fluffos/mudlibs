#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

object *cast=({});

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "blue" &&
      tp->query_skill("faith") >= 10*5 &&
      tp->query_skill("healing") >= 10*4)
    return 1;
  return 0;
}

int ok_cast(object tp) {
  if (environment(tp)->query_property("no magic"))
    FAIL("You cannot do that here.\n");

  return 1;
}

int heal_me(object thing) {
  object tp=this_player();
  if (member_array(thing,cast) != -1) return 0;
  if (thing == tp) return 1;
  if (tp->query_party() && userp(thing) && thing->query_party() == tp->query_party())
    return 1;
  return 0;
}

int cmd_regenerate(string str) {
  object tp=this_player();
  object *tgts;

  int wis, faith, heal;
  int cost, times, howmuch;
  int i;

  string party;
  
  if (!spell()) return 0;

  if (tp->query_disable()) return 1;

  if (!ok_cast(tp)) return 0;
  
  wis=tp->query_stats("wisdom");
  faith=tp->query_skill("faith");
  heal=tp->query_skill("healing");
  
  if (!(party=tp->query_party())) party="";
  
  tgts=all_inventory(environment(tp));
  tgts=filter(tgts, "heal_me");

  i=sizeof(tgts);

  if (i==0)
    FAIL("You are already regenerating everybody that you can.\n");

  cast+=tgts;
  
  cost=i*30+40+random(tp->query_level());
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");
  
  tp->set_disable(1);
  tp->add_mp(-cost);
  howmuch=heal/4+faith/5+wis/3;
  times=4+(heal-40)/80+(wis-20)/50;
  if (times > 10) times=10;

  message("magic",COL+"A soft light fills the room and begins to heal you."+RES,tgts);
  message("magic",COL+"A soft light surrounds "+tp->query_cap_name()+(i>1?"'s party":"")+"."+RES,
                  environment(tp),tgts);

  call_out("do_regen",0,({tp,tgts,howmuch,times}));

  return 1;
}

void do_remove(object *tgts) {
  cast-=tgts;
}

void do_regen(mixed *args) {
  object tp=args[0];
  object *tgts=args[1];
  int howmuch=args[2];
  int times=args[3];
  
  tgts->add_hp(howmuch);
  tgts->add_sp(howmuch/2);
  tp->add_mp(-(sizeof(tgts)*35));

  if (tp->query_mp() < 100 || --times < 1)
    do_remove(tgts);
  else
    call_out("do_regen",4,({tp,tgts,howmuch,times}));
}

void help() {
  message("help","\n"
    "Syntax: <regenerate>\n"
    "Benevolent casters can regenerate the health and stamina of their party members and themselves.",
    this_player());
}

