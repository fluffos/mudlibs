// zengke.c 
// Zine 2012/10/14
#include <ansi.h>
#include "cmd_assist.h"
inherit F_CLEAN_UP;
#include "/d/yingtianfu/neicheng/npc/promote.h"
int help(object me);
int zengke(object li)
{
    if (living(li))
    {
        li->add_lists();
    }
    return 1;
}
int main(object me,string arg)
{
    object qt,li;
    if (identifications(me,({"礼部尚书","礼部左侍郎","礼部右侍郎",}))==0)
	return deny(me);
	if (arg=="-h")
	return help(me);
    qt=load_object("/d/yingtianfu/neicheng/qintian");
    if (!qt)
	{
		tell_object(me,"时下时局实在不宜增开科考。\n");
		return 1;
	}
    if (!li=qt->query("li"))
    {
		tell_object(me,"时下时局实在不宜增开科考。\n");
		return 1;
	}
    if (!living(li))
    {
		tell_object(me,"时下时局实在不宜增开科考。\n");
		return 1;
	}
    if (me->query("ming/energy")<100)
    {
		tell_object(me,"你现在的行动力不足，无法增开科考。\n");
		return 1;
	}
    if (identification(me,"礼部尚书"))
    {
        if (time()-me->query("ming/zengke/time")>3600*24*7)
        {
            me->set("ming/zengke/time",time());
            me->set("ming/zengke/times",1);
            me->add("ming/energy",-100);
            li->add_lists();
        }
        else
        {
            if (me->query("ming/zengke/times")<2)
            {
                me->add("ming/zengke/times",1);
                me->add("ming/energy",-100);
                li->add_lists();
            }
            else
            {
                tell_object(me,"这段时间内你已经增开了两场科考，再等等吧！\n");
            }
        }
        return 1;
    }
    if (identifications(me,({"礼部左侍郎","礼部右侍郎"})))
    {
        if (time()-me->query("ming/zengke/time")>3600*24*7)
        {
            me->set("ming/zengke/time",time());
            tell_object(me,"上峰已经答应了你的请求，将尽快增开科考！\n");
            me->add("ming/energy",-100);
            call_out("zengke",20+random(40),li);
        }
        else
        {
            tell_object(me,"这段时间内你已经增开过科考了，再等等吧！\n");
        }
        return 1;
    }
}
int help(object me)
{
    write("
指令格式 : ming zengke
增科抡才大典。
"    );
    return 1;
}
