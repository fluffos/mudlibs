#include <ansi.h>
inherit ITEM;
int do_chou(string);
void init();

void init()
{
   add_action("do_eat", "eat");  
}

void create()
{
          set_name(HIW "QQ糖" NOR, ({"qq tang", "qq","tang"}));
      set_weight(20);
     if (clonep())
      set_default_object(__FILE__);
    else {
       set("unit", "袋");
       set("long", WHT"这是一小袋梦牌QQ糖，好象是梦巫师的大家精心制作的。\n"NOR);
       set("value", 50);
        set("no_get",1);
        set("no_drop",1);
     }
     setup();
}

int do_eat(string arg)
{
       object me = this_player();
        if(me->query("combat_exp",1)>100000) {
        message_vision(WHT "这是为新人准备的！！\n\n" NOR,me);
        destruct (this_object());
        return 1;
                }
       if (!id(arg))
        return notify_fail("你要吃什么？\n");
        me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
        me->set("neili", (int)me->query("max_neili"));
        me->set("jingli", (int)me->query("max_jingli"));
        me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        message_vision(WHT "$N掏出一粒“"NOR+HIR"QQ糖"NOR+WHT"”，放在嘴里，说不上是什么味道，只感道有一股清心的气息流遍全身，好象爽多了！\n\n"NOR, me);
        if (!(int)this_object()->query_temp("eat_full")) 
          this_object()->set_temp("eat_full",0);
        if ((int)this_object()->query_temp("eat_full")<=9)
         this_object()->set_temp("eat_full",(int)this_object()->query_temp("eat_full")+1);
           else
            {
           (int)this_object()->delete_temp("eat_full");
            message_vision(WHT "$N你望着最后一粒，意由未尽，有点舍不得吃下！\n"NOR
             HIC "只见$N有点念念不舍的丢下了一个QQ糖的包装袋！\n "NOR, me);
              destruct(this_object());
         }
              return 1;
}
