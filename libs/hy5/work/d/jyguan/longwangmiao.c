// Room: /jyguan/longwangmiao.c
// Shark 10/08/1998

inherit ROOM;

void create()
{
	set("short", "龙王庙");
	set("long", @LONG
这里的百姓为了乞求上天降雨以滋民生，也求水井泉涌若河永不枯竭，就修建
了这座龙王庙。庙后面就是民居了。
LONG
	);
	//set("no_fight", 1);
	set("no_beg",1);
	set("objects", ([
		"/d/city/obj/box" : 1,
	]));
	
	set("exits", ([
		"north" : __DIR__"townroad1",
	]));

	setup();
	replace_program(ROOM);
}

