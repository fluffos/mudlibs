// Room: /d/linzhi/lin31.c

inherit ROOM;

void create()
{
	set("short", "高原曲坡峰道");
	set("long", @LONG
这里是高原曲坡峰道，你来到这里，只见峰壁边一条小路曲
折伸延。你小心地绕过一座座峰壁，警惕地注意着可能发生的一
切。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin30",
  "west" : __DIR__"lin32",
  "southeast" : __DIR__"lin22",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
