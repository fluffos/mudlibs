// Room: /d/mingjiao/fandian.c

inherit ROOM;

void create()
{
	set("short", "草棚");
	set("long", @LONG
这是一间小草棚，这儿有个小贩，你可以向他买东西。旁边似乎有个小洞(dong)。
LONG
	);
        set("item_desc",([ "dong" : 
                "你真够无聊的，一个黑呼呼的洞有什么好看的！\n"
        ]));

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hutong",
]));
	set("no_clean_up", 0);
   set("objects",([
    __DIR__"npc/seller" :1,
]));

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
                if( 1==1 ) 
                {
                        message("vision",
                                me->name() + "运起丐帮缩骨功，一弯腰往香案下的洞里钻了进去。\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/undermj");
                        message("vision",
                                me->name() + "从洞里走了进来。\n",
                                environment(me), ({me}) );
                        return 1;
                }
                else 
                        return notify_fail("这么小的洞，你钻得进去吗？\n");
        }
}       

