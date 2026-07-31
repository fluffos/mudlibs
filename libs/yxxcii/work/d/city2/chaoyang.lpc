//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "朝阳门");
	set("long", @LONG
这里就是朝阳门，城墙上刻着“朝阳门”三个大字。东门就在东南边
，那里人来车往，是进出京城的要道，盘查十分严密。一条宽阔的大道向
西延伸，通往著名的王府井大街。从这里也可以出北京城，东北边就是郊
外，那里有一大片竹林，一个人也看不见。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"southeast" : __DIR__"chaoyan2",
		"northeast" : __DIR__"zhulin1",
		"west" : __DIR__"chaoyan1",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));

	setup();
	replace_program(ROOM);
}


