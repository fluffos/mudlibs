// Room: /city/chaguan.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "八仙茶楼");
        set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排
开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，这里
是个好所在。桌上放着几个粗茶碗，是不要钱的茶水，渴了可以随便喝(drink)。
LONG);
        set("resource/water", 1);

        set("exits", ([
                "east" : __DIR__"northstreet1",
                "south" : __DIR__"weststreet2",
        ]));

        set("objects", ([
              __DIR__"npcs/waiter" : 1,
                
        ]));

        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 450);
                message("vision", me->name()+"急冲冲的跑了过来，拿起茶碗一阵豪饮。\n",
                        environment(me), ({me}) );
                write("你端起桌上的粗茶碗，咕噜咕噜饮喝了几大口茶。\n");
        }
        else write("你已经不渴了，还是别喝了。\n");

        return 1;
}
