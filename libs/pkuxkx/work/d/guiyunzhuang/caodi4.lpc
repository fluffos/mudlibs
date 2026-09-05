// guiyunzhuang/caodi4 草地

inherit ROOM;

void create()
{
    set("short", "草地");
    set("long", @LONG
这是一块草地，是一个无拘无束的好地方。
LONG);
        set("exits", ([ /* sizeof() == 2*/
	"east" : __DIR__"taihujie",
        "south" : __DIR__"caodi3",
        ]));
	set("objects",([__DIR__"npc/laonong":1,__DIR__"npc/minnv":1,]));

        set("outdoors","guiyunzhuang");
	setup();
	replace_program(ROOM);
}
