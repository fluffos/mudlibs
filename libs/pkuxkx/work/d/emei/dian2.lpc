// Room: /d/emei/dian2.c 峨嵋派 文殊殿
#include "jing.h"
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "文殊殿");
        set("long",
"这里是千佛庵的前殿----文殊殿。穿过毗卢殿就到了\n"
"这里，从这里往北就是千佛庵的大殿了。文殊殿上供奉的\n"
"是文殊菩萨，正对面是一尊两米多高的文殊菩萨，两边各\n"
"有一排菩萨，殿中央是一些蒲团。照看这里的是静风师太。\n"
        );

        set("exits", ([
                "south" : __DIR__"dian1",
		"north" : __DIR__"dadian",
               ])); 
        set("objects", ([
            __DIR__"npc/jingfeng" : 1,
              ]));

        setup();
        
}
