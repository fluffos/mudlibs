// Room: /u/mei/room56.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "昆仑山");
	set("long", @LONG
这里往西，地势略略向上倾斜。路两旁的灌木渐渐换成乔木，越走地
势越开阔。云，翻腾在脚下，象海浪，又象流水。你就象乘在一条孤舟之
中在云海中漂荡，分不清是水在流还是船在走。
LONG );
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"room57",
  "eastdown" : __DIR__"room55",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room56");

	setup();
	replace_program(ROOM);
}
