#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

status
main(string arg, object room, object master)
{
  object ob;

  if (!arg || !strlen(arg))
  {
    write(HIY+"The following players are allowed to enter: \n"+NORM+NORM);
    write((string)HOUSED->dump_invited(master));
    return 1;
  }

  if (!((status)master->add_invited(arg)))
    return 0;

  ob = find_player(arg);
  write(capitalize(arg)+" will be allowed to enter.\n");

  if (ob && (int)ob->query_invis() <= (int)this_player()->query_level())
  {
    write("They are being notified.\n");
    tell_object(ob, HIY+"You have received an open invitation to enter the following residence:\n"+NORM+NORM);
    tell_object(ob, "Invited by: "+(string)this_player()->query_name()+" to: "+(string)master->short() + ".\n");
  }

  return 1;
}
