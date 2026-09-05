//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "洛阳东门");
        set("long", @LONG
洛阳东门高约三丈，宽约二丈有余，一尺许厚的城门上镶满了拳头般
大小的柳钉。门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧帖满
了悬赏捉拿之类的官府通谍，一条笔直的青石板大道向东西两边延伸，西
去就是洛阳内城了，向东一桥高高跨过洛阳城护城河。
LONG
        );

        set("exits", ([
               "eastup" : __DIR__"chengdongqiao",
               "west" : __DIR__"dongdajie2",

        ]));
        set("objects", ([
                "/d/city/npc/wujiang1"+random(2) : 1,
                "/d/city/npc/bing" : 2,
        ]));



        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

