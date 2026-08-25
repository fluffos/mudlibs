//  _order.c
//  from the Nightmare mudlib
//  A command for use in conjunction with _raise.c
//  Created by Manny@Nightmare 941008

#include <std.h>

inherit DAEMON;

int cmd_order(string str) {
  string who, what;
  object corpse, me;
  int sp;

  if(!str) return notify_fail("Order whom to do what?\n");

  if(!((sscanf(str, "%s to %s", who, what)==2) ||
     (sscanf(str, "%s %s", who, what)==2)))
    return notify_fail("Syntax: order <who> [to] <action>\n");

  me=this_player();
  if(!corpse=present(who, environment(me)))
    return notify_fail("That is not around to be ordered!\n");

  if((object)corpse->query("master") != me)
    return notify_fail("You have no control over that.\n");

  message("say", me->query_name()+" attepts to command "+
      me->query_possessive()+" servant.", environment(me));

  if(random(me->query_sp())-10 < 0) {
    message("my_action", "%^RED%^The corpse peers at you with "
        "a dimly confused look which quickly evolves "
        "into a look of rage, anger and hatred!!", me);
    message("say", "%^RED%^The corpse rebels against it's masters command!",
        environment(me));
    corpse->kill_ob(me);
    return 1;
  }

  me->add_sp(random(10)-20);
  if(!random(me->query_sp())) {
    message("my_action", "%^RED%^Your servant pays no heed to your "
        "orders.", me);
    return 1;
  }

  message("my_action", "%^GREEN%^%^BOLD%^You impose your orders upon your "
      "dead servant.", me);
  corpse->force_me(what);
  return 1;
}

void help() {
  message("help", "Syntax: order <whom> [to] <do what>\n\n"
      "Orders a being under your command to do what you wish.\n"
      "Example: order corpse to kill beggar", this_player());
}


