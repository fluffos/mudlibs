#include <const.h>

int main(string who) {
  object victim;
  int x;

  WIZ_CHECK

  if (!who) {
    write ("Who do you want to satiate?\n");
    return 1;
  }
  if (victim = find_living(who)) {
    x = (victim->query_food_capacity() * 3 / 4) - victim->query_food();
    if (x > 0)
      victim->add_food(x);
    x = (victim->query_drink_capacity() * 3 / 4) - victim->query_drink();
    if (x > 0)
      victim->add_drink(x);
    if( victim != this_player() )
       write (capitalize(who)+" has been satiated by divine mana.\n");
    msg_object(victim,"You have been satiated by divine mana.");
    victim->recalc();
  } else
    write ("Could not find "+capitalize(who)+".\n");
  return 1;
}
