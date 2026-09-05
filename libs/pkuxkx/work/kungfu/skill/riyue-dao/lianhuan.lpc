// by whuan
// 2007-8-2

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
        
    string str;
    string dodskill,msg;
    string level;
    int effect;
    int extra; int tmp; 
    object weapon,ob; 
    mapping attack_val = ([
        "base" : ([ "weapon" : "blade", ]),//基本功夫类型
        "skill" : ([ "weapon" : "riyue-dao", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("［计出连环］只能对战斗中的对手使用。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("family/family_name")!="日月神教" && me->query("chushi/last_family")!="日月神教")
        return notify_fail("你不能使用这个绝招！\n");

    if( !objectp(ob = me->query_temp("weapon")) || ob->query("skill_type") != "blade" )
        return notify_fail("你必须先找一把刀才行。\n");

    tmp = me->query_skill("riyue-dao",1);
    extra = me->query_skill("blade",1);

    if (objectp(weapon = me->query_temp("secondary_weapon")) && weapon->query("id") == "riyue dao")
        extra=extra+random(extra/2);

    if ( extra < 100 ) return notify_fail("你的［基本刀法］还不够纯熟！\n");

    if ( tmp < 101) return notify_fail("你的［日月刀法］还不够纯熟！\n");

    if((int)me->query("max_neili") < 1000 ) return notify_fail("你的内功太差。\n");

    if((int)me->query("neili")<500) return notify_fail("你的内力不够了。\n");


    tmp /= 4;
    extra /= 4;
    me->add("neili",-(300+tmp));
    if ( me->query("riyuepfm/dao") && me->query("family/family_name")=="日月神教" )
    {
        message_vision(HIY+"$N暗运心法，手中神刀泛出异芒。\n"+NOR,me);
        extra = extra*5/4+random(extra/4);
    }
	else
	{
	  tmp = tmp*8/10;
	  extra = extra*8/10;
	}
    weapon = me->query_temp("weapon");
    me->add_temp("apply/attack",tmp);
    me->add_temp("apply/damage",extra);

    //显示perform具体情况
    //me->set_temp("combat_env",me->query("env/skip_combat"));
    //me->set("env/skip_combat",0);
    //target->set_temp("combat_env",target->query("env/skip_combat"));
    //target->set("env/skip_combat",0);


    if (me->query_skill("riyue-dao",1)>100)
    {
        if ( objectp(me->query_temp("weapon")) ) 
        {
            msg = BLINK""+HIR  "\n［浩月当空］$N手中"+weapon->query("name")+"直劈$n！" NOR;
            //      message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }

        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIY  "［阳春三月］$N手中"+weapon->query("name")+"斜刺$n！" NOR;
            //      message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }

        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIW  "［斗转星移］$N手中"+weapon->query("name")+"平削$n！" NOR;
            //      message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }
    }

    me->add_temp("apply/attack",tmp/4);

    if ( random(me->query_skill("riyue-dao",1))>120)
    {
        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIG  "［天地乍合］$N手中"+weapon->query("name")+"横砍$n！" NOR;
            //    message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }
    }

    if (random(me->query_skill("riyue-dao",1))>140)
    {
        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIC  "［霜色满地］$N手中"+weapon->query("name")+"反撩$n！" NOR;
            //    message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }
    }

    if (random(me->query_skill("riyue-dao",1))> 160)
    {
        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIR  "［阳光普照］$N手中"+weapon->query("name")+"加紧，旋风般向$n杀去！" NOR;
            //     message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }
    }

    if ( ( (me->query_skill("riyue-dao",1)> 550 && !random(3))||
    (me->query_skill("riyue-dao",1)>(1000-(int)me->query("int")*3)&&
    random(me->query_skill("riyue-dao",1))> 400) ) &&
    me->query("riyuepfm/dao") &&
    me->query("family/family_name")=="日月神教" )
    {
        effect = me->query_skill("blade");
    //    effect = effect*8/10;

        if(me->query_temp("jjf_set")) effect += effect/2;
        me->add_temp("apply/strength",effect/20);
        me->add_temp("apply/damage",effect/20);

        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIM  "［声东击西］$N手中"+weapon->query("name")+"虚劈，拐弯向$n剁去！" NOR;
            //       message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }

        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIY  "［以逸待劳］$N手中"+weapon->query("name")+"轻晃，写意般向$n挥去！" NOR;
            //       message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }

        if ( objectp(me->query_temp("weapon")) )
        {
            msg = BLINK""+HIG  "［擒贼擒王］$N手中"+weapon->query("name")+"排山倒海向$n舞去！" NOR;
            //       message_vision(msg, me, target);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
        }

        me->add_temp("apply/strength",-effect/20);
        me->add_temp("apply/damage",-effect/20);
    }

    msg = "\n" NOR;
    message_vision(msg, me, target);

    me->add_temp("apply/attack",-tmp/4);
    me->add_temp("apply/attack",-tmp);
    me->add_temp("apply/damage",-extra);
    //恢复combat设置
    //me->set("env/skip_combat",me->query_temp("combat_env"));
    //target->set("env/skip_combat",target->query_temp("combat_env"));
    me->add_busy(2+random(2));
    return 1;
}

