#include <const.h>

/*
 * Displays a player's hitpoints. If they have ANSI turned on, the number will be
 * color coded according to the percentage of hit points remaining.
 *
 * Note: You can pass in the parameter of the object whose hitpoints you wish to
 * view; it is ignored if you are not a wizard (heh, fixed *that* bug :-P)
 */

// Returns a color code depending on the percent of health you have.
string percent_color(int per) {
  if (per > 100)        // hicyan
    return "~[140";
  else if (per == 100)        // white
    return "~[150";
  else if (per > 90)        // higreen
    return "~[100";
  else if (per > 75)        // green
    return "~[020";
  else if (per > 50)        // yellow
    return "~[110";
  else if (per > 25)        // red
    return "~[010";
  else if (per > 0)        // hired
    return "~[090";
  else
    return "~[080";        // gray
}

string hp_string(object target) {
  int hp, maxhp, mana, maxmana, end, maxend, per;
  string buf = "~[060HP: ";

  hp = target->query_hp();
  maxhp = target->query_max_hp();
  mana = target->query_mana();
  maxmana = target->query_max_mana();
  end = target->query_endurance();
  maxend = target->query_max_endurance();

  if (hp != 0)
    per = 100*hp/maxhp;
  else
    per = 0;
  buf += percent_color(per);
  buf += (string)hp+"~[060/"+(string)maxhp+" ("+(string)per+"%)~CDEF ";

  if (maxmana > 0) {
    buf += "~[060Mana: ";
    if (mana != 0)
      per = 100*mana/maxmana;
    else
      per = 0;
    buf += percent_color(per);
    buf += (string)mana+"~[060/"+(string)maxmana+"~CDEF ";
  }

  if (maxend > 0) {
    buf += "~[060End: ";
    if (end != 0)
      per = 100*end/maxend;
    else
      per = 0;
    buf += percent_color(per);
    buf += (string)end+"~[060/"+(string)maxend+"~CDEF";
  }

  if (target->query_in_combat()) {
    object enemy = target->query_target();
    if( enemy->query_hp() > 0)
       per = 100 * enemy->query_hp() / enemy->query_max_hp();
    else
       per = 0;
    buf += " ~[060Enemy: ";
    buf += percent_color(per);
    buf += "/daemon/desc_vars"->hp(enemy);
    buf += "~CDEF";
  }

  return buf;
}

void force(object victim) {
  msg_object(victim,hp_string(victim));
}

varargs int main(string param) {
  object target;

  if( !param || this_player()->query_level() < WIZLEVEL )
     target = this_player();
  else
     target = find_living( param );

  if( !target ) {
     notify_fail("Can't figure out whose hp to display.\n");
     return 0;
  }

  if (this_player() != target)
    msg(target->query_cap_name());

  msg(hp_string(target));
  return 1;
}

