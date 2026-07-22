// Room: /u/jpei/guiyun/road2.c

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "湖滨小路");
	set("long", @LONG
一条湖滨的小路，往东面看远处似乎横着一条小河。往北面看是一条不知
有多长的小路。南面是一家小酒馆。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "归云庄");

	set("exits", ([
		"east": __DIR__"riverw",
		"north": __DIR__"road3",
		"south": __DIR__"jiuguan",
	]) );
	set("objects", ([
		"/clone/npc/kid" : 1,
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
一条湖滨的小路，往东面看远处似乎横着一条小河。往北面看是一条不知
有多长的小路。南面是一家打烊了的小酒馆。
LONG
		);
		delete("exits/south");
	}
	else {
		set("long", @LONG
一条湖滨的小路，往东面看远处似乎横着一条小河。往北面看是一条不知
有多长的小路。南面是一家开着的小酒馆。
LONG
		);
		set("exits/south", __DIR__"jiuguan");
	}
	call_out("quarter_pass", 30);
}
