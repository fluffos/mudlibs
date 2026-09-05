// guiyunzhuang/shanlu2 山路
// Made By:pingpang
inherit ROOM;

void create()
{
        set("short", "山路");
set("long", @LONG
这是长满荆棘的山路，一不小心就会被划伤了。
LONG);
        set("exits", ([ /* sizeof() == 2*/
        "southdown" : __DIR__"shanlu1",
        "northup" : __DIR__"shanlu3",
        ]));
	set("objects",([__DIR__"obj/corpse":2,]));
        set("outdoors","guiyunting");
	setup();
	replace_program(ROOM);
}
