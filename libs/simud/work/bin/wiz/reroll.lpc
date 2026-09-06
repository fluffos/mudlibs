#include <wizard.h>
#include <dice.h>
#include <const.h>

int main( string param ) {
  object ob, creator;
  mapping skills;
  string x;

  if( !param ) {
    notify_fail("==> [Format] reroll who\n");
    return 0;
  }

  if( ob = find_living(param) ) {
    msg(capitalize(param)+" found.");
    if (ob->query_level() > this_player()->query_level()) {
      msg_object(ob,this_player()->query_name()+" just tried to reroll your stats... grin.");
      notify_fail("You are not powerful enough to do that!\n");
      return 0;
    }

    // Reset food and weight values
    msg("resetting food and weight...");
    if (ob->query_gender() == 1) {
      ob->set_weight(68000);
      ob->set_food(215);
      ob->set_drink(85);
    } else {
      ob->set_weight(49500);
      ob->set_food(165);
      ob->set_drink(70);
    }

    // flush wc and ac arrays
    msg("flushing wc and ac arrays...");
    ob->set_ac(0);
    ob->set_wc((["blunt":3]));

    msg("invoking character creation system...");
    creator = clone_object("/obj/character_creation");
    creator->start(ob);

    // notify people of the change that just occurred
    if (this_player() != ob) {
       msg("You have rerolled "+capitalize(param)+"'s stats.");
       msg_object(ob,capitalize(this_player()->query_name())+" has rerolled your stats.");
    }
    return 1;
  } else {
    notify_fail(capitalize(param)+" not found.");
    return 0;
  }
  return 1;
}
