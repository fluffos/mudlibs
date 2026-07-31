// Room: 大理北门/dali/beimen.c
// bbb 1997/06/11
// Modify By River 98/12/
// Fix a bug by caiji@SJ 8/26/2000

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "北门");
	set("long", @LONG
这是大理北城门，大理和大宋间的来往都要经过此门，往北你可看到一条
宽广笔直的石板大道，可以通向中原。阳苜咩城，或简称苜咩城，是大理国的
都城。自南诏于初创，历经陈氏“长大和国”、赵氏“大天兴国”、杨氏“大
义宁国”诸代而至当今的段氏的“大理国”，均以此城为都。城门两边的武将
和士兵门认真地检查着过往的行人，不少中原来的江洋大盗均在此落网。
LONG
	);

	set("exits", ([
		"south" : __DIR__"beijie3",
		"north" : __DIR__"dadao4",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "大理");
	setup();
}

void init()
{
	object me = this_player();
	if( me->query("qinwang") && me->query("tls"))
		me->delete("qinwang");
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("xuncheng") && dir == "north")
		return notify_fail("你还在巡城呢，仔细完成你的任务吧。\n");
	if(objectp(present("wujiang", environment(me)))&& me->query("qinwang")) {
		message_vision(HIY"武将恭恭敬敬地对$N说道：“"+(string)me->query("qinwang")+"慢走。”\n"NOR, me); 
	}
	if(objectp(present("bing", environment(me)))&& me->query("qinwang")) {
		message_vision(HIY"官兵恭恭敬敬地对$N说道：“"+(string)me->query("qinwang")+"慢走。”\n"NOR, me); 
	}//原来的"你"改为"$N" by caiji@SJ 8/26/2000
	return ::valid_leave(me, dir);
}
