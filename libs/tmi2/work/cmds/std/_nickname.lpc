// nickname.c
// Lets a player set nicknames for commonly used words. If the player types
// "nickname frog Pinkfish@discworld", then any time he later types the
// work "frog" it will be replaced by "Pinkfish@discworld". You can override
// the nickname by typing "\frog", in which case it'll come out "frog". Or
// you can use the unnickname command to get rid of the silly thing.
// Original author unknown, probably quite old. Came over from TMI-1.
// Mobydick added this header on 4-9-93.
// This file is part of the TMI-2 mudlib. Do not remove or alter this
// header, etc. Be one with the header.

#include <mudlib.h>

inherit DAEMON ;


int cmd_nickname(string str)
{
   mapping nicknames;
   mixed *nicks;
   int i;
   string nn,rn;
   object act_ob;

   act_ob = this_player();
   if (str == "reset")
       act_ob->empty_nicknames();
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
 
    //  Strip out leading spaces from request.
 
    while(str[0] == ' ')  str = str[1..sizeof(str)-1];
 
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
	act_ob->remove_nickname(str);
	return 1;
   }
   return 1;
}

string help() {
 return("Syntax: nickname <nickname> <real name>\n\n"+
  "Nickname will substitute <readname> for all occurances of <nickname>\n"+
  "on your command line (except for the first word. that's reserved for\n" +
  "aliases. :)) This allows you to use shortened words to refer to people, \n" +
  "objects, etc, rather than typing long drawn out names. Talking to players\n"+
  "with long names is no longer an annoyance!\n" +
  "An escape of \\ in front of a word will prevent that word from being\n" +
  "expanded (For when you want to say the nickname and not the realname!)\n" +
  "\nEXAMPLE:\n\n" +
  "> nickname way wayfarer\n" +
  "> tell way No \\way way! These nicknames are stuf!ly!(tm)\n" +
  "This expands to:\n" +
  "> tell Wayfarer No way Wayfarer! These nicknames are stuf!ly!(tm)\n");
}
