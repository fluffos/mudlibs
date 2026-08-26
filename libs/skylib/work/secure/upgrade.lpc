void create() {
  seteuid("Root");
} /* create() */

int new_player(object old) {
  object ob;
  seteuid("Room");
  old->save();
  ob = clone_object("/secure/login");
  ob->new_player(old);
  destruct(this_object());
} /* new_player() */
