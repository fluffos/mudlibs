/* Last modified by tune on Fri Apr 28 14:21:08 1995
** Made using Ulantris Roommaker II version 1.33
*/


#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort("Tutorial for Hanarra's editor page 3");
 SetIntLong(
  "COMMANDS\n"+
  "\n"+
  "  The following commands are available for the editor:\n"+
  "\n"+
  "  file <filename>          --- set a file to edit.\n"+
  "  esave                    --- save the current buffer.\n"+
  "  discard                  --- discard the current buffer.\n"+
  "  print <range>            --- prints a range of line numbers.\n"+
  "  print [all/more/less]    --- print all lines, or a chunk of lines.\n"+
  "  insert [#/start/end]     --- inserts text after given arguement.\n"+
  "  delete <range>           --- deletes a line or range of lines.\n"+
  "  change <#>               --- change a line.\n"+
  "  bufinfo                  --- prints info about the current buffer\n"+
  "  lines [on/off]           --- turn on/off the numbering of lines.\n"+
  "  chunk <#>                --- define # of lines for print more/less.\n"+
  "  find <string>            --- search for string from buffer start\n"+
  "  next <string> optional   --- find string from current line.\n"+
  "  prev <string> optional   --- find string before current line.\n");

 AddExit("continue","./han_ed4");
 AddExit("return","./han_ed2");

}
