// Room: /d/nanyang/xiaolu2.c
// Lklv Modify 2001.10.11

inherit ROOM;
void create()
{
	set("short", "岔路");
	set("long", @LONG
这是一条僻静的小路，两旁是茂密的丛林。路上依稀可见车马走过留下的
痕迹。从这里往东北方向是南阳府许家集，西边方向走是通往襄阳和南阳之间
的一条驿道。
LONG
	);
	set("outdoors", "南阳");
	set("exits", ([
		"northeast" : __DIR__"xujiaji",
		"west" : __DIR__"yidao",
	]));
        set("objects", ([
                NPC_D("caiyaoren") : 1,
        ]));
	setup();
}
