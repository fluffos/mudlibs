#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_history(string str) {
   int i,tptr;
   int max,cmd_num,ptr;
   string *history_queue;
   object act_ob;

   act_ob = previous_object();

    seteuid(UID_USERACCESS);
   max = (int)act_ob->query_max();
   cmd_num = (int)act_ob->query_cmd_num();
   ptr = (int)act_ob->query_ptr();
   history_queue = (string *)act_ob->query_history();
   seteuid(getuid());

   if((tptr = ptr + 1) == max)
      tptr = 0;

   for(i = max - 1; i >= 0; i--)
   {
      if(history_queue[tptr])
         printf("%4d %s\n",cmd_num - i,history_queue[tptr++]);
      else
         tptr++;
      if(tptr == max)
         tptr = 0;
   }
   return 1;
}

void help()
{
   write("History\n-------\n\n" +
   "Command line history very similar to such un*x shells as\n" +
   "tcsh. There are 4 types of history access and these are listed below:\n" +
   "!!                 : This does your last command again.\n" +
   "!<negative offset> : This will do the command <negative offset> prior\n" +
   "                   : to the current one.\n");
   write("!<command number>   : This will do the command <command number>.\n");
   write("!!<string pattern> : This will match the most recent command which starts\n");
   write("                     with <string pattern>\n");

   write("\nEXAMPLES:\n");
   write("(Sample history list. Typing 'history' will show you your list!)\n");
   write("  10 bounce\n   9 break door\n   8 bounce wayfarer\n   7 grovel\n\n");
   write("!! - This will cause you to 'bounce'\n");
   write("!8 - will cause you to 'bounce wayfarer'\n");
   write("!-2 - will cause you to 'break door'\n");
   write("!b - will cause you to 'bounce'\n");
   write("!b*w - will cause you to 'bounce wayfarer'\n");
   write("!br - will cause you to 'break door'\n");
   write("\nSee also: alias, unalias, nickname, unnickname\n");
}
