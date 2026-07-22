// Room: /chengdu/cdjiulou2.c
// oooc: 1998/06/25 

inherit ROOM;
inherit F_DEALER;

void create()
{
        set("name", "迎仙酒楼");
        set("short", "迎仙酒楼二楼");
	set("long", @LONG
这座楼阁不知是什么时候建的，但是似乎已经很长时间以来都
是个热闹所在。这里到是个看成都城的好地方，你找个邻窗的位子
坐下，歇一会儿，静静的看看平静的百花潭，或是另一边的街道，
让你感到很和谐。两边的粉墙(wall)上有不少文人墨客提的诗词。
墙上挂着价格牌子(paizi)。
LONG
	);

	set("item_desc", ([
		"paizi" : "本店出售烤鸭及上等花雕酒。\n",
	]));

	set("exits", ([
                "down" : __DIR__"cdjiulou",
	]));

	setup();
	replace_program(ROOM);
}
