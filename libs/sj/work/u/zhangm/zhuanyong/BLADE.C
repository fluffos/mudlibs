#include <weapon.h>
#include <ansi.h>
inherit F_SSERVER;
inherit BLADE;

void create()
{
        set_name(HIB"小太刀"NOR,({"blade"}) );
        set("long",
        "一把仿造的跟四乃森苍紫的爱刀一样的仿制品。\n"
        );
        set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",10000);        
        set("limit_skill",80);
                  
        }
        init_blade(90);
        setup();        
}

void init()
{
        add_action("do_sevenkill","danc");      
}

int do_sevenkill(object target)
{
        object me;
        me=this_player();

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「"HIM"回天剑舞"NOR"」只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧  \n");

        if (me->is_busy() )
                return notify_fail("你的上一个动作还没有完成，不能施展特攻。\n");

        if(me->query_temp("sevenkill"))
                 return notify_fail("你已正在施展中了，不能再用了。\n");

        message_vision(
        HIR"\n$N怒喝一声，气运双臂，准备施展出「"HIM"回天剑舞"HIW"·"HIB"六连"HIR"」！！\n\n"NOR
        ,me);
        
         me->set_temp("sevenkill",1);
         me->start_busy(2);
         call_out("do_crazy",4,me,target,6);
         call_out("do_clean",6,me);
         return 1;
}


int do_crazy(object me,object target,int times)
{
  int i;
  if(!me) return 0;

  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("sevenkill");
    return notify_fail("目标似乎脱离了你的攻击范围..\n");
  }

  message_vision(HIC"\n$N仰天长啸一声，身上杀气大现，对着"+target->query("name")+"施展出惊世绝技「"HIM"回天剑舞"HIW"·"HIB"六连"HIC"」！！\n\n"NOR,me);
  for(i=0;i < times;i++)
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);

  me->improve_skill("parricide",1+random(me->query_int()/10));
  return 1;
}

int do_clean(object me)
{
         if(!me) return 0;
         me->delete_temp("sevenkill");
         return 1;
}

int query_autoload() { return 1; }

