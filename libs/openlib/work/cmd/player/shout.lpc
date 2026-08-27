#include <command.h>

int
main(string arg)
{
   if(!arg){
        return notify_fail("usage:  shout <message>\n");
   }
shout(capitalize(this_player()->query_name())
               + " shouts: " +  arg + "\n");
   write("You shout: " + arg +"\n");
   
     return 1;
}
