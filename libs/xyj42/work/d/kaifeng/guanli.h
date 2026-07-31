// create by snowcat.c 2/8/1997

#include <command.h>

void init ()
{
  add_action ("do_look","look");
}

void write_objects (object room, object who)
{
  mixed *inv = all_inventory (room);
  int i = sizeof(inv);

  while (i--)
  {
    object ob = inv[i];
    if (! who->visible(ob) || ob == who)
      continue;

    write ("  "+ob->short()+"\n");    
  }
}

int do_look (string arg)
{
  object who = this_player();
  object room = environment(who);

  if (arg)
    return 0;

  LOOK_CMD->look_room(who,room);

  room = load_object (__DIR__"ground");
  if (! room)
    return 1;

  write ("\n        －－－－－－－〖赛场内〗－－－－－－－\n");
  write (room->query("long"));    
  write_objects(room, who);
  write ("\n        －－－－－－－－－－－－－－－－－－－\n");
  return 1;    
}
