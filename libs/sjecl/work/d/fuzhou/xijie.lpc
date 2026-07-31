// Room: /d/fuzhou/xijie.c
// Lklv 2001.9.10

inherit ROOM;

void create()
{
	set("short", "西街");
	set("long", @LONG
这里是福州的西大街，街面可以算的上很热闹，街道上往来着形形色色的
男女老少，其中不乏身背兵器的江湖豪客。北面看起来象是一个当铺，门面不
是很大，街南面有两扇高高的大门，门里是一座很大的宅院，抬头可以看见门
上的四个大字：“福威镖局”。
LONG
	);

	set("exits", ([
                "east" : __DIR__"zhongxin",
                "west" : __DIR__"xijie2",
                "north" : __DIR__"dangpu",
                "south" : __DIR__"biaoju",
	]));

	set("objects", ([
		__DIR__"npc/tangzi" : 2,
		__DIR__"npc/shi_bt" : 1,
		__DIR__"npc/zheng_bt" : 1,
	]));

	set("outdoors", "福州");
	setup();
}
