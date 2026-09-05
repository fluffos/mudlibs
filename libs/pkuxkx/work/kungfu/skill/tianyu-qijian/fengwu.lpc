#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

void remove_no_move(object me);

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string str;
    int level;
    object weapon;  
    int ap,dp;          
    int a_damage,a_attack;
    int more,extra,sword,da,flag;
    mapping attack_val = ([
                           "base" : ([ "weapon" : "sword", ]), //基本功夫类型
                           "skill" : ([ "weapon" : "tianyu-qijian", ]), //高级技能名称
                          ]);

    if( !target ) target = offensive_target(me);
    
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail(""HIY"「"HIR"鳳"HIM"舞"HIG"九"HIC"天"HIY"」"NOR"只能对战斗中的对手使用！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        (me->query("family/family_name") != "灵鹫宫" && me->query("chushi/last_family") != "灵鹫宫") )
        return notify_fail("你哪里偷来的武功？\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
        return notify_fail("你需要装备剑类武器才能使用鳳舞九天的绝招。\n");

    if((int)me->query("max_neili") < 300 )
        return notify_fail("你的内力不够！\n");

    if((int)me->query("neili") < 400 )
        return notify_fail("你的内力不足！\n");

    if((int)me->query("qi") < 200 )
        return notify_fail("你的气血不足，没法子施用外功！\n");

    if((int)me->query_skill("tianyu-qijian", 1) < 150)
        return notify_fail("你的天羽奇剑级别还不够，使用这一招会有困难！\n");

    if((int)me->query_skill("bahuang-gong", 1) < 150)
        return notify_fail("你的八荒六合唯我独尊功还不够，使用这一招会有困难！\n");

    if(me->query_temp("busy_fengwu")>time())
        return notify_fail("你累坏了先休息一下吧。\n");

    me->delete("env/brief_message");
    target->delete("env/brief_message");
    a_damage=(int)me->query_skill("bahuang-gong",1)/10+(int)me->query_skill("tianyu-qijian",1)/15-20;
    a_damage=a_damage*8/10;
    if(me->query_temp("lj_set")) a_damage += a_damage/2;
    a_attack=(int)me->query_skill("bahuang-gong",1)/5+(int)me->query_skill("tianyu-qijian",1)/10;
    a_attack=a_attack*8/10;
    if(me->query_temp("lj_set")) a_attack+= a_attack/2;
    me->add_temp("apply/damage",a_damage);
    me->add_temp("apply/attack",a_attack);
    me->receive_damage("qi", 100);
    me->add("neili", -200);
    level = (int)me->query_skill("bahuang-gong", 1);
    sword = (int)me->query_skill("tianyu-qijian", 1);
    if(level >= 400){ extra = 1+sword/210; flag = 1;}
    else if(level >= 250){ extra = 1+sword/250; flag = 3;}
    else if(level >= 150){ extra = 1+sword/320;flag = 5;}
    else extra =0;
    //限制额外招式最大值
    if ( extra>=4 )
        extra=4;
        
    if(me->query_temp("lj_set")) extra+= extra/2;
    if(wizardp(me)) printf("the extra is %d\n",extra);
    if(wizardp(me)) printf("the flag is %d\n",flag); 
    //显示perform具体情况
    //me->set_temp("combat_env",me->query("env/skip_combat"));
    //me->set("env/skip_combat",0);
    //target->set_temp("combat_env",target->query("env/skip_combat"));
    //target->set("env/skip_combat",0);            
    message_vision(HIC"$N一招蜻蜓点水手中的"HIR+weapon->name()+HIC"如发疯般的攻向$n,\n"NOR+HIW"只见$n没有来的及招架$N这一阵狂攻乱舞，当场目瞪口呆不知所措！\n\n"NOR,me,target);
    message_vision(HBRED+HIW"$N使出了灵鹫宫天羽奇剑的精髓鳳舞九天,\n"NOR,me,target);

    message_vision(HIW"
                         "HBRED+HIG"┏━━━━┓"NOR"
                         "HBRED+HIG"┃   "NOR+BLINK+HIR"鳳"NOR+HBRED+HIG"   ┃"NOR"
                         "HBRED+HIG"┗━━━━┛\n"NOR,me,target);

    me->set_temp("attack_val", attack_val);
    da = COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    if(da > 0 && extra > 0)
    {
        more = extra;
        while(more > 0)
        {
            if(!random(flag))
            {
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            }
            more --;
            if(wizardp(me)) printf("the more is %d\n",more);
        }                
     }
     message_vision(HIW"
                         "HBRED+HIG"┏━━━━┓"NOR"
                         "HBRED+HIG"┃   "NOR+BLINK+HIM"舞"NOR+HBRED+HIG"   ┃"NOR"
                         "HBRED+HIG"┗━━━━┛\n"NOR,me,target);

    me->set_temp("attack_val", attack_val);
    da = COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    if(da > 0&&extra > 0)
    {
        more = extra;
        while(more > 0)
        {
            if(!random(flag))
            {
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            }
            more --;
            if(wizardp(me)) printf("the more is %d\n",more);
        }                
    }
    message_vision(HIW"
                         "HBRED+HIG"┏━━━━┓"NOR"
                         "HBRED+HIG"┃   "NOR+BLINK+HIG"九"NOR+HBRED+HIG"   ┃"NOR"
                         "HBRED+HIG"┗━━━━┛\n"NOR,me,target);

    me->set_temp("attack_val", attack_val);
    da = COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    if(da > 0&&extra > 0)
    {
        more = extra;
        while(more > 0)
        {
            if(!random(flag))
            {
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            }
            more --;
            if(wizardp(me)) printf("the more is %d\n",more);
        }                
    }

    message_vision(HIW"
                         "HBRED+HIG"┏━━━━┓"NOR"
                         "HBRED+HIG"┃   "NOR+BLINK+HIC"天"NOR+HBRED+HIG"   ┃"NOR"
                         "HBRED+HIG"┗━━━━┛\n"NOR,me,target);

    me->set_temp("attack_val", attack_val);
    da = COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    if(da > 0&&extra > 0)
    {
        more = extra;
        while(more > 0)
        {
            if(!random(flag))
            {
                me->set_temp("attack_val", attack_val);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            }
            more --;
            if(wizardp(me)) printf("the more is %d\n",more);
        }                
    }

    me->add_temp("apply/damage",-a_damage);
    me->add_temp("apply/attack",-a_attack);

    //恢复combat设置                                                  
    //me->set("env/skip_combat",me->query_temp("combat_env"));        
    //target->set("env/skip_combat",target->query_temp("combat_env"));         

    if( !target->is_fighting(me) ) 
    {
        if( living(target) ) 
        {
            if( userp(target) ) target->fight_ob(me);
            else target->kill_ob(me);
        }
    }
    ap = me->query("combat_exp");
    dp = target->query("combat_exp"); 
    //即使敌人再强，也有一定几率，busy几率是C级
    if( F_KUNGFU->hit_rate( ap+dp, dp*2, 8, me, target) ) 
    {
        message_vision(HIM"$N被这绚丽无比的招式所震撼，不由得呆了一下！\n"NOR, target);
        F_KUNGFU->hit_busy( "confuse", 3+random(2), target );
    }
    
    if (level<=500)
        me->set_temp("busy_fengwu",time()+6);
    else
        me->set_temp("busy_fengwu",time()+4);
    me->set_temp("no_move",1);
    call_out("remove_no_move",2+random(3),me);
    return 1;
}

void remove_no_move(object me) 
{
    if (me) me->delete_temp("no_move");
}

