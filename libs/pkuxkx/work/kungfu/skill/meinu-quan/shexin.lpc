// shexin.c 摄心
#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        int affect,skill,busytime,app;
        string msg;
        mapping attack_val = ([
            "base": ([ "no_weapon" : "cuff" ]),//基本功夫类型
            "skill" : ([ "no_weapon" : "meinu-quan" ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「摄心」只能对战斗中的对手使用。\n");

        if( me->query_skill("meinu-quan", 1) < 150 )
                return notify_fail("你的美女拳法还不够纯熟，无法施展「摄心」绝技。\n");

        if( me->query_skill("yunu-xinfa", 1) < 150 )
                return notify_fail("你的玉女心法等级不够，无法施展「摄心」绝技。\n");
                
/*        if( me->query_skill_mapped("parry") != "meinu-quan" )
                return notify_fail("你没有使用美女拳法作为招架！\n"); */

        if( objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")) )
                return notify_fail("你手持武器，如何使用「摄心」绝技？\n");

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_SEX) &&  
           me->query("gender") != "女性" && !wizardp(me) )
                return notify_fail("你不是女性，如何施展「摄心」绝技？\n");        
        
        if( target->query("gender") == "女性")
                return notify_fail("你不能对女性施展「摄心」绝技。\n");          

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你内力不够，无法使用「摄心」绝技。\n");
                
        if( me->query("max_neili") < 1500 )
                return notify_fail("你的内力修为不够，无法使用「摄心」绝技。\n");

        affect = me->query_per()+random(me->query("per"));
        skill = me->query_skill("meinu-quan", 1);

        me->add("neili",-100);
        me->start_busy(1+random(2));
        if ( target->query_skill("buddhism") > (skill+affect)
            || target->query_skill("daoxue-xinfa") > (skill+affect)  // 修改拼写错误：没有 daojia-xinfa 这样的技能 by lordstar 2017-8-28
            || target->query_skill("taoism") > (skill+affect) ){
                msg = HIY"\n$N对$n轻轻一笑，眼光之中流露出妩媚之意，想施展「摄心」绝技。\n"+
                        HIW"不料$n定了定神，突然大喝一声，顿时把$N惊出一身冷汗。\n"NOR;
                message_vision(msg,me,target);
                me->start_busy(4);
        }
        else if (target->query_per()>=me->query_per()){
                msg = HIY"\n$N忽然对$n轻轻一笑，眼光四处流动，所经过之处似乎充满了妩媚。\n"NOR; 
                message_vision(msg, me, target);
                message_vision(HIW"但是$N沮丧地发觉，$n比自己漂亮，身处「摄心」之下仍无动于衷。\n"NOR,me,target);
                me->start_busy(3);
        }
//命中率级别是B+&B+，也就是C级
//这里有bug，不过懒得改了by yhzzyahoo
        else if ( F_KUNGFU->hit_rate(me->query_per(), target->query_per(), 5, me, target) &&
                  me->query("combat_exp")>target->query("combat_exp")/4 ){
                msg = HIY"\n$N忽然对$n轻轻一笑，眼光四处流动，所经过之处似乎充满了妩媚！\n"NOR; 
                message_vision(msg, me, target);
                if(!target->is_busy()){
                        message_vision(HIW"$n两眼直勾勾地看着$N，身处「摄心」妩媚之中不能自拔！\n"NOR,me,target);
                        busytime = random(me->query_per());
                        if (busytime < 2) busytime = 2;
                        if (busytime > 20) busytime = 20;
                        F_KUNGFU->hit_busy( "confuse", busytime, target );
                } 
                else{
                		if (me->query_per() < 40)
                			app = skill*me->query_per()/20;
                		else app = skill * to_int(sqrt(to_float(me->query_per()))) * 6 /20;  //容貌高于40的时候增长曲线减缓
						if (app > 12000)
						{
							app = 12000;
						}
                        message_vision(CYN"\n$n眼睛一愣，不由走了下神，$N乘机连出数招。\n"NOR, me, target);
                        //target->add_temp("apply/dexerity", -affect);
                        me->add_temp("apply/attack", app);
                        me->add_temp("apply/damage", app);
                        me->set_temp("attack_val", attack_val);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
                        me->set_temp("attack_val", attack_val);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
                        me->set_temp("attack_val", attack_val);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
                        me->add_temp("apply/attack", -app);
                        me->add_temp("apply/damage", -app);
                        //target->add_temp("apply/dexerity", affect);
                }
        }
        else{
                msg = HIY"\n$N忽然对$n轻轻一笑，想施展「摄心」绝技。\n"+ HIM"谁知$n根本就没有上当。\n"NOR; 
                message_vision(msg, me, target);                
                me->start_busy(2+random(2));
        }
                   
        return 1;
}

