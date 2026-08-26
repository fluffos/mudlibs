#include <mudlib.h>

int cmd_ssemote(string str) {
  object *users ; 
  object ob ;
   int i ;
  ob = present("cybernetic eyelink", TP) ;
  if (!ob) {
    write("The ground seems to shudder and you hear glass breaking in the distance.\n") ;
    write("Please report this to Chronos.\n") ;
    return 1;
  }
  if (!ob->query("chat")) {
       write("You must turn your chatline on first.\n") ;
       return 1;
   }
  if (!str) {
    write("Usage: ssemote <emote>\n") ;
    return 1;
  }
    
   // If we got here, they are talking over the chatline.
    users = users() ;
    if (!users) {
          write("Ha, ha, very funny.\n") ;
          return 1;
    }
  for(i=0;i<sizeof(users);i++) {
         ob=present("cybernetic eyelink", users[i]) ;
         if (ob && ob->query("chat")) 
              tell_object(users[i], "[SSChat] "+TPN+" "+str+"\n") ;
    }
    return 1;
}
