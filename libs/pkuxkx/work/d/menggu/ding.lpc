// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;
#include "/d/menggu/shediao_bonus.h"
void create()
{
	set("short", WHT"崖顶"NOR);
	set("long", @LONG
这里是一处悬崖的顶端，往下望去，一切尽在脚下。
LONG
	);

	set("exits", ([
        "west" : __DIR__"buerhan-4",
	]));
    set("outdoors", "menggu_e");
	set("shediao_yading",1);
	setup();
}

void init()
{
    object me=this_player();
    add_action("do_lx","lianxi");
    add_action("do_climb","climb");
    if (!me->query_temp("shediaoquest/mayu_s2"))
    {
        return;
    }
	me->delete_temp("shediaoquest");
    if (me->query("shediaoquest/mayu"))
    {
        return;
    }
    me->set("shediaoquest/mayu",1);
    tell_object(me,"你眼前站着一位三髻道人。\n");
    tell_object(me,HIC"三髻道人传授了你一些吐纳功夫，嘱咐你每晚爬上崖顶练习(lianxi)！\n"NOR);
    return;
}

int do_climb(string arg)
{
    object me=this_player();
    object xy=new(__DIR__"xuanya");
    if (arg!="down")
    {
        tell_object(me,"你只能向下爬！\n");
        return 1;
    }
    tell_object(me,"你转身想崖下爬去……\n");
	if (!me->query_temp("shediaoquest/muya_down__ya"))
	{
		me->set_temp("shediaoquest/muya_down__ya",1);
		me->move(xy);
		xy->check_down(me);
    }
	return 1;
}

int reward(object me)
{
    int e_reward,increase=40000+random(20000);
    if (me->query("shediaoquest/mayu")==2)
    {
        return 1;
    }
    else
    {
        e_reward=bonus(me,3500);
        me->add("combat_exp",e_reward);
		user_record(me,e_reward,"mayu");
        tell_object(me,HIC"完成射雕主线任务【悬崖传功】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
        if (me->query("family/family_name")=="全真派")
        {
            me->improve_skill("xiantian-gong", increase);
            tell_object(me,HIC"你的「先天功」获得了一些进步！\n"NOR);
        }
        else
        {
            me->improve_skill("force", increase);
            tell_object(me,HIC"你的「基本内功」获得了一些进步！\n"NOR);
        }
        return 1;
    }
}

int finish(object me)
{
    if (!me||!living(me)||!environment(me)->query("shediao_yading"))
    {
        return 1;
    }
    me->add_temp("shediaoquest/muya_tuna_times",1);
    tell_object(me,HIC"你依言继续练习吐纳功夫！\n"NOR);
    if (me->query_temp("shediaoquest/muya_tuna_times")>5+random(5))
    {
        if (random(10)>5&&me->query("shediaoquest/mayu")==1)
        {
            tell_object(me,HIG"突然间，你觉得真气在体内贯通起来！\n"NOR);
            reward(me);
            me->set("shediaoquest/mayu",2);
            return 1;
        }
        else
        {
            tell_object(me,"今天的练习可以结束了，明晚再来吧！\n");
            return 1;
        }
    }
    else
    {
        call_out("finish",1,me);
        return 1;
    }
}

int do_lx()
{
    object me=this_player();
    if (!me->query("shediaoquest/mayu"))
    {
        return 0;
    }
	if (me->query("shediaoquest/mayu")>1)
    {
        tell_object(me,"你已经修成了马道长教你的吐纳方法，到别处用功去吧！\n");
        return 1;
    }
    if (me->query("shediaoquest/mayu_tuna")&&NATURE_D->get_current_day_phase()!="晚上"&&NATURE_D->get_current_day_phase()!="午夜"&&NATURE_D->get_current_day_phase()!="凌晨"&&me->query("id")!="zine")
    {
        tell_object(me,"马道长不是让你夜间来此练习吗？\n");
		tell_object(me,HIC+"提示：输入time，在系统时间为晚上、午夜或凌晨时分可以在这里使用lianxi命令。\n"+NOR);
        return 1;
    }
    if (time()-(int)me->query("shediaoquest/mayu_tuna")<60*12)
    {
        tell_object(me,"勤加练习是好的，但是过犹不及！\n");
        return 1;
    }
    tell_object(me,"你起初思潮起伏，难以归摄，但依着那道人所授缓吐深纳的呼吸方法做去，良久良久，渐感心定。\n丹田中却有一股气渐渐暖将上来，崖顶上寒风刺骨，却也不觉如何难以抵挡。\n");
    me->set("shediaoquest/mayu_tuna",time());
    me->add_busy(1);
    call_out("finish",1,me);
    return 1;
}

int valid_leave(object me,string dir)
{
    if (dir=="west"&&me->query("id")!="zine")
    {
        return notify_fail("这条裂缝极深极宽，非人力能渡。\n");
    }
    return ::valid_leave(me,dir);
}