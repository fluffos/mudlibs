//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"小舍"NOR);
        set("long", @LONG
这里是主人用餐之处，中间摆着一张竹子编制的桌子。角落里居然有几罐
酒，隐隐发出香味，不禁让人食指大动。
LONG
        );

        set("exits", ([
               "north" : __DIR__"xiaoshe3",     
        ]));
        set("objects", ([
                "/d/riyuejiao/obj/fenjiu":1,
                "/d/riyuejiao/obj/baicaojiu":1,
                "/d/riyuejiao/obj/zhuyeqing":1,

        ]));
        setup();
        replace_program(ROOM);
}

