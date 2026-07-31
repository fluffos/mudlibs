//Room: /d/city/shuyuan2.c

#define STORY_TOC "/doc/legend/toc"
inherit ROOM;

void create()
{
	set("short", "书院书库");
	set("long", @LONG
这里是书院的图书馆，窗明几净，一尘不染。壁上的书架堆满先贤们的文选，有一个书童正在这里打理。
LONG);

	set("item_desc", ([ /* sizeof() == 1 */
		"【书架】" : "上面一尘不染，全是诸子百家的书。\n"
	]));

	set("exits", ([
	    "down" : __DIR__"shuyuan",
	]));

	set("no_fight", 1);
	set("no_sleep_room", 1);

	set("objects", ([
		__DIR__"npc/shutong" : 1,
	]));

	setup();
}

