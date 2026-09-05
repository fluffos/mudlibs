// Room: /d/emei/qianfoqiandian.c 峨嵋派 毗卢殿
#include <ansi.h>
#include "jing.h"
inherit ROOM;

void create()
{
        set("short", "毗卢殿");
        set("long",
"千佛庵又名洪椿坪，因坡上有一株洪椿树而得名，这里就是\n"
"峨眉弟子清修之处，殿前出出进进的都是峨眉派的女弟子，此处\n"
"秀丽风景，每逢盛夏常有霏霏细雨飘忽庭院，既是峨眉十大奇景\n"
"之一－－－“"MAG"洪椿晓雨"NOR"”。\n"
        );

        set("exits", ([
                "southdown" : __DIR__"gate",
		"north" : __DIR__"dian2",
               ]));    
        set("objects", ([
            __DIR__"npc/jingdao" : 1,
              ]));

        setup();
        
}
