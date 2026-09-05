// wencai.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "special_permit.h"
int help(object me);
int wencaicheck(object me)
{
	int k;
	if (!me||!me->query_temp("songspecial/wencaiamount"))
	{
		return 1;
	}
    k=(int)me->query_temp("songspecial/wencaiamount");
    if (me->is_fighting())
    {
        me->delete_temp("songspecial/wencaiamount");
        me->add_temp("apply/intelligence",-k);
        tell_object(me,RED+"战斗中你再也不能像平常那样文思泉涌了。\n"+NOR);
        return 1;
    }
    remove_call_out("wencaicheck");
    call_out("wencaicheck",1,me);
    return 1;
}

int main(object me,string arg)
{
    object room=environment(me);
    int k;
    string need="wenqu";
    if (arg=="-h")
	return help(me);
	if (special_permit(me,need)==0)
    {
		return 1;
    }
    if (me->query_temp("songspecial/wencaiamount"))
    {
        tell_object(me,"你已经在使用文采特技了。\n");
        return 1;
    }
    
    else
    {
        k=(int)me->query_int();
		if (k>100)
		k=100;
        me->set_temp("songspecial/wencaiamount",k);
        me->add_temp("apply/intelligence",k);
        message_vision(HIC"$N凝神思索，片刻之后，全是文采激扬。\n"NOR,me);
        remove_call_out("wencaicheck");
        call_out("wencaicheck",1,me);
        return 1;
    }
}
int help(object me)
{
    write("
指令格式 : song wencai
文采激扬，增加临时悟性，需要大宋特技文曲。
"    );
    return 1;
}
