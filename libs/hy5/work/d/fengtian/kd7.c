// Room: /d/fengtian/kd7.c

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
  "west" : __DIR__"zhai1",
  "northwest" : __DIR__"kd8",
  "southeast" : __DIR__"kd6",
]));

	set("objects",([
"/clone/npc/man" : 1,
]));

	setup();
	replace_program(ROOM);
}
