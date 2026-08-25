/* addchar.c by fire on 26/06/98
this cmd is used to add a new char (npc)
in the sg system, this cmmond should
set some priviliage in case careless
wiz may cause unnessary data just by testing
usage: addchar <surname> <givenname>
example: addchar lv bu
*/
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
nomask private void main(string str)
{
	string p_id=str;
    string extra = 0;
    if (!str)
    {
        write("用法：addchar <surname> <givenname>\n");
        return;
    }
	extra=CHAR_D->add_char(p_id);
	write(extra);
}
