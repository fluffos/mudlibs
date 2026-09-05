// Room: /city/beidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。南边
显得很繁忙。东边是一座两层的楼阁，挂着「太白遗风」的招帘，门额上悬挂一
方横匾，「醉仙楼」三字擦得闪闪发亮，乃是苏学士的手笔。阵阵酒肉香酒香让
你垂涎欲滴。西边是一座古朴的庙宇，香火缭绕，那就是天下学武之人所共同敬
仰的武庙了。
LONG);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"zuixianlou",
		"south" : __DIR__"beidajie1",
		"west" : __DIR__"wumiao",
		"north" : __DIR__"beimen",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if( (me->query_encumbrance() * 100 / me->query_max_encumbrance() > 40) && (dir == "west") )
                return notify_fail("你背了这么多杂七杂八的东西，进武庙未免太不恭敬了吧？\n");
        return ::valid_leave(me, dir);
}