inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "大草原");
        set("long",
"这里就是蒙古大草原了，蒙古军营就在不远初了，你似乎可以听到蒙古
军队的马蹄声，你不禁放慢了脚步，尽量隐蔽大军的行踪，试图偷偷接近蒙
古军的军营。\n"
);    
        set("outdoors", "xiangyang");
        set("no_magic",1);

        set("exits", ([
                    "west"  : __DIR__"caoyuan2",
                    "north"  : __DIR__"caoyuan4", 
        ]));

        setup();
} 

