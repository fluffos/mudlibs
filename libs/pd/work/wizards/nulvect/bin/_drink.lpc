#include <std.h>
#include <rooms.h>
#include <dirs.h>
#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <drink [beverage]>\n\n"
    "This lets you drink something. Alcoholic drinks provide an initial "
    "boost of stamina, but don't contribute to the natural healing process much. "
    "Other drinks can give you an overall boost in health and help with magic regeneration. "
    "Those with caffeine will help you sober up a little more quickly.",
    this_player() );
}

int cmd_drink(string str) {
  object tp = this_player();
  object env = environment(tp);
  object drink, empty;
  string mymsg, yourmsg, type, func;
  int poison, disable, strength, uses, usesleft, max, current, servingsize;
  int hp, sp, mp;
  mixed extra;

  if (tp->query_busy()) FAIL("You are too busy to drink.");
  if (tp->query_ghost()) FAIL("The dead do not need to drink.");
  if (tp->query_current_attacker()) FAIL("You are too busy fighting!");
  if (!str) FAIL("Drink what?");

  drink = present(str, tp);
  if (!drink) FAIL("You have nothing by that name.");
  if (!drink->is_drink()) FAIL("You can't drink that.");

  type = drink->query_type();

  switch (type) {
    case "alcoholic":
      func = "intox";
    break;
    case "caffeine":
    case "soft drink":
    default:
      func = "quenched";
  }

  max = call_other(tp, "query_max_"+func);
  current = call_other(tp, "query_"+func);

  strength = drink->query_strength();
  servingsize = max / 18;
  uses = servingsize / strength;
  usesleft = drink->query_uses();
  disable = drink->query_disable();
  poison = drink->query_poison();
  extra = drink->query_extra();

  if (uses > usesleft)
    uses = usesleft;
  if (uses < 1)
    uses = 1;

  // drink the largest serving you can
  while (uses > 0 && max - current < strength * uses)
    uses--;
  if (uses == 0) {
    if (func == "intox")
      FAIL("You are too drunk!");
    else
      FAIL("You are too bloated!");
  }

  if (uses >= usesleft) {
    mymsg = drink->query_my_mess();
    yourmsg = drink->query_your_mess();
  }
  else {
    mymsg = drink->query_my_serving_mess();
    yourmsg = drink->query_your_serving_mess();
  }

  strength *= uses;

  switch (type) {
  case "alcoholic":
    mp = strength/2;
    hp = strength;
    sp = strength*2;
  break;

  case "caffeine":
    tp->add_intox(-strength);
    hp = sp = mp = strength*3/4;
  break;

  default:
    hp = sp = strength;
    mp = strength*3/2;
  }

  tp->add_hp(hp);
  tp->add_sp(sp);
  tp->add_mp(mp);
  call_other(tp, "add_"+func, strength);

  message("info", mymsg, tp);
  message("info", yourmsg, env, tp);

  if (poison) tp->add_poisoned(poison);
  if (disable) tp->set_disable(disable);
  if (functionp(extra)) evaluate(extra);

  if (uses >= usesleft) {
    if (empty = drink->clone_empty()) {
      drink->move(ROOM_CACHE);
      if (empty->move(tp))
        empty->move(env);
    }
    if (drink) drink->remove();
  }
  else {
    drink->set_uses(usesleft - uses);
  }

  return 1;
}

