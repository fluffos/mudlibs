// Room: /d/diaoyudao/shatan3.c 沙滩
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "沙滩");
	set("long", @LONG
你走在南沙滩上，海水冲刷你的脚面，海风吹拂你的脸庞，你感
到全身轻松舒畅。南面是一望无际的大海，背面有一片草地。
LONG
	);
	
	set("exits", ([
      "west" : __DIR__"shatan3",
         "southeast" : __DIR__"shatan5",
		 "northeast" : __DIR__"caodi1",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

