// Room: /d/zuojiacun/haichan.c

inherit ROOM;

void create()
{
	set("short", "肉铺");
	set("long", @LONG
这是一家肉铺，虽然不大，却能买到多种新鲜的海产品，如
黄鱼、海参什么的。店里也买猪肉，不过价格稍贵了一些。店主
崔寡妇是个好人，自男人死了后，带着两个孩子十分不易。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu5",
]));
  	set("objects",([
	__DIR__"npc/butcher" : 1,
]));
	setup();
	replace_program(ROOM);
}
