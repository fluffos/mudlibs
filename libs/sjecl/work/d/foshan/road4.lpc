//road4.c by Xiaoyao

inherit ROOM;
void create()
{
        set("short","林间道");
        set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山林茂密，多
产毒虫，各位行路要十分小心。
LONG);
        set("objects", ([
		__DIR__"npc/snake": 1,
	]));
	set("outdoors", "佛山");
	set("exits",([ /* sizeof() == 1 */
		"southwest" : "/d/group/entry/fsroad5",
		"southeast" : __DIR__"road3",
	]));
	setup();
}
