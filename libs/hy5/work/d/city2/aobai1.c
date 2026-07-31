// Room: /city2/aobai1.c


inherit ROOM;

void create()
{
	set("short","街道");
	set("long", @LONG
再往西就是鳌拜府了，谁也不敢往那儿去。东面是王府井大街。
路边有个狗洞(dong)，几只懒狗正在那里探头。
LONG );
	set("exits", ([
		"west" : __DIR__"aobai2",
		"east" : __DIR__"wangfu1",
	]));
	set("item_desc", ([
            "dong" : "黑呼呼的狗洞，不知道有多深。\n",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
           if( (fam = me->query("family")) && fam["family_name"] == "丐帮")
           {
               message("vision",
                        me->name() + "运起丐帮缩骨功，一弯腰往狗洞里钻了进去。",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underbj");
               message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                        return 1;
           }
           else  return notify_fail("这么小的洞，你钻得进去吗？\n");
       }
}
