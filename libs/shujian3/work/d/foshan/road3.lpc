// road3.c by XiaoYao

inherit ROOM;
void create()
{
        set("short","林间道");
        set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山林茂密，多
产毒虫，各位行路要十分小心。
LONG);
	set("outdoors", "佛山");
	set("exits",([ /* sizeof() == 1 */
		"east"      : __DIR__"road2",
		"northwest" : __DIR__"road4",
	]));
	setup();
}
