// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "猴子洞");
        set("long", @LONG
这里传说是观世音菩萨点化的猕猴和岩洞女妖结合、繁衍后代的地方。岩洞
深处的壁上雕有猴子像，形态活泼，亲切可爱。洞外到处都是光秃秃的岩石，石
缝中挤出的几颗杂草在寒风中瑟瑟发抖。
LONG 
        );

        set("exits", ([

                "westup" : __DIR__"xuejigudao3",
                "southeast" : __DIR__"jiaopan",
                "northeast" : __DIR__"xuepo",
        ]));
        set("objects", ([
//                __DIR__"npc/baoxiang" : 1,

        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

