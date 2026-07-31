 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "小院");
        set("long", @LONG
走进这扇门，便是翠浓的香闺。小院子里疏落落的种着几十竿翠竹，衬着角落
里的天竺葵，和一丛淡淡的小黄花，显得清雅而有余韵。这儿是这样地幽静。地上
铺满了绿草、落下来的榆钱和风吹来的柳絮。
LONG
        );
        set("exits", ([ 
        "north": __DIR__"xiaojinku",
        "enter": __DIR__"xiaojinku3",
        ]));
        set("objects", ([
                __DIR__"npc/girl":      1,
        ]) );
        set("coor/x",-1140);
        set("coor/y",160);
        set("coor/z",0);
        setup();
}    
