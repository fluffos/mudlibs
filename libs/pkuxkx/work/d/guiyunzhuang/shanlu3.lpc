// guiyunzhuang/shanlu3 山路
// Made By:pingpang
inherit ROOM;

void create()
{
        set("short", "山路");
set("long", @LONG
这是长满荆棘的山路，一不小心就会被划伤了。
LONG);
        set("exits", ([ /* sizeof() == 2*/
        "southdown" : __DIR__"shanlu2",
	"west" : __DIR__"sheku",
        "north" : __DIR__"shandong",
        ]));
	set("objects",([__DIR__"obj/baigu":2,__DIR__"npc/heiying":1,]));
        set("outdoors","guiyunting");
	setup();
}
int valid_leave(object me, string dir)
{
        if ( (me->query("id") == "mei chaofeng" || me->query("id") == "chen xuanfeng")&&  dir == "southdown" ) return 0;

        return ::valid_leave(me, dir);
}
