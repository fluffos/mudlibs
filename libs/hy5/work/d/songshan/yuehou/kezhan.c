// Room: /d/yuehou/kezhan.c

inherit ROOM;

void create()
{
        set("short", "岳王客栈");
        set("long", @LONG
这里是岳候镇的一家客栈，生意还算兴隆。在这里有南来北
往的人在这里打尖住店，其中做生意的商贾，以及慕名而来的进
香客。一进门，你就看到小二不停的忙碌着招呼着客人，正面一
个高大的柜台。柜台后是成坛成坛的洒缸，门前挂着两个大灯笼。
正中摆放着一些桌椅。墙上挂着一个牌子(paizi)。
LONG
        );

        
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上客房，每晚二两白银。\n",
        ]));

        set("objects", ([
                __DIR__"npc/waiter_1" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"center_e",
                "up" : __DIR__"kezhan2",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎么着，想白住啊！\n");
        if( me->query_temp("on_rided") && dir == "up")  // 判断是否骑着坐骑
                return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

        if ( me->query_temp("rent_paid") && dir == "north" )
                me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}


