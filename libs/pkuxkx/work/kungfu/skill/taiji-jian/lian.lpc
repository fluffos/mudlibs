// tie@fengyun
// seagate@pkuxkx 2010/11/02
//修改了实际上17连招的bug，连招16循环从1开始计数
//修改了连招对攻击和伤害的加成，修改为削减。
//加入太极蓄力大招影响

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        int extra,dmg;
        int dt, delay=time();
        int i, pflv;
        object weapon;
        mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "taiji-jian" ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("太极剑法「连」字诀只能对战斗中的对手使用。\n");
        
        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        
        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");
        
		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "武当派")
			pflv = 0;

		dt = 10;
		dt -= pflv;
		if (pflv>=4) dt -= (pflv-3);
		if (dt<3) dt = 3;
		
        if( delay < dt +(int)me->query_temp("lianend") )
                return notify_fail("你刚刚用完连字诀窍，气血汹涌，无法出招！\n");
        
        if( (int)me->query_skill("taiji-jian", 1) < 50 )
                return notify_fail("你的太极剑法不够娴熟，不能用「连」字诀。\n");
        
        if( (int)me->query_skill("taiji-shengong", 1) < 60 )
                return notify_fail("你的太极神功不够娴熟，不能使用「连」字诀。\n");
        
        extra = me->query_skill("taiji-jian",1) / 20;
        extra += me->query_skill("taiji-shengong",1) /20;
        if (extra > 64) extra = 64;
                
        //显示perform具体情况
        //me->set_temp("combat_env",me->query("env/skip_combat"));
        //me->set("env/skip_combat",0);
        //target->set_temp("combat_env",target->query("env/skip_combat"));
        //target->set("env/skip_combat",0);
        
        dmg=me->query_temp("apply/damage");       
        me->add_temp("apply/attack", -me->query_skill("taiji-jian",1)/10);
        me->add_temp("apply/dodge", -me->query_skill("taiji-jian",1)/10);
        //me->set_temp("apply/damage", (dmg*9)/10);//by all，武器断掉引起apply/damage增加
        me->add_temp("apply/damage", -dmg/10);  
        msg = HIR  "$N"HIR"运起［太极神功］，同时使出「太极剑法」中的「连」字诀，手中的"+ weapon->name() +HIR"一招连着一招画起圈来，闪电般的击向$n！\n" NOR;
		if (me->query_temp("taiji_xuli")>0)
		{
			msg+=HIR  "$N"HIR"积蓄起来的太极劲力猛地爆发了出来！\n";
			me->add_temp("apply/damage",me->query_temp("taiji_xuli"));
		}
        message_vision(msg, me, target);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, 0);
        for(i=1;i<extra/4;i++)
        {
            if ( !objectp(weapon = me->query_temp("weapon")) ) break;
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
        }
        i = extra/4;
        msg =  HIW "剑光一闪，$N一口气画了"+chinese_number((i>0?i:1))+"个圈!\n" NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/attack", me->query_skill("taiji-jian",1)/10);
        me->add_temp("apply/dodge",  me->query_skill("taiji-jian",1)/10);
        //me->set_temp("apply/damage", dmg);//by all，武器断掉引起apply/damage增加
        me->add_temp("apply/damage", dmg/10);
		if (me->query_temp("taiji_xuli")>0)
		{
			me->add_temp("apply/damage",-me->query_temp("taiji_xuli"));
			me->set_temp("taiji_xuli",0);
		}

        me->add("neili", -(300+extra*4));

        //恢复combat设置                                                  
        //me->set("env/skip_combat",me->query_temp("combat_env"));        
        //target->set("env/skip_combat",target->query_temp("combat_env"));
        me->start_busy(2+random(2));
        me->set_temp("lianend",time());
        return 1;
}

