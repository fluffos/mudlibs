// restroom.c
// by paladin
#include <ansi.h>

inherit ROOM;
void wakeup(object);
void create()
{
	set("short", HIG"睡房"NOR);
	set("long", 
"这里是天龙寺寺内弟子休息的地方。\n"
	);
	set("sleep_room",1);
	set("exits", ([
"out" : __DIR__"changlang2",

	]));
    
	setup();
	set("no_fight",1);
}

void init()
{
    add_action("do_sleep",({"sleep","shui"}));
}

int do_none()
{
    object me=this_player();
    if (me->query_temp("block_msg/all"))
    {
        return 1;
    }
}

int do_sleep(string arg)
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

    if ((NATURE_D->get_current_day_phase()=="晚上"||NATURE_D->get_current_day_phase()=="午夜")&&me->query("combat_exp")<10000&&me->query("family/family_name")=="天龙寺")
    {
        me->set_temp("tlnewbiejob/newbie/sleep",2);
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
        if ( me->query("combat_exp")<10000 && me->query("family/family_name")=="天龙寺" )
        {   
            tell_object(me,"\n作为一名天龙入门弟子，规律的生活是必要的。\n");
            if (me->query_temp("tlnewbiejob/newbie/nian")!=2)
            {
                tell_object(me,"你做过早课了吗？\n");
                return;
            }
            if (me->query_temp("tlnewbiejob/newbie/qiao")!=2)
            {
                tell_object(me,"你敲响晨钟了吗？\n");
                return;
            }
            if (me->query_temp("tlnewbiejob/newbie/bangchu")!=2)
            {
                tell_object(me,"你早晚去帮厨了吗？\n");
                return;
            }
            if (me->query_temp("tlnewbiejob/newbie/dazuo")!=2)
            {
                tell_object(me,"你正午在雨花院打坐了吗？\n");
                return;
            }
            if (me->query_temp("tlnewbiejob/newbie/tiaoshui")!=2)
            {
                tell_object(me,"你下午提后院挑水了吗？\n");
                return;
            }
            if (me->query_temp("tlnewbiejob/newbie/tiaoshui")!=2)
            {
                tell_object(me,"你下午提后院挑水了吗？\n");
                return;
            }
            if (me->query_temp("tlnewbiejob/newbie/sleep")!=2)
            {
                tell_object(me,"晚上不睡觉，白天能有精神吗？\n");
                return;
            }
        }
    }
}

