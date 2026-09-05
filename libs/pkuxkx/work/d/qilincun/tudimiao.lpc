// Created by iszt@pkuxkx, 2007-02-11

inherit ROOM;

void create()
{
        set("short", "土地庙");
        set("long", @LONG
这里是一个破败不堪的土地庙，庙中供着两尊不知是什么的神像，供品却付
阙如。庙的一角堆着一团干草，似乎掩盖着一个洞(dong)。你仔细一看，旁边还
歪歪扭扭的树了一块小牌子，看来是江湖传言中丐帮遍及各地的暗道罢。
LONG);
        set("objects", ([
                __DIR__"obj/box" : 1,
                __DIR__"npc/cunzhang" : 1,
        ]));
        set("exits", ([
                "east" : __DIR__"guangchang",
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
        me = this_player();

        if( !arg || arg=="" ) return notify_fail("你要钻什么？\n");

        if(me->is_busy() || me->is_fighting())
                return notify_fail("你先忙完了再钻洞吧。");

        if( arg=="dong" )
        {
                message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );
                me->move("/d/gaibang/underly");
                message("vision",
                        me->name() + "从洞外走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }
}
