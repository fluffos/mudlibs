// Room: /d/linzhi/lin16.c

inherit ROOM;

void create()
{
	set("short", "察隅");
	set("long", @LONG
这里就是察隅了，地处西藏东南部，此处地差特别大，河谷
丘陵地带海拔只有1600米左右，而在梅里雪山附近地区，海拔平
均都在5000米以上，最高峰有6740米。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"lin17",
  "west" : __DIR__"lin21",
  "north" : __DIR__"lin15",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1600);
	setup();
	replace_program(ROOM);
}
