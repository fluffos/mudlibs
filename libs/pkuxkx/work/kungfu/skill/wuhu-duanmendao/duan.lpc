#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
	object weapon, ob, weapon2;
	string msg;
	string* action_name = ({ "白虎跳涧", "一啸风生", "剪扑自如", "雄霸群山", "伏象胜狮" });
    mapping attack_val = ([
            "base": ([ "weapon" : "blade" ]),//基本功夫类型
            "skill" : ([ "weapon" : "wuhu-duanmendao" ]),//高级技能名称
            ]);
	
	int i,j,hitp;
 if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("五虎断门刀「断」字决只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("blade",1) < 60 )
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

	if( (int)me->query_skill("wuhu-duanmendao",1) < 60 )
		return notify_fail("你的「五虎断门刀」还不到家，无法使用「断」字决！\n");

	msg = HIY "$N猛然伏地，使出「五虎断门刀」断字诀，顿时一片蓝光直向前滚去！\n" NOR;
	message_vision(msg,me,target);
	j = 1 + me->query_skill("wuhu-duanmendao",1)/120;

	if ( j > 5 )
		j=5;
// 增加一点攻击力，太惨不忍睹了。 by lordstar 
	me->add_temp("apply/attack", j*100);
	me->add_temp("apply/damage", j*50);

   //门派大招影响
	if (me->query_temp("active_force_buffer/cangming-gong.zhengqi") && me->query_temp("cmg/zhengqi/times") < me->query_temp("cmg/zhengqi/point")&& !me->query_temp("cmg_zq_buff"))
	{
		me->add_temp("apply/attack", j*250);
		me->add_temp("cmg/zhengqi/times",1);
		me->set_temp("cmg_zq_buff",1);
		me->add("neili",-j*6);
		msg = HIR "$N正气凛然，临战神勇！\n" NOR;
		message_vision(msg,me,target);

	}
	
    me->set_temp("attack_val", attack_val);
	for(i=1;i<j;i++)  // 第j刀单独进行 by lordstar 
	{
        if ( !objectp(weapon = me->query_temp("weapon")) ) break;
        me->set_temp("attack_val", attack_val);
		msg =  HIR "第"+chinese_number(i)+"刀："+ action_name[i-1] + "！" NOR;
		COMBAT_D->do_attack(me,target, weapon,TYPE_SPECIAL,msg);
	}

	msg =  HIR "第"+chinese_number(j)+"刀："+ action_name[j-1] + "！" NOR;
	hitp = COMBAT_D->do_attack(me,target, weapon,TYPE_SPECIAL,msg);
	if (hitp && me->query("family/family_name")=="天地会" && objectp(weapon2 = target->query_temp("weapon")))
	{
		msg = HIW"$N顺着这一刀的气势，使一个崩字诀，刀刃一翻，弹向$n！\n" NOR;
//命中率B- 因为最后一刀要砍中之后才有这个判断，所以这个概率不算高了。 by lordstar 2017/8/28
        if( F_KUNGFU->hit_rate( me->query_str(), target->query_str(), 6, me, target) ) 
		{
            msg += HIW"只听当的一声响，兵刃相击，$n手腕一麻，掌中"+weapon2->name()+HIW"再也把持不住，脱手而飞！\n" NOR;
			weapon2->add("rigidity", -1-random(4));
            weapon2->unequip();
            weapon2->move(environment(me));
            if (weapon2->query("unique") )
                 destruct(weapon2);
			weapon->add("rigidity", -1-random(4));
			if(weapon->query("rigidity") < 1)
			{
				msg += HIY "\n$N"+HIY+"手中的" + weapon->name() + HIY + "受力过剧，也在同一时间「啪」地一声断为两截！ \n\n" NOR;
				weapon->unequip();
				weapon->move(environment(me));
				weapon->set("name", "断掉的" + weapon->query("name"));
				if (!weapon->query("gem_ob_autoloaded"))
				{
					weapon->set("value", 0);
					weapon->set("weapon_prop", 0);
				} 
				destruct(weapon);
				me->reset_action();
        }			
		}
		else
			msg += HIC"$n识得厉害，急忙收招往回一缩，避开了锋芒！\n\n" NOR;
        message_vision(msg, me, target);
	}
	
	me->add_temp("apply/attack", -j*100);
	me->add_temp("apply/damage", -j*50);
	
	me->delete_temp("attack_val");

	if (me->query_temp("cmg_zq_buff"))
	{
		me->add_temp("apply/attack", -j*250);
		me->delete_temp("cmg_zq_buff");
	}
	me->add("neili", - (j * 50 + 50));
	me->start_busy(2+random(2));
	return 1;
}
