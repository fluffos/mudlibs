#include <weapon.h>
#include <ansi.h>
inherit F_SSERVER;
inherit SWORD;

void create()
{
        set_name(HIM"悲恋"HIW"·"HIB"无悔"NOR,({"pathos sword","pathos","sword"}) );
        set("long",
        "由天野魂的悲恋之心所打造出的，神兵利器。据说拥有强大的魔性。"
        );
        set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",10000);           
        }
        init_sword(255);
        setup();        
}

void init()
{
        add_action("do_sevenkill","wind");
        add_action("do_slash","slash");
        add_action("do_fast","fast");
        add_action("do_mage","mage");   
}

int do_sevenkill(object target)
{
        object me;
        me=this_player();

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「"HIM"单恋之苦"HIW"·"HIB"毁"NOR"」只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧  \n");

        if (me->is_busy() )
                return notify_fail("你的上一个动作还没有完成，不能施展特攻。\n");

        if(me->query_temp("sevenkill"))
                 return notify_fail("你已正在施展中了，不能再用了。\n");

        message_vision(
        HIR"\n$N怒喝一声，气运双臂，登时杀气涌现，准备施展出「 "HIM"单恋之苦"HIW"·"HIB"毁" HIR"」！！\n\n"NOR
        ,me);
        
         me->set_temp("sevenkill",1);
         me->start_busy(2);
         call_out("do_crazy",4,me,target,12);
         call_out("do_clean",8,me);
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

  message_vision(HIC"\n$N仰天长啸一声，脸上紫气大现，对着"+target->query("name")+"施展出惊世绝技「"HIM"秘剑"HIW"·"HIB"残"HIC"」！！\n\n"NOR,me);
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

int do_slash(string agr)
{
        int damage,i,dx,SS,sr;
        string msg;
        object* enemy,me;
        object target;

        me = environment();
        enemy=me->query_enemy();

        if(sizeof(enemy))
        target = enemy[random(sizeof(enemy))];


        if (( this_object()->query("equipped"))!="wielded") return 0 ;
                    if(!me->is_fighting())
                 return notify_fail("你必须进入战斗状态～～！\n");

         if(me->is_busy())
            return notify_fail("你的动作还在进行中！！\n");

        message_vision("$N"+HIY+"平举手上的刀，"+HIM+"使出传说中的"+MAG+"「九头龙闪」。\n"NOR,me);
        message_vision("$N"+HIB+"冲向"+NOR+"$n"+HIR+"快速的使出刺击。\n\n"NOR,me,target);

        me->add("angry",-random(30));   

        dx = target->query_attr("dex");
        sr = target->query_attr("str");
        SS = dx+ sr;

        for(i=0; i<10; i++)
        {
        damage = random(500);   
        
        if(i){
                if(me->query("qi") < random(1)) {
                        message_vision("$N"+HIY+"自觉实力不足只好停止攻势。\n"NOR,me);
                        break;
                }       
        else{
                msg = "$N"HIY"刀光锋利的刺出第"+(i+0)+"段刺，"NOR;
                if(damage > 0) {
                        msg +="$n"HIR"鲜血四溅。"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,me,target);
                        target->receive_damage("qi", damage, me);
                        COMBAT_D->report_status(target);
                }
                else {
                        msg +="$n"HIW"并无受到任何伤害。\n"NOR;
                        message_vision(msg,me,target);
                }
        } 
        }
        }
        me->start_busy(2);
        return 1;
}
int do_fast(string agr)
{
        int damage,i,dx,SS,sr;
        string msg;
        object* enemy,me;
        object target;

        me = environment();
        enemy=me->query_enemy();

        if(sizeof(enemy))
        target = enemy[random(sizeof(enemy))];


        if (( this_object()->query("equipped"))!="wielded") return 0 ;
                    if(!me->is_fighting())
                 return notify_fail("你必须进入战斗状态～～！\n");

         if(me->is_busy())
            return notify_fail("你的动作还在进行中！！\n");

        message_vision("$N"+HIY+"平举手上的刀，"+HIC+"使出传说中的"+MAG+"「天翔龙闪」。\n"NOR,me);
        message_vision("$N"+HIB+"冲向"+NOR+"$n"+HIR+"快速的使出拨刀术。\n\n"NOR,me,target);

        me->add("angry",-random(30));   

        dx = target->query_attr("dex");
        sr = target->query_attr("str");
        SS = dx+ sr;

        for(i=0; i<2; i++)
        {
        damage = (1000+random(1600));   
        
        if(i){
                if(me->query("qi") < random(1)) {
                        message_vision("$N"+HIY+"自觉实力不足只好停止攻势。\n"NOR,me);
                        break;
                }       
        else{
                msg = "$N"HIY"刀光锋利的从$n胸前闪过，"NOR;
                if(damage > 0) {
                        msg +="$n"HIR"鲜血四溅。"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,me,target);
                        target->receive_damage("qi", damage, me);
                        COMBAT_D->report_status(target);
                }
                else {
                        msg +="$n"HIW"并无受到任何伤害。\n"NOR;
                        message_vision(msg,me,target);
                }
        } 
        }
        }
        me->start_busy(1);
        return 1;
}
int do_mage(string agr)
{
        int damage,i,dx,SS,sr;
        string msg;
        object* enemy,me;
        object target;

        me = environment();
        enemy=me->query_enemy();

        if(sizeof(enemy))
        target = enemy[random(sizeof(enemy))];


        if (( this_object()->query("equipped"))!="wielded") return 0 ;
                    if(!me->is_fighting())
                 return notify_fail("你必须进入战斗状态～～！\n");

         if(me->is_busy())
            return notify_fail("你的动作还在进行中！！\n");

        message_vision("$N"+HIY+"平举手上的刀，"+HIC+"使出传说中的"+MAG+"「相思无用」。\n"NOR,me);
        message_vision("$N"+HIB+"冲向"+NOR+"$n"+HIR+"一边念着奇怪的咒语。\n\n"NOR,me,target);

        me->add("angry",-random(30));   

        dx = target->query_attr("dex");
        sr = target->query_attr("str");
        SS = dx+ sr;

        for(i=0; i<3; i++)
        {
        damage = (1000+random(1600));   
        
        if(i){
                if(me->query("jing") < random(1)) {
                        message_vision("$N"+HIY+"自觉实力不足只好停止攻势。\n"NOR,me);
                        break;
                }       
        else{
                msg = "$N"HIY"刀锋带着泛红的忙光芒陇罩$n全身，"NOR;
                if(damage > 0) {
                        msg +="$n"HIR"顿时忽感无力。"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,me,target);
                        target->receive_damage("jing", damage, me);
                        COMBAT_D->report_status(target);
                }
                else {
                        msg +="$n"HIW"并无受到任何伤害。\n"NOR;
                        message_vision(msg,me,target);
                }
        } 
        }
        }
        me->start_busy(1);
        return 1;
}

int query_autoload() { return 1; }


