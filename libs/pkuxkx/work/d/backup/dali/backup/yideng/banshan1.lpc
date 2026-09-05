//半山1
//by icer
inherit ROOM;
void create()
{
        set("short", "半山");        set("long", @LONG
这里是半山腰。眼前是一个极大的喷泉，奔雪溅玉。那溪水到此而止，
这喷泉显然是下面溪水与瀑布的源头了。山边一条手臂粗细的长藤，延峰而
上。这山峰的上半截隐入云中，不知峰顶到底有多高。
LONG
);
set("exits", ([
                "down" :__DIR__"pubu",
]));
set("objects",([

      __DIR__"npc/qiao" : 1,
     ]));
setup();
}

void init()
{
	add_action("do_climb","climb");
}
int do_climb()
{
        if ( this_player()->query_encumbrance() * 100 / this_player()->query_max_encumbrance() > 30)
		return notify_fail("你身上背的东西太多，怎么爬也爬不上去。\n");

        if (((int)this_player()->query_skill("dodge")>150) && (this_player()->query_temp("marks/樵1")))
	{
		write("你双手握着长藤，提气而上，爬得甚是迅捷。片刻之间，离地已十余丈。\n
突见那长藤向前神，原来已经到了峰顶。\n");
		this_player()->move(__DIR__"banshan2");
		return 1;
	}
	else
	{
		return notify_fail("你费了好大劲，怎么也爬不上山壁。\n");
	}
}
