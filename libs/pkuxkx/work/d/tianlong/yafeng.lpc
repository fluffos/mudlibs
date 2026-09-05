// by paladin

inherit ROOM;
void create()
{
        set("short", "崖间古松");
        set("long", @LONG
你惊魂略定, 慢慢的移身崖壁, 细看山崖中裂开了一条大缝(yafeng)，
勉强可攀援而下.
LONG
        );

        set("item_desc", ([
                "yafeng" : "悬崖非常陡峭，最好不要爬。\n",
              ]));
        set("no_tianlong",1);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me;
        mapping fam;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="yafeng" )
        {
                        message_vision("$N小心翼翼沿着崖缝向下爬去。
山崖似乎无穷无尽，爬到后来，衣衫早给荆刺扯得东破一块，西烂一条，
手脚上更是到处破损, 但耳中轰隆轰隆的声音越来越响, 只见左边山崖上
一条大瀑布如玉龙悬空，滚滚而下，倾入一座清澈异常的大湖之中.\n", me);
                        message("vision",
                                me->name() + "小心翼翼的向下爬去。\n",
                                environment(me), ({me}) );
                        me->move("/d/wuliang/lake");
                        message("vision",
                                me->name() + "从上面爬了过来。\n",
                                environment(me), ({me}) );
                        return 1;
        }
}
