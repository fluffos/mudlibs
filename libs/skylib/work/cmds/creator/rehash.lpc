/* rehash command, trial out by Turrican for a commands daemon. */

#define CMD_D "/secure/command"

inherit COMMAND_BASE;

mixed cmd(string str) {
  if (!str)
    return notify_fail("Syntax: rehash <path>\n");
  if (file_size(str) != -2)
    return notify_fail(str+": Path not found.\n");
  CMD_D->eventRehash(str);
  write(str+": Rehashed.\n");
  return 1;
}
