/* Last modified by tune on Sun Apr 23 15:04:10 1995
** Made using Ulantris Roommaker II version 1.32
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort("Tutorial for Hanarra's Editor Page 10");
 SetIntLong(
  "TUTORIAL - CONT'D\n"+
  "\n"+
  "  To insert a line, type 'insert <nr>', where the number is the\n"+
  "  line _before_ where you want to put your line. Your text will\n"+
  "  be inserted after that line.\n"+
  "  Or, 'insert start' will start at the beginning of the file.\n"+
  "\n"+
  "  Type:\n"+
  "\n"+
  "       insert 1\n"+
  "\n"+
  "  You should see:\n"+
  "\n"+
  "        0002:\n"+
  "\n"+
  "  You may insert as many lines as you wish. When you are satisfied,\n"+
  "  just type a '.' at the beginning of a blank line to exit insert\n"+
  "  mode.\n");
 AddExit("continue","./han_ed11");
 AddExit("return","./han_ed9");
}
