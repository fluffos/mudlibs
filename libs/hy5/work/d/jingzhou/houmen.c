// Room: houmen
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "后门");
	set("long", @LONG
关庙的后门，望北是一处小山坡。
LONG
	);

	set("exits", ([
		"south" : __DIR__"houdian",
		"northup" :__DIR__"xiaoshan",
	]));

	setup();
	replace_program(ROOM);
}

