/* status command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

mixed cmd(string str) {
  if (str)
    this_player()->more_string(mud_status(1), "Status info");
  else
    printf("%s", mud_status());
  return 1;
}

mixed query_patterns() { return ({"", (: cmd($4) :) }); }
