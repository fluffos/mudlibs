// Room: /d/jingzhou/lydao3.c
// congw 980830

inherit ROOM;

void create()
{
	set("short", "林荫道");
	set("long", @LONG
这是一条安静的林荫道，地上铺着奇奇怪怪五颜六色的石子，向东西两头延伸。
东面是一条林荫道。直通南大街。西边好像有一眼温泉。
LONG
	);
        set("outdoors", "jingzhou");
	set("exits", ([
		"out" : __DIR__"lydao2",
	]));

	set("objects", ([
	 __DIR__"npc/kid" :3,
	]));
        
	setup();
	replace_program(ROOM);
}

