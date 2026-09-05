inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
	这是扬州药铺的分店,战乱时期,伤者剧增,这里可发了大财,价钱也比内地高得多.
掌柜的坐在茶几旁,一名小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)。
LONG
	);
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t八十两白银
大力丸: \t一两黄金
其他神药与老板面议。\n",
	]));


	set("objects", ([
//
		__DIR__"npc/huoji" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"xyeast1",
	]));

	setup();
	replace_program(ROOM);
}

