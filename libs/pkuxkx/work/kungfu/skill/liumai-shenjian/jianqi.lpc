
#include <ansi.h>
#include <char.h>
inherit F_SSERVER;
inherit YIZHAOYUN;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int rate_level,agile_wt;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("「剑气纵横」只能对战斗中的对手使用。\n");

//        if( !me->query("feihua"))
//                return notify_fail("你的外功中没有这种功能。\n");

    if (base_name(environment(me))[0..10] == "/d/changbai")
            return notify_fail("这里气候奇寒无比，冻得你哆哆嗦嗦的，手脚都不灵光，也使不出来「剑气纵横」。\n");

    if( objectp(me->query_temp("weapon")) )
            return notify_fail("你必须空手才能施展「剑气纵横」！\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&  
       me->query_skill_mapped("force")!="beiming-shengong" )
        return notify_fail("必须激发北冥神功才能使出「剑气纵横」！\n");

    if ( me->query_skill("force", "beiming-shengong") < 500 )
            return notify_fail("你的北冥神功等级不够，无法施展「剑气纵横」。");

    if (me->query_skill("finger", "liumai-shenjian") < 500 )
            return notify_fail("你的六脉神剑等级不够，施展不出「剑气纵横」。\n");

    if ( (int)me->query_int()<50 )
            return notify_fail("你的悟性不够，一时之间还领悟不到六脉剑法纵横飞舞的诀窍。\n");

		if (me->query("neili")<2500||me->query("max_neili")<5000)
            return notify_fail("你的内力不够，无法施展「剑气纵横」。");
		
    msg = HIY "只见$N" HIY "全身真气激荡，双手各指接连疾点，一股股真气从指尖激射而出，嗤嗤嗤嗤声响不绝。\n";
	msg += HIY "一时少商、商阳、中冲、关冲、少冲、少泽六脉剑法纵横飞舞，使来得心应手，有如神助。\n";

    me->add_busy(4);
    //C-或者D-
    if ( target->query("combat_exp")/me->query("combat_exp")>=2 )
        rate_level=12;
    else
        rate_level=9;
     if(target->query_temp("special_skill/agile")>1)
	{
		agile_wt=(int)(target->query_temp("special_skill/agile")/5);
		rate_level += agile_wt;
	}

    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), rate_level, me, target) ) {
            msg += HIR"$n慌忙间躲过了数道剑气，胸前却门户洞开，被$P中宫直入，一指正中「膻中穴」。\n";
			msg += "只听$p“啊”的一声大叫，仰面翻跌下去，胸口一个小孔中鲜血激射而出，射得有两尺来高！\n" NOR;
            // target->set_temp("last_damage_from", me);
            message_vision(msg, me, target);
            // target->unconcious();
            yizhaoyun(target, me);
            me->add("neili",-500);
    } else {
            msg += HIW"$n手足无措，慌作一团，急忙伏地，使出形如“狗吃屎”的招数，狼狈不堪地躲过了这一击！\n" NOR;
            message_vision(msg, me, target);
            me->add("neili",-2500);
    }
    return 1;
}
