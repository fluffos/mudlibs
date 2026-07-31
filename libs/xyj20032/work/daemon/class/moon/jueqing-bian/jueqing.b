// writted by fbbz
// 10/2001

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int calculate_damage(object me, object target, int base_damage, int damge_bonus);

int perform(object me, object target)
{       
        string msg="";
        int damage,wound,k,damage_bonus,mystr;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("一个人绝情给谁看啊！\n");

        if(!me->is_fighting())
                return notify_fail("「绝情」只能在战斗中让别人的心灵受伤！\n");
        
        if (!PFM_D->valid_family(me, "月宫"))
                return notify_fail("不是月宫的如何用「绝情」！\n");
              
        if ((string)me->query("gender")=="男性")
                return notify_fail("你是女的么?想用绝情?别恶心了！\n");
                   
        if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("「绝情」必须以圆月心法为底子！\n");
                
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神状态太差了，没人会看你！\n");
        if((int)me->query_skill("moonforce", 1) < 100)
                return notify_fail("你的圆月心法修为还不够，绝情会很危险！\n");
        if((int)me->query_skill("jueqingbian", 1) < 100)
                return notify_fail("你的绝情鞭修为还不够，恐怕只能偷偷的流泪吧！\n");
        
        mystr=me->query_str();

        k=(int)me->query_skill("whip");
        damage_bonus=k;
        damage_bonus=mystr*(damage_bonus+100+me->query("force_factor"))/200;
        message_vision(HIY"$N满心伤痕，痛不欲生，哭道：你真没良心，我跟你拼了! 说罢扑向$n，早已忘了自己的生死!\n"NOR,me,target);
                     
        if (random((int)me->query("per"))<10 || random((int)target->query("daoxing")) > ((int)me->query("daoxing"))) 
        {
//              msg = "可是$p看到了$P哭泣背后的企图，笑道:我本来就无情无义，你能如何！\n" NOR;
//              message_vision(msg, me, target）;
                message_vision(HIB"可是$p看到了$P哭泣背后的企图，笑道:我本来就无情无义，你能如何！\n"NOR,me,target);

        }
        else 
        {
                msg +=HIB "   ┏━┓\n";
                msg +=HIB "   ┃绝┃\n";
                msg +=HIB "   ┗━┛\n\n";
                damage=calculate_damage(me, target, 20, damage_bonus);
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(damage>0) 
                {
                        target->receive_damage("kee", damage, me, "pfm");
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        msg+=HIB"结果$n心中一动，呆呆的看着$N。\n" NOR;
                }
                msg +=HIB "   ┏━┓\n";
                msg +=HIB "   ┃情┃\n";
                msg +=HIB "   ┗━┛\n\n";
                damage=calculate_damage(me, target, 40, damage_bonus);
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(damage>0) 
                {
                        target->receive_damage("kee", damage, me, "pfm");
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        msg+=HIB"结果$n想起你的情，低下了头。\n" NOR;
                }
                msg +=HIB "   ┏━┓\n";
                msg +=HIB "   ┃绝┃\n";
                msg +=HIB "   ┗━┛\n\n";
                damage=calculate_damage(me, target, 60, damage_bonus);
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(damage>0) 
                {
                        target->receive_damage("kee", damage, me, "pfm");
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        msg+=HIB"结果$n绝望的看着$N，无地自容。\n" NOR;
                }
                msg +=HIB "   ┏━┓\n";
                msg +=HIB "   ┃意┃\n";
                msg +=HIB "   ┗━┛\n\n";
                damage=calculate_damage(me, target, 80, damage_bonus);
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(damage>0) 
                {
                        target->receive_damage("kee", damage, me, "pfm");
                        if(wound>0) target->receive_wound("kee", wound, me, "pfm");
                        msg+=HIB"结果$n想起你的情意，满面通红，羞愧万分。\n" NOR;
                }
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }
        me->start_busy(2+random(1));
        me->add("kee", -100);
        me->add("force", -400);
        me->add("sen",-100);
        return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
        int damage;
        int myexp, youexp;

        damage=base_damage+(damage_bonus+random(damage_bonus))/4;
        myexp=me->query("combat_exp");
        youexp=target->query("combat_exp");
        if(random(youexp)>myexp) {
                damage-=damage/3;
                youexp/=2;
        }
        if (wizardp(me) && me->query("env/combat")=="verbose")
                tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

        return damage;
}


