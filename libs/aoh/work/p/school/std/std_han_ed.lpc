/* Last modified by tune on Fri Apr 28 14:09:13 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>

inherit "/std/room";

int x_continue();
int x_return();
int commands();

varargs void create()
{
  ::create();
  SetIntShort("Commands for the editor tutorial");
  SetIntLong(
  "Commands for the editor tutorial");

  AddExit("school","/p/school/school");
  AddRoomCmd("c", "x_continue");
  AddRoomCmd("r", "x_return");
}

int x_continue()
{
  this_player()->command_me("continue");
  return 1;
}

int x_return()
{
  this_player()->command_me("return");
  return 1;
}

void init()  {
  ::init();
  add_action("commands","commands");
}


int commands() {
 write("COMMANDS\n"+
  "\n"+
  "  file <filename>          --- set a file to edit.\n"+
  "  esave                    --- save the current buffer.\n"+
  "  discard                  --- discard the current buffer.\n"+
  "  print <range>            --- prints a range of line numbers.\n"+
  "  insert [#/start/end]     --- inserts text after given arguement.\n"+
  "  delete <range>           --- deletes a line or range of lines.\n"+
  "  change <#>               --- change a line.\n"+
  "  bufinfo                  --- prints info on current buffer.\n"+
  "  lines [on/off]           --- turn on/off the numbering of lines.\n"+
  "  chunk <#>                --- define # of lines for more/less\n"+
  "  find <string>            --- search for string from start of buffer.\n"+
  "  next <string> optional   --- find string from current line.\n"+
  "  prev <string> optional   --- find string before current line.\n");
  return 1;
}
