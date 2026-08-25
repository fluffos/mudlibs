void create() {
  seteuid("Root");
} /* create() */

int new_player(object old) {
  object ob;
  int succ;

  if(!old) return 0;
  if(file_name(previous_object())!="/cmds/creator/upgrade") return 0;
  ob = new("/secure/login");
  succ=ob->new_player(old);
  call_out((: destruct, this_object() :), 0);
  return succ;
} /* new_player() */
