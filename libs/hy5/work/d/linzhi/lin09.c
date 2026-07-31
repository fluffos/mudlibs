// Room: /d/linzhi/lin09.c

inherit ROOM;

void create()
{
	set("short", "高原宽道");
	set("long", @LONG
你走到这里，只见远处山峰起伏，白云缭绕。一只秃鹫在你
的头项盘旋，你不禁觉得有些紧张。放眼望去，这里空旷无野，
你不由得加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin08",
  "southwest" : __DIR__"lin10",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
