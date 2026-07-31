// Room: /u/jpei/thd/hbroad.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
一条通往海边的土路，东边就是海边的小渔港了，不时从那边传来喧闹
声。路的北边有一座老旧的客栈，掉了金的招牌上写着"归来客栈"几个字。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"kezhan.c",
		"east": __DIR__"bay.c",
		"southwest": __DIR__"njeast.c",
	]) );

	setup();
	replace_program(ROOM);
}

