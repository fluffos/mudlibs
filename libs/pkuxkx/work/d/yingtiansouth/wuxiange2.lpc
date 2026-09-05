inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
        set("short", "清水塘"NOR);
        set("long", 
"这里是一片大水塘，里面却一条鱼都没有。\n"

        );
        set("exits", ([
                
				"westup" : __DIR__"wuxiange1",
				"eastdown" : __DIR__"guandaosc",
        ]));
        /*set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));*/
		set("no_task",1);
        set("outdoors", "yingtianfu");
		set("entry_direction","westup");
		set("migong","/d/yingtiansouth/wuxiang");
		set("migong_posi","east");
		set("look_refuse_msg","建康府军正在无想山练兵，不许偷窥。\n");
		set("enter_refuse_msg","建康府军正在无想山练兵，稍等等再进山吧。\n");
        setup();
   
}

