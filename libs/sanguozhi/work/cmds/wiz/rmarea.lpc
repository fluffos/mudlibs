/* rmarea.c by fire on 16/06/98
this cmd is used to remove an area
in the sg system, this cmmond should
set some priviliage in case careless
wiz may delete data just by testing
usage: rmarea <area_id>
example: rmarea luoyang
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
        write("用法：rmarea <area_id>\n");
        return;
    }
    sscanf(p_id, "%s %s", p_id, extra);
    if ( extra )
    {
        write("地区名之间不得有空格．\n");
		return;
	}
	extra=AREA_D->remove_area(p_id);
	write(extra);
}
