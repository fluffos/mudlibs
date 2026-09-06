/* Last modified by tune on Fri Apr 28 14:16:03 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort("Tutorial for Hanarra's Editor Page 5");
 SetIntLong(
  "TUTORIAL\n"+
  "\n"+
  "  First, clone yourself a copy of the editor if you don't already have one:\n"+
  "\n"+
  "      /obj/tool/ed.c\n"+
  "\n"+
  "  Next, make yourself a copy of the practice file. Copy it to your own\n"+
  "  player directory so that you can make changes to it:\n"+
  "\n"+
  "      cp /p/school/files/editor/example_room.c /players/(your name)\n"+
  "\n"+
  "  To start editing the file, type 'file example_room.c'.\n"+
  "  This will load a copy of the file into the editor buffer.\n"+
  "  You should see:\n"+
  "\n"+
  "       Read 20 more lines.\n"+
  "       20 lines read.\n"+
  "       Now editing: /players/(your name)/example_room.c\n"+
  "\n");

 AddExit("continue","./han_ed7");
 AddExit("return","./han_ed5");

}
