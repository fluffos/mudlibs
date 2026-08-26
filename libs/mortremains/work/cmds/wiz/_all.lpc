// Chronos recreates his all command from for-ever ago.
// (06-23-00) Written by Chronos.
#include <mudlib.h>

inherit DAEMON; 
int filter_user(object ob) ;

int cmd_all(string str) {
  mixed work ;
  object *users ;
  int i ;
  if (!str) {
    write("Usage: all <variable>\n") ;
    return 1;
  }
  users = users() ;
  printf("%-25s      Result of query for \"%s\".\n", "Username", str) ;
  printf("--------------------------------------------------------------\n") ;
  for(i=0;i<sizeof(users);i++) {
   if (filter_user(users[i])) continue ;
    if (wizardp(users[i])) write("[Wz] ") ;
    else write("[Pl] ") ;
    printf("%-25s : ", users[i]->query("cap_name")) ;
   work = users[i]->query(str) ;
   if (objectp(work)) write("[Obj]->\""+file_name(work)+"\"\n") ;
    else  write(work+"\n") ;
  }
  return 1;
}

string help() {
   return @ENDHELP
Usage: all <variable>

This command will show you what everyone on the mud has set for whatever
variable you designate as the argument.

Another fine utility program brought to you by Chronos!  :)
ENDHELP
  ;
}

int filter_user(object ob) {
  if (adminp(TP)) return 0 ;
  if (ob->query("invisible")>1) return 1;
}
