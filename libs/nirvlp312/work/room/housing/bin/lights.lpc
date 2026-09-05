#include "../defs.h"

int *priv_cost() { return ({ 1, 0 }); }

status 
main(string arg, object room, object master)
{
  status flag;

  flag = (status)room->query_lights();

  if (!arg)
  {
    write("Lights are currently turned "
      + (flag ? HIY+"turned on" : HIK+"turned off")
      + NORM+NORM+".\n");
    return 1;
  }

  if (arg == "on")
  {
    if (flag)
    {
      notify_fail("The lights are already on.\n");
      return 0;
    }

    room->toggle_lights();
    write("The lights are now "+HIY+"on"+NORM+NORM+".\n");
    return 1;
  }

  if (arg == "off")
  {
    if (!flag)
    {
      notify_fail("The lights are already off.\n");
      return 0;
    }

    room->toggle_lights();
    write("The lights are now "+HIK+"off"+NORM+NORM+".\n");
    return 1;
  }

  notify_fail("Syntax: "+HIW+"lights"+NORM+NORM+" or "+HIW+"lights"+HIK+" <on or off>\n"+NORM+NORM);
  return 0;
}
