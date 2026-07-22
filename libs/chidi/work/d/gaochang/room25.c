// Room: /u/mei/room25.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "高昌废墟");
	set("long", @LONG
陡然间眼前一片空旷，此时朝阳初升，只见景色奇丽，莫可名状。一座
白玉山峰参天而起，峰前一排排的都是房屋。千百所房屋断垣剩瓦，残破不
堪，已没一座完整，但建筑规模宏大，气象开朗，可见当年是一座十分繁荣
的城市。
LONG
	);
	set("no_new_clean_up", 0);
	set("outdoors", "room25");
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room24",
  "west" : __DIR__"room26",
]));

	setup();
	replace_program(ROOM);
}
