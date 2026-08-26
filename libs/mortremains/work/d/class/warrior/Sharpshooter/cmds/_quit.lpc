int cmd_quit() {
  int i ; 
 object *users;
  object ob2;
  if (wizardp(TP)) return 0 ;
  users = users() ;
  for(i=0;i<sizeof(users);i++) {
   ob2 = present("cybernetic eyelink", users[i]) ;
    if (ob2 && ob2->query("chat")) {
    if (users[i] != TP )
                tell_object(users[i], "[- The SharpShooters bid "+
                  TPN+" farewell. -]\n") ;
     }
  }
  return 0 ;
}
