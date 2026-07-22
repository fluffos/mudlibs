// Room: /city/zahuopu.c

inherit MISC_ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG                                 
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。掌柜
懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵重的东
西。摊上立着一块招牌(zhaopai)。
    门前立了个牌子(sign)。
LONG
	);

	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
                __DIR__"npc/girl": 1,
	]));

	set("coor/x",110);
  set("coor/y",-20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

