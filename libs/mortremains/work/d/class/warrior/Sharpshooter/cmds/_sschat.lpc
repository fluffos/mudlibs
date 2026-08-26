#include <mudlib.h>

int cmd_sschat(string str) {
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
    write("You toggle your SharpShooter Chatline.\n") ;
    switch((int)ob->query("chat")) {
             case 0: write("SS Chatline is now enabled.\n") ;
                         ob->set("chat", 1) ;
              break ; 
             case 1: write("SS Chatline is now disabled.\n") ;
                        ob->delete("chat") ;
               break ;
             default: write("You hear a strange buzzing noise from your eyelink.\n") ;
                           ob->set("chat", 1) ;
                           write("The noise fades away quietly.\n") ;
                break ;
        }
      return 1;
     }
   // If we got here, they are talking over the chatline.
    users = users() ;
    if (!users) {
          write("Ha, ha, very funny.\n") ;
          return 1;
    }
  for(i=0;i<sizeof(users);i++) {
   if (users[i]) 
         ob=present("cybernetic eyelink", users[i]) ;
         if (ob && ob->query("chat")) 
    tell_object(users[i], iwrap("[SSChat] "+TPN+
  " says: "+str)) ;
    }
    return 1;
}
         
