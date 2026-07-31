// Room: /d/hainan/cave.c

inherit ROOM;

void create()
{
	set("short", "小山洞");
	set("long", @LONG
这是一个小小的山洞,四壁的岩石因为海风的吹袭,变得十分光滑.
靠里面的内壁上有一个更小的洞口,里面显得很黑暗.从此向外看,风景
十分美丽.偶尔有巨大的鲸鱼喷出高达几十丈高的水柱.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "洞口" : "这个洞口明显比你刚进来的那个要小得多,如果你不把身上的衣物
都脱下的化,很可能进不去.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"ontree",
  "northdown" : __DIR__"cave1",
]));

	setup();
	replace_program(ROOM);
}
