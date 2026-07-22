// ROOM : /u/numa/thd/zhulin1.c
// Created by Numa 19990828

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "绿竹林");
        set("long", @LONG
这里是一片郁郁葱葱的绿竹林，你似乎迷失了方向，象没头苍蝇般到处乱闯。
LONG
        );
        set("exits", ([
                "south" :  __DIR__"zhulin"+(random(10)+1),
                "north" : __DIR__"zhulin7",
                "west" :  __DIR__"zhulin"+(random(10)+1),
                "east" : __DIR__"zhulin"+(random(10)+1),
        ]));

        set("outdoors", "桃花岛");

        setup();
}

void init()
{
        object ob=this_player();

        if (ob->query_skill("qimen-bagua", 1) > 80)
        {
                write("由于你平时看惯了这些简易的阵法，所以不用细想，信步就走出了竹林！\n");
                ob->move(__DIR__"jicui", 1);
                tell_room(environment(ob), "竹林突然一阵闪动，" + ob->name() + "从中走了出来。\n", ({ob}));
                return;
        }
        if (ob->query_temp("step_count") > 99) {
                ob->delete_temp("step_count");
                write("你在竹林中累得精疲力尽，终因体力不支而昏了过去！\n");
                write("迷迷胡胡中似乎有人把你抬出了竹林，仿佛有个威严的声音喝道：“扔到海里去”。\n");
                ob->unconcious();
                ob->move(__DIR__"haibin", 1);
                message("vision", "忽然一个大潮涌了过来，将一个被水泡得半死的家伙冲到了岸边。\n", environment(ob), ob);
                return;
        }
        ob->add_temp("step_count", 1);
}

