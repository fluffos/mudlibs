/* RoomMaker- Headerfile
 *
 * Part of RoomMaker V0.94 (c) Sique 9/1992
 *
 * Author: Sique 9/92
 *
 * Last Update: Sep 29 1992
 */

/* Defines the sizes of a normal terminal screen */

#include "/obj/tool/roommaker/sizes.h"

/* Define some variables */
#define ROOMSTDS ({"room","hotelroom","port","shop","pub"})

/* Prototypes and global variables */

nosave void gotogetstring();
nosave void gotogettext();
nosave void abort();
nosave string help();
nosave string file_print();
nosave void SetLabel(string label,mixed argument);
nosave mixed QueryLabel(string label);
nosave void ClearText();
nosave void SetText(string *text);
nosave void gotomenu();
string QueryFile();
string *EditText();
string arrayprint(string *arr);
