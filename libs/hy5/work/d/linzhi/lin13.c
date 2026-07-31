// Room: /d/linzhi/lin13.c

inherit ROOM;

void create()
{
	set("short", "高原坡路");
	set("long", @LONG
这是一条高原坡路，路面随山势凹凸，时有山风吹过，荡起
阵阵尘土，你觉得有些凉意。你在坡道上时上时下，走了不一会
儿，就感到有些累了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"lin12",
  "south" : __DIR__"lin14",
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
