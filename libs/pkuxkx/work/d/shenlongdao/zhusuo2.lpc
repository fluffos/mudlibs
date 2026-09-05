// Room: /shenlongjiao/zhusuo2.c
// kiden 06/08/26
#include <ansi.h>;
#include <room.h>;

inherit ROOM;

void create()
{
        set("short", MAG"女弟子住所"NOR);
        set("long", @LONG
这里是女弟子的住所。这些弟子很多都是新加入神龙岛的，由洪岛主和教主夫人亲自调教功夫。
他们年纪虽轻，你可不要小瞧了他们哦！
LONG );
//        set("outdoors", "shenlongdao");

        set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"pingtai",                
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}
