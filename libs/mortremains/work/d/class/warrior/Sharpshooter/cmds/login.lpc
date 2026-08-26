// This is the login processor.
// -- Chronos. ;)
#include <mudlib.h>

int login(object ob) {
  object *users ;
  object ob2;
  int i ;
  write("\n") ;
 write("                   S  H  A  R  P     S  H  O  O  T  E  R  S\n") ;
 write("           =------------------------------------------------------=\n");
 write("           =     For the latest in Class News, type \"snews\"!      =\n") ;
 write("           =------------------------------------------------------=\n");
 if (wizardp(ob)) return 1;
  users = users() ;
  if (!users) return 1;   // Seems silly, doesn't it ?
  for(i=0;i<sizeof(users);i++) {
     ob2 = present("cybernetic eyelink", users[i]) ;
     if (ob2 && ob2->query("chat")) {
    if (users[i] != ob ) 
  tell_object(users[i], "[- The SharpShooters welcome "+
                 ob->query("cap_name")+
                 " back to Mortal Remains. -]\n") ;
     }
  }
  return 1;
}
         
