// Room: /d/jindezheng/china-shop.c

inherit ROOM;

void create()
{
	set("short", "温记老店");
	set("long", @LONG
温记老店也许是景德镇最老也是最大的一家陶瓷店了,从开创至今, 
据说有几百年了,它的分店遍及全国,但是店堂中除了几个伺候的伙计之 
外,只摆了一长溜的红木椅子,看不到一点陶瓷器的影子. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"yuanzi",
  "north" : __DIR__"jindezhen",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huoji.c" : 1,
  __DIR__"npc/wenfang.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
