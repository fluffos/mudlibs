// Room: westroad1.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "西大街");
	set("long", @LONG
你正走在成都府的西大街上，这是一条宽敞开阔的大路，往北面
一直延伸。路上行人来来往往，好不热闹。小商小贩常在这里做些小
买卖，常常可见有人骑着高头大马穿行其间。
    西南边却显得特别清静，好象是个清幽所在，东南方向通往南大
街。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
	    "southwest"  : __DIR__"qingyanggong",
	    "southeast"  : __DIR__"southroad3",
	    "north"      : __DIR__"westroad2",
	]));
	set("objects", ([
	    "/d/village/npc/seller": 1,
	    "/d/city/npc/liumang"  : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}
