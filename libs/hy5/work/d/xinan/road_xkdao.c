//road.c.山路
//date:97.10.16
//by dan

#include <room.h>
#include <ansi.h>
inherit ROOM; 



void create()
{
        set("short", HIC"山路"NOR);
        set("long", @LONG
这里是处于闽粤之间的山脉，虽然并不甚高，却绵延数百里，不知何处才是
尽头。这是一条通往小渔村泥泞的山路。路边荆棘丛生，但由于渔民们经常和外
界联系，你依稀还可以辨别出一条小小的山路。从这再往东就是渔村了。你不由
的加快了步伐。
LONG
        );
        set("exits", ([
                "north"     : __DIR__"milin4",
        ]));
        setup();
        set("outdoors","xinan");
}
