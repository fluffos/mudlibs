// Room: /d/linzhi/lin44.c

inherit ROOM;

void create()
{
	set("short", "高原山脊路");
	set("long", @LONG
这是一条高原山脊路，路陡而坡斜。你小心的走在上面，时
时注意着方向。不远处一群野羊正在山道间驰骋，好像没有注意
到你在存在。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"lin43",
  "northwest" : __DIR__"lin47",
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
