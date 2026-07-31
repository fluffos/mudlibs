// Room: /d/kunlun/zwf.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "坐忘峰");
	set("long", @LONG
这里面积不大，旁边有一小亭，里有些石椅石凳供人稍作休息。因为昆仑
山高路险，所以昆仑派便修了个小亭供人休息。
LONG
	);
	set("outdoors", "zwf");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"klt",
  "north" : __DIR__"wft",
]));

	setup();
	replace_program(ROOM);
}
