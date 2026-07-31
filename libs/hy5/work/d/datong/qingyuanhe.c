// Room: /open/dt/qingyuanhe.c

inherit ROOM;

void create()
{
	set("short", "清元和");
	set("long", @LONG
这家酒楼在大同可是首屈一指的，不光楼内装璜摆设得富丽
堂皇，这里的红烧甲鱼味道之鲜美在方圆百里内再也找不出第二
家可与之比美的了，但这还不是这里的招牌菜。这里的招牌菜名
叫“头脑”，相传是医仙傅山所创，其不光口味绝佳而且滋阴补
阳、益气健脾，是一种少有的滋补食品。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youfujie1",
]));

	setup();
	replace_program(ROOM);
}
