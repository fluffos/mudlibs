//Room: /d/foshan/road12.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。岭南山林茂密，多产毒
虫，各位行路要十分小心。
LONG);
	set("objects", ([
	   "/clone/beast/dushe": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northwest" : __DIR__"road10",
	]));

	set("resource/snake", ({ "/clone/beast/dushe", }));

	setup();
}

