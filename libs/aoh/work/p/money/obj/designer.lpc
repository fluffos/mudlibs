/*--------------------------------------------------------------------------
 * /p/money/obj/designer -- A money designer to build new coins
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <properties.h>
#include <money.h>
#include <secure/wizlevels.h>

inherit "/std/thing";
inherit "/p/money/obj/designer/description";
inherit "/p/money/obj/designer/design";
inherit "/p/money/obj/designer/file";
inherit "/p/money/obj/designer/viewfuns";

public int help_command(string cmd)
{
  object this;

  if(!security()) return 0;
  if(!cmd || ((this = present(cmd,this_player())) != this_object()
	      && !QueryFuns()[cmd,1])) {
    notify_fail("** Usage: [design] " +  QueryFuns()["help",1] + "\n");
    return 0;
  }
  if(this) {
    write("Possible commands are:\n" +
	  implode(map(m_indices(QueryFuns()),
                            lambda(({'fun}),
				   ({#'sprintf,"%-28s: %s\n",
				     ({#'[,QueryFuns(),'fun,1}),
				     ({#'[,QueryFuns(),'fun,2})
				     }))),
		  ""));
    return 1;
  }
  smore("COMMAND\n        " + cmd + " - " + QueryFuns()[cmd,2] +
	"\n\nSYNOPSIS\n        " + QueryFuns()[cmd,1] +
	"\n\nDESCRIPTION\n" + QueryFuns()[cmd,3] + "\n");
  return 1;
}

public void init()
{
  int    i;
  string *cmds;

  if(!IS_WIZARD(this_player()))
    if(this_player() != environment()) return;
    else write("This tool is totally useless for you!\n");
  else {
    add_action("design_money","design");
    for(i = sizeof(cmds = m_indices(QueryFuns()));i--;)
      add_action(QueryFuns()[cmds[i]],cmds[i]);
  }
}

public void create()
{
  ::create();
  AddId("designer");
  AddId("moneydesigner");
  AddAdjective("money");
  SetShort("the money designer (tm)");
  SetLong("This is the money designer for the Finance Department.\n\
Initial command is 'design'.\n\
The helppage you can get with 'help designer'.\n");
  Set(P_AUTOOBJECT,"0.9");
  seteuid(getuid());
}

public varargs int remove()
{
  abort_design(0);
  return ::remove();
}
