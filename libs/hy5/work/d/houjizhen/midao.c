// didao.c
// by dicky

inherit ROOM;

void create()
	{
	set("short","秘道");
	set("long", @LONG
这是一条异常幽静的秘道，四周漆黑一团，你好象什么都看不见似
的，走在里面，你不觉想到这似乎在每个角落都藏着无限杀机，太恐怖
了，四周毫无声息，好象掉下一根针都可能听到。
LONG 
);
	set("exits",([
		"east" : __DIR__"midao1",
		"out" : __DIR__"miao",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
