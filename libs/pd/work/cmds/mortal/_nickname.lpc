#include <std.h>

inherit DAEMON;

int cmd_nickname(string str)
{
   mapping nicknames;
   mixed *nicks;
   int i;
   string nn,rn;
   object act_ob;

   act_ob = this_player();
   if (str == "reset") {
       write("Resetting nicknames...");
       act_ob->empty_nicknames();
       write("Done.\n");
       return 1;
   }
   nicknames = (mapping)act_ob->query_nicknames();

   if(!str)
   {
      nicks = keys(nicknames);
      if(!sizeof(nicks))
      {
         write("No nicknames defined.\n");
         return 1;
      }
      else
         write("Currently defined nicknames:\n");
      for(i = 0; i < sizeof(nicks); i++)
         printf("%-15s : %s\n",nicks[i],nicknames[nicks[i]]);
      return 1;
   }
   if(sscanf(str,"%s %s",nn,rn) == 2)
   {
      if(nicknames[nn])
         write("Nickname "+nn+" changed from "+nicknames[nn]+".\n");
      else
         write("Nickname "+nn+" added.\n");
      act_ob->set_nicknames(nn,rn);
      return 1;
   }
   else {
        write("Nickname removed: "+str+"\n");
	act_ob->remove_nickname(str);
	return 1;
   }
   return 1;
}

void help() {
  write( @END
usage:
 
To make a nickname:
nickname <nick_name> <real_name>
To remove a nickname:
nickname <nick_name>
To remove all nicknames:
nickname reset
To list nicknames:
nickname
 
Nickname will substitute real_name for all occurances of nick_name
on your command line (except for the first word. that's reserved for
aliases.) This allows you to use shortened words to refer to people,
objects, etc, rather than typing long drawn out names. Talking to players
with long names is no longer an annoyance!

An escape of \\ in front of a word will prevent that word from being
expanded (For when you want to say the nick_name and not the real_name!).
See also: unnickname, history, alias, unalias
END
    );
}
