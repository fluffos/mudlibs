// flower.c 情花
// By River 99/05/20
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
       set_name(HIM"情花" NOR, ({"qing hua", "flower", "hua"}));
       set_weight(700);
       if( clonep() )
               set_default_object(__FILE__);
       else {
             set("long", "这是一朵极为鲜艳的情花。\n"+
                         "花瓣的颜色娇艳无比，似芙蓉而更香，如山茶而增艳。\n");
             set("unit", "朵");
             set("no_drop", 1);
             set("no_get", 1);
             set("no_give",1);    
             set("material", "plant");
             set("wear_msg", "$N将$n插在发髻上。\n");
             set("remove_msg", "$N从发髻上摘下了$n。\n");
             set("armor_prop/armor", 1);
	     }
             setup();
}

void init()
{
     add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        if(!id(arg))
             return notify_fail("你要吃什么？\n");
        message_vision(HIY"$N将"HIM"情花"HIY"一瓣瓣的摘下送入口中，入口香甜，芳甘似蜜，更微有醺醺然的酒气。\n"NOR,me);
        if(me->query_condition("medicine")){
          me->add("max_neili", -5);
          write(HIY"你正感心神俱畅，但嚼了几下，却有一股苦涩的味道直冲心头。\n"NOR);
          me->unconcious();
          return 1;
          }
        message_vision(HIY"虽略感苦味，要待吐出，似觉不舍，要吞入肚内，又有点难以下咽。\n"NOR,me);
        if ( !me->query("marry"))
          me->set("food",me->max_food_capacity());
        else {
          me->add("max_neili",random(2)+1);
          me->apply_condition("medicine", 25);
          }
        destruct(this_object());
	return 1;
}
