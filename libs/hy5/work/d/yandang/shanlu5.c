// Room: /d/yandang/shanlu5.c

inherit ROOM;

void create()
{
	set("short", "果盒岩");
	set("long", @LONG
在凝碧潭畔,有一块巨石,形状扁圆平整,中间有一条环痕,形似果
盒.又象磨盘,俗称'卖磨岩'.清方尚惠诗云'果盒始混沌,风雷劈不开,
可知天地秘,任与世人猜.',岩上有亭(ting).
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("item_desc", ([ /* sizeof() == 1 */
  "ting" : "这是一座六角小石亭,名果盒亭,据说果盒岩中藏有一个秘密,你
隐隐觉得跟这个小亭有关.
",
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shanlu4",
  "northeast" : __DIR__"shanlu6",
  "westdown" : __DIR__"shanlu7",
]));
	setup();
	replace_program(ROOM);
}
