// Modified by iszt@pkuxkx, 2007-04-20

#include <ansi.h>

inherit ROOM;

void create ()
{
	set("short",YEL"城中心"NOR);
	set("outdoors","xiangyang");
	set("long",YEL @LONG
这里是襄阳的城中心。兵荒马乱的年月，这里早失去了往日的繁华，街边零
零散散有些小商小贩在叫卖，生意也不怎么好。不时有盔明甲亮的守将带着守军
在街面上巡逻。
LONG NOR);
	set("exits", ([
		"east" :   __DIR__"xyeast1", 
		"west" :   __DIR__"xywest1", 
		"south" :  __DIR__"xysouth1", 
		"north" :  __DIR__"xynorth1", 
	]));  
	set("objects", ([
		"/clone/npc/camel1": 1,
		__DIR__"npc/shjiangc" : 2,
	]));
	setup();

//	"/clone/board/xiangy_b"->foo();
}