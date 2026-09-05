/*
 * Standard Load/Update cmd by V [7.8.01]
 * Also catches a load error and shows the log
 */

#include "/obj/user/load_object.h"
#include "/obj/user/resolve_path.h"

status
cmd_mk(string arg)
{

    if((int)this_player()->query_level() < 21)
      return 0;

    if(!arg)
    {
      write("Mk what?\n");
      return 1;
    }

    else
    {
      object ob;

      if(!(arg = resolve_path(arg, ".c")))
      {
        write("Bad path error.\n");
        return 1;
      }

      write("Making " + arg + "...\n");
      if(ob = find_object(arg))
      {
        write("Object found.\n");
        write("Updating old copy... ");
        destruct(ob);
        write("Ok\n");
      }

      else
        write("No object found.\n");

      write("Loading new copy... ");

      if(!(ob = loadObject(arg)))
      {
        string me;

        write("Load aborted.\n");

        if(file_size("/log/" + 
           (me = (string)this_player()->query_real_name())) > 0)
        {
          write("Error found.\n");
          command("log " + me, this_player());
          command("rlog " + me, this_player());
        }

        else
          write("File does not exist!\n");
        return 1;
      }

      else
        write("Success!\n");

      return 1;
    }
}
