// Room: /u/bibi/testroom.c

inherit ROOM;

void create()
{
	set("short", "[31m七星回廊[2;37;0m");
	set("long", @LONG
这里是[31m七星宫[2;37;0m的后院，[31m七星回廊[2;37;0m恰似一道北斗七星，又如一条弯弯曲曲的折尺，
将七座风格迥异的园中小亭连在一起。而回廊的北侧，正是[31m七星宫[2;37;0m最美丽的[34m七星湖[2;37;0m。
这就是连接[1;36m开阳亭[2;37;0m与[33m瑶光亭[2;37;0m的一段回廊，回廊整体上都由一种特别珍贵的[34m香木[2;37;0m制成，
淡淡的幽香惹人遐想。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kaiyang",
  "west" : __DIR__"yaoguang",
]));

	setup();
	replace_program(ROOM);
}
