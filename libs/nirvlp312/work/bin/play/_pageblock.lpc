#include <ansi.h>
#include <security.h>

int
cmd_pageblock(string arg)
{
     string *blockers;

     if(!arg)
       return (notify_fail("Syntax: 'pageblock <who>', 'pageblock list', " +
                           "or 'pageblock all'.\n"), 0);

     if(arg == "all")
     {
       if(!this_player()->query_pageblock())
       {
         this_player()->set_pageblock(1);
         return (write("You are now blocking all pages.\n"), 1);
       }
       else
       {
         this_player()->set_pageblock(0);
         return (write("You are now accepting most pages.\n" +
                       "Type 'pageblock list' for a list of people you are blocking.\n"), 1);
       }
     }

     blockers = (string *)this_player()->query_blocking_pagers();
     if(arg == "list")
     {
       int s;
       s=sizeof(blockers);
       if(!s) return (write("You aren't blocking anyone's pages.\n"), 1);
       write("\n\t\tBlocking:\n\t\t----------\n");
       while(s--)
         write("\t" + capitalize(blockers[s]) + "\n");
       return (write("\n"), 1);
     }

     if(member_array((arg=lower_case(arg)), blockers) > -1)
     {
       this_player()->remove_blocking_pager(arg);
       return (write("You have stopped blocking " + capitalize(arg) + "'s pages.\n"), 1);
     }
     else
     {
       this_player()->add_blocking_pager(arg);
       return (write("You are now blocking " + capitalize(arg) + "'s pages.\n"), 1);
     }
}
        
         
