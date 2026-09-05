#include <security.h>
/*
 * clean cmd
 */

void
sweep_room(object room)
{
    if (!room)
      return;
    else
    {
      object ob, oc;

      ob = first_inventory(room);
      while(ob)
      {
        oc=next_inventory(ob);
        if(!ob->is_player() || !query_ip_name(ob))
        {
          write(object_name(ob) + " " + (string)ob->short() + ".\n");
          sweep_room(ob);
          destruct(ob);
        }
        ob=oc;
      }
    }
}

int
cmd_clean(string arg)
{
    object ob;
    if((int)this_player()->query_level() < APPRENTICE) return 0;
    if (!arg || arg == "me")
      ob = this_player();
    else if (!(ob = find_player(arg)))
      return (notify_fail("That player is not logged onto Nirvana.\n"), 0);
    if (!(ob=environment(ob)))
      return (notify_fail("That player has no environment to clean.\n"), 0);
    write("Sweeping " + object_name(ob) + "...\n");
    tell_room(ob, "A magical broomstick appears and sweeps everything away.\n", 
      ({ this_player() }));
    sweep_room(ob);
    write("Done.\n");
    return 1;
}
