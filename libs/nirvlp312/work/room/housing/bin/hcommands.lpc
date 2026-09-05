/* ***************************************************************************
 * Command Name:  hcommands
 * Description:   Display house commands
 * Arguments:     arg - it's junk, flag - 1 for if it's for facade
 * Returns:       status - 0 for failure, 1 for success
 * **************************************************************************/

#include "../defs.h"

status 
main(string arg, object room, object master)
{
  mapping cmds;
  string *t;
  int i;

  cmds = (mapping)HOUSED->get_valid_commands(master);
  i = sizeof(t = m_indices(cmds));
  write("The following commands are available to you:\n\n");
  write("Priv Command             Cost\n");

  while(i--)
    write((cmds[t[i]][0] == 3 ? HIY : (cmds[t[i]][0] == 2 ? YEL : ""))
      + cmds[t[i]][0] 
      + " -  "
      + pad(t[i], 20)
      + (cmds[t[i]][1] ? (string)UTILITYD->comma_number(""+cmds[t[i]][1]) : "")
      + NORM + NORM + "\n");

  write("You can do 'hinfo commandname' for more info.\n");
  return 1;
}

/*
  write("You can do the following commands here:");
  write("\nCost     Command <arguments>\n"+HIW+
    "add_owner "+HIK+"<name>\n"+HIW+
    "remove_owner "+HIK+"<name>\n"+HIW+
    "list_owners\n"+HIW+
    "set_privelege "+HIK+"<name> <type or all>\n"+HIW+
    "unset_privelege "+HIK+"<name> <type>\n"+HIW+
    "clear_privelege "+HIK+"<name or all>\n"+NORM+NORM+
    "------------------------------------\n"+HIW+
    "set_short "+HIK+"<short_description of residence>\n"+HIW+
    "set_long "+HIK+"<long description of residence>\n"+HIW+
    "add_id "+HIK+"<id to add>\n"+HIW+
    "add_entrance "+HIK+"<entrance command>\n"+HIW+
    "save_settings\n"+NORM+NORM);
  return 1;
}
*/
