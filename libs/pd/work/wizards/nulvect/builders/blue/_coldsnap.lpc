#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "blue" &&
      tp->query_skill("faith") >= 35*5 &&
      tp->query_skill("conjuring") >= 35*3)
    return 1;
  return 0;
}

int ok_cast(object tp) {
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  return 1;
}

int hit_me(object thing) { if (thing->is_living()) return 1; else return 0; }

int cmd_coldsnap(string str) {
  object tp=this_player();
  object *tgts;

  int intel, wis, faith, conj;
  int twis, tmd;
  int cost, len;
  int i;
  
  if (!spell()) return 0;

  if (tp->query_disable()) return 1;

  if (!ok_cast(tp)) return 0;
  
  intel=tp->query_stats("intelligence");
  wis=tp->query_stats("wisdom");
  faith=tp->query_skill("faith");
  conj=tp->query_skill("conjuring");
  
  tgts=all_inventory(environment(tp));
  tgts=filter(tgts, "hit_me");

  i=sizeof(tgts);

  cost=i*100+50+random(tp->query_level());
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");
  
  tp->set_disable(1);
  tp->add_mp(-cost);

  message("magic",COL+"You concentrate your powers and suddenly the area freezes solid!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" closes "+tp->query_possessive()+ " eyes and "
                  "suddenly the area freezes solid!"+RES,environment(tp),tp);

  for (i--;i>=0;i--) {
    if (tgts[i] == tp) continue;
    twis=tgts[i]->query_stats("wisdom");
    tmd=tgts[i]->query_skill("magic defense");
    
    len=wis/30+intel/50+faith/60+conj/70;
    len-=twis/30+tmd/80;
    if (len < 6) len=6;
    tgts[i]->set_paralyzed(len,"You are frozen solid.","You break free of the ice.");
  }

  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <coldsnap>\n"
    "Blue dragons can freeze the whole room in place using their frosty magic.",
    this_player());
}

