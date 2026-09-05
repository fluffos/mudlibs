/*
 *      File:                   /obj/player/modify_command.c
 *      Function:               Process commands before driver sees them -
 *                              Aliases, Nicknames
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/20/06
 *      Notes:                  Inherited by player.c
 *                              Processes nicknames/aliases in /obj/daemons/commands
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* Global Variables */
string *saved_aliases;   /* Legacy Support                     */
string *saved_nicknames; /* Legacy Support                     */
mapping Aliases;         /* ([ alias: definition ])            */
mapping Nicknames;       /* ([ nickname: text to substitute ]) */
 
/* ========================================================================
 * modify_command
 * ========================================================================
 * Function name:  modify_command
 * Description:    Modify commands before they go to the driver for parsing
 * Arguments:      (string) command as typed by player
 * Returns:        0 - use unmodified command
 *                 (string) modified command to pass to driver
 *                 non-zero integer - ignore the command altogether
 */

mixed 
modify_command(string command)
{
  string verb, arg;
  string *subs, *args;
  int i, t;
  
  if (!command)
    return 0;
   
  /* Parse into verb and argument */
  if (sscanf(command, "%s %s", verb, arg) != 2)
  {
    verb = command;
    arg = 0;
  }

  /* Expand and return the direction aliases */
  switch(verb) {
    case "n" : return "north";
    case "ne" : return "northeast";
    case "nw" : return "northwest";
    case "s" : return "south";
    case "se" : return "southeast";
    case "sw" : return "southwest";
    case "u" : return "up";
    case "d" : return "down";
  }

  /* Check if it's an alias, if so, substitute it out */
  if (Aliases && member(Aliases, verb))
  {
    verb = Aliases[verb];
  }
  
  /* Now parse it into verb and argument again */
  if (arg)
    verb = sprintf("%s %s", verb, arg);
    
  if (sscanf(verb, "%s %s", verb, arg) != 2)
  {
    arg = 0;
  }
  
  /* Process special commands here */
  if (verb == "heals+") return "heals_all";
  
  /* If it's a nickname or alias command, process it here */
  if (verb == "alias" || verb == "unalias")
  {
    if (!arg)
      COMMANDSD->list_subs("Aliases", Aliases);
    else
      COMMANDSD->process_alias(arg, Aliases);
      
    return 1;
  }
  
  if (verb == "nickname" || verb == "unnickname")
  {
    if (!arg)
      COMMANDSD->list_subs("Nicknames", Nicknames);
    else
      COMMANDSD->process_nickname(arg, Nicknames);
      
    return 1;
  }
  
  /* Check if a nickname is involved, if so, substitute it out */
  if (!arg) return verb;
  
  args = explode(arg, " ");
  subs = m_indices(Nicknames) & args;
  
  if (i = sizeof(subs))
  {
    while(i--)
    {
      args[member(args, subs[i])] = Nicknames[subs[i]];
    }
  }
  
  arg = implode(args, " ");
  
#ifdef DEBUG
  write_file("/log/earwax.nicknames", sprintf("%s: %s\n", command, arg));
#endif
  
  return sprintf("%s %s", verb, arg); 
} 
  
  
  
