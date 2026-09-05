//taskob
//Made by kiden@pkuxkx
//2001.1.3

#include <ansi.h>
#include "task_obj.h"

inherit ITEM;

void create()
{
        set_name("先天罡气谱",({"gangqi pu"}));
        set_weight(4000);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
                set("task_owner","wang chongyang");
                set("task_owner_cname","王重阳");
                set("reward_point",1);
                set("unit","本");
                set("no_sell",1);
                set("no_beg",1);
//              set("value",1000);
        }
        
        setup();
        
}

