// Room: /d/fengtian/kd9.c

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

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fangjia",
  "southeast" : __DIR__"kd8",
]));

	set("objects",([
"/clone/npc/man" : 1,
]));

	setup();
	replace_program(ROOM);
}
