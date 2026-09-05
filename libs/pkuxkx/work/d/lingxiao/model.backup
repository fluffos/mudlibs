#include <room.h>
#include <ansi.h>

inherit ROOM;

string snow(object);

void create()
{
	set("short", HIW"凌霄样本"NOR);
	set("long", @LONG
这是房间描述的第一行，系统会自动在开头插入四个空格，最长32个汉字，
这是第二行，最长34个汉字。
|<---------------------- 34 个汉字或 68 个英文 --------------------->|
LONG);

	set("outdoors", "凌霄城");
//	set("no_fight", 1);
//	set("no_get_from", 1);
//	set("sleep_room", 1);
//	set("no_sleep_room", 1);
//	set("no_death", 1);
	set("valid_startroom", 1);

	set("item_desc", ([
//		"item": "item的描述\n",
		"snow": (: snow :),
	]));

	set("objects", ([
		__DIR__"npc/baiwj" : 1,
	]));


	set("exits", ([
		"south" : __DIR__"workspace",
	]));

	setup();

//	replace_program(ROOM);
}

string snow(object me)
{
	switch(random(3)) {
		case 0: return HIW"环顾四周，到处都是白皑皑的积雪。\n"NOR;
		case 1: return HIW"雪，雪，还是雪。\n"NOR;
		case 2: return HIW"洁白的雪地上零星的散落着几朵脚印。\n"NOR;
	}
}
