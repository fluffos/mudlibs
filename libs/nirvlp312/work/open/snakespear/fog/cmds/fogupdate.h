do_fogupdate() {
  object ob;
  destruct(previous_object());
  ob=clone_object(PATH+"brand.lpc");
  if(!ob) {
    write("Guild object failed to update.\n");
    return 1;
  }
  ob->move_object(resolve_ob(TP));
  write("Your brand has been updated.\n");
  return 1;
}
