//taskob
//Made by kiden@pkuxkx
//2006.10.28

#include <ansi.h>
#include "task_obj.h"

inherit ITEM;

void create()
{
        set_name("包袱",({"bao fu"}));
        set_weight(4000);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
                set("task_owner","xiang wentian");
                set("task_owner_cname","向问天");
                set("reward_point",1);
                set("unit","个");
                set("no_sell",1);
                set("no_beg",1);
//              set("value",1000);
        }
        
        setup();
        
}

