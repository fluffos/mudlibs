// shanlu1.c 山路1
// create by host dec,12

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是一条上山小路上，蜿蜒迂回，两旁依然是茂密的树林，四周一片
寂静，清风吹来只听得书叶摇摆间发出的声响。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "west": __DIR__"shanlu2",
                "northeast": "/d/wudang/wdroad9",
      	]));
	setup();
}

