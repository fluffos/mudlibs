// xiangfu-lun perform
// by iceland
// changed by emnil     2/7/2000
// changed by winter    4/19/2003
// fix by yhzzyahoo @2016.3.15 加强了一些附加str，命中增加了1个小级
#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#include "wushuai.h";

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg, limb, *limbs;
    int times,p,damage,x,h,t,lx,i,damage_base,pflv,eny=0,nlcost=0,rate_fix=0;
    object weapon, *enemy;
    mapping wp;
    string type,weapon_name;
    int uweapon_flag=0,uweapon_damage,cds;
    mapping attack_val = ([
        "base" : ([ "weapon" : "hammer", ]),//基本功夫类型
        "skill" : ([ "weapon" : "xiangfu-lun", ]),//高级技能名称
        ]);

    weapon = me->query_temp("weapon");
    x = me->query_skill("xiangfu-lun", 1)/4;
    h = me->query_skill("hammer", 1)/4;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) )
        return notify_fail("「天人五衰」只能对战斗中的对手使用。\n");

    if ( !objectp(weapon) ) return notify_fail("你必须在装备法轮时才能施展「天人五衰」！\n");

    type = weapon->query("skill_type");
    if( type!="hammer" ) return notify_fail("你必须在使用法轮时才能施展「天人五衰」！\n");

    // 判断是不是自制武器
    wp = copy(me->query("user_weapon"));
    if( wp&&wp["id"][0]== weapon->query("id") )
    {
        uweapon_flag=1;
        weapon_name=wp["name"];
        uweapon_damage = (int)wp["weapon_prop/damage"];
    }
    //      t = weapon->query_amount(); pkuxkx没有query_amount()，设计意图是看看手里拿着几个法轮决定发几招
    t = 5;
/*    if (me->query_skill_mapped("hammer") != "xiangfu-lun")
        return notify_fail("你必须激发降伏轮法才能施展「天人五衰」！\n"); */

    if(me->query_skill("xiangfu-lun", 1) < 380 )
        return notify_fail("你的降伏轮法还不够娴熟，使不出「天人五衰」绝技。\n");

    if(me->query_skill("longxiang-boruo", 1) < 260 )
        return notify_fail("你的龙象般若功尚未达到融会贯通的境界，无法使出「天人五衰」绝技。\n");

    if((int)me->query_skill("force") < 500 )
        return notify_fail("你的内功等级不够，使不出「天人五衰」绝技。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&
        me->query_skill_mapped("force") != "longxiang-boruo")
        return notify_fail("没有龙象般若功作为根基，是无法使出「天人五衰」绝技的！\n");

    if((int)me->query_str() < 40)
        return notify_fail("你的膂力还不够强劲，使不出「天人五衰」绝技。\n");

/*    if(me->query_skill_mapped("parry") != "xiangfu-lun")
        return notify_fail("「天人五衰」需要使用降伏轮法招架一切敌方攻击。\n"); */

    if((int)me->query("max_neili") < 5000 )
        return notify_fail("你内力修为尚浅，使不出「天人五衰」。\n");

    if( (int)me->query("neili") < 1000 )
        return notify_fail("你现在真气太弱，使不出「天人五衰」。\n");

    if( (int)me->query_temp("dalunsi/wushuai") > time() )
        return notify_fail("你刚刚使用过「天人五衰」，目下气血翻涌，无法再次施展。\n");

    //显示perform具体情况
    //me->set_temp("combat_env",me->query("env/skip_combat"));
    //me->set("env/skip_combat",0);
    //target->set_temp("combat_env",target->query("env/skip_combat"));
    //target->set("env/skip_combat",0);

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "大轮寺") 
		pflv=0;

    limbs = target->query("limbs");

    msg = HIY"\n只听“呜-呜-”之声大作，$N将手中法轮旋转掷出，使出「天人五衰」绝技！\n"NOR;
	
    cds=17-me->query_skill("longxiang-boruo", 1)/100;
	cds -= pflv;
	if (pflv==4) i=4;
	else if (pflv>=5) i=3;
	else i = 5;
    if ( cds<i ) cds=i;
    me->set_temp("dalunsi/wushuai", time()+cds);

    if(weapon->query("id") == "fenghuo lun")
    {
        me->set_temp("fhl", 1);
        me->add_temp("apply/damage", 150);
        me->add_temp("apply/attack", 150);
        t=5;
        msg+= HIR"$N手中风火轮发出灿灿佛光，化为金银铜铁铅五道光华，挟风带火，排山倒海般攻向$n！\n\n"NOR;
    }

    if(uweapon_flag==1)
    {
        me->set_temp("wushuai/uweapon", 1);
        me->add_temp("apply/damage", uweapon_damage);
        me->add_temp("apply/attack", uweapon_damage);
        t=5;
        msg+= HIR"$N手中"+weapon_name+HIR"发出灿灿佛光，化为金银铜铁铅五道光华，挟风带火，排山倒海般攻向$n！\n\n"NOR;
    }

    if(me->query_temp("xs/longxiang")) 
    {
        msg += MAG"$N更把龙象内劲附于兵刃之上，"+weapon->query("name")+MAG"通体流淌着异样的紫色光芒！\n"NOR;
        lx = me->query_skill("longxiang-boruo",1)/3;
        if(lx>200) lx=200;
        h = h/2;
        x = x/3;
    }
    else lx = 0;

    msg += "\n";
    message_vision(msg, me, target);
    me->add_temp("apply/strength", x);
    me->add_temp("apply/hammer", h);
	
    if(wizardp(me) && me->query("env/test"))
        tell_object(me,sprintf("lx:%d , str:%d , att:%d , damage:%d\n",lx,x,h,me->query_temp("apply/damage")));
	
    damage_base = (int)me->query_skill("xiangfu-lun",1) + (int)me->query_skill("longxiang-boruo",1);
	if (me->query_temp("longxiang.jingang"))
	{
		damage_base*=2;
		rate_fix=1;
	}
	else
	{
		damage_base*=5;
		damage_base>>=2;
	}
	
    i = 0;	
	// 设置该属性使得物理攻击不会触发对手的大挪移等特殊parry效果
	if (pflv>=4) me->set_temp("apply/invalid_target_special", 1); 
	enemy = me->query_enemy();
	
    for (times=0;times<t;times++) 
    {
        switch(times) 
        {
        case 0:
            msg=msga[random(sizeof(msga))];
            //命中率C
            if ( F_KUNGFU->hit_rate( me->query_skill("hammer", "xiangfu-lun"), target->query_skill("parry"), 7-rate_fix, me, target) ) 
			{
				damage = damage_base>>1;
				damage = damage + random(damage)*2*(100+lx)/100;
				F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
				if (pflv>=5) nlcost = -damage/9;
				else if (pflv==4) nlcost = -damage/7;
				else nlcost = -damage/6;
				me->add("neili", nlcost);
				msg += damage_msg(damage, "瘀伤");
				limb = limbs[random(sizeof(limbs))];
				msg = replace_string(msg, "$l", limb );
				message_vision(msg, me, target);
				COMBAT_D->report_status(target);
				i++;
				// 干掉一个，转换去攻击另外的对手。
				if (target->query("qi")<=0 && (pflv>=5 || (pflv==4 && eny<=0)) && sizeof(enemy)>1)
				{
					enemy -= ({ target });
					target = enemy[random(sizeof(enemy))];
					msg = HIW"$N伸手在"+weapon->query("name")+HIW"上一拨，"+weapon->query("name")+HIW"飞速旋转着改变了轨迹，直撞向了$n！\n"NOR;
					message_vision(msg, me, target);
					eny++;
				}
            }
            else {
				me->add("neili", -100);
				msg += msgd[random(sizeof(msgd))];
				message_vision(msg, me, target);
            }
            break;
        case 1:
			damage = me->query_temp("apply/damage")/3;
            me->add_temp("apply/damage", damage );
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            me->add_temp("apply/damage", -damage ); 
            me->add("neili", -100);
			if (target->query("qi")<=0 && (pflv>=5 || (pflv==4 && eny<=0)) && sizeof(enemy)>1)
			{
				enemy -= ({ target });
				target = enemy[random(sizeof(enemy))];
				msg = HIW"\n$N伸手在"+weapon->query("name")+HIW"上一拨，"+weapon->query("name")+HIW"飞速旋转着改变了轨迹，直撞向了$n！\n\n"NOR;
				message_vision(msg, me, target);
				eny++;
			}
            else message_vision("\n",me);
           break;
        case 2:
            msg=msga[random(sizeof(msga))];
            //命中率B-
            if ( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), 5-rate_fix, me, target) ) 
            {
				damage = damage_base>>1;
                damage = damage + random(damage)*3*(140+lx)/100;
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
				if (pflv>=5) nlcost = -damage/8;
				else if (pflv==4) nlcost = -damage/7;
				else nlcost = -damage/6;
				me->add("neili", nlcost);
                msg += damage_msg(damage, "瘀伤");
                limb = limbs[random(sizeof(limbs))];
                msg = replace_string(msg, "$l", limb );
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                i++;
				if (target->query("qi")<=0 && (pflv>=5 || (pflv==4 && eny<=0)) && sizeof(enemy)>1)
				{
					enemy -= ({ target });
					target = enemy[random(sizeof(enemy))];
					msg = HIW"$N伸手在"+weapon->query("name")+HIW"上一拨，"+weapon->query("name")+HIW"飞速旋转着改变了轨迹，直撞向了$n！\n"NOR;
					message_vision(msg, me, target);
					eny++;
				}
            }
            else 
            {
                me->add("neili", -150);
                msg += msgd[random(sizeof(msgd))];
                message_vision(msg, me, target);
            }
            break;
        case 3:
            me->add_temp("apply/hammer", me->query_skill("force")/5);
			damage = me->query_temp("apply/damage")/2;
            if(i==2) me->add_temp("apply/damage", damage );
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            if(i==2) me->add_temp("apply/damage", -damage );
            me->add_temp("apply/hammer", -me->query_skill("force")/5);
            me->add("neili", -100);
			if (target->query("qi")<=0 && (pflv>=5 || (pflv==4 && eny<=0)) && sizeof(enemy)>1)
			{
				enemy -= ({ target });
				target = enemy[random(sizeof(enemy))];
				msg = HIW"\n$N伸手在"+weapon->query("name")+HIW"上一拨，"+weapon->query("name")+HIW"飞速旋转着改变了轨迹，直撞向了$n！\n\n"NOR;
				message_vision(msg, me, target);
				eny++;
			}
            else message_vision("\n",me);
           break;
        case 4:
            msg=msga[random(sizeof(msga))];
            //命中率A-
            if ( F_KUNGFU->hit_rate( me->query_con()+me->query_str(), target->query_dex()*2, 3, me, target) ) 
            {
				damage = damage_base;             
				damage = damage + (random(damage)+200)*(2+random(2))*(180+lx)/100;
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
				if (pflv>=5) nlcost = -damage/6;
				else if (pflv==4) nlcost = -damage/5;
				else nlcost = -damage/4;
                me->add("neili", nlcost);
                msg += damage_msg(damage, "瘀伤");
                limb = limbs[random(sizeof(limbs))];
                msg = replace_string(msg, "$l", limb );
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
            }
            else 
            {
                me->add("neili", -150);
                msg += msgd[random(sizeof(msgd))];
                message_vision(msg, me, target);
            }
            break;
        }
        if ( !objectp(me->query_temp("weapon")) ) break;
    }

    if(me->query("neili")<0) me->set("neili",0);
    if(me->query("jingli")<0) me->set("jingli",0);

    if ( objectp(me->query_temp("weapon")) )
    {
        msg= HIY"\n$N抬手接住落下的法轮，气喘吁吁，犹如脱力一般，行动迟滞了许多。\n"NOR;
        message_vision(msg, me, target);
    }
	
    if (me->query_temp("fhl")){
    me->delete_temp("fhl");
    me->add_temp("apply/damage", -150);
    me->add_temp("apply/attack", -150);
    }
	
    if (me->query_temp("wushuai/uweapon")){
    me->delete_temp("wushuai/uweapon");
    me->add_temp("apply/damage", -uweapon_damage);
    me->add_temp("apply/attack", -uweapon_damage);
    }
	
    me->add_temp("apply/strength", -x);
    me->add_temp("apply/hammer", -h);
	if (pflv>=4) me->delete_temp("apply/invalid_target_special");
	
    me->start_busy(random(4)+1);
    me->start_perform(50,"天人五衰");

    return 1;
}
int help(object me)
{
        write(HIR"\n降伏轮之「天人五衰」：\n\n"NOR);
        write(@HELP
        当年密宗金轮法王横扫西域，威镇草原，一手藏密金刚降伏轮使得出神入化！
        此「天人五衰」绝技乃法王得意之作，全由龙象之力以御气操作！

        要求：  当前内力 1000 以上；
                最大内力 5000 以上；
                金刚降伏轮等级 380 以上；
                龙象般若功等级 260 以上；
                有效内功等级 500 以上；
                后天膂力 40 以上；
                激发内功为龙象般若功；
                激发锤法为金刚降伏轮；
                激发招架为金刚降伏轮；
                与上次出招间隔一定时间；
                且装备兵器。
HELP
        );
        return 1;
}
