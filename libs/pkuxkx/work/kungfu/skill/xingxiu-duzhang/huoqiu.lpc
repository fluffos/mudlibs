// huoqiu.c
#include <ansi.h>
#include <char.h>
#include <combat.h>
#include <armor.h> 
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

void remove_broken_cloth(object obj);
void overflow_attack(object me, object target, int damage, int rate);

int perform(object me, object target)
{
    string msg, *limbs;
    int i, neili, ap, dp, damage, p, makeash, rate, count, target_qi, pflv, flow_attack = 0;
    object ob, *inv;
	object ash, *enemy;
    mapping attack_val = ([
                            "base" : ([ "no_weapon" : "strike", ]), //基本功夫类型
                            "skill" : ([ "no_weapon" : "xingxiu-duzhang", ]), //高级技能名称
                           ]);

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("「火球」攻击只能对战斗中的对手使用。\n");

/*    if (objectp(me->query_temp("weapon")) && objectp(me->query_temp("secondary_weapon")))
        return notify_fail("你必须空手才能使用「火球」！\n"); */

    if ((int)me->query_skill("huagong-dafa", 1) < 180)
        return notify_fail("你的化功大法修为不够，无法使用「火球」进行攻击。\n");

    if ((int)me->query_skill("poison", 1) < 150)
        return notify_fail("你体内聚毒不够，无法使用「火球」进行攻击。\n");

    if ((int)me->query_skill("xingxiu-duzhang", 1) < 180)
        return notify_fail("你的星宿毒掌还不够娴熟，无法使用「火球」进行攻击。\n");

/*    if (me->query_skill_prepared("strike") != "xingxiu-duzhang"
        || me->query_skill_mapped("strike") != "xingxiu-duzhang"
        || me->query_skill_mapped("parry") != "xingxiu-duzhang")
        return notify_fail("你必须用星宿毒掌才能使用「火球」进行攻击。\n"); */

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "huagong-dafa" )
        return notify_fail("你所用的内功无法进行「火球」攻击。\n");

    if ((int)me->query("max_neili") < 2500)
        return notify_fail("你的内力修为太弱，无法驱动「火球」进行攻击。\n");

    if ((int)me->query("neili") < (200 + me->query("jiali") / 2))
        return notify_fail("你的内力太弱，使不出「火球」进行攻击。\n");

    ob = present("huo yan", environment(me));
    if (!me->query_temp("apply/xx_fire") && !objectp(ob))
        return notify_fail("没有火堆怎么驱动「火球」进行攻击？\n");

    me->set_temp("attack_val", attack_val);
    ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
    me->delete_temp("attack_val");

    dp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);

    if (target->is_busy())
        dp /= 2;
    if (ap < 1)
        ap = 1;
    if (dp < 1)
        dp = 1;
    damage = ((int)me->query_skill("xingxiu-duzhang", 1) + me->query("jiali")) * 4;
    if (ap < dp)
        damage -= random(damage / 3);
    if (ap > dp)
        damage += random(damage / 3);

    me->add("neili", -(200 + me->query("jiali") / 2));

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "星宿派") 
		pflv=0;
	enemy = me->query_enemy();

    msg = HIR"\n$N厉声大喝，掌力加盛，火焰中突然生出一个斗大的火球，在空中骨碌碌的迅速转动！\n"NOR;
    msg += HIR"\n火势随着旋转之势益发旺盛起来，只听嗤嗤两声轻响，爆出几朵火花，火球陡然变大向$n疾冲过来！\n" NOR;
    message_vision(msg, me, target);
    msg = "";
    //命中率级别C~C+
	rate = 8;
	if (me->query_temp("apply/xx_fire")) 
		rate -= 1;
    if (F_KUNGFU->hit_rate(ap, dp, rate, me, target))
    {
        if (!target->is_busy())
            target->start_busy(2);
        inv = filter_array(all_inventory(target), (:$1->query("equipped")=="worn":));
        inv -= ({0});
		makeash = 0;
        if (sizeof(inv) >= 1)
        {
            if (me->query("neili") > random(target->query("neili")) * 2)
            {
                if (me->query_str() / 3 * 2 > random(target->query_str()))
                {
                    msg += HIY"猛烈间火球温度飙升，火花迸射，将$p的护具碾成碎片！\n" NOR;
                    damage += random(damage) * 2;
                    damage -= target->query_temp("apply/armor");
                    for (i = 0; i < sizeof(inv); i++)
                    {
						if (inv[i]->query("no_burn_destroy")) 
						{
							if (stringp(inv[i]->query("no_burn_destroy")))
								msg += inv[i]->query("no_burn_destroy") + "\n" NOR;
							else
								msg += HIW + inv[i]->query("name") + HIW "抵挡住了烈火的灼烧！\n" NOR;
							continue; // 允许具备特殊属性的衣服不被烧毁
						}
                        inv[i]->unequip(); 
                        inv[i]->move(environment(target));
						if (inv[i]->query("armor_type")==TYPE_CLOTH)
						{
							if (!inv[i]->query("fire_burned"))
								makeash = 1;
                            inv[i]->unequip();
                            destruct(inv[i]);							
						}
						else
						{
                        if (objectp(inv[i]) && !inv[i]->query("gem_ob_autoloaded"))   //某些物品离开主人后自动消失
                        {
                            inv[i]->set("name", "粉碎的" + inv[i]->query("name"));
                            inv[i]->delete("value");
                            inv[i]->set("armor_prop", 0);
                            call_out("remove_broken_cloth", 60 + random(60), inv[i]);
                        }
                        else if (objectp(inv[i]) && inv[i]->query("gem_ob_autoloaded"))
                            remove_broken_cloth(inv[i]);
						}
                    }
					if (makeash)
					{
						ash = new("/clone/cloth/ash-cloth");
						ash->move(target);
						ash->wear();
					}			  
                }
//                                else {
//                                        msg += HIY"只见火球猛然升温，火花四溅，热力直透$p的护具！\n" NOR;
//                                        damage += random(damage);
//                                        damage -= target->query_temp("apply/armor");
//                                        for(i=0; i<sizeof(inv); i++){
//                                                inv[i]->set("name", "碎裂的" + inv[i]->query("name"));
//                                                inv[i]->set("value", 49);
//                                                if(inv[i]->query("armor_prop/armor"))
//                                                        inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
//                                        }
//                                }
//                                target->reset_action();
            }
            else
            {
                msg += HIY"火球急速滚动，火光四溅，掀起阵阵火焰撞向$p怀里！\n" NOR;
            }
			target_qi = target->query("qi");
            F_KUNGFU->hit_wound("qi", damage, damage / 2, me, target);
 			if (pflv >=5 && sizeof(enemy) > 1 && (int)target->query_temp("combat/qi_damage") > target_qi)
				flow_attack = (int)target->query_temp("combat/qi_damage") - target_qi;
       }
        else
        {
            //target has no armor, so, hehe...
            if (neili > target->query("neili") / 2 * 3)
                damage += random(damage);
            else if (neili < target->query("neili") / 3 * 2)
                damage -= random(damage / 2);
            else if (neili > target->query("neili") * 2)
                damage *= 3;
            damage += random(damage);
			target_qi = target->query("qi");
            F_KUNGFU->hit_wound("qi", damage, damage / 2, me, target);
 			if (pflv >=5 && sizeof(enemy) > 1 && (int)target->query_temp("combat/qi_damage") > target_qi)
				flow_attack = (int)target->query_temp("combat/qi_damage") - target_qi;
        }
        msg += damage_msg(damage, "砸伤");
        limbs = target->query("limbs");
        msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
        msg = replace_string(msg, "$w", RED"火球"NOR);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);		
		if (flow_attack>0)
			overflow_attack(me, target, flow_attack, rate);
    }
    else
    {
        if (!target->is_busy())
            target->start_busy(2);
        msg += HIY"\n$p眼看就要被打中，冒死一个“铁板桥”，全身自膝盖处向后倒去，堪堪避过火球"HIY"！\n" NOR;
        message_vision(msg, me, target);
    }

	if (me->query_temp("apply/xx_fire") && !me->query_temp("huoqiu_multi_attack"))
	{
		count = sizeof(enemy);	
		if (count>1 && random(2) && (int)me->query("neili") > (500 + me->query("jiali") / 2) )
		{
			enemy -= ({target});
			message_vision(HIM"\n$N肩上的"HIG"幽"HIB"冥"HIR"火焰"HIM"中爆出一朵火花，$P顺势一引，再度挥出一掌！\n"NOR, me);
			me->set_temp("huoqiu_multi_attack", 1);
			perform(me, enemy[random(sizeof(enemy))]);
			me->delete_temp("huoqiu_multi_attack");
		}
	}
		
    me->start_busy(2+random(2));

    return 1;
}

void overflow_attack(object me, object target, int damage, int rate)
{
	object *enemy;
	object ntarget;
	int i, count, ap;
	if (!objectp(me) || !objectp(target) || damage <=0 ) return ;
	enemy = me->query_enemy();
	enemy -= ({ target });
	count = sizeof(enemy);
	if (count<=0) return;
	ap = (int)me->query_skill("strike","xingxiu-duzhang");
	damage = damage*(6+random(3))/10;
	if (count==1 || damage < 500 || random(2))	// 溢出攻击单一目标
	{
		if (count==1)
			ntarget = enemy[0];
		else 
			ntarget = enemy[random(count)];
		message_vision(HIR"火球从$N身上狠狠碾过，只略变小了一些，去势不衰，又对着$n砸了过去！\n"NOR, target, ntarget);
		if (F_KUNGFU->hit_rate(ap, (int)ntarget->query_skill("dodge"), rate+1, me, ntarget))
		{
			message_vision(HIM"$N一时措手不及，眼看着火球掀起阵阵火焰撞入怀中，轰的一声炸裂开来！\n"NOR, ntarget);
			F_KUNGFU->hit_wound("qi", damage, damage / 2, me, ntarget);
			COMBAT_D->report_status(ntarget);	
		}
		else
		{
			message_vision(HIY"$N眼看就要被打中，冒死一个“铁板桥”，全身自膝盖处向后倒去，堪堪避过火球！\n" NOR, ntarget);
		}
	}
	else
	{
		message_vision(HIR"火球撞在$N身上，轰的一声炸裂开来，碎成一片火花，向在场的其他人劈头盖脸地洒了过去！\n"NOR, target);
		while (sizeof(enemy)>4)
		{
			enemy -= ({ enemy[random(sizeof(enemy))] });
		}
		count = sizeof(enemy);
		damage /= count;
		for (i=0; i<count; i++)
		{
			if (F_KUNGFU->hit_rate(ap, (int)enemy[i]->query_skill("dodge"), rate-1, me, enemy[i]))
			{
				message_vision(HIM"火花洒在$n身上，发出呲呲数声，冒起滚滚紫烟，痛得$p连声惨叫！\n"NOR, me, enemy[i]);
				F_KUNGFU->hit_wound("qi", damage, damage / 2, me, enemy[i]);
				COMBAT_D->report_status(enemy[i]);	
			}
			else
				message_vision(HIY"$N急忙向后疾跃，堪堪避过了过去！\n" NOR, enemy[i]);
		}
	}
}

void remove_broken_cloth(object obj)
{
    if (obj && environment(obj))
    {
        tell_object(environment(obj), "一阵微风吹过，" + obj->name() + "化为片片飞尘，消失不见了。\n");
        destruct(obj);
    }
}

