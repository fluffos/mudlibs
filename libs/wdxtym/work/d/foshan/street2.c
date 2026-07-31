//Room: /d/foshan/street2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","西镇街");
	set("long",@LONG
佛山镇街道横亘东西。南边有一座破败的庙宇，里面是一家赌
场，大门上写着“英雄会馆”四个大字。
LONG);
	set("objects", ([
	    "/d/city/npc/liumang": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south" : __DIR__"huiguan",
	    "west"  : __DIR__"street1",
	    "east"  : __DIR__"street3",
	]));
	setup();
}

