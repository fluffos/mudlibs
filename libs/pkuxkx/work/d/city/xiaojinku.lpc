// xiaojinku.c
// Created by iszt@pkuxkx, 2007-02-25

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "销金窟");
        set("long", @LONG
这里是一个富家子弟，有钱书生，附庸风雅的商家大沽之辈常常光顾的所在。
达官贵人、富绅巨贾们都喜欢聚集于此，征歌逐色，诗酒风流。如果你可以一掷
千金(xiaojin)，众人必定会对你另眼相待。
LONG);
        set("indoors", "city");

        set("exits", ([
                "out" : __DIR__"idleroom",
                "up" : __DIR__"guangchang",
        ]));

		set("no_sick_spread",1);
        set("least_msg",1);
        setup();
}

void init()
{
        add_action("do_xiaojin", "xiaojin");
}

int do_xiaojin(string arg)
{
        object me = this_player();
        object ob = present("gold", me);

        if(!ob)
                return notify_fail("你身上没有金子，如何销金？\n");
        if(ob->query_amount() < 1000)
                return notify_fail("你身上没有千金，你想一掷千金也不行啊。\n");

        message_vision(CYN"老板接过$N递来的金子，点头哈腰的道："
                        "「多谢多谢，小的知道您金子多，这就替您把金子销毁掉。」\n"NOR, me);
        CHANNEL_D->do_channel(this_object(), "jh", "销金窟老板(Lao ban)："+me->name()+"在销金窟一掷千金，气魄大矣！", -1);

        me->add("xiaojin", ob->query_amount());
        destruct(ob);

        return 1;
}
