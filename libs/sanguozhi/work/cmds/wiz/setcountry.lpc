/* setcountry.c by fire on 2/07/98
this cmd is used to set paras for a country
in the sg system, this cmmond should
set some priviliage in case careless
wiz may cause unnessary data just by testing
usage:  setcountry <country_id> <para_name> <para_value>
*/
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
nomask private void main(string str)
{
	string p_id=str,p_id2;
	string para_name;
	mixed para_value;
	string extra;
    if (!str)
    {
        write("用法：setcountry <country_id> <para_name> <para_value>\n");
        return;
    }
    sscanf(p_id, "%s %s %s %s", p_id,p_id2,para_name,para_value);
	if(!para_value)
    {
        write("用法：setcountry <country_id> <para_name> <para_value>\n");
        return;
    }
	if (restore_variable(para_value)!=0)
	{
		para_value=restore_variable(para_value);
	}
	if(para_value=="0")
		para_value=0;
	extra=COUNTRY_D->set_country(p_id+" "+p_id2,para_name,para_value);
	write(extra);
}
