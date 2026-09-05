// Room: /d/shaolin/bagua.c
// Date: YZC 96/01/19
// Date: CLEANSWORD 96/05/19

inherit ROOM;

void create()
{
        set("short", "洪荒古阵");
        set("long", @LONG
这里就是古阵的中心。站在这里，才能看清楚四周
的情形，只见周围暮蔼沉沉，云气弥漫，不见边际、
诡异可惧。此阵的中心，便有一个洞(dong,hole)。
LONG
        );
        set("no_clean_up", 0);
        set("no_task", 1);
        set("exits", ([ /* sizeof() == 1 */
                  "up" : __DIR__"andao3",
                ]));
        set("item_desc", ([ /* sizeof() == 1 */
                  "dong" : "洞边的树着一块岩石，刻着四个巨大的古篆：“洪荒古洞”，
                再有五个小字：“苍松子谨书”。
                ",
                ]));
        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong"|| arg=="hole") 
        {
			if (me->is_busy())
			{
				write("你正忙着呢！\n");
				return 1;
			}
                if( present("fire", me)) 
                {
                        message_vision("$N取出火折，轻轻一纵，跃入古洞之中。\n", me);
                        me->move(__DIR__"hantan1");
                        message("vision", "只听哗啦一声响，似乎跃入古洞中来。\n",
                                environment(me), ({me}) );
                }
                else
                {
                        tell_object(me, "你一进入古洞中，只觉蚀骨寒气从全身无数个毛孔侵入，四肢几乎完全麻木，\n"
                                        "你拚着丹田中残余的一股内力，攀住洞壁的岩石，急急忙忙地爬了出来！\n");
                           me->set("eff_qi",10);
                           me->set("qi",10);
                           message("vision", me->name() + "下半身一浸入水中，立刻大叫一声，哆哆嗦嗦似地跳了出来！，\n",
                                environment(me), ({me}) );
                }

                return 1;
        }
}       
