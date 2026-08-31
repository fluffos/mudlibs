#include <std.h>

#define WARRIOR_WIELD_PENALTY 2

inherit DAEMON;

int query_warrior_wield(object tp);

void help() {
  message("help",
    "Syntax: <wield [weapon] (in [limb])>\n"
    "\n"
    "This command allows you to hold a weapon for use in combat.\n"
    "\n"
    "Examples: <wield axe> will automatically pick where to hold it\n"
    "          <wield axe in left hand> to specify a limb\n"
    "          <wield axe in left hand and right hand> for two-handed weapons"+
    (query_warrior_wield(this_player()) ?
      "\n\n"
      "Skilled warriors can automatically use one less hand to hold "
      "multi-handed weapons, at a small penalty to the effectiveness "
      "of the weapon. To wield them normally, just specify the limbs "
      "to wield the weapon in, such as "
      "<wield axe in left hand and right hand>."
      : ""
    ),
    this_player() );
}

int cmd_wield(string str) {
  object tp = this_player();
  object env = environment(tp);
  object wep;
  string what, where, errorcheck;
  string *tryhands;
  mixed wield;
  int hands, war, lower;

  if (tp->query_race() == "dragon" ||
      tp->query("bear") ||
      tp->query("lion") ||
      tp->query("wolf")) {
        return notify_fail("Your claws would work much better than that!");
  }

  if (!str)
    return notify_fail("Wield what?");

  // allow skilled warriors to use 1 less hand for multi-handed weapons
  // weapons wielded this way will incur a WC penalty for balance
  if (query_warrior_wield(tp))
    war=1;

  if (sscanf(str, "%s in %s", what, where) == 2) {
    where = replace_string(where, " and ", ",");
    where = replace_string(where, ", ", ",");
    where = replace_string(where, " ,", ",");
    tryhands = explode(where, ",");
  }
  else {
    what = str;
    tryhands = tp->query_wielding_limbs() -
               tp->query_limbs_wielded();
  }
  
  wep = present(what, tp);

  if (!wep)
    return notify_fail("You don't have a \""+what+"\" to wield.");
  

  if (!sizeof(tryhands))
    return notify_fail("You don't have any free hands.");

  foreach (string tryit in tryhands) {
    if (member_array(tryit, tp->query_limbs()) == -1) {
      return notify_fail("You don't have a \""+tryit+"\"!");
    }
    if (member_array(tryit, tp->query_wielding_limbs()) == -1) {
      return notify_fail("You can't hold a weapon in your "+tryit+".");
    }
    if (member_array(tryit, tp->query_limbs_wielded()) != -1) {
      return notify_fail("You are already wielding something in your "+tryit+".");
    }
    if (tp->query_crippled(tryit)) {
      return notify_fail("Your "+tryit+" is crippled and cannot hold a weapon.");
    }
  }
  
  if (wep->query_skill_level() > tp->query_skill(wep->query_type()) &&
      !(tp->is_monster()))
        return notify_fail("You do not have the talent to use that weapon.\n");

  if (wep->query_wielded()) {
    return notify_fail("You are already wielding that!");
  }

  hands = wep->query_hands();
  if (war == 1 && hands > 1) {
    hands--;
    lower=1;
  }

  if (hands > sizeof(tryhands)) {
    return notify_fail("You must wield such a weapon with "+
                       cardinal(hands)+" hands.");
  }

  // if a warrior specifically wields a multi-handed weapon in the
  // original number of required hands, allow it and don't lower the wc
  if (where && lower && sizeof(tryhands) == wep->query_hands()) {
    lower=0;
    hands++;
  }

  if (!hands) hands=1;

  errorcheck =
    wep->equip(tp, tryhands[0..hands-1], 0,
               (lower ? WARRIOR_WIELD_PENALTY : 0)
    );

  tp->set_disable(1);

  if (errorcheck) {
    return notify_fail(errorcheck);
  }
  
  return 1;
}

int query_warrior_wield(object tp) {
  if (tp->query_subclass() == "warrior" &&
      tp->query_skill("double wielding") >= 120)
        return 1;
  return 0;
}

