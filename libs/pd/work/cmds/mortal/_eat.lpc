#include <std.h>
#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <eat [food]>\n\n"
    "Allows you to eat something. Food restores some stamina and health when you eat it, "
    "and having food in your belly will help you heal faster.\n"
    "\n"
    "Dragons and some animals can eat the bodies of their freshly killed prey.",
    this_player());
}

int can_eat_corpse(object tp) {
  if (tp->query_race() == "dragon" || tp->query_class() == "animal" ||
      tp->query("bear") || tp->query("lion") || tp->query("wolf"))
        return 1;
  return 0;
}

int cmd_eat(string str) {
  object tp = this_player();
  object env = environment(tp);
  object food;
  string mymsg, yourmsg;
  int poison, disable, strength, uses, usesleft, max, current, servingsize;
  mixed extra;

  if (tp->query_busy()) FAIL("You are too busy to eat.");
  if (tp->query_ghost()) FAIL("The dead have no need of food.");
  if (tp->query_current_attacker()) FAIL("You are too busy fighting!");
  if (!str) FAIL("Eat what?");

  current = tp->query_stuffed();
  max = tp->query_max_stuffed();

  if (can_eat_corpse(tp) &&
      objectp(food = present(str, env)) && food->query_corpse()) {
        strength = food->query_level()*3/2;
        if (food->query_decay()) {
          strength /= 3;
          poison = food->query_level();
        }
        else {
          poison = 0;
        }
        if (max - current < strength)
          FAIL("You are too full!");
        disable = 1;
        uses = 1;
        usesleft = 1;
        extra = (: $(food)->loot($(tp)) :);
        mymsg = "You eat the remains of your prey.";
        yourmsg = tp->query_cap_name()+" eats the remains of "+tp->query_possessive()+" prey.";
  }
  else {
    food = present(str, tp);
    if (!food) FAIL("You have nothing by that name.");
    if (!food->is_food()) FAIL("That isn't edible.");

    strength = food->query_strength();
    disable = food->query_disable();
    servingsize = max / 15;
    uses = servingsize / strength;
    usesleft = food->query_uses();
    poison = food->query_poisoned();
    extra = food->query_extra();

    if (uses > usesleft)
      uses = usesleft;
    if (uses < 1)
      uses = 1;

    // eat the largest serving you can hold
    while (uses > 0 && max - current < strength * uses)
      uses--;
    if (uses == 0) FAIL("You are too full!");

    if (uses >= usesleft) {
      mymsg = food->query_my_mess();
      yourmsg = food->query_your_mess();
    }
    else {
      mymsg = food->query_my_serving_mess();
      yourmsg = food->query_your_serving_mess();
    }

    strength *= uses;

  }

  tp->add_hp(strength);
  tp->add_sp(strength);
  tp->add_mp(strength/2);
  tp->add_stuffed(strength);

  message("info", mymsg, tp);
  message("info", yourmsg, env, tp);

  if (poison) tp->add_poisoned(poison);
  if (disable) tp->set_disable(disable);
  if (functionp(extra)) evaluate(extra);

  if (uses >= usesleft)
    food->remove();
  else
    food->set_uses(usesleft - uses);

  return 1;
}
