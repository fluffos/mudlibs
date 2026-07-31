//JMQJIGUAN.C

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "巨木旗神木");
	set("long", @LONG

你眼前只见一棵大树，高有百丈，十人也环抱不住。巨树倚绝壁而
生，枝叶繁茂，藤萝环绕，竟然无法一览全貌。树身有一处光滑无
比，是常有人摩挲而成。
LONG );
	set("exits", ([
		"east" : __DIR__"jmqshulin6",
		"xiaodao" : __DIR__"jmqmen",
        ])); 
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_climb", "climb");
}
int do_climb()
{
        object me=this_player();
//        mapping mypar = (mapping) me->query("party");
        me->receive_damage("qi",15);
        me->receive_wound("qi",15);
//        if(!mypar || mypar["party_name"] != HIG "明教" NOR) 
//             return notify_fail("你努力想爬上去, 可是树身实在太光滑..\n"); 
        
	message_vision(HIC"$N三下两下就顺树身爬了上去...\n"NOR, me);
	call_out("kicking", 0, me);
	tell_object(me, HIC"你爬到了巨木旗大厅。\n"NOR);
	message("vision", HIC"只见"+me->query("name")+"顺树身爬了上来，靠在墙边直喘气！\n"NOR, environment(me), me);
}
void kicking(object me)
{
	me->move(__DIR__"jmqdating");
}
