//霹雳三打
//Created by Wuyou@Sanjie

#include <ansi.h>

inherit F_SSERVER;

int calc_damage(int,int);

int perform(object me, object target)
{
        object weapon;
        string msg,result;
        int i,j,k,total,mypot,tapot; 
        weapon = me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「霹雳三打」？\n");
 
        if(!me->is_fighting())
                return notify_fail("「霹雳三打」只能在战斗中使用！\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这门绝学只能对战斗中的对手使用。\n");
        
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("请使用四平大马站桩功!\n");
        
        if((int)me->query_skill("buddha-club", 1) < 100 )
                return notify_fail("你的释厄棍法还不够熟练，不能使用「霹雳三打」！\n");

        if((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("neili") < 300 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("qi") < 300 )
                return notify_fail("你的气不足，没法子施用外功！\n");

        if (me->query_skill("buddha-club",1)<400 
          ||me->query_temp("oldpili"))
        {
                mypot = (int)me->query_skill("buddha-club",1);
                tapot = (int)target->query("parry",1);

                message_combatd(HIY"\n$N双手合十，念起了咒语：\n" NOR,me,target,"");
                message_combatd(HIW"\n               “慢慢的！→→→→→→→→→→。\n"NOR,me,target,"");
                message_combatd(HIC"\n          ◇"BLINK""HIR"◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆◇◆"NOR""HIC"◇\n"NOR,me,target,"");
                message_combatd(HIY"\n                  一股金光照耀在$N和$N手中"+weapon->name()+ HIY"的身上。\n"NOR,me,target,"");
                message_combatd(HIC"\n          ☆"BLINK""HIG"★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★"NOR""HIC"☆\n"NOR,me,target,"");
                message_combatd(HIB"\n                 $N吼到："HIM"§      "BLINK""HIB"如意     "NOR""HIY"金"BLINK"     "HIB"箍棒"NOR""HIM"      §"HIR" 
                     \n "+weapon->name()+ HIR"化做一根"HIW"〓定海神针〓"HIB"向$n冲去→→→→→→→→→→→\n"NOR,me,target,"");
                
                me->add("neili", -100);
                me->receive_damage("qi", 100);
                
                if (random(mypot) > tapot/3)
                {
                        target->receive_damage("qi", mypot+random(mypot),me);
                        target->receive_wound("qi", mypot+random(mypot),me);
                        target->start_busy(2);
                }
                if (!target->is_busy())
                        target->start_busy(1);
                
                message_combatd(HIG"\n       刹那间，人棍分离，$N转手快攻五招\n"NOR,me,target,"");
                
                me->add_temp("apply/attack", 200);
                me->add_temp("apply/damage", 1200); 
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));                  
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                me->add_temp("apply/attack", -200);
                me->add_temp("apply/damage", -1200);
         
        }
        else
        {       
                me->add("neili", -250);
                me->receive_damage("qi", 100);

                i = (me->query_skill("club", 1) + me->query_skill("buddha-club", 1) + me->query_skill("zhanzhuang-gong", 1)) /3 ;
                j = (target->query_skill("force", 1) + target->query_skill("dodge", 1) + target->query_skill("parry", 1))/3;

                mypot = me->query("combat_exp");
                k = mypot / 3000;
                if(k > 1000) k=1000;
                i = i * (1000 + k/3)/1000;
                k = 1000 + random(k/2);

                if(wizardp(me)) tell_object(me,sprintf("\nattack: %d , parry: %d  , mypot: %d \n",i,j,k));

                msg = HIR"$N乘$n稍稍走神之机，拼尽全力使出方寸山三星洞不传之绝技－－「霹雳三打」\n"NOR;

                if(random(me->query("combat_exp")) > target->query("combat_exp")/4  || random(3)==0) 
                {
                        total = 0;
                        msg += HIW "\n$N连翻几个筋斗云，一招"HIM"「霹雳流星」"HIW"随手挥出。\n";
                        msg += "只见$N身体一歪，手中"+weapon->name()+ HIW"迎风一抖，光芒暴涨，流星赶月般直罩$n。\n";
                        msg += "$n眼睁睁看着"+weapon->name()+ HIW"袭来，呆呆怔立当场，浑然不知闪躲。\n"NOR;
                        i = calc_damage(me->query_skill("buddha-club",1),k);
    					total += i;
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                        target->receive_damage("qi", i,me);
                        target->receive_wound("qi", i/2,me);
                        result = COMBAT_D->damage_msg(i,"瘀伤");
                        result = replace_string( result, "$l", "小海穴" );
                        msg += result;
                        message_combatd(msg,me,target,"");
                        COMBAT_D->report_status(target, 0);     
                }
                else
                {
                        msg += HIW "\n$N连翻几个筋斗云，一招"HIM"「霹雳流星」"HIW"随手挥出。\n";
                        msg += "只见$N身体一歪，手中"+weapon->name()+ HIW"迎风一抖，光芒暴涨，流星赶月般直罩$n。\n";
                        msg += "但是$n看破了$N的企图，没有上当，急急忙忙向旁边一闪，躲了过去。\n"NOR;
                        message_combatd(msg,me,target,"");
                }
                
                if(random(me->query("combat_exp")) > target->query("combat_exp")/4  || random(3)==0) 
                {
                        msg = HIY "\n$N一个虎跳，使出"HIR"「乾坤一棒」"HIY"。\n";
                        msg += "$N将手中"+weapon->name()+ HIY"迎风一挥，幻出万千虚影，蓄力劲发，高举过顶，\n";
                        msg += ""+weapon->name()+ HIY"对准$n的脑门就砸了下去。这一下要是打中，恐怕连大罗金仙也难逃一命。\n"NOR;
                        i = calc_damage(me->query_skill("club",1),k);
                        total += i;
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                        target->receive_damage("qi", i,me);
                        target->receive_wound("qi", i/2,me);
                        result = COMBAT_D->damage_msg(i,"刺伤");
                        result = replace_string( result, "$l", "小腹" );
                        result = replace_string( result, "$w", weapon->query("name") );
                        msg += result;
                        message_combatd(msg,me,target,"");
                        COMBAT_D->report_status(target, 0);     
                }
                else
                {
                        msg = HIY "\n$N一个虎跳，使出"HIR"「乾坤一棒」"HIY"。\n";
                        msg += "$N将手中$w迎风一挥，幻出万千虚影，蓄力劲发，高举过顶，\n";
                        msg += ""+weapon->name()+ HIY"对准$n的脑门就砸了下去。\n"NOR;
                        msg += "$n吃了一惊，但随即冷静下来，猛然后撤。\n";      
                        message_combatd(msg,me,target,"");
                }

                if(random(me->query("combat_exp")) > target->query("combat_exp")/4  || random(3)==0) 
                {
                        msg = HIG "\n$N仰天长笑，看也不看，一招"HIC"「如意金箍棒」"HIG"应声而来。\n";

                        msg += "$N双手合十，默念咒语。慢慢的，$N手中的"+weapon->name()+ HIG"越变越大，直插云霄。\n";
                        msg += ""+weapon->name()+ HIG"突然砸向$n，只听“轰”的一声，$n被砸了一个血肉模糊。\n"NOR;

                        i = calc_damage(me->query_skill("zhanzhuang-gong",1),k);
                        total += i;
                        if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
                        target->receive_damage("qi", i,me);
                        target->receive_wound("qi", i/2,me);
                        result = COMBAT_D->damage_msg(i,"内伤");
                        result = replace_string( result, "$l", "头部" );
                        msg += result;

                        message_combatd(msg,me,target,"");
           COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                        COMBAT_D->report_status(target, 0);

                }
                else
                {
                        msg = HIG "\n$N仰天长笑，看也不看，一招"HIC"「如意金箍棒」"HIG"应声而来。\n";
                        msg += "$N双手合十，默念咒语。慢慢的，$N手中的"+weapon->name()+ HIG"越变越大，直插云霄。\n";
     msg += ""+weapon->name()+ HIG"突然砸向$n，只听“轰”的一声，本以为$n必死无疑，然而$n却安然无恙，毫发未损。\n"NOR;
                        message_combatd(msg,me,target,"");
                }
                
                if(wizardp(me)) tell_object(me,sprintf("Total damage: %d \n",total));
        }
                

        me->start_busy(1+random(2));
        return 1;
}

int calc_damage(int skill,int k)
{
        int i;

        if(skill>200)
                i = (200*3 + (skill-200)*4) * k/1000;
        else
                i = (skill * k/1000) * 5;

        i = i/2 + random(i/2);
        if(i > 1000) i = 1000;
        return i;
}