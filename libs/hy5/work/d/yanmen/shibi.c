// Create by lonely@NT
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石壁"NOR);
        set("long",
"这里快到「大宋」军营驻扎地了，远远地可以看见大营内飞扬的尘土\n"
"，不时有几匹快马飞奔进出，你正欲再看，忽然嗖地一枚冷箭从你头上飞\n"
"过，还是赶快离开的好。\n"
);

        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south" :   __DIR__"canyon2",
               "north" :   __DIR__"luanshi8",
        ]));    

        set("objects", ([

        ]));
    
        setup();
        replace_program(ROOM);
}

