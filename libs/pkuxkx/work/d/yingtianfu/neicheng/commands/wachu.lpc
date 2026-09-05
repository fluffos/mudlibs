// wachu.c 
// Zine 2012/10/14
#include <ansi.h>
#include "special_permit.h"
inherit F_CLEAN_UP;
int help(object me);
int afterwa(object me)
{
    object room=environment(me);
    object bei;
    if (!room->query("goodplace"))
    {
        tell_object(me,"你挖了半天，似乎什么也没发现。\n");
        return 1;
    }
    tell_object(me,"你往下挖了三尺，似乎遇到一个硬碑。\n");//出现
    bei=new(__DIR__"bei");
	bei->set("owner",me->query("id"));
    bei->set("pin",(int)me->query("mingpin"));
    bei->move(room);
    if (room->query("no_reset"))
    {
        bei->set("roomno_reset",1);
    }
    room->set("no_reset",1);
    room->set("no_clean_up", 1);
    return 1;
}
int main(object me, string arg)
{
    object env=environment(me);
    object shibei;
	string need="fengshui";
    if (arg=="-h")
	return help(me);
	if (special_permit(me,need)==0)
    {
		return 1;
    }
    if (present("shi bei",env))
    {
        shibei=present("shi bei",env);
    }
    if (shibei && shibei->query("is_shibei"))
    {
        tell_object(me,"你要挖的东西不是已经在这里了？\n");
        return 1;
    }
	if (me->query("neili")<500)
	{
		tell_object(me,"你现在内力不够，怎能徒手挖穿这里？\n");
        return 1;
	}
    message_vision("$N开始用手吃力地在地上挖着什么。\n",me);
    me->add("neili",-500);
	me->add_busy(3);
    remove_call_out("afterwa");
    call_out("afterwa",3,me);
    return 1;
}
int help(object me)
{
    write("
指令格式 : ming wachu
挖出辅助修炼的石碑，需要大明特技风水。
"    );
    return 1;
}
