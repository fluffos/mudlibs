/* Beek - 10/4/94 */

inherit COMMAND_BASE;

mixed cmd(string str) {
  mapping error;
  object ob;

  if (str) {
    str = this_player()->expand_nickname(str);
    ob = find_player(str);
    if (!ob) {
      write("No such player.\n");
      return 1;
    }
  } else
    ob = this_player();
  if (error = (mapping)ob->get_last_error()) {
    printf("%s\n", master()->standard_trace(error, 1));
  } else write("No error.\n");
  return 1;
}
