// by enter
// modified by wind
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "假日客店");
        set("long", 
"这里是一家老字号的客栈，崭新的桌椅排得整齐齐，隔着一\n"
"层屏风隐隐传来一阵阵锅铲的声音，大概是客栈的厨房，靠南边\n"
"的墙壁边上有一道通往二楼的楼梯，门口一个烫金的大牌匾上写\n"
"着四个大字“假日客栈”。"HIG"里面还有个后院，备有马车，可以直\n"
"接回扬州去。"NOR"墙上还有个牌子。(paizi)\n"
        );

        set("no_roar", 1);
        set("no_steal", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "假日客店，全国驰名，安全舒适，宾至如归。\n"
                          "想坐马车，价格面议，请与小二联系。\n",
        ]));

        set("objects", ([
                __DIR__"npc/qiuwa" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"dongjie1",
                "up" : __DIR__"kedian2",
        ]));

        setup();
//       "/clone/board/cdkd_b"->foo();
}
int valid_leave(object me, string dir)
{
        if (!userp(me))         return ::valid_leave(me, dir);
        if (present("qiu wa",environment(me))){
                if ( !me->query_temp("rent_paid") && dir == "up" )
                        return notify_fail("秋娃一下挡在楼梯前，白眼一翻：嘿嘿！你住得起吗？\n\n一晚要五两金子的耶！\n");
                if (!NATURE_D->outdoor_room()  && dir == "up" )
                        return notify_fail("秋娃一下挡在楼梯前，大白天的睡什么觉？客房在打扫呢！\n");
                if ( me->query_temp("rent_paid") && dir == "south" )
                        return notify_fail("秋娃跑到门边拦住：客官已经付了钱了，怎麽不住店就走了呢！\n旁人还以为小店伺候不周呢！\n");
        }
        return ::valid_leave(me, dir);
}

