// File         : dingfeng.c
// Created By   : iszt@pkuxkx, 2006-03-02
// 部分文字节选自北大山鹰社之巅峰时刻，有改动

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "顶峰");
        set("long", @LONG
壮哉，伟哉！雪山之巅，平坦宽阔，煦暖的阳光径直照下来，数座雪峰环绕
主峰，亭亭而立，雪粒闪闪发光。放眼望去，青灰色的一片屋顶夹在两条深谷中，
带着些许陌生感。四周生长着一些珍奇的高山植物，从东侧冰壁向下不远就是凌
霄城。
LONG);

        set("outdoors", "凌霄城");

        set("item_desc", ([
                "east": "从东侧冰壁向下不远就是凌霄城。\n",
        ]));
        set("objects", ([
                __DIR__"obj/xuelian" : 1,
                __DIR__"obj/xuemei" : 1,
        ]));
        set("exits", ([
                "southdown" : __DIR__"bingchuan",
                "north" : __DIR__"xiaomen",
                "down" : __DIR__"xuepo6",
        ]));

        setup();
}

void init()
{
        add_action("do_get", "get");
        add_action("do_eat", "eat");
}

int do_get(string arg)
{
        object ob;
        if(arg == "all")
        {
                write("在这里你无法一次捡起所有物品。\n");
                return 1;
        }
        if(!arg || !ob = present(arg, this_object()))
                return 0;
        write("你慢慢走进"+ob->name()+"，勉强弯下腰去，费了不少气力。\n");
        this_player()->receive_damage("qi", 100);
        return 0;
}

int do_eat(string arg)
{
        write("这里冰天雪地的，还是下山再吃东西罢。\n");
        return 1;
}

int valid_leave(object me, string dir)
{
        object* ob = deep_inventory(me);
        int i;

        if(!::valid_leave(me, dir))
                return 0;
        if(dir != "down")
                return 1;
        if(me->query_skill("dodge") < 200)
                return notify_fail("你的轻功不足，这样直接下去会摔死的。\n");
        for(i=sizeof(ob)-1; i>=0; i--)
                if(ob[i]->is_character())
                        return notify_fail("你还带着"+ob[i]->name()+"，无法这样下冰壁。\n");
        return 1;
}
