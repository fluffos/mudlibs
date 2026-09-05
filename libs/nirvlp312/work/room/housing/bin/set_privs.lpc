#include "../defs.h"

int *priv_cost() { return ({ 3, 0 }); }

status
main(string arg, object room, object master)
{
  string name;
  int priv;

  if (!arg || !strlen(arg) || sscanf(arg, "%s %d", name, priv) != 2)
  {
    notify_fail("Syntax: "+HIW+"set_privs "+HIK+"<name> <level>\n"+NORM+NORM+"See "+HIW+"hinfo privileges"+NORM+NORM+" for details.\n");
    return 0;
  }

  if (name == (string)this_player()->query_real_name())
  {
    notify_fail("You may not set your own privileges below 3.\n");
    return 0;
  }

  if (priv > 3)
  {
    notify_fail("Privileges may not be set above 3.\nSee "+HIW+"hinfo privileges"+NORM+NORM+" for information about privileges.\n");
    return 0;
  }

  return (status)master->set_privs(name, priv);
}
