// Room: /d/xiangyang/juyiwupin.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "物品房");
	set("long", @LONG
這是聚義館的堆放各種各樣物品的房間。郭靖的二弟子武
修文正在這兒負責向有任務的新手分發各種物品。
LONG );
	set("exits", ([
		"northwest" : __DIR__"juyihuayuan",
	]));
	set("objects", ([
		__DIR__"npc/wuxiuwen" : 1,
	]));
	set("coor/x", -525);
	set("coor/y", -504);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}