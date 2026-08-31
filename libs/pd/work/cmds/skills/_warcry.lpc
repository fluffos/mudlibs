
#include <std.h>

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define WARCRY_PROP "warcry_abil_time"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp &&
      member_array(tp->query_subclass(), ({"berserker","antipaladin"}) ) != -1 &&
      // level 40 for berserkers, 34 for antis
      tp->query_skill("ferocity") >= 200)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <warcry>\n\n"
    "A fierce fighter can shout forth a warcry to "
    "faze those around him.",
    this_player() );
}

int can_cast(object tp, object *tgts) {
  
  if (!tp) return 0;

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You let forth a ghostly wail.");

  if (!sizeof(tgts))
    FAIL("There is nobody here to attack!");
  
  return 1;
}

int cmd_warcry(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;
  int time, cost, tmp;

  if (!abil()) return 0;

  tgts = filter(all_inventory(env),
    function (object who, string party) {
      if (!living(who)) return 0;
      if (who == this_player()) return 0;
      if (who->query_rider() == this_player()) return 0;
      if (party) {
        if (who->query_party() && who->query_party() == party) return 0;
        if (who->query_rider() && who->query_rider()->query_party() == party) return 0;
      }
      return 1;
    }, this_player()->query_party() );

  if (!can_cast(tp, tgts)) return 0;

  // time in rounds
  time = 8;
  time += (tp->query_skill("ferocity")-200)/25;
  if (time > 15) time = 15;

  // the more often you use it, the more it costs each time
  if (tmp = (int)tp->query(WARCRY_PROP)) {
    tmp = time() - tmp;
    tmp = 32 - tmp;
    if (tmp < 0)
      tmp = 0;
  }
  cost = time*3;
  cost += tmp;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");
  
  tp->set_disable();
  tp->add_sp(-cost);
  tp->set(WARCRY_PROP, time());
  
  message("info", "You let forth a "+COL+"fierce"+RES+" warcry!", tp);
  message("info", tp->query_cap_name()+" lets forth a "+
                  COL+"fierce"+RES+" warcry!", env, tp);
  
  foreach (object tgt in tgts) {
    int penalty;
    penalty = tgt->query_skill("defense")/4;
    if (tgt->query_level() > tp->query_level())
      penalty -= (tgt->query_level() - tp->query_level())*2;
    if (penalty < 5) penalty = 5;
    if (!tgt->query_skill_bonus("defense"))
      tgt->add_skill_bonus("defense", -penalty, time*2);
  }

  return 1;
}

