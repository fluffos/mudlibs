//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "xunshi.h"
void create()
{
        set("short", HIM"承天门"NOR);
        set("long", 
"这里是承天门，取义“奉天承运”。东面是御林军的驻地，西面是御前侍卫\n的营地。\n"

        );
        set("exits", ([
                
              
                
                "north" : __DIR__"yudao4",
                "south" : __DIR__"damingmen",
                "enter" : __DIR__"zayichu",
                "east" : __DIR__"yulinjun",
                "west" : __DIR__"shiweichu",
                
                
        ]));

         set("objects", ([
                __DIR__"npc/ligonggong" : 1,
               
        ]));
        
        set("outdoors", "yingtianfu");
        setup();
   
}

int valid_leave(object me,string dir)
{
    object* inv;    
    int i;
    inv = deep_inventory(me);
	if (dir=="enter")
    {
		if (!userp(me))
		{
			return notify_fail("\n");
		}
        if (!me->query("mingpin")&&!me->query("ming/tj/pin"))
        {
            return notify_fail("你是怎么混进来的？快离开这里！\n");
        }
        if (me->query("mingpin")>2)
        {
            return notify_fail("大明有律，外臣不得插手内廷事务，大人还是请回吧。\n");
        }
        for(i=sizeof(inv)-1; i>=0; i--)
            {
                if(userp(inv[i]))
                {
                    me->unconcious();
                    return notify_fail(HIR"竟敢带外人入宫，下次再犯，定斩不赦！”\n"NOR);
                }
            }
    }
	return ::valid_leave(me, dir);
}
