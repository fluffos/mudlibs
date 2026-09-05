
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你走着走着，突然发现你迷失了方向，你往回走的时候却发现那已不
是你来的道路了，你不禁心中一阵发麻。突然你在昏黄的灯光下，隐约发
现两边的洞壁上刻着一些奇形怪状的符号(fuhao)。
LONG );
	set("exits", ([
		"northeast" : __DIR__"midao6",
		"northwest" : __DIR__"midao8",
		"eastdown":__DIR__"midao10",
	]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
