// Room: /u/jpei/beijing/road1.c

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "长安街");
	set("long", @LONG
一条繁华的街道，南边是一家小酒馆。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "北京");

	set("exits", ([
		"south": __DIR__"jiuguan1",
	]) );

	setup();
	quarter_pass();
}

void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) {
		set("long", @LONG
一条繁华的街道，南边是一家打烊了的小酒馆。
LONG
		);
		delete("exits/south");
	}
	else {
		set("long", @LONG
一条繁华的街道，南边是一家小酒馆。
LONG
		);
		set("exits/south", __DIR__"jiuguan1");
	}
	call_out("quarter_pass", 30);
}

