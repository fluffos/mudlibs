#include "../defs.h"

int *priv_cost() { return ({ 2, 0 }); }

status
main(string arg, object room, object master)
{
  if (!arg || !strlen(arg))
  {
    notify_fail("You must specify a new short description.\n");
    return 0;
  }

  if ((status)master->query_upgrade(UPGRADE_ANSI))
    arg = (string)ANSI_PARSER->parse_pcodes(arg)+NORM+NORM;

  room->set_short(": "+arg);
  room->set_changed();
  write("Room short has been changed to: "+arg+"\n");
  write("Note: changes do not take effect until you use 'save_settings'\n");
  return 1;
}
