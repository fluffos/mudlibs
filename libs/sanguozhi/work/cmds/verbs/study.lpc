// by fire on Jan 8 1998
// study.c
#include <mudlib.h>
#include <setbit.h>
#include <verb.h>
inherit VERB_OB;
void do_study_str(string str)
{

	object o;
	mixed ret;
	o=MY_OB(str);
	if(!o) {return;}
	ret=o->direct_study_obj();
	if(ret==1)
	{
		o->study_book();
		return;
	}
	if(!ret)
		ret="你没法学习"+o->short()+"。\n";
	write(ret);
	return;
}
mixed * query_verb_info()
{
    return ({ ({ "STR" }) });
}
