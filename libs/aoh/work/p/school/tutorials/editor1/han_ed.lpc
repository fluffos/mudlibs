/* Last modified by tune on Fri Apr 28 14:10:30 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort(
  "Hanarra's Editor tutorial room 1");
 SetIntLong(
  "WORKING WITH HANARRA'S EDITOR\n"+
  "\n"+
  "  This is a small help file and tutorial for those unfamiliar \n"+
  "  with using the file editors in OSB. While the roommaker and\n"+
  "  objectmaker are both very powerful and useful tools, it is also \n"+
  "  important to be able to edit files manually.\n"+
  "\n"+
  "  This tutorial offers some guided practice for those who would like\n"+
  "  some help using the features of Hanarra's editor.\n"+
  "\n"+
  "  When you are finished with a page, type 'continue'.\n"+
  "\n"+
  "  To go back a page, type 'return'.\n"+
  "\n"+
  "  If would like the page to be redisplayed at any time,\n"+
  "  just type 'look'.\n"+
  "\n"+
  "  To see the list of commands available in the editor, type 'commands'.\n");

 AddExit("continue","./han_ed2");

 AddRoomCmd("repeat","repeat");
 AddRoomCmd("commands","commands");

}
