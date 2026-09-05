/*
 *      File:                   /wiz/bin/_hand.c
 *      Function:               Hand command
 *      Author(s):              Nirvana
 *      Copyright:              Copyright (c) 2005 Nirvana
 *                                      All Rights Reserved.
 *      Source:                 11/06/05
 *      Notes:                  See 'wizhelp hand' 
 *      Change History:         
 */

#include <ansi.h>
#include <security.h>
#include "/bin/wiz/cmd_defs.h"

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
 

int cmd_hand(string str)
{ 
 object ob, targ;
 string what, name;

 if(!str || sscanf(str,"%s %s",name,what) != 2)
 {
  write("Usage: 'hand <player> <file>'\n");
  return 1;
 }

 if(!(targ = find_living(name)))
 {
  write("Target not in play.\n");
  return 1;
 }

 what = resolve_path(what);
 if(catch(ob = CO(what)))
 {
  write("Incorrect file or corrupt object: "+what+"\n"+
        "Object did not clone.\n");
  return 1;
 }

 MO(ob, targ);
 TL(targ, "\
A soft wind blows and something is dropped into your inventory.\n\
    **   From: "+CAP((string)TP->RN)+"   **\n");
 write("You have cloned "+what+" to "+CAP(name)+".\n");
 return 1;
}

