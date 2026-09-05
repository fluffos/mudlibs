inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
        set("short", "石岗"NOR);
        set("long", 
"这里叫做石岗，是无想山下一处小镇。\n"

        );
        set("exits", ([
                
				"eastup" : __DIR__"wuxiangw1",
				"westdown" : __DIR__"guandaos2",
        ]));
        /*set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));*/
		set("no_task",1);
        set("outdoors", "yingtianfu");
		set("entry_direction","eastup");
		set("migong","/d/yingtiansouth/wuxiang");
		set("migong_posi","west");
		set("look_refuse_msg","建康府军正在无想山练兵，不许偷窥。\n");
		set("enter_refuse_msg","建康府军正在无想山练兵，稍等等再进山吧。\n");
        setup();
   
}

