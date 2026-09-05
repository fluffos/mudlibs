#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

status
main(string arg, object room, object master)
{
  string item, desc;

  if (!arg || !strlen(arg))
  {
    notify_fail("You must specify an item to describe and its description.\nSyntax: "+HIW+"add_desc "+HIK+"<noun or \"noun\"> <description>\n"+NORM+NORM);
    return 0;
  }

  if (sscanf(arg, "\"%s\" %s", item, desc) != 2 && sscanf(arg, "%s %s", item, desc) != 2)
  {
    notify_fail("You must specify an item to describe and its description.\nSyntax: "+HIW+"add_desc "+HIK+"<noun or \"noun\"> <description>\n"+NORM+NORM);
    return 0;
  }

  if ((status)master->query_upgrade(UPGRADE_ANSI))
    desc = (string)ANSI_PARSER->parse_pcodes(desc)+NORM+NORM;

  if (!((status)room->add_item(item, (string)WAXFUNS->line_wrap(desc))))
    return 0;

  write("Item description added: \n"+HIK+item+": "+NORM+NORM+desc+"\n");


  write("Note: changes do not take effect until you use 'save_settings'\n");
  return 1;
}
/*
  room->set_short(": "+arg);
  room->set_changed();
  write("Room short has been changed to: "+arg+"\n");
*/
