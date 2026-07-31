// hanshuitan.c 寒水潭
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_qian(string arg);

void create()
{
        set("short", "寒水潭");
        set("long", @LONG
这里是草地的边缘，青草已经很稀疏了，仍然有一二玉蜂来回地
飞过寻觅食物。你的面前是一个清波荡漾的大水潭 (tan)，水很清，
隐约可以见过水底的怪石嶙峋，一二游鱼倏地从水底游过，又不知道
躲到哪块石头后面藏身去了。阳光映照下，水面泛起了一道七色彩虹，
望着这般美景，你俗念尽消。
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "northwest" : __DIR__"caodi2",
        ]));

        set("objects", ([
                __DIR__"npc/yufeng" : random(3),
        ]));

        set("item_desc", ([
        "tan": "一口很深的水摊，不知道可不可以潜(qian)下到这水底世界去？\n"
        ]) );

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_qian", "qian");
}


int do_qian(string arg)
{
        object me=this_player();

        if( !arg || arg != "tan" ) {
                return notify_fail("你要往哪里潜水？\n");
        }

        message_vision(HIG"$N纵身一跃，跳入水摊之中，许多游鱼从你身边游过，
你伸手一捞，\n"NOR,this_player());
        message_vision(HIG"却抓了空。突然$N眼前一亮，一股暗流扑面而来，将$N
冲入一个所在。\n"NOR, this_player());

        me->move(__DIR__"mishi1");

        return 1;
}

