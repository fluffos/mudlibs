// 山林
// edit: by zine Oct 19 2010

inherit __DIR__"shanlinconfig";

void create()
{
	set("short", "山林");
	set("long", @LONG
这里是一座毒虫出没的山林，千年的古树却是制作兵器的上佳材料。
LONG
	);
    set("normaldesc", @LONG
这里是一座毒虫出没的山林，千年的古树却是制作兵器的上佳材料。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"shanlin3",
        "east" : __DIR__"shanlin7",
        "west" : __DIR__"gu4",
		
    ]));
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

void init()
{
    add_action("do_west","zuan");
    add_action("do_look","look");
    ::init();
}

int valid_leave(object me,string dir)
{
    if (dir=="west")
    {
        return notify_fail("树林太茂密了，你虽然能看见西面的谷底深处，但只能钻过去(zuan)。\n");
    }
    return ::valid_leave(me,dir);
}

int do_west()
{
    object gu,me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        return notify_fail("你正忙着呢。\n");
    }
    me->add_busy(1);
    gu=load_object(__DIR__"gu4");
    message("vision", me->name()+"钻进密林，向"+gu->query("short")+"方向离开。\n",environment(me), ({me}) );
    tell_room(gu,me->name()+"从树林深处钻了过来。\n");
    me->move(gu);
    return 1;
}

int do_look(string arg)
{
	if(arg=="west")
	{
		tell_object(this_player(), "树林里雾气太大，西面依稀有路，你却看不清楚通向何处。\n");
		return 1;
	}
	return 0;
}