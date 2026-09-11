// by fire on Dec 17, 1997 sell.c
#include <verb.h>
inherit VERB_OB;
void do_sell_str(string str)
{
	object o;
    mixed ss,sen;
	o=MY_OB(str);
	if(!o) return;
	sen=PARASE_D->sep_id_num( str);
	if(!sen) return;
	ss=o->query_can_sell();
	if(!ss) ss=o->short()+"不能卖。\n";
	if(stringp(ss)) 
	{
		write(ss);
		return;
	}
	ss=environment(this_body())->sell(sen[0],sen[1]);
    if(!ss)
	{
        write("这儿不能卖东西。\n");
		return;
	}

    this_body()->start_busy(2);
}
mixed * query_verb_info() {
    return ({ ({ "STR" }) });
}
