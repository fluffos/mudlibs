// ss5.c By River 98/08
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short",HIB"石室"NOR);
       set("long", @LONG
你觉得眼前一亮，前方石室透过来一丝微弱的光，给了你一丝希望。但还
是只听见远远传来你脚步的回音，空荡荡的感觉使你心中只有恐惧，甚至忘记
孤独。四周如此寂然无声。只能靠摸索前行。
LONG
     );
    
        set("exits", ([
                "enter" : __DIR__"lingshi",
                "west" : __DIR__"ss4",
        ]));

        setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me,string dir)
{          
       object *inv = deep_inventory(me);
       object *obj;   
       if((int)me->query_skill("yunu-xinjing",1) < 101 && !me->query("gmpass") && dir == "enter")
            return notify_fail(HIR"\t\t古墓重地，一般弟子不得入内。\n"NOR);  
       obj = filter_array(inv,(:get_object:));
       if( sizeof(obj) && dir =="enter")
         return notify_fail (HIR"\t\t古墓重地，不得随意带他人进入！\n"NOR);
         return ::valid_leave(me, dir);
}
