/* Last modified by tune on Fri Apr 28 14:24:29 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort("Tutorial for Hanarra's Editor Page 4");
 SetIntLong(
  "COMMANDS - CONT'D\n"+
  "\n"+
  "  -To stop inserting lines, enter a '.'\n"+
  "  \n"+
  "  -With the change command, use a '.' to leave line unchanged.\n"+
  "\n"+
  "  -<range> means a line number or a range of line numbers, format is \n"+
  "  either a number or two numbers separated by '-'.  You may also use\n"+
  "  \"start\" and \"end\" instead of a number.\n"+
  "\n"+
  "  -optional means that you dont have to include this arguement if you\n"+
  "  defined the <string> with a previous search, next, or prev command.\n");

 AddExit("continue","./han_ed5");
 AddExit("return","./han_ed3");

 AddRoomCmd("commands","commands");

}
