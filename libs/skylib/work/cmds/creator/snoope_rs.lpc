/* snoopers command, trial out by Turrican for a commands daemon. */

#include <creator.h>

inherit COMMAND_BASE;

mixed cmd(string str) {
  object *obs;
  int i;

  obs = (object *)PEOPLER->get_people(str);
  obs = filter_array(obs, "check_snoop", this_object());
  if (!sizeof(obs)) {
    notify_fail("No one is being snooped by anyone.\n");
    return 0;
  }
  for (i=0;i<sizeof(obs);i++)
    write(obs[i]->query_cap_name()+" is snooping "+
          obs[i]->query_snoopee()->query_cap_name()+".\n");
  return 1;
}

int check_snoop(object ob) {
  if((object)ob->query_snoopee())
    return 1;
  else
    return 0;
}
