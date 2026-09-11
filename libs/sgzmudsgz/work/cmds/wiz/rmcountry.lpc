/* rmcountry.c by fire on 2/07/98
this cmd is used to remove an country
in the sg system, this cmmond should
set some priviliage in case careless
wiz may delete data just by testing
usage: rmcountry <country_id>
example: rmcountry zhang fei
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
        write("用法：rmcountry <country_id>\n");
        return;
    }
	extra=COUNTRY_D->remove_country(p_id);
	write(extra);
}
