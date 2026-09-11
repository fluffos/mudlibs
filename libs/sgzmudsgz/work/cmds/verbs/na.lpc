// na used to deliever nation information
#include <mudlib.h>
#include <setbit.h>
#include <verb.h>

inherit VERB_OB;

void do_na_str(string str)
{
	string p_id;
	mixed ret;
	p_id=this_body()->query_id()[0];
	ret="/daemons/nation_channel_d"->deliever_enter(p_id,str);
	if(stringp(ret))
		write(ret);
}
void do_na()
{
	do_na_str("");
}

array query_verb_info()
{
    return ({ ({ "", "STR" }) });
}
