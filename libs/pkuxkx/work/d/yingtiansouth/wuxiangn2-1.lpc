inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
        set("short", "入山路"NOR);
        set("long", 
"这里是山间一条小路，虽不曲折，但也绝不好走。\n"

        );
        set("exits", ([
                
				"north" : __DIR__"wuxiangn2",
				"southup" : __DIR__"wuxiangn1",
        ]));
        /*set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));*/
		set("no_task",1);
        set("outdoors", "yingtianfu");
		set("entry_direction","southup");
		set("migong","/d/yingtiansouth/wuxiang");
		set("migong_posi","north");
		set("look_refuse_msg","建康府军正在无想山练兵，不许偷窥。\n");
		set("enter_refuse_msg","建康府军正在无想山练兵，稍等等再进山吧。\n");
        setup();
   
}

