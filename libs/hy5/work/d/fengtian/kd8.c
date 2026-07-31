// Room: /d/fengtian/kd8.c

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
康定路的尽头的小巷是个居民区，这条斜斜的小巷很窄，不
少行人；来来往往住，还有不少孩子们在路边玩耍，傍晚时分小
巷深处的民宅烟筒都飘起了炊烟。
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"zhai2",
  "northwest" : __DIR__"kd9",
  "southeast" : __DIR__"kd7",
]));

	setup();
	replace_program(ROOM);
}
