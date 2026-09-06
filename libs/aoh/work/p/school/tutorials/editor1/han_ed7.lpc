/* Last modified by tune on Fri Apr 28 14:17:27 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort("Tutorial for Hanarra's Editor page 6");
 SetIntLong(
  "TUTORIAL - CONT'D\n"+
  "\n"+
  "  Next, since the file is relatively short, print out the whole\n"+
  "  file on the screen: 'print all'.\n"+
  "\n"+
  "  The first thing you should notice is that line 12 is written\n"+
  "  incorrectly (for " MUDSHORT ", at least). To change the whole line,\n"+
  "  type 'change 12'. You should see:\n"+
  "\n"+
  "       OLD\n"+
  "       0012: set(\"internal_short\", \"An example room\");\n"+
  "       NEW\n"+
  "       0012:\n"+
  "\n"+
  "  Enter the following line:\n"+
  "\n"+
  "       SetIntShort(\"An example room\");\n"+
  "\n");

 AddExit("continue","./han_ed8");
 AddExit("return","./han_ed6");

}
