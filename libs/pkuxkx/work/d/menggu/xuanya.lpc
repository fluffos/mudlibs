// Room: grass.c 草原
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"悬崖"NOR);
	set("long", @LONG
这里是一处悬崖，上面光溜溜的崖陡如壁，寸草不生。
LONG
	);

	set("exits", ([
	]));
	set("shediao_xuanya",1);
	set("outdoors", "menggu_e");
    setup();
}

void init()
{
    object me=this_player();
    if (me->query_temp("shediaoquest/mayu_s2"))
    {
        return;
    }
    add_action("do_climb","climb");
}

int ma_appear(object me)
{
    object ding=new(__DIR__"ding");
    if (!me||!living(me)||!environment(me)->query("shediao_xuanya"))
    {
        return 1;
    }
    tell_object(me,"这时你突然听见一声长笑，已经被人拉至顶端。\n");
    me->move(ding);
    return 1;
}

int check_down(object me)
{
    if (!me)
    {
        return 1;
    }
	me->delete_temp("shediaoquest/muya_down__ya");
    me->add_temp("shediaoquest/muya_downya_times",1);
    if (me->query_temp("shediaoquest/muya_downya_times")>4+random(5))
    {
        me->delete_temp("shediaoquest/muya_downya_times");
        tell_object(me,"你很顺利地爬下了悬崖。\n");
        me->move("/d/menggu/xuanya_qian");
    }
    else
    {
        me->add_busy(1);
        tell_object(me,HIM"你小心翼翼地攀附着藤蔓，一脚一脚地试探着往下爬去。\n"NOR);
        call_out("check_down",random(2)+1,me);
    }
    return 1;
}


int check(object me)
{
    if (!me)
    {
        return 1;
    }
    me->add_temp("shediaoquest/muya_paya_times",1);
    if (me->query_temp("shediaoquest/muya_paya_times")>1+random(5))
    {
        me->delete_temp("shediaoquest/muya_paya_times");
        me->set_temp("shediaoquest/mayu_s2",1);
        tell_object(me,"你咬紧牙关，勉力试了两次，都是刚爬上一步，就是一滑，险险跌下去粉身碎骨。\n");
        tell_object(me,"你心知无望，吁了一口气，要想下来，哪知望下一瞧，只吓得魂飞魄散。\n");
        tell_object(me,"原来上来时一步步的硬挺，想从原路下去时，本来的落脚之点已给凸出的岩石挡住，再也摸索不到，若是涌身向下一跳，势必碰在山石上撞死。\n");
        call_out("ma_appear",1,me);
    }
    else
    {
        me->add_busy(1);
        tell_object(me,"你攀藤附葛，一步步的爬上去。\n");
        call_out("check",1,me);
    }
    return 1;
}

int do_climb(string arg)
{
    object me=this_player(),theya=load_object(__DIR__"xuanya_qian");
    string *ya=({"up","down",});
    if (!me->query_temp("shediaoquest/mayu_s1")&&!me->query("shediaoquest/mayu"))
    {
        tell_object(me,"不知不觉你爬下了悬崖！\n");
        me->move(theya);
        return 1;
    }
    me->delete_temp("shediaoquest/mayu_s1");
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!arg||member_array(arg,ya)==-1)
    {
        tell_object(me,"你要往上爬还是往下爬？\n");
        return 1;
    }
    if (me->query_temp("shediaoquest/mayu_start_pa"))
    {
        tell_object(me,"老实点吧，一不小心就会掉下去尸骨无存的。\n");
        return 1;
    }
    if (arg=="down")
    {
        tell_object(me,"不知不觉你爬下了悬崖！\n");
        me->move(theya);
        me->add_busy(1);
        return 1;
    }
    if (arg=="up")
    {
        tell_object(me,"你攀藤附葛，一步步的爬上去。\n");
        call_out("climb",1,me);
        me->set_temp("shediaoquest/mayu_start_pa",1);
        me->add_busy(1);
        check(me);
    }
    return 1;
}