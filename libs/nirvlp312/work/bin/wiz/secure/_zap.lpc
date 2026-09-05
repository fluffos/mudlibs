#include <security.h>

int cmd_zap(string str)
{
  object ob;
  if((int)this_player()->query_level() < DAMAGE)
    return 0;
  if(!str && !(ob=(object)this_player()->query_attack()))
  {
    write("You aren't attacking anything, therefore\n" +
          "you must specify a target.\n");
    return 1;
  }
  else if(str && !(ob = present(lower_case(str),
                  environment(this_player()))))
  {
    write("You don't see " + str + " here.\n");
    return 1;
  }
  if(!ob || !living(ob))
  {
    write("You don't see the creature " + str + " here.\n");
    return 1;
  }
  this_player()->zap_object(ob);
  return 1;
}

