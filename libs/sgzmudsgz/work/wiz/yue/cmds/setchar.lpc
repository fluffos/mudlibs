/* setchar.c by fire on 26/06/98
this cmd is used to set paras for an char(should be npc)
in the sg system, this cmmond should
set some priviliage in case careless
wiz may cause unnessary data just by testing
usage:  setchar <char_id> <para_name> <para_value>
example: setchar lv bu wuli 30
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
        write("用法：setchar <char_id> <para_name> <para_value>\n");
        return;
    }
    sscanf(p_id, "%s %s %s", p_id,para_name,para_value);
	if(!para_value)
    {
        write("用法：setchar <char_id> <para_name> <para_value>\n");
        return;
    }
	if (restore_variable(para_value)!=0)
	{
		para_value=restore_variable(para_value);
	}
	if(para_value=="0")
		para_value=0;
        extra=CHAR_D->set_char(p_id,para_name,para_value);
	write(extra);
}
