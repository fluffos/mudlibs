// Room: /chengdu/ruin2.c
// oooc: 1998/06/26

inherit ROOM;

void create()
{
        set("short", "玄天秘道");
        set("long", @LONG
玄天派的秘密通道，无名老人所造。
LONG
        );



        setup();
}
void init()
{
        add_action("do_enter", "enter");
        add_action("do_climb", "climb");
}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="地下" )
        {
                message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );
                me->move("d/xuantian/chi");
                message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }
}     
int do_climb(string arg)
{
       
        object me=this_player();
        object ob; 
        if( (!arg) ||!((arg == "tree") || (arg == "wall")))
                return 0;
                message_vision("$P施展开壁虎游墙的上乘轻功，快速向上游去。\n\n",me);
        ob = load_object("d/xuantian/wall");
        ob = find_object("d/xuantian/wall");
        message("vision", me->query("name")+"从下面爬了上来。\n", ob);
        me->move("d/xuantian/wall");
        return 1;
}

