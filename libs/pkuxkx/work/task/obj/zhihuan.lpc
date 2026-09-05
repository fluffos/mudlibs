//taskob
//Made by kiden@pkuxkx
//2001.1.3

#include <ansi.h>
#include <armor.h>
#include "task_obj.h"

inherit FINGER;

void create()
{
        set_name("掌门指环",({"zhi huan"}));
        set_weight(40);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
                set("task_owner","xu zhu");
                set("task_owner_cname","虚竹");
                set("reward_point",6);
                set("unit","件");
                set("no_beg",1);
                set("no_sell",1);
//              set("value",1000);
                set("armor_prop/armor",100);
        }
        
        setup();
        
}

