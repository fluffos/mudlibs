// guiyunzhuang/xiuxishi 休息室
// modified byZine
#include <ansi.h>
inherit ROOM;

void wakeup(object);

void create()
{
    set("short", "休息室");
    set("long", @LONG
这里是归云庄里用来休息的地方。屋内有几张藤床，不禁让人睡意大增。
LONG);
    set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"zoulang2",
            ]));
	set("objects",([__DIR__"npc/xiaohua":1,]));
	set("sleep_room",1);
	set("hsz_no_task",1);
	setup();
}

void init()
{
    add_action("do_sleep",({"sleep","shui"}));
}

int do_sleep()
{
	object me=this_player();

    if ((me->query("neili")<0)||(me->query("jingli")<0))
        return notify_fail("你精血不足，翻来覆去无法入眠! \n");

    if ((me->query("jing")<0)||(me->query("qi")<0))
        return notify_fail("你精气不足，小心一觉睡去永远也无法醒过来! \n");

    if (me->is_busy())
        return notify_fail("你正忙着呢！\n");

    if( me->is_fighting() )
        return notify_fail("战斗中不能睡觉！\n");

    if(me->query_condition("sleep")!=0)
        return notify_fail("你刚在三分钟内睡过一觉, 多睡对身体有害无益! \n");

	if (me->query_temp("shediaoquest/guiyun/step")==10)
	{
		me->set_temp("shediaoquest/guiyun/step",11);
	}

    call_out("wakeup", 0, me);

    return 0;
}

void wakeup(object me)
{
    if ( me->query_temp("debug_sleep/duration") )
    {
        call_out("wakeup", me->query_temp("debug_sleep/duration"), me);
    }
    else
    {
        if (me->query_temp("shediaoquest/guiyun/step")==11)
        {
            me->set_temp("shediaoquest/guiyun/step",12);
            tell_object(me,"\n"+HIW+"你决定再去见见陆庄主"+HIR+"请教"+HIW+"一番。\n"+NOR);
        }
    }
}

