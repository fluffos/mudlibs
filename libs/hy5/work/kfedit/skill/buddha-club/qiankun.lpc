//乾坤一棒
//modify by wuyou@sk_sjsh 
//2003-7-27

#include <ansi.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

string get_name(string str)
{
        str="乾坤一棒";
        return str;
}

string get_help(string str)                
{
        str="指令：ｐｅｒｆｏｒｍ　ｑｉａｎｋｕｎ\n"
        +"条件：释厄棍法法150级，基本棍法150级，小无相功150级，最大内力1200，先天臂力20"
        +"威力甚居，不仅可以破坏对方的盔甲，而且能够使对方身受内伤！";
        return str;
}

int perform(object me, object target)
{
        string msg, dodge_skill;                                
        int damage, jiali, attack, defense, p;
        object armor,weapon;
      
        if( !target ) target = offensive_target(me);
     
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「乾坤一棒」？\n");
                
        if(!me->is_fighting())
                return notify_fail("「乾坤一棒」只能在战斗中使用！\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这门绝学只能对战斗中的对手使用。\n");
                
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
                
        if( (int)me->query_skill("buddha-club",1) < 150 )
                return notify_fail("你的释厄棍法法不够娴熟，还不会使用「乾坤一棒」！\n");
      
        if( (int)me->query_skill("club",1) < 150 )
                return notify_fail("你的基本棍法不够娴熟，还不会使用「乾坤一棒」！\n");

        if( (int)me->query_skill("zhanzhuang-gong",1) < 150 )
                return notify_fail("你的本门内功等级不够，不能使用「乾坤一棒」！\n");  
      
        if( (int)me->query_str() < 20 )
                return notify_fail("你的臂力不够强，不能使用「乾坤一棒」！\n");
      
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力太弱，不能使用「乾坤一棒」！\n");
      
        if( (int)me->query("neili") < 800 )

                return notify_fail("你的内力太少了，无法使用出「乾坤一棒」！\n"); 
        if( time()-(int)me->query_temp("qiankun_end") < 3 )
                return notify_fail("你的内息还没有平复。\n");                     
       
        if( (int)target->query_condition("qiankunyibang"))
                return notify_fail("对方早已身中「乾坤一棒」的内伤了！\n");                                                                                
      
        jiali = me->query("force_factor")+1;
        attack = me->query("combat_exp")/1000;
        attack += me->query_skill("unarmed");
        attack += me->query("force")/5;
        defense = target->query("combat_exp")/1000;
        defense += target->query_skill("dodge");
        defense += target->query("force")/7;
//      attack = (attack+random(attack+1))/2;
        attack += random(defense+1);
      
        damage = me->query_skill("buddha-club", 1)/20 * jiali;
        if(damage > 23000) damage = 23000;
      
        message_vision(HIR"\n$N突然面色怪异，口中爆发一声轻吼，双臂骨节一阵爆响，猛然腾空而起，双手抡起棍子向$n当空砸去，好一式"HIY"「乾坤一棒」"BLU"！\n"NOR,me,target);
 
//      if( attack > defense ) { 
        if( random( attack ) > defense/2 || !living(target) ) 
        { 
                if( objectp(armor = target->query_temp("armor/cloth"))
                && armor->query("armor_prop/armor") < 600
                && damage > 100)
                {
if (!armor->query("systemmake") && !armor->query("ownmake"))
{
                        message_vision(HIY"只见这一棍正好砸在$N的$n"HIY"上，立即将它震得粉碎，裂成一块块掉在地上！\n"NOR, target, armor);
                        armor->unequip();
                        armor->move(environment(target));
                        armor->set("name", "破碎的" + armor->query("name"));    
                        armor->set("value", 0);
                        armor->set("armor_prop/armor", 0);
                        target->reset_action();
}
                }
                tell_object(target, RED"你只觉得霍的胸口一阵剧痛，浑身上下向散了架一样！\n"NOR);
                target->apply_condition("qiankunyibang", 6+(me->query_str()));
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                target->add("neili",-damage);
                target->start_busy(2);
                if ((int)target->query("neili")<0)
                {
                        target->set("neili",0);
                     message_vision(HIR"$n一口鲜血狂喷而出！\n"NOR,me,target);

                }
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg = damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                message_vision(msg, me, target);
                me->add("neili", -jiali);
        }
        else 
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                //message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
        }
//      me->add("force", -200);
//      me->start_busy(1+random(2));  
        me->set_temp("qiankun_end",time());          
        return 1;
}

 
