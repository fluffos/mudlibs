// caodi3.c 草地
//Made By:pingpang
inherit ROOM;

void create()
{
    set("short", "草地");
    set("long", @LONG
这是一块草地，是一个无拘无束的好地方。
LONG);
        set("exits", ([ /* sizeof() == 2*/
	"east" : __DIR__"caodi2",
        "north" : __DIR__"caodi4",
        ]));
	set("objects",([__DIR__"npc/yetu":2,]));
        set("outdoors","guiyunzhuang");
	setup();
	replace_program(ROOM);
}
