// Room: /d/yanjing/liangziweng.c

inherit ROOM;

void create()
{
	set("short", "梁子翁居处");
	set("long", @LONG
你一踏进房,便觉药气冲鼻,又见桌上、榻上、地下,到处放满了诸般
药材,以及大大小小的瓶儿、罐儿、缸儿、钵儿,瓶罐上面画的都是些弯弯
曲曲的符号,竟无一个文字.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/liangziweng.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lack",
]));

	setup();
	replace_program(ROOM);
}
