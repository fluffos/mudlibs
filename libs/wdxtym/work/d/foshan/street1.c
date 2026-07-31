//Room: /d/foshan/street1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","西镇街");
	set("long",@LONG
佛山镇街道平整。西面是镇西门，北面有一座北帝庙，建构宏
伟，好大一座神祠。
LONG);
	set("objects", ([
	    __DIR__"npc/jiading": 1,
	    "/clone/npc/walker" : 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"beidimiao",
	    "west"  : __DIR__"westgate",
	    "east"  : __DIR__"street2",
	]));
	setup();
}

