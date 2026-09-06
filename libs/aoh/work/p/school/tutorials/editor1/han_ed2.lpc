/* Last modified by tune on Fri Apr 28 14:19:22 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort(
  "Tutorial for Hanarra's editor");
 SetIntLong(
  "INTRODUCTION\n"+
  "\n"+
  "  There are two editors currently available for wizards in " MUDSHORT ".\n"+
  "  The first is ed, which is based on the standard, built-in \"ed\"\n"+
  "  editor in UNIX systems. Although more powerful, it can also be somewhat \n"+
  "  confusing for new users.\n"+
  "\n"+
  "  The second editor is Hanarra's editor. It lacks some of the\n"+
  "  functionality of ed, but is much easier to learn, and at times can \n"+
  "  be more practical than ed. It is expected that all wizards who code \n"+
  "  in " MUDSHORT " should be able to use one, if not both. \n"+
  "\n"+
  "  This tutorial deals with Hanarra's editor and its basic commands.\n"+
  "\n"+
  "  Type 'continue' to go to the next page.\n");

 AddExit("continue","./han_ed3");
 AddExit("return","./han_ed");
 AddRoomCmd("commands","commands");
 AddRoomCmd("repeat","repeat");

}
