#include <std.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "cleric" &&
      tp->query_skill("belief") >= 30*6 &&
      tp->query_skill("healing") >= 30*6)
    return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <regenerate [whom]>\n\n"
    "This spell heals the target's health and stamina over time.",
    this_player());
}

int ok_cast(object tp, object tgt) {
  
  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");
  
  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (tp->query_ghost())
    FAIL("You cannot cast that in your current state.\n");
  
  if (environment(tp)->query_property("no magic"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("Regenerate whom?\n");

  if (!living(tgt))
    FAIL("You can't heal things that aren't alive.\n");

  if (tgt->query_ghost())
    FAIL("It's a little late to be healing "+tgt->query_objective()+".\n");

  if (tgt->query("regenerate_spell"))
    FAIL("You are already regenerating "+tgt->query_objective()+".\n");

  return 1;
}

int cmd_regenerate(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;

  int wis, faith, heal;
  int cost, times, howmuch;
  int i;

  if (!spell()) return 0;

  if (str == "me" || str == "myself")
    tgt = tp;
  else if (sizeof(str))
    tgt = present(str, env);

  if (!ok_cast(tp, tgt)) return 0;
  
  wis=tp->query_stats("wisdom");
  faith=tp->query_skill("belief");
  heal=tp->query_skill("healing");
  
  cost=170+random(tp->query_level());
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");
  
  tp->set_magic_round(1);
  tp->add_mp(-cost);

  howmuch=heal/7+faith/10+wis;
  times=4+(heal-40)/80+(wis-20)/50;
  if (times > 10) times=10;

  message("magic",COL+"A soft light fills the room and begins to heal you."+RES, tgt);
  message("magic",COL+"A soft light surrounds "+tgt->query_cap_name()+"."+RES,
                  environment(tgt), tgt);

  if (tp != tgt)
    tp->add_alignment(5+times);

  tgt->set("regenerate_spell", 1);
  call_out("do_regen",0,({tp,tgt,howmuch,times}));

  return 1;
}

void do_regen(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  int howmuch=args[2];
  int times=args[3];
  
  if (!tgt) return;
  if (!tp) { tgt->set("regenerate_spell", 0); return; }
  tgt->add_hp(howmuch);
  tgt->add_sp(howmuch/3);
  tp->add_mp(-(35+random(6)));

  if (tp->query_mp() < 100 || --times < 1) {
    message("magic", COL+"The light around you fades."+RES, tgt);
    message("magic", COL+"The light around "+tgt->query_cap_name()+
                     " fades."+RES, environment(tgt), tgt);
    tgt->set("regenerate_spell", 0);
  }
  else
    call_out("do_regen",6,({tp,tgt,howmuch,times}));
}

