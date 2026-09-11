/* createcountry.c by fire on 26/06/98
this cmd is used to create a newcountry 
in the sg system, this cmmond should
set some priviliage in case careless
wiz may cause unnessary data just by testing
usage: createcountry <char id>
example: createcountry ma teng
*/
#include <mudlib.h>
#include <daemons.h>
#include <country.h>
inherit CMD;
nomask private void main(string str)
{
	string p_id=str;
    int extra = 0;
	string ret;
    if (!str)
    {
        write("用法：createcountry <char id>\n");
        return;
    }
	extra=COUNTRY_D->creat_country(str);
	switch(extra)
	{
	case CC_ALREADYEXIST:
		ret="该角色已经是国王．\n";
		break;
	case CC_CHARNOTEXIST:
		ret="没有该角色．\n";
		break;
	case CC_CHARNOAREA:
		ret="该角色没有所在地．\n";
		break;
		case CC_OTHERCOUNTRYCAPITAL:
			ret="该地为他国国都．\n";
			break;
	case CC_ACCEPTED:
		ret ="成功．\n";
		break;
	default:
		ret= "未成功\n";
	}
	write(ret);
}
