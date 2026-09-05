//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
#include "/d/yingtianfu/neicheng/royal_area_access.h"
void create()
{
        set("short", "交泰宫");
        set("long", 
"这里交泰宫。\n"

        );
        set("exits", ([
                
              
                
                "north" : __DIR__"beianmen",
                "south" : __DIR__"qianqing",
                "west" : __DIR__"chunhe",
                "east" : __DIR__"rouyi",
                
                
                
        ]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
        ]));
        set("outdoors", "yingtianfu");
        setup();
   
}

int valid_leave(object me,string dir)
{  
    object* inv,guard;    
    int i;
    inv = deep_inventory(me);
	if (dir=="south"||dir=="west"||dir=="east")
    {
		for(i=sizeof(inv)-1; i>=0; i--)
		{
			if(userp(inv[i]))
			{
				me->unconcious();
				return notify_fail(HIR"竟敢带外人入宫，下次再犯，定斩不赦！\n"NOR);
			}
		}
        if (!me->query("mingpin")&&!me->query("ming/tj/pin")&& !present("entry permit",me))
        {
            return notify_fail("你不是大明官员也不是内廷官员，皇城岂可随意进入。\n");
        }
		if (forbid(me)==1&&!identification(me,"御前侍卫统领")&&!identification(me,"御林军统领"))
		{
			return notify_fail("此刻你被御林军统领禁止进入皇城！\n");
		}
		guard=present("yuqian shiwei",this_object());
        if (me->query("mingpin")>1||(me->query("ming/tj/pin")>4&&!me->query("ming/tj/zhuguan") && !me->query_temp("mingtasks/sishe/yizhangout")))
        {
			if (identification(me,"御前侍卫统领")||identification(me,"御林军统领"))
            {
				if (guard)
				guard->bow(me);
                return ::valid_leave(me, dir);
            }
			if (permit(me)==1)
			{
				for(i=sizeof(inv)-1; i>=0; i--)
				{
					if(userp(inv[i]))
					{
						me->unconcious();
						return notify_fail(HIR"竟敢带外人入宫，下次再犯，定斩不赦！”\n"NOR);
					}
				}
				if (guard)
				{
					guard->bow3(me);
				}
				return ::valid_leave(me,dir);
			}
            return notify_fail("天子近臣以及各监正官之外，无诏不得进入皇帝寝宫！\n");
        }
    }
	if (guard)
	guard->bow2(me);
	return ::valid_leave(me, dir);
}

