// Room: /open/dt/zhubaodian.c

inherit ROOM;

void create()
{
	set("short", "珠宝店");
	set("long", @LONG
这是一家布置得富丽堂皇的珠宝店，柜台里各式各样的珍珠
宝石和屋顶上吊着的波斯琉璃灯交相辉映，使站在柜台边的一位
女郎浑身散发出一股神秘迷离的奇异光彩。看来这就是女人们为
什么爱珠宝胜过一切的原因了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tanhuanglu1",
]));

	setup();
	replace_program(ROOM);
}
