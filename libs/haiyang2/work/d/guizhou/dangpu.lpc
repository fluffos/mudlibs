inherit ROOM;

void create()
{
	set("short", "甲秀楼");
	set("long", @LONG
这是家远近闻名的当铺，三开间的门面，一块写着『贵阳当铺』四
个金字的黑匾，足足七尺高的紫檀木的柜台被磨得光可照人，你一进去
就有一种压抑和悲怅的感觉，柜台后的老板邱航头也不抬的只顾拨拉着
算盘，柜台上方挂着一块花木牌子(paizi) 。据街坊们说铁面当铺给的
价还不算最坏，并且从不问货的来处，除了活人什么都收，所以生意很
不错。
LONG );
	set("item_desc", ([
		"paizi" : "
你情我愿，概不赊欠。\n",
	]));
	set("no_fight", 1);
	set("no_beg", 1);
	set("exits", ([
		"southwest" : __DIR__"beishi",
	]));
	set("objects", ([
		__DIR__"npc/qiu" : 1,
	]));
	setup();
	replace_program(ROOM);
}

