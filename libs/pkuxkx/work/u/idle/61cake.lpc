#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("儿童节蛋糕",({"child cake","cake"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
          set("long","这是北侠巫师送给各位玩家的精美节日糕点，看起来味道不错哦，要不要尝试一下啊？\n");
          set("unit","块");
          set("no_drop",1);
          set("no_get",1);
          set("value",1);
          set("no_store",1);
          set("no_steal", 1);
          set("no_give", 1);
          set("no_pawn", 1);
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
      if (!arg)  return notify_fail("你要吃什么？\n");
      if ( me->query("gift/idle0601") > 0 ) return notify_fail("你已经吃过蛋糕了，还想再吃？等明年吧！\n");
         if ( (int)me->query("age" ) < 18 )
         {
             me->add("neili",5000);
             me->add("max_neili",100);
             me->add("max_jingli",100);
             me->add("food",1000);
             me->add("water",1000);
             me->add("potential",1000);
             message_vision(HIG "$N迫不及待的吃下蛋糕，然后密切的关注自己的身体有什么反应。\n" NOR,me);
             tell_object(me,"\n你的内力增长了5000点!\n你的最大内力增长了100点!\n你的最大精力增长了100点!\n你的潜能增长了1000点!\n\n");
             me->set("gift/idle0601",1);
         }
         else
         {
             message_vision(HIG "$N虽然已经早就过了儿童的年龄，但是厚着脸皮吃了巫师的礼物，居然也有一点效果。\n" NOR,me);
             me->add("neili",2500);
             me->add("max_neili",50);
             me->add("max_jingli",50);
             me->add("food",500);
             me->add("water",500);
             me->add("potential",500);
             message_vision(HIR "$N迫不及待的吃下蛋糕，然后密切的关注自己的身体有什么反应。\n" NOR,me);
             tell_object(me,"\n你的内力增长了2500点!\n你的最大内力增长了50点!\n你的最大精力增长了50点!\n你的潜能增长了500点!\n\n");
             me->set("gift/idle0601",1);
         }
        me->save();
        destruct(this_object());
        return 1;
}
