//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "洛阳南门");
        set("long", @LONG
洛阳内城南门高三丈，宽约二丈有余，尺许厚的城门上镶满了拳头般
大小的柳钉。门洞长约四丈，大约每隔两个时辰就换官兵把守。洞侧帖满
了悬赏捉拿之类的官府通谍，一条笔直的青石板大道向南北两边延伸，北
去就是洛阳内城了，向南一条长长的山麓横过你的视野。
LONG
        );

        set("exits", ([
               "north" : __DIR__"nandajie3",           
               "south" : __DIR__"longmen",
        ]));
        set("objects", ([
                "/d/city/npc/wujiang1"+random(2) : 1,
                "/d/city/npc/bing" : 2,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

