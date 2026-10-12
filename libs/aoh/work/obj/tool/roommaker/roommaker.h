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

protected void gotogetstring();
protected void gotogettext();
protected void abort();
protected string help();
protected string file_print();
protected void SetLabel(string label,mixed argument);
protected mixed QueryLabel(string label);
protected void ClearText();
void SetText(string *text);
protected void gotomenu();
string QueryFile();
string *EditText();
string arrayprint(string *arr);
