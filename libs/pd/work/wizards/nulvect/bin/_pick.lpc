
#include <std.h>
#include <daemons.h>
#include <money.h>

#define FAIL(s) return notify_fail(s+"\n")

// how many coins == 1 unit of weight??
#define COINS_PER_ONE_WEIGHT 5
// maximum coins to get in one grab = MAX + random(MAX/10)
#define MAX_COINS_PER_PICK 3000

inherit DAEMON;

int steal_his_money(object tp, object tgt, int steal, int rank, mapping money);

int abil() {
  object tp = this_player();
  if (tp && tp->query_skill("stealing") >= 15)
    return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <pick [living]>\n\n"
    "The ability to pickpocket from someone, perhaps getting some money.\n"
    "If a player catches you, you may be branded an outlaw.",
    this_player());
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no steal"))
    FAIL("Some force prevents your mischief.");

  if (tp->query_ghost())
    FAIL("Your immaterial fingers would pass right through the money.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("Pick whose pocket?");

  if (!tgt->is_living())
    FAIL("That's not alive.");

  if (tgt == tp)
    FAIL("You cannot pick your own pocket!");

  if (tgt->is_player()) {

    // FAIL("You may not steal from players.");

    if (!interactive(tgt))
      FAIL("You may not steal from link-dead players.");

    if (tp->is_player()) {

      if (wizardp(tgt) && !wizardp(tp))
        FAIL("You would surely be punished for such insolence.");

      if (tp->query_level() < 20)
        FAIL("You are protected from PK, so "+tgt->query_subjective()+
             " is protected from your sticky fingers.");

      if (tgt->query_level() < 20)
        FAIL("You may not steal from newbies.");
    }
  }

  if (tgt->query_property("no steal"))
    FAIL("You cannot steal from "+tgt->query_objective()+".");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 15)
    FAIL("You are too tired.");

  return 1;
}

int cmd_pick(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  mapping money;
  int rank, steal, weight, exp, perc, outlaw, kill;
  int gotmoney, stolen, stealskill, tmp;
  string mymsg, yourmsg, theirmsg;

  exp = perc = outlaw = kill = stolen = stealskill = gotmoney = tmp = 0;

  mymsg = yourmsg = theirmsg = "";

  if (!abil()) return 0;

  if (str) tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  tp->set_disable(1);
  tp->add_sp(-(8+random(5)));
  tp->add_alignment(-(3+random(3)));

  // build a mapping of information about tgt's money
  money = ([ "total coins" : 0 ]);
  foreach (string c in tgt->query_currencies()) {
    int i = member_array(c, HARD_CURRENCIES);
    if (i == -1) continue;
    money[c] = tgt->query_money(c);
    money["total coins"] += money[c];
  }

  weight = money["total coins"]/COINS_PER_ONE_WEIGHT;

  if (tp->query_subclass() == "thief")
    rank = 1 + tp->query_level()/10;
  else
    rank = 1 + tp->query_level()/15;

  if (rank > 4) rank = 4;

  steal = BALANCE3_D->get_steal(tp, tgt, rank,
    ({ "stealing", "stealth" }),
    ({ "dexterity", "charisma" }) );

  if (weight >= 40)
    steal += to_int(log(weight)-1);

  if (steal < -10) {
    mymsg = "You utterly fail to pick "+tgt->query_cap_name()+"'s pocket.";
    yourmsg = "You catch "+tp->query_cap_name()+" trying to pick your pocket!";
    theirmsg = tp->query_cap_name()+" brushes up against "+
               tgt->query_cap_name()+".";
    perc = 50;
    outlaw = 1;
    kill = 1;
  }

  else if (steal < 1) {
    mymsg = "You fail to pick "+tgt->query_cap_name()+"'s pocket.";
    yourmsg = "You feel a hand in your pocket!";
    perc = 25;
    if (steal < -4)
      outlaw = 1;
    if (random(100) < 50)
      kill = 1;
  }

  else if (steal < 7) {
    gotmoney = 1;
    if (steal+50 < tgt->query_skill("perception")) {
      yourmsg = "You feel someone brush up against you.";
      perc = 15;
      kill = 1;
    }
  }

  else
    gotmoney = 1;

  if (gotmoney) {
    tmp = steal_his_money(tp, tgt, steal, rank, money);
    if (tmp > 0) {
      mymsg = "You pick some coins from "+tgt->query_cap_name()+"'s pocket.";
      exp = tp->query_steal_exp(tp, tgt)*3/4 + tmp;
      stolen = 2;
      stealskill = 50 + tmp;
    }
    else {
      if (money["total coins"] == 0)
        mymsg = capitalize(tgt->query_cap_name())+" seems to be broke!";
      else
        mymsg = "You fail to pick "+tgt->query_cap_name()+"'s pocket.";
      exp = tp->query_steal_exp(tp, tgt)/3;
      stolen = 1;
      stealskill = 30;
    }
  }
  else {
    stolen = 3;
    stealskill = 5+random(6);
  }

  if (tp->query_arena()) {
    outlaw = 0;
    exp = 0;
  }

  tp->add_exp(exp);
  tp->add_skill_points("stealing", stealskill);
  tp->add_stolen(tgt, stolen);
  
  if (tgt->is_player()) {
    if (outlaw)
      tp->caught_theft();
    if (perc > 0)
      tgt->add_skill_points("perception", perc);
  }

  if (kill && tgt->is_monster()) {
    tgt->force_me("kill "+tp->query_name());
    tgt->kill_ob(tp);
  }

  message("info", mymsg, tp);
  if (strlen(yourmsg))
    message("info", yourmsg, tgt);
  if (strlen(theirmsg))
    message("info", theirmsg, env, ({ tp, tgt }) );

  return 1;
}

int steal_his_money(object tp, object tgt, int steal, int rank, mapping money) {
  int max;
  int value = 0;

  max = steal * COINS_PER_ONE_WEIGHT;
  max += random(tp->query_level()/2);
  switch (rank) {
    case 2: max += 15; break;
    case 3: max += 40; break;
    case 4: max += 90; break;
  }

  // should never happen
  if (max < 0) max = 5+random(50);
  if (max > MAX_COINS_PER_PICK)
    max = MAX_COINS_PER_PICK + random(MAX_COINS_PER_PICK/10);

  foreach (string curr in keys(money)-({"total coins"})) {
    int get = 20;
    int tmp = member_array(curr, HARD_CURRENCIES);
    // this makes it more likely to grab higher value coins at higher levels
    if (rank >= 3) {
      switch (curr) {
        case "platinum": get = 25; break;
        case "gold": get = 30; break;
      }
    }
    get = random(get+money[curr]*7/6) + random(9);
    if (get > money[curr]) get = money[curr];
    if (get > max) get = max*5/6 + random(max/6);
    money[curr] -= get;
    max -= get;
    value += to_int(get * (1.0/EXCHANGE_RATES[tmp]));
    tp->add_money(curr, get);
    tgt->add_money(curr, -get);
    if (max < 1) break;
  }

  return value;
}
