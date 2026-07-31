// Room: /d/japan/nanmen.c

inherit ROOM;

void create()
{
         set("short", "神户南门");
	set("long", @LONG
你面前的是一座城池,高大的城墙围起了极大的一片空间.几个穿着
甲盔的兵士在城门口站得跟木人似的,有几个穿了武士服装的人不时检查
行人的包裹.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jiedao",
  "south" : __DIR__"road1",
]));
         set("objects", ( [ /* sizeof() == 1 */
              __DIR__"npc/chengwei":3,
]));

	setup();
	replace_program(ROOM);
}
