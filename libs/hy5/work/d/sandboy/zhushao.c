// Room: /d/sandboy/zhushao.c

inherit ROOM;

void create()
{
	set("short", "竹梢上");
	set("long", @LONG
你被倒吊在一根竹稍上，下面是一堆砍好的竹子。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/sandboy");

	setup();
	replace_program(ROOM);
}
