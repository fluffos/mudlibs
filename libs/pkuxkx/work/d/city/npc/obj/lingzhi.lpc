//灵芝
#include <ansi.h>
#include "chop.h"
inherit ITEM;

void setup()
{}


void create()
{
        set_name(HIM"千年灵芝"NOR, ({"ling zhi", "zhi", "lingzhi"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "产自泰山的千年灵芝，能使人恢复精力。\n");
                set("value", 80000);
        }
		set("product","/d/taishan/obj/lingzhipian");
        setup();

}

int do_eat(string arg)
{
        object me=this_player();
        if (arg!="ling zhi" && arg!="zhi"&& arg!="lingzhi")
           return 0;
              if (me->is_busy())
              	{
              		tell_object(me,"你忙着呢，根本腾不开手。\n");
              		return 1;
              	}            
              if (time()-me->query_temp("last_eat_lingzhi")<180)
              {
                tell_object(me,"等等，你上次吃的灵芝效果还没有完全发挥呢。\n");
                return 1;
               }
              me->set_temp("last_eat_lingzhi",time());             
           if( me->query("max_jingli")<5000)
                me->set("jingli", me->query("max_jingli")+random(300));
           else
                    me->set("jingli", 5000+random(300));
                message_vision("$N吃下一只灵芝，顿时觉得精力充沛。\n", me);


                destruct(this_object());
                return 1;
}
