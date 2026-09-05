// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "入幽口");
        set("long", @LONG
此处已在群山环绕之中，山路去处就是巍峨的大雪山，抬头了望，峰顶云雾
缭绕，宛如仙境。
真是：
    天山相连苍茫外，碧云去尽山无数。
    云山万重，寸心千里。
    望极天涯不见家。 

LONG 
        );

        set("exits", ([

                "eastup" : __DIR__"qianbuling2",
                "westup" : __DIR__"fengjiantai",


        ]));
        set("objects", ([CLASS_D("dalunsi") + "/baoxiang" : 1,]));

        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

