//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "洛阳北门");
        set("long", @LONG
    洛阳内城北门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳头般
大小的柳钉。门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧帖满
了悬赏捉拿之类的官府通谍，一条笔直的青石板大道向南北两边延伸，南
去就是洛阳内城了，向北一桥高高跨过洛阳城护城河。
LONG
        );

        set("exits", ([
               "south" : __DIR__"beidajie2",  
               "northup" : __DIR__"chengbeiqiao",         
        ]));
        set("objects", ([
                "/d/city/npc/wujiang1"+random(2) : 1,
                "/d/city/npc/bing" : 2,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

