inherit ROOM;
void create()
{
    set("short", "虎跳峡");
    set("long", @LONG
这里是山谷的尽头，再往北已经没有路了，一条琮琮流淌的小河(river)横在
你面前，河的对岸有个黑乎乎的山洞(hole)，东南边有座亭子。
LONG
    );
        set("exits", ([
                "southdown" : __DIR__"caocong",
                "southeast" : __DIR__"guajianci",
        ]));
        set("objects", ([
                __DIR__"npc/yufu" : 1]));
        set("item_desc", ([
                "river" : "一条清清的小河。河水荡漾之间，竟似深不见底的样子。\n河中有几块礁石，都在水面以下，波浪起伏时，便若隐若现。\n",
                "hole" : "太远了，实在看不到什么东西，但是却给人一种感觉，让你觉得那里面一定有什么大秘密的。\n",
        ]));
    setup();
}
void init()
{
        add_action("do_swim", "swim");
}
int do_swim(string arg)
{
        object me;
        me = this_player();
     
                if( present("shui kao", me) )
                {
                     message_vision("$N取出水靠，披在身上，轻轻一纵，跳入河中。\n", me);
                        me->move("/d/quanzhou/hole");
      message("vision", "只听水面哗啦一声响，似乎有人也潜下水来。\n",
                                environment(me), ({me}) );
                }
                else
                {
   tell_object(me, "你一跳入河中，顿时呛了一口水，你急急忙忙地爬出了水中！\n");
                        message("vision", me->name() + "一跳入水中，立刻大叫一声「救命」，落汤鸡似地跳了出来！，\n",
                                environment(me), ({me}) );
                }
                return 1;
        
}
