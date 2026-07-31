// xiaolu.c

inherit ROOM;

void create()
{
  set ("short", "小路");
  set ("long", @LONG

高家后墙外的一条小路，看样子极少有人来．到处是半人多高的杂
草，每走一步都会惊起许多小虫子，有些小蚂蚱还蹦到你的身上．．．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"xiaolin",
]));

        set("outdoors", "xy5");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{       object me;
        me=this_player();

        if ( !arg || ((arg != "wall") ))
                return notify_fail("你要爬什么？\n");
if (me->query_temp("ridee"))
return notify_fail("你的坐骑可没你这么好的本事！\n");
                message_vision("$N一扒墙头，翻了过去。\n", me);
                me->move("/d/qujing/gao/huayuan");
/*
                me->set_temp("apply/dodge",0);
                me->set_temp("ride/dodge",0);
*/
// mudring Jan/03/2002
me->delete_temp("ridee");
me->set_temp("ride/dodge",0);
me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
                tell_room( environment(me), "「咕咚」一声，" + me->name() + "从墙头上跳了下来！\n",
({me}) );
                return 1;
}

