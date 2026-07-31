// Room: /d/linzhi/lin41.c

inherit ROOM;

void create()
{
	set("short", "高原崖道");
	set("long", @LONG
这里是高原崖道，陡峭的崖壁侧立在你身边，仿佛随时都会
塌下来一般。你不由得加快了脚步。南面出现一片果林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin39",
  "south" : __DIR__"lin42",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
