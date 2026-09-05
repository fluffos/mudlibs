// Room: /hangzhou/beidajie2.c
// hubo 2008/4/19 
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include <localtime.h>
void create()
{
	set("short", "景灵宫");
	set("long", @LONG
这是景灵宫，皇家恭奉祖宗衣冠、牌位之所在。四季朝献，禁中行礼。
LONG);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"beidajie2",
	]));
	set("objects", ([
		__DIR__"npc/huangmen" : 2,
        ])); 
	setup();
}
int Calc_Remain(int time)//计算从ask起到下一周还有多少时间
{
	int hour,min,wday,sec,remain;
	mixed* timeinfos=localtime(time());
	hour = timeinfos[LT_HOUR];
	min = timeinfos[LT_MIN];
	sec = timeinfos[LT_SEC];
	wday = timeinfos[LT_WDAY];
	if (wday<1) wday=7;//星期天LT_WDAY为0	
	remain=(86400-sec-min*60-hour*3600)+(7-wday)*86400;
	return remain;
}
void init()
{
	add_action("do_start","start");
}

int do_start()
{
	object me=this_player();
	if (!me->query("strategy_books"))
	return 0;
	if (time()<me->query("statistics/sbook_double/next_init"))
	{
		tell_object(me,"必须再过"+CHINESE_D->chinese_period(me->query("statistics/sbook_double/next_init")-time())+"，到了下一周，你才能再次开启双倍奖励状态。\n");
		return 1;
	}
	if (time()<me->query("double_reward"))
	{
		tell_object(me,"你现在正处于双倍奖励状态中。\n");
		return 1;
	}
	me->set("statistics/sbook_double/next_init",time()+Calc_Remain(time()));
	tell_object(me,HIG+"你开启了为期两个小时的双倍奖励状态。加油！加油！\n"+NOR);
	me->set("doublereward",time()); //赋值到系统狂欢变量1
	me->set("double_reward",time()+7200);  //赋值到系统狂欢变量2
	return 1;
}