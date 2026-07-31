// /u/beyond/hz/zahuopu.c  杂货铺
 
inherit MISC_ROOM;
void create()
{
	set("short","杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。掌
柜懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵重
的东西。摊上立着一块招牌(zhaopai)。
    门前立了个牌子(sign)。
LONG
	);

	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"east" : __DIR__"qsddao5",
	]));
	set("objects", ([
		__DIR__"npc/zhlaoban": 1,
	]));

	set("coor/x",90);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}

