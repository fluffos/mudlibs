#include <security.h>
int cmd_set_al(string al)
{
  object ob;
  if ((int)this_player()->query_level() < EXPLORE)
    return 0;
  if(ob = present("soul", this_player()))
  {
    if(!al)
    {
      al = "";
      write("Alignment title reset.\n");
    }
    else
      write("Alignment title set to: (" + al + ")\n");
    ob->set_al_title(al);
    this_player()->update(8);
  }
  else
    write("You don't have a soul!\n");
  return 1;
}

