//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "钟楼");
        set("long", 
"这里是应天府的钟楼。一个大钟(zhong)矗立着象征着帝国的威严。\n"

        );
        set("item_desc", ([
		"zhong" : "一口大钟，如果没有防备的情况下，敲(qiao)一下也许会吓到别人。\n", 
	    ]));
        set("exits", ([
                
                
                
                "north" : __DIR__"beicheng",
                
                
        ]));
        
        set("outdoors", "yingtianfu");
        setup();
   
}

void init()
{ 
	add_action("do_qiao","qiao"); 
	
}

int do_qiao()
{
    object* allob;
    object ob;
    object me=this_player();
	allob = all_inventory(environment(me));
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
    tell_object(me,"你敲响了巨钟。\n");
    for(int i=0;i<sizeof(allob);i++)
		{    
			if(!objectp(allob[i])) continue;
            ob = allob[i];  
            if(!living(ob)) continue;
			if(ob==me) continue;
            tell_object(ob,HIR"不只哪里传来的一声巨响，吓得你胆战心惊。\n"NOR);
			ob->add_busy(2);
		}
	me->start_busy(1);
    return 1;
}