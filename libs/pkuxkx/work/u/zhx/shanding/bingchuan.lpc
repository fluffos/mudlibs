// File         : bingchuan.c
// Created By   : iszt@pkuxkx, 2007-03-01

inherit ROOM;

void create()
{
        set("short", "冰川");
        set("long", @LONG
雪山顶峰巍峨挺立，条条冰川如巨龙般蜿蜒盘旋下来，在南侧山脊上的松林
边形成勒巨大的冰舌。此处人迹罕至，周围一片静谧，从此向东往山下望，凌霄
城正处在两条深谷的环绕中，闪动着光芒。继续往北行去，就是雪山的顶峰了。
LONG);

        set("outdoors", "凌霄城");
        set("exits", ([
                "northup" : __DIR__"dingfeng",
                "southdown" : __DIR__"songlin",
        ]));

        setup();
}

void init()
{
        add_action("do_look", "look");
        add_action("do_go", "go");
        add_action("do_get", "get");
}

int do_look(string arg)
{
        if(arg != "southdown")
                return 0;
        write("那边是一片浓密的松林，什么也看不到。\n");
        return 1;
}

int do_go(string dir)
{
        object me = this_player();
        object* ob = deep_inventory(me);
        int i;

        if(dir != "southdown")
                return 0;
        if(!userp(me))
                return 1;
        for(i=sizeof(ob)-1; i>=0; i--)
                if(ob[i]->is_character())
                {
                        write("你带着"+ob[i]->name()+"，无法在雪地中行走。\n");
                        return 1;
                }

        message_vision("$N深一脚浅一脚的踏入了松林深处。\n", me);
        call_out("do_move", 1, me);
        me->start_busy(2);

        return 1;
}

int do_move(object me)
{
        object room;

        room = new(__DIR__"songlin");
        me->move(room);
        message_vision("$N方进入此地，惊觉自己已然陷身林海之中，找不到来时的路了！\n", me);

        return 1;
}

int do_get(string arg)
{
        write("你勉强弯下腰去，费了不少气力。\n");
        this_player()->receive_damage("qi", 100);
        return 0;
}
