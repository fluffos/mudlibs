#include <ansi.h>

inherit F_SSERVER;

string get_name(string str)
{
        str="翻天覆地";
        return str;
}

string get_help(string str)                
{
        str="指令：ｐｅｒｆｏｒｍ　ｆａｎｔｉａｎ\n"
        +"条件：释厄棍法法150级，最大内力1000"
        +"威力自揣，但是与拜佛五式合用威力惊人！";
        return str;
}

int perform(object me, object target)
{
        
        object *inv, obj, obj1;
        int i, mypot, tapot, damage;
        string str;

        object weapon;
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「翻天覆地」？\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");

        if(!me->is_fighting())
                return notify_fail("「翻天覆地」只能在战斗中使用！\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("你的易筋经级别还不够，使用这一招会有困难！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
                
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 600 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        i=(int)me->query_skill("buddha-club",1);

        if( i < 150)
                return notify_fail("你的棒法还不够，使用这一招会有困难！\n");

        if( time()-(int)me->query_temp("fantian_end") < 4 )
                return notify_fail("“翻天覆地”哪里有老用的道理？\n");
                
        message_vision(HIY"\n$N手指$n愤恨道：“对我不仁尔等小命休以”，一语道罢，$N气运丹田，力灌掌心，使出「翻天覆地」。\n\n"NOR,me,target);
                
        mypot=(int)me->query_skill("buddha-club");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

       
        if( random( mypot+tapot ) > tapot/5 || !living(target) ) 
        {               
                message_vision(HIR"\n只见$n硬生生的接住$N这技绝招，顿感喉头一甜，[噗]的一声吐出一口鲜血。\n\n"NOR,me, target);  
                COMBAT_D->do_attack_damage(me, target);
                damage = random(me->query_skill("club")) + me->query_skill("club")+200;
                target->receive_wound("qi", damage,me);
                COMBAT_D->report_status(target);
                

                        if ( random(10)>1 )
                        {
                                message_vision(HIR"\n\n$N见到$n受伤不轻，乘胜追击，又出一技“翻云覆雨”，$n的七魂六魄早已少去一半。\n"NOR,me,target);
                                COMBAT_D->do_attack_damage(me, target);
                                damage = random(me->query_skill("parry")) + me->query_skill("parry")+200;
                                target->receive_wound("qi", damage,me);
                                COMBAT_D->report_status(target);
                                target->start_busy(1+random(2));
                                message_vision(HIR"\n$N甩出释厄棍法最后三招，想致$n于死地。\n"NOR,me,target);
                                me->set_temp("QJB_perform", 6);
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                                me->delete_temp("QJB_perform");
                        }
          
// }
        }        
     
        else  
        {
                message_vision(HIC"$N识破此招，气运丹田，以力抗力硬接此绝招！\n"NOR, target);
                //me->start_busy(2);
        }
        me->start_busy(2);       
        me->add("neili", -150);
        me->receive_damage("jing", 50);
        me->set_temp("fantian_end",time());
        return 1;
}


