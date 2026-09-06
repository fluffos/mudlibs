/* Last modified by tune on Fri Apr 28 14:15:35 1995
** Made using Ulantris Roommaker II version 1.33
*/

#include <rooms.h>
#include "/p/school/sys/school.h"

inherit STD_HAN_ED;

varargs void create()
{
 ::create();
 SetIntShort("Tutorial for Hanarra's Editor, Page 5");
 SetIntLong(
  "NOTES\n"+
  "\n"+
  "  When you load a file into the editor, it makes a copy of the file\n"+
  "  and puts it into a \"buffer\". Remember that this is a copy of the\n"+
  "  file; you aren't editing the original!\n"+
  "\n"+
  "  Unlike ed, Hanarra's editor does not have it's own prompt, and only \n"+
  "  edits the file when you type in a specific editor command. It is\n"+
  "  thus practical, since you can do other things while you are editing\n"+
  "  a file.\n"+
  "\n"+
  "  If at any time you feel that you would rather go back to the original\n"+
  "  version and not save the version you have been editing, just type\n"+
  "  'discard'. This will remove the file from the edit buffer without making\n"+
  "  any changes to the original file.\n"+
  "\n");
 AddExit("continue","./han_ed6");
 AddExit("return","./han_ed4");

}
