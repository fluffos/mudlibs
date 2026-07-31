// Room: /d/yandang/luoyan20.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
客房是落雁山庄招待客人的地方,由于来往的人多,自己随身的物品
一定要保管好.旁边有小厮伺候,所以到了这,你会感觉跟到了家没什么两
样,还是好好睡一觉吧!
LONG
	);
	set("sleep_room", "1");
	set("no_magic", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"luoyan36",
]));
	set("no_fight", "1");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
