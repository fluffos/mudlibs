// 以彼之道还施彼身 /kungfu/skill/douzhuan-xingyi/douzhuanxingyi.c
// updated by keinxin 2003

inherit F_SSERVER;

#include <ansi.h>
#include <weapon.h>
#include <combat.h>
#include "skill.h"

int perform_case_1(object me,object target);
int perform_case_2(object me,object target);
int perform_case_3(object me,object target);
int perform_case_4(object me,object target);
int perform_case_5(object me,object target);

int perform(object me, object target)
{
        int i,j;
        mapping fam;
        object weapon,weapon2;
        if( !target ) target = offensive_target(me);
        if( !target)  return notify_fail("你准备向谁施展慕容绝技以彼之道还施彼身呢?\n");
        weapon = me->query_temp("weapon");
        weapon2 = target->query_temp("weapon");
        fam = (mapping)target->query("family");
        if ( (int)me->query_condition("pfm_dzxy") > 0 ) 
                return notify_fail("你心力耗费过多，短时间内无法再以彼之道还施彼身。\n");
        if(!me->is_fighting(target) ) 
                return notify_fail("您只能在战斗中施展以彼之道还施彼身!。\n");                
        if (!fam) 
                return notify_fail("他无门无派，您怎么以彼之道还施彼身？\n");
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力还不够高！\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你当前的内力不够！\n");
        if( (int)me->query_skill("douzhuan-xingyi", 1) < 100 )
                return notify_fail("你的星移斗转还不够熟练，目前无法还施彼身！\n");
        if( (int)me->query_skill("murong-daofa",1) < 100 )
                return notify_fail("你的慕容刀法还不够熟练，目前无法还施彼身！\n");
        if( (int)me->query_skill("murong-jianfa", 1) < 100 )
                return notify_fail("你的慕容剑法还不够熟练，目前无法还施彼身！\n");
        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("你的本门掌法还不够熟练，目前无法还施彼身！\n");
        if((int)me->query_skill("canhe-zhi", 1) < 100 )
                return notify_fail("你的本门指法还不够熟练，目前无法还施彼身！\n");

        j = sizeof(perform)-1;
        for(i=0 ; i < j; i++)
        if((string)fam["family_name"] == (string)perform[i]["menpai"])
        {
                if( !weapon2 ) i++;
                message_vision(HIW"\n$N仰天发出一阵狂笑，吼道:"+perform[i]["menpai"]+"的小儿，今日让你见识我慕容「以彼之道还施彼身」的历害！\n\n",me,target);

                switch(random(5))
                        {
                        case 0: { message_vision( HIW+"$N"+perform[i]["describe"]+"\n"NOR,me,target);break;}
                        case 1: { message_vision( HIY+"$N"+perform[i]["describe"]+"\n"NOR,me,target);break;}
                        case 2: { message_vision( HIR+"$N"+perform[i]["describe"]+"\n"NOR,me,target);break;}
                        case 3: { message_vision( HIC+"$N"+perform[i]["describe"]+"\n"NOR,me,target);break;}
                        case 4: { message_vision( HIB+"$N"+perform[i]["describe"]+"\n"NOR,me,target);break;}
                        }
                switch(random(5))
                
                        {
                        case 0:   {perform_case_1(me,target);break;}	
                        case 1:   {perform_case_2(me,target);break;}
                        case 2:   {perform_case_3(me,target);break;}
                        case 3:   {perform_case_4(me,target);break;}
                        case 4:   {perform_case_5(me,target);break;}
                        case 5:   {perform_case_5(me,target);break;}
                        }
        if( (int)me->query("neili") > 500 ) {me->add("neili", -100); }
        else {me->add("neili",-(int)me->query("neili")*2/3);}
        me->apply_condition("pfm_dzxy",5+random(5));
        return 1;
        }
        return notify_fail("你对他门派绝技知之甚少，实在无从出手还施彼身。\n");
}

int perform_case_1(object me,object target)
{
        int count_s,count_d;
        object use_weapon,target_weapon;
        count_s = me->query_str();
        count_d = (int)me->query_dex();
        me->clean_up_enemy();
        target = me->select_opponent();
        use_weapon = me->query_temp("weapon");
        target_weapon = target->query_temp("weapon");
        me->add_temp("apply/dexerity",  count_s*3 );
        me->add_temp("apply/strength",  count_d*3 );
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_vision(HIW"\n$N将$n的招试一一破解！\n",me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        message_vision(HIW"\n$N将$n毕身习得的绝学施展出来，排山倒海搬的攻向对方！\n",me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        me->add_temp("apply/dexerity",  -count_s*3 );
        me->add_temp("apply/strength",  -count_d*3 );        
        return 1;
}
 
int perform_case_2(object me,object target)
{
        int i;
        me->clean_up_enemy();
        target = me->select_opponent();
        i = (random(5)+3);
        target->start_busy(i);   
        message_vision(HIY"\n$N仰天发出一阵狂笑，鼠辈！见识我慕容「以彼之道还施彼身」的历害！\n\n",me,target);   
        return 1;
}

int perform_case_3(object me,object target)
{
        int count_s,count_d,skill;
        count_s = me->query_str();
        count_d = (int)me->query_dex();
        skill = ((int)me->query_skill("dodge")+(int)me->query_skill("strike"))/30;
        me->add_temp("apply/strength", count_s );       
        me->add_temp("apply/dexerity", count_d );
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count_s, count_d :), skill);
        message_vision(HIW"\n$N仰天发出一阵狂笑，让你见识我慕容「以彼之道还施彼身」的历害！\n\n",me,target);
        return 1;
}

void remove_effect(object me, int aamount, int damount)
{
        me->add_temp("apply/strength", -aamount);
        me->add_temp("apply/dexerity", -damount);
        tell_object(me, HIY "你深深的吸了一口气，把充溢身体中的内力收回丹田之中。\n" NOR);
        me->start_busy(random(3));
}

int perform_case_4(object me,object target)
{
        int busy_time;
        string msg;
        busy_time = ((int)me->query_skill("parry")+(int)me->query_skill("sword"))/20;   
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/10 ) 
                {
                msg = HIR "\n结果$p大骇之下被$P攻了个措手不及！\n" NOR;
                target->start_busy(busy_time);
                } 
        else    {
                msg = "\n$p惊心之余仍看破了$P的意图，并没有上当。\n" NOR;
                me->start_busy(busy_time/4);
                }
        message_vision(msg, me, target);
        return 1;
}

int perform_case_5(object me,object target)
{
        int count_s,count_d;
        object use_weapon,target_weapon;
        me->clean_up_enemy();
        target = me->select_opponent();
        use_weapon = me->query_temp("weapon");
        target_weapon = target->query_temp("weapon");
        count_s = (int)me->query_str();
        count_d = (int)me->query_dex();
        me->add_temp("apply/dexerity",  count_s*3 );
        me->add_temp("apply/strength",  count_d*3 );
        if ( !target_weapon && use_weapon) use_weapon->unequip(); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/strength", -count_s*3 );
        me->add_temp("apply/dexerity", -count_d*3);
        message_vision(HIW"\n$N仰天发出一阵狂笑，「参合慕容，斗转星移」「以彼之道，还施彼身」！\n\n",me,target);
        return 1;
}
