/* Last modified by tune on Mon Apr 24 11:53:10 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort("Tutorial for Hanarra's Editor Page 11");
 SetIntLong(
  "TUTORIAL - CONT'D\n"+
  "\n"+
  "  Now, there is one last mistake in the file. Look at line 17.\n"+
  "  /d/cove/common/center/house.c doesn't exist. If you try to use this\n"+
  "  exit, you will get an error. Change this line so that the exit\n"+
  "  returns you to your workroom.\n"+
  "\n"+
  "      change 17\n"+
  "\n"+
  "  You should see:\n"+
  "\n"+
  "      OLD\n"+
  "      0017: AddExit(\"north\",\"/d/cove/common/center/house.c\");\n"+
  "      NEW\n"+
  "      0017:\n"+
  " \n"+
  "  Change this to:\n"+
  "\n"+
  "       AddExit(\"north\",\"/players/(your name)/workroom.c\");\n"
  "\n");
 AddExit("continue","./han_ed12");
 AddExit("return","./han_ed10");

}
