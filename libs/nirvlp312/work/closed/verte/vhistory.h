#include <security.h>

int
cmd_vhistory(string arg)
{
     int    i, s, history_ticker;
     string *my_history;
     string reason;
     object ob;

     if((int)this_player()->query_level() < SNOOP)
       return 0;

     if(!arg)
       return (notify_fail("View whose history?\n"), 0);
  if((int)this_player()->query_level() < GOD)
     if(sscanf(arg, "%s %s", arg, reason) < 2) {
       write("You must supply a reason.\n");
       return 1;
     }
     if(!(ob=find_player(arg)) || 
       ((int)ob->query_invis() > (int)this_player()->query_level()))
       return (notify_fail("That player isn't online.\n"), 0);
     if((int)ob->query_level() > (int)this_player()->query_level())
       return (notify_fail("That wizard is a higher level than you.\n"), 0);
     if("/pa/admin/pa-daemon"->query_name((string)ob->query_real_name())) {
       if((int)this_player()->query_level() < ELDER) {
         write("Only level 1000+ can vhistory PA wizards.\n");
         return 1;
      }
    }

  if((int)this_player()->query_level() < GOD)
     write_file("/pa/log/History.txt", ctime()[4..15]+" "+(string)this_player()->query_real_name()+" viewed "+capitalize(arg)+" ==> \""+reason+"\"\n");
     my_history =     (string *)ob->query_action_history();
     history_ticker = (int)ob->query_action_ticker();

     if(!my_history || !history_ticker || !(s = sizeof(my_history)))
       return (write("No History\n"), 1);

     write("\n\t\t" + capitalize(arg) + "'s History\n");
     write("\n");
     for(i=0;i<s;i++)
       write(my_history[i] + "\n");

     write("\n");
     return 1;
}
