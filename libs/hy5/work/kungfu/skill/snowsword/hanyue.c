//寒月吟花千层雪 BY Cigar 2002.01

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
void qianxue_ok(object);

int perform(object me, object target)
{
        int damage,damagea;
        object weapon;
        string msg;
        int extra,add_dodge;
        string *mapped;
        mapping map;
                extra = me->query_skill("snowsword",1);         
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「寒月吟花千层雪」？\n");


     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bitao-shengong")
                return notify_fail("请使用碧涛心法!\n");

        if((int)me->query_skill("bitao-shengong",1) < 100)
                return notify_fail("你的碧涛心法还不够。。。\n"); 
                

        if(!me->is_fighting())
                return notify_fail("「寒月吟花千层雪」只能在战斗中使用！\n");
        if((int)me->query("max_neili") < 300 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
         if((int)me->query_skill("snowsword", 1) < 120)
                return notify_fail("你的风回雪舞剑法不够熟练，使用这一招会有困难！\n");

  
        if(me->query_temp("no_qianxue"))
                return notify_fail("你现在“寒月吟花千层雪”刚用毕，等会儿再用吧！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        //damagea=random((int)me->query_skill("dodge")/2);
        damagea=random((int)me->query_skill("dodge"));
        if(random((int)target->query("combat_exp"))/2 < (int)me->query("combat_exp"))
        {
                message_vision(HIW"\n$N凝望窗外寒绵小月，暖心未眠，心生诗意，低吟"+HIR"“寒月吟花千层雪”"+HIW"。\n"NOR,me,target);
                target->receive_damage("qi",damagea,me);
                target->receive_wound("qi",damagea/2,me);
                target->receive_damage("jing",damagea/3,me);
                target->start_busy(2);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIG"\n$N眠意已生，低吟句句缠绵，$n觉似情深，$N却感无味...\n"NOR,me,target);
        }
        message_vision(HIG"\n$N轻拭绢丝窗上雪花，看窗外寒梅，景映眼中，情自心生：“\n"NOR,me,target);
        message_vision(HIG"\n玉为花瓣雪为神，冰姿不怕雪侵，羞依绢丝窗下，醉心。\n"NOR,me,target);
        
        	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 2200);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n月明亭阁下，寒依疏影潇潇竹，池底影浮寒月，香闻流水，醉意。\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIG"\n窗前香遍酒阑人，酒腻花熏，酒不醉人人自醉。”\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        //damage=random((int)me->query_skill("sword")/2);
        damage=(int)me->query_skill("sword")+random((int)me->query_skill("parry"));
         	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -2200);
        if(random((int)target->query("combat_exp"))/2<(int)me->query("combat_exp"))
        {
                message_vision(HIC"\n小月、花香、酒醉，围绕在$N的周围，此情此景，早已让$n神魂颠倒....\n"NOR,me,target);
                target->receive_damage("qi",damage/2,me);
                target->receive_wound("qi",damage/2,me);
                COMBAT_D->report_status(target);
        }
        else 
        {
                message_vision(HIY"\n$n冷冷一笑，此笑更添寒月余光。$n从怀中掏出一壶美酒，独自小酌。\n"NOR,me,target);
        }

       message_vision(
                HIW"$N略一提气，运起轻功，拔剑起舞。只见$N足不沾地，手中剑越舞越快，逐渐幻做一团白雾，满堂滚动。\n" NOR, me);
 
 if ((int)me->query_skill("snowsword",1) > 300)
 {
 	       if(  me->query_skill("snowsword",1)<100)
        {
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);                
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))  
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来.\n"NOR,target);
                        target->start_busy(3);
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来.\n"+NOR,me);
                        me->start_busy(2);
                }
        }
        if( (me->query_skill("snowsword",1)<300)&&(me->query_skill("snowsword",1)>100))
        {
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2)))  
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来..\n"NOR,target);
                        target->start_busy(2+random(3));

                       
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来..\n"+NOR,me);
                        me->start_busy(3);
                }
        }
        if( me->query_skill("snowsword",1)>300 )   
        {
                message_vision(HIY"\n$N脚踩连环，环绕着$n飞速转了起来！\n\n"+NOR,me,target);
                if (random(me->query("combat_exp")) > random((target->query("combat_exp")*7/10)))                
                {
                        message_vision(HIR"只见"+target->query("name")+"四周就象有千万只"HIY"蝴"HIC"蝶"HIM"在"HIG"飞"HIB"舞"HIY",\n
                              结果$N被扰得眼花潦乱，接应不暇！手脚顿时慢了下来...\n"NOR,target);
                        target->receive_damage("jing", extra);
                        if(!userp(target)) 
                        {
                                target->add("eff_jing", -extra*2);
                                target->receive_damage("jing", extra);
                        }
                                target->start_busy(4);
                }
                else
                {
                        message_vision(HIY"结果$N自己转了个头晕眼花！手脚顿时慢了下来...\n"+NOR,me);
                        me->start_busy(2);
                }
        }
 	
}
 
me->start_busy(3);
        //me->receive_damage("jing", 30);
        me->add("neili", -100);
        me->set_temp("no_qianxue",1);
        call_out("qianxue_ok",2+random(2),me);

        return 1;
}

void qianxue_ok(object me)
{
        if (!me) return;
        me->delete_temp("no_qianxue");
}

