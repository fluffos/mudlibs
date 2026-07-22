// by xiaoyao

inherit ROOM;
void create()
{
        set("short","林间道");
        set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。岭南山林茂密，多产毒虫，各位行
路要十分小心。
LONG);
        set("objects", ([
		__DIR__"obj/shikuai": 1,
		__DIR__"npc/tufei": 1,
        ]));
        set("outdoors", "佛山");
        set("exits",([ /* sizeof() == 1 */
		"northeast" : "/d/group/entry/fsroad13",
		"southwest" : __DIR__"road10",
	]));
	setup();
}
