// Room: /d/yanjing/intielao.c

inherit ROOM;

void create()
{
	set("short", "铁牢内");
	set("long", @LONG
屋子分成前后两部分,用一条条极粗铁条编成的栅栏隔开,就如监禁
猛兽的大铁笼一般.铁牢内靠栅栏的地方摆了张木桌,放了两个粗瓷水碗.
墙脚一堆干稻草,就是睡觉的地方.
LONG
	);
//	set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/clone/clothyoudeng.c" : 1,
//]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tianjing1",
]));

	setup();
	replace_program(ROOM);
}
