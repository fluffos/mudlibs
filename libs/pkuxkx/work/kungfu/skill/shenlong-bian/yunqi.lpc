//whuan
//神龙鞭的绝招-云起龙骥

#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;
#define Menpai "神龙教"

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg, tparryskill;
    int mjianb, mjianh,mjianl,tjianl, tparryb, tparryh, mneili, tneili, mexp, texp, damage;
    object weapon,tweapon;

    weapon = me->query_temp("weapon");
    mjianb= (int)me->query_skill("whip",1);
    mjianh= (int)me->query_skill("shenlong-bian",1);
    mjianl= (int)me->query_skill("literate",1);
    mneili = (int)me->query("neili");
    mexp = (int)me->query("combat_exp");
    msg = "";

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「云起龙骥」只能在战斗中使用。\n");

    if( !objectp(weapon) || (string)weapon->query("skill_type")!="whip" )
        return notify_fail("不拿鞭子怎使「云起龙骥」？\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
        me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1))
        return notify_fail("你的师傅会「云起龙骥」吗？\n");

    if( me->query_skill("shenlong-xinfa",1) < 100 )
            return notify_fail("你的神龙心法功力不足，不能使用云起龙骥。\n");

    if ( mjianh < 80) return notify_fail("你的神龙鞭还不够火候！\n");

    if ((int)me->query("neili")<300) return notify_fail("你的内力不够。\n");

    tweapon = target->query_temp("weapon"); 
    tparryb= (int)target->query_skill("parry",1);
    tjianl= (int)target->query_skill("literate",1);
    tneili = (int)target->query("neili");
    texp = (int)target->query("combat_exp");
    tparryskill = target->query_skill_mapped("parry");
    tparryh=target->query_skill(tparryskill,1);
    me->add("neili",-300);
    me->receive_damage("qi", 20);
    message_vision(HIC"$N招式一变，抖动手中"+weapon->name()+HIC"，正是神龙鞭法的绝学--「云起龙骥」！\n" NOR,me,target);        
    message_vision(HIM"$N向前迈一步，平无华地挥出一鞭，慢，却噼啪作响。\n"NOR,me);

    //命中率A+&B+&未知
    if ( F_KUNGFU->hit_rate( mexp, texp, 1, me, target)
         && F_KUNGFU->hit_rate( mneili, (int)tneili, 4, me, target )
         && (int)me->query("max_neili") + mneili > (int)target->query("max_neili") + random(tneili/2) ) 
    {
        msg = HIC"$n只觉得一股劲气象化作漫天鬼影！\n"
                        "“哇”的一声，$n喷出一大口鲜血，看来是受了内伤！\n"NOR;
        damage= (int)(((int)me->query("max_neili")-  (int)target->query("max_neili")/3)/4);
 
        if(damage<100) damage = 100;
        if(damage>1600) damage=1600;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    }
    else
    {
        msg = HIC"$n忙运功向抗，深厚的内力将$N的漫天鬼影都激散了。\n"NOR;
        message_vision(msg, me, target);
    }

    message_vision(HIM"$N四两拨千斤，脚踏奇门，鞭走奇招，每一鞭从$n意想不到的方位无声无息地挥出！\n" NOR,me,target);
    //命中率A&C-=D/2+D+/2
    if( F_KUNGFU->hit_rate( mexp, texp, 2, me, target) && 
          F_KUNGFU->hit_rate( (int)(mjianb + mjianh*3)/2, (int)(tparryb+tparryh), 9, me, target) )
    {
        msg = HIC"$n马上手忙脚乱，不知该如何去招架这灵蛇般的鞭法！\n"
          "果不然，$N的"+weapon->name()+HIC"招招命中，$n浑身上下被抽得遍体鳞伤！\n"NOR;
        damage=random(mjianh)+me->query("jiali");               
        if(damage<100)damage = 100;
        if(damage>2000) damage=2000;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    }
    else 
    {
        msg = HIC"$n却心静如水，丝毫不显慌乱，见招拆招，瓦解了$N这无声的攻势。\n"NOR;
        message_vision(msg, me, target);
    }
    message_vision(HIM"$N突然收住身形，回步而立，收鞭于背后，无招胜有招，无形胜有形。\n"NOR,me);

    //命中率C-，不低于15%
    if( F_KUNGFU->hit_rate( (2*mexp/3 + texp/3), texp, 9, me, target) )  //tonii,03-5-15
    {
        msg = HIC"$n果然上当，以为$N露出破绽，大喜之下，急忙上前想抢攻。\n"
          "$N微微一笑，待$n靠近，长袖一抖，袖尽鞭出，直探$n的胸口。\n"
          "$n连鞭影还没看到，就差点儿被穿的透心凉！\n"NOR;
        damage=(int)(random(mjianh)+me->query("jiali")*2);          
        if(damage<100)damage = 100;
        if(damage>2400) damage=2400;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    }
    else
    {
        msg = HIC"$n看破了这招的虚实，将计就计，假装冲上前，却在$N出招的一瞬间腾空而起，避过了一击！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
    }

    message_vision(HIM"$N突然收鞭于背后，念念有词。\n"NOR,me);
    //命中率B-
    if( F_KUNGFU->hit_rate( mjianl, tjianl, 6, me, target) )
    {
        msg = HIC"$n以为$N露出破绽，有机可乘，急急攻了上来。\n"
         "$N微微一笑，待$n靠近，舞动长鞭，直探$n的脸部。\n"
         "$n顿时目瞪口呆，死了过去！\n"NOR;
        damage=(int)( mjianh + me->query("jiali") + random(me->query("jiali")));

        if(damage<100) damage = 100;
        if(damage>3000) damage=3000;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    }
    else
    {
        msg = HIC"$n识得此招，将计就计，假装冲上前，一瞬间腾空而起，攻出毕生绝学！\n"NOR;
        message_vision(msg, me, target);        
    }
    me->start_busy(2+random(2));
       
    return 1;
}

