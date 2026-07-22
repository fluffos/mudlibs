// shanlu2.c 山路2
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你正走在一条上山小路上，蜿蜒迂回，两旁依然是茂密的树林，四周一片
寂静，清风吹来只听得书叶摇摆间发出的声响。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "east": __DIR__"shanlu1",
                "west": __DIR__"shanlu3",
      	]));
	setup();
}

