// Write By Yanyang@SJ 2001.9.27
// Room: /d/changan/kezhan.c

inherit ROOM;

void create()
{
        set("short", "聚豪客栈");
        set("long", @LONG       
这是长安城里的聚豪客栈，老板是城中的首富李员外，街对面的酒楼也是
他开的。外地游客大多选择这里落脚，江湖人物更是把这里当成聚会碰头的场
所，不时有江湖豪客进进出出。店小二里里外外忙得团团转，接待着南腔北调
的客人。客栈正面的墙上挂着一块醒目的牌子(paizi)。
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("no_fight",1);
        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));

        set("objects", ([
             __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
            "east" : __DIR__"northjie1",
              "up" : __DIR__"kezhan2",
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("怎么着，想白住啊！\n");

        if ( me->query_temp("rent_paid") && dir == "east" )
                return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

        return ::valid_leave(me, dir);
}
