add_init() {
  add_action("open","open");
  add_action("unlock","unlock");
}

open(str) {
  if(str!="door") return;
  write("It cannot be opened.\n");
  return 1;
}
unlock(str) {
  if(str!="door") return;
  write("There is no lock on it.\n");
  return 1;
}
