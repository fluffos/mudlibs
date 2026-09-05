status cmd_who5() {
  object *list;
  int i;

  list = users();
  while (i < sizeof(list)) {
    string sh;
    sh = (string)list[i]->short();
    if (sh == 0 && this_player()->query_level() >= 20)
        write("(" + list[i]->query_real_name() + ")\n");
    else if (sh)
        write(sh + "\n");
    i += 1;
  }
  return 1;
}
