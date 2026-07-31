// Room: /d/yanjing/hubian.c

inherit ROOM;

void create()
{
	set("short", "小湖边");
	set("long", @LONG
前面水光闪动,正是一个小小湖泊.此时天气倒不甚寒,湖中并未结冰
雪花落在湖面,都融在水里,湖边一排排都是梅树,梅花再加上冰花雪蕊，
更显皎洁。只听忽喇喇一声响，湖边飞起两只水鸟。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"to_yj1",
]));
	set("objects",([
		__DIR__"npc/man6":1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
