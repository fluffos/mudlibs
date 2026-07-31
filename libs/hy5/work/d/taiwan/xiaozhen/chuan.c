// Room: /d/taiwan/chuan.c

inherit ROOM;

void create()
{
	set("short", "小货船");
	set("long", @LONG
一艘装慢了货物的三桅小船,看来并不能经受海上的大风浪.有个
小小的船舱勉强能容人休息.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liusan.c" : 1,
]));
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"matou",
]));
          set("no_fight", 0);

	setup();
	replace_program(ROOM);
}
