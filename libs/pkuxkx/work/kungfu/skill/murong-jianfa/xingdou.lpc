#include <ansi.h>
#include <skill.h>
#include <combat.h>
#include <weapon.h>

inherit F_SSERVER;
int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void xingdou(object me,object target,object weapon,int now);
int perform(object me,object target)
{
        object ob,weapon;
 
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) || !living(target)
         || environment(target)!=environment(me))
                return notify_fail("「满天星斗」只能对战斗中的对手使用。\n");
        if( me->query_temp("canshang") )
                return notify_fail("你已经在使用「参商指」了！\n");
        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("你的内功不是神元功，无法使用「满天星斗」！\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
//         || me->query_skill_mapped("sword") != "murong-jianfa")
                return notify_fail("你手里没有剑，无法使用「满天星斗」！\n");
/*        if(me->query_skill_mapped("parry") != "douzhuan-xingyi")
                return notify_fail("你的招架功夫不对，无法使用「满天星斗」！\n"); */
        if((int)me->query("max_neili") < 3000 )
                return notify_fail("你的内力修为不够，不能使用「满天星斗」！\n");
        if((int)me->query("neili") < 1200 )
                return notify_fail("你现在真气不足，不能使用「满天星斗」！\n");
        if((int)me->query("jingli") < 500 )
                return notify_fail("你现在精力不足，不能使用「满天星斗」！\n");
        if((int)me->query_temp("lianhuan"))
                return notify_fail("你正在使用「七剑连环指」！\n");
        if((int)me->query_temp("murong/xingdou"))                                            
                return notify_fail("你正在使用「满天星斗」！\n");    
        if((int)me->query_skill("sword", 1) < 230 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用「满天星斗」。\n");
        if( (int)me->query_skill("xingyi-zhang", 1) < 250 )
                return notify_fail("你的星移掌不够娴熟，无法施展出「满天星斗」。\n");
        if( (int)me->query_skill("canhe-zhi", 1) < 250 )
                return notify_fail("你的参合指不够娴熟，无法施展出「满天星斗」。\n");
        if( (int)me->query_skill("douzhuan-xingyi", 1) < 200 )
                return notify_fail("你的斗转星移不够娴熟，无法施展出「满天星斗」。\n");
        if( (int)me->query_skill("shenyuan-gong", 1) < 200 )
                return notify_fail("你的内功还未练成，不能使用「满天星斗」！\n");
        if( (int)me->query_skill("murong-jianfa", 1) < 250 )
                return notify_fail("你的剑法还未练成，不能使用「满天星斗」！\n");
/*        if( me->query_skill_mapped("finger") != "canhe-zhi" 
         || me->query_skill_prepared("finger") != "canhe-zhi")
                return notify_fail("你没有备参合指，无法使用「满天星斗」！\n");
        if(me->query_skill_mapped("strike") != "xingyi-zhang"
         || me->query_skill_prepared("strike") != "xingyi-zhang")
                return notify_fail("你没有备星移掌，无法使用「满天星斗」！\n");  */
        me->set_temp("murong/xingdou",1);
        message_vision(HIM"\n$N"HIM"想起复国大业，不禁激起壮志豪情，长啸一声，使出慕容绝技「满天星斗」！\n"NOR, me,target);
        me->add("neili", -100);
//      me->start_perform(10,"满天星斗");
        me->start_busy(2+random(2));
        call_out("xingdou",0,me,target,weapon,0);
        return 1;
} 
void xingdou(object me,object target,object weapon,int now)
{
        string msg,weaname,name;
        int lvl,force,damage,attack,qi;
string *xue_name = ({
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});
    mapping attack_val1 = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "murong-jianfa" ]),//高级技能名称
            ]);
    mapping attack_val2 = ([
            "base": ([ "no_weapon" : "finger" ]),//基本功夫类型
            "skill" : ([ "no_weapon" : "canhe-zhi" ]),//高级技能名称
            ]);
    mapping attack_val3 = ([
            "base": ([ "no_weapon" : "strike" ]),//基本功夫类型
            "skill" : ([ "no_weapon" : "xingyi-zhang" ]),//高级技能名称
            ]);
        name = xue_name[random(sizeof(xue_name))];

        if( !objectp(me) ) return;
        if (!weapon&&living(me))
        {
                        message_vision(HIC"\n$N"HIC"「满天星斗」运用完毕。\n"NOR, me);
                        return;
        }
        
            weaname = weapon->query("name");
        
        if( !objectp(target) || !me->is_fighting(target) || (now >= 6) || (me->query("neili")<200) ) {
                me->set_temp("murong/xingdou",0);
//              me->start_perform(5,"满天星斗");
                weapon->wield();
//              me->prepare_skill("strike")
//              me->prepare_skill("finger","canhe-zhi");
                if(living(me))
                        message_vision(HIC"\n$N"HIC"「满天星斗」运用完毕，复而抽剑出鞘。\n"NOR, me);
                return;
        }

        lvl = me->query_skill("murong-jianfa",1);
        force = me->query_skill("shenyuan-gong",1)+lvl;

        switch( now ) {
            case 0:
            case 1:
                msg = HIR"\n$N"HIR"微笑不语，伸指向剑尖一弹，"NOR+weaname+HIR"抖起五朵洁白的剑花，有急有缓，分别刺向$n"HIR"的"NOR+name+HIR"。\n"NOR;
				me->set_temp("attack_val", attack_val1);
                break;
            case 2:
//              me->prepare_skill("hand");
//              me->prepare_skill("strike");
//              me->prepare_skill("cuff");
//              me->prepare_skill("finger");
//              me->prepare_skill("leg");
//              me->prepare_skill("claw");
                weapon->unequip();
//              me->prepare_skill("strike","xingyi-zhang");
                msg = NOR+MAG"\n$N"MAG"收剑还鞘,双掌一搓，在双掌之间形成一个耀眼的「" + HIW"气旋"MAG + "」！\n" +
                  HIY"随即$N"HIY"移形换步，双掌收在胸前，闪电般将「" + HIR"日旋" + HIY"」击向$n"HIY"！\n"NOR;
				me->set_temp("attack_val", attack_val3);
                break;
            case 3:
                msg = HIC"\n$N"HIC"空中一个回转，携「"HIG"月旋"HIC"」, 双掌按向$n"HIC"的丹田！\n"NOR;
				me->set_temp("attack_val", attack_val3);
                break;
            case 4:
//              me->prepare_skill("strike");
//              me->prepare_skill("finger","canhe-zhi");
                msg = HIG"\n$N"HIG"化掌为指，指风轻飘飘地点向$n"HIG"周身大穴！\n"NOR;
				me->set_temp("attack_val", attack_val2);
                break;
            case 5:
                msg = HIB"\n$N"HIB"双手拇指一阵虚点，两道真气如剑一般刺向$n！\n"NOR;
				me->set_temp("attack_val", attack_val2);
                break;
        }

        attack = 6-now;
        damage = 6-now;
        me->add_temp("apply/damage", force/damage);
        me->add_temp("apply/attack", force/attack);
        if (present(target,environment(me)) && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
		else
				me->delete_temp("attack_val");
        me->add_temp("apply/damage", -force/damage );
        me->add_temp("apply/attack", -force/attack);

        me->add("neili", -50*now);
        if(me->query("neili") < 0) me->set("neili",0);
        now++;
        call_out("xingdou",0,me,target,weapon,now);
}

