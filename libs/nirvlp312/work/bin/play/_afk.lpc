/* _afk.c used to set/unset an afk message indicating
 * player is not at the keyboard
 */
 
cmd_afk(string str) {
  object me;
  me=this_player();
  if(me->query_afk_message()) {
    write("You return from being afk.\n");
    say((string)me->query_name()+" returns from being afk.\n");
    me->set_afk_message(0);
    return 1;
  }
  if(!str)
  str="afk";
  write("You go afk: "+str+"\n");
  say((string)me->query_name()+" goes afk: "+str+"\n");
  me->set_afk_message(str);
  return 1;
}
