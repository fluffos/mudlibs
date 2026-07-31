// Room: /d/tianshui/nroad1.c

inherit ROOM;

void create()
{
	set("short", "小镇北街");
	set("long", @LONG
北街是镇子里的繁华地段，一到晚上一派灯红酒绿，笑声、
歌声、琴声汇成一片，尤为热闹。西面一幢房子门口挂着大红灯
笼，几位姑娘站在那里不时地向行人挥手打招呼。东面是小镇的
酒楼，门楣上挂着一块黑漆匾，上书“醉仙阁”三个镏金大字。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad2",
  "west" : __DIR__"jiyuan",
  "south" : __DIR__"cross",
  "east" : __DIR__"jiulou",
]));
	set("objects",([
	__DIR__"npc/drunk" : 1,
	__DIR__"npc/cleaner" : 1,
]));

	set("outdoors","tianshui");
	setup();
}