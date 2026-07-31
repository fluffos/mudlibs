//Room: /d/foshan/road2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","小道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山
林茂密，多产毒虫，各位行路要十分小心。
LONG);
	set("objects", ([
	   __DIR__"obj/hua1": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"road1",
	    "east"  : __DIR__"road3",
	]));
	setup();
}

