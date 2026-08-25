/* Clean function by Valodin Jan 93 */

#include <std.h>

inherit DAEMON;

/* gets rid of nested objects */
recursive_dest(object ob)
{
  int i;
  object *inv;

  inv = all_inventory(ob);
  for(i = 0; i < sizeof(inv); i++)
  {
    if(!inv[i]->query_auto_load())
    {
      write("Desting: " + inv[i]->query_short() + "\n");
      if(!(inv[i]->is_player() && interactive(inv[i])))
      {
        recursive_dest(inv[i]);
        inv[i]->remove();
        if(inv[i])
          destruct(inv[i]);
      }
    }
  }
}

int cmd_clean()
{
  int i;
  object *ob;
  int flag;

  flag = 0;
  ob = all_inventory(this_player());
  for(i = 0; i < sizeof(ob); i++)
  {
    if(!ob[i]->query_auto_load())
    {
      flag++;
      write("Desting: " + ob[i]->query_short() + "\n");
      if(!(ob[i]->is_player() && interactive(ob[i])))
      {
        recursive_dest(ob[i]);
        ob[i]->remove();
        if(ob[i])
          destruct(ob[i]);
      }
    }
  }
  if(!flag)
    write("Nothing to clean.\n");
  return 1;
}

int help()
{
  write("Command: clean\nSyntax: clean\n" +
        "This command destroys all non-auto-loading items\n" +
        "in your inventory.\nSee also: dest, mdest, I\n");
  return 1;
}
