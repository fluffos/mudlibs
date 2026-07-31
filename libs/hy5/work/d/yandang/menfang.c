// Room: /d/yandang/menfang.c

inherit ROOM;

void create()
{
	set("short", "门房");
	set("long", @LONG
这里是落雁山庄的门房,房中的摆设比较简单,仅几张桌椅之类,桌
上摆着几个茶杯,确是景德镇官窖的精品,空气中飘落着茶叶的清香,
如果你是行家的话,可以辨出这是正宗的雁茗.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/laowang.c" : 1,
  "/clone/money/silver.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"luoyan3",
]));

	setup();
	replace_program(ROOM);
}
