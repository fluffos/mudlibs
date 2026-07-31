//Room: /d/foshan/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","小道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里向东是广西。向西
北走就是大理国的地界了。
LONG);
	set("objects", ([
	   __DIR__"obj/shikuai": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northwest" : "/d/dali/road5",
	    "east"      : __DIR__"road2",
	]));
	setup();
}

