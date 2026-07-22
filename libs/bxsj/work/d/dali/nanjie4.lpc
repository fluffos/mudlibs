// Room:  /dali/nanjie4.c
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这是繁华的大理南大街，街上人来人往，大理百姓走到这里，无不放慢了
脚步，以敬仰的目光向西看去，西边过去就是大理皇宫了。南面住着一家大富
人家，门口站着几个家人，西边就是太和南街了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"nanjie3",
		"east" : __DIR__"nanjie5",
		"south" : __DIR__"dafujia",
	]));
	set("outdoors", "大理");
	setup();
}
