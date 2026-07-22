// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad4.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土飞扬的路，不算太宽，路上行人不多，给人一种落寞的感觉。
南面是一大片的农田，北面则是一眼看不到尽头的桑树林。
LONG
	);
	set("outdoors", "长安");

	set("exits", ([
		"south": "/d/zhiye/nongtian0",
		"north": "/d/zhiye/sanglin0",
		"northup"  : __DIR__"northroad5",
		"southwest"  : __DIR__"northroad3",
	]));

	setup();
}

int valid_leave(object me,string dir)
{
	if( me->query("no_quest")
	 && ( dir == "south" || dir == "north")){
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}
