/* addarea.c by fire on 16/06/98
this cmd is used to add a new area
in the sg system, this cmmond should
set some priviliage in case careless
wiz may cause unnessary data just by testing
usage: addarea <area_id>
example: addarea luoyang
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
        write("用法：addarea <area_id>\n");
        return;
    }
    sscanf(p_id, "%s %s", p_id, extra);
    if ( extra )
    {
        write("地区名之间不得有空格．\n");
		return;
	}
	extra=AREA_D->add_area(p_id);
	write(extra);
}
