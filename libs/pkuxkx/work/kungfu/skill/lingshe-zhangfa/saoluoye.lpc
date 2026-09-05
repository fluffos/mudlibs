//vast 2003.2
// Modified by iszt@pkuxkx, 2007-03-09, fixed a bug:
// if weapon was destroyed while performing, heartbeat would be lost

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
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
    int extra,i,rstime;
    object weapon,ob;
    mapping attack_val = ([
        "base": ([ "weapon" : "staff" ]),//基本功夫类型
        "skill" : ([ "weapon" : "lingshe-zhangfa" ]),//高级技能名称
        "skill_action": ([ "weapon" : "lingshe-zhangfa/saoluoye" ]),//query_action所在位置，相对于/kungfu/skill/
        ]);

    if( !target ) target = offensive_target(me);
    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「狂风扫落叶」只能对战斗中的对手使用。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff" )
        return notify_fail("你需要装备staff类武器才能使用狂风扫落叶的绝招。\n");
   
    if( (int)me->query("neili") < 1200 )
            return notify_fail("你的真气不够！\n");

    if( (int)me->query_skill("force",1) < 180 )
            return notify_fail("你的内功修为不够，无法使用「狂风扫落叶」！\n");
    if( (int)me->query_skill("hamagong",1) < 180 )
            return notify_fail("你的内功修为不够，无法使用「狂风扫落叶」！\n");

    extra = me->query_skill("lingshe-zhangfa",1);
    extra += me->query_skill("hamagong",1);
    extra = extra * 2 / 5;
    if( extra < 100 )
            return notify_fail("你的灵蛇杖法火候不够，无法使用「狂风扫落叶」！\n");
		
	// 蛇阵给予的朱红蛇血攻击加成
	rstime = (int) me->query_temp("baituo_redsnake/time"); 
    if ( rstime && time() < rstime )
		extra += extra/5;
	
    me->add_temp("apply/attack",extra);
    me->add_temp("apply/damage",extra/2);
    //显示perform具体情况
    //me->set_temp("combat_env",me->query("env/skip_combat"));
    //me->set("env/skip_combat",0);
    //target->set_temp("combat_env",target->query("env/skip_combat"));
    //target->set("env/skip_combat",0);     
    msg = HIY "$N掌中" + weapon->query("name") + HIY"越舞越急，招数大开大阖，棒影漫天飞舞，棒风带得尘土纷飞，\n"HIC
            "犹如席卷落叶的狂风，以铺天盖地、势不可挡的气势，迎面直卷向$n！\n" NOR;
			
    message_vision(msg, me, target);  

    for(i=1;(i<=(extra-60)/30)&&(i<=8);i++)
    { 
        me->set_temp("lingshezhang",i);             
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
    }

    me->add_temp("apply/attack",-extra);
    me->add_temp("apply/damage",-extra/2);
    me->add("neili", -700);
    if (me->query("neili")<0) me->set("neili", 0);
    me->delete_temp("lingshezhang");
    me->start_busy(3+random(5));
    //恢复combat设置                                                
    //me->set("env/skip_combat",me->query_temp("combat_env"));        
    //target->set("env/skip_combat",target->query_temp("combat_env"));
    return 1;
}
mapping query_action(object me)
{
    string msg,msg1, msg2,msg3,msg4,msg5,msg6,msg7,msg8;
    object weapon=me->query_temp("weapon");
    int r = me->query_temp("lingshezhang");
    if(!weapon)
            return ([
                    "action": YEL"$N兵器既失，毫不慌乱，凌空又劈出一掌！"NOR,
                    "force": r * 30 + 150,
                    "dodge": - r * 3 + 20, 
                    "damage": r * 30,
            ]);
    msg1  =  YEL"$N身形趋退如神,在狂风中忽隐忽现,如同神龙翱翔天际！"NOR;
    msg2  =  YEL"$N如同恶魔般突如其来的从狂风中闪出，单手擎杖向$n当胸劈至！"NOR;
    msg3  =  YEL"$N收杖隐去,$n望着$N的背影刚出口长气,忽觉眼前一花,当面一张磨牙利口,却是$N蛇杖毒龙趁机反噬！"NOR;
    msg4  =  YEL"$N杖尾受力,身形已经腾在半空,$n仰头一望,$N信手一带长杖拦腰急扫,端的是险峻无伦！"NOR;
    msg5  =  YEL"人在半空，$N化虚为掌，化实为杖，偌大一条" + weapon->query("name") + YEL"竟然举重若轻,化为剑招凌空刺到！"NOR;
    msg6  =  YEL"$N持杖乱舞，密不透风，$n只觉对方手中有千百件兵器如山压力当胸压至呼吸都要停止了！"NOR;
    msg7  =  YEL"$N看到$n已经手忙脚乱,灵蛇杖法更是得心应手,出招连环,处处攻敌所必救！"NOR;
    msg8  =  YEL"$N领悟到了灵蛇杖法人蛇合一的境界,聚起天地之灵气，手中的"+ weapon->query("name") +YEL"卷起千层大浪风起云涌！\n$n在怒海波涛中如同一叶小舟颠簸翻覆,眼看就要淹没在$N无边的攻势中！"NOR;

    switch (r)
    {
            case 1: msg=msg1;break;
            case 2: msg=msg2;break;
            case 3: msg=msg3;break;
            case 4: msg=msg4;break;
            case 5: msg=msg5;break;
            case 6: msg=msg6;break;
            case 7: msg=msg7;break;
            case 8: msg=msg8;break;
    }

    return ([
            "action":msg,
            "force": r * 30 + 150,
            "dodge": - r * 3 + 20, 
            "damage": r * 30,
    ]);
}

