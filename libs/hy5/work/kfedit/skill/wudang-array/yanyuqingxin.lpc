#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	string *style = ({
HIR"花雨奇蝶－－$N手持$w，前进中一阵急骤，如雨蝶般刺向$n！"NOR,
HIB"风云行天－－$N反手握住$w化做一道惊虹，罩住$n全身，令其动弹不得！"NOR,
HIY"欲擒故纵－－$N向前一纵，略退半步，突然一个急进，带着手中$w向$n猛扑过去！"NOR,
HIG"月誉枫牵－－$N突身，互换，刺进，$w，齐出，分打$n的两处要害！"NOR});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［烟雨清心］只能对战斗中的对手使用。\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("只有队伍领袖才可以发动此式！\n");
	if(me->query_skill_mapped("array") != "wudang-array") 
		return notify_fail("你的队伍没有用四象两仪阵！\n");
	if(me->query_skill("wudang-array",1)<sizeof(obs)*20)
		return notify_fail("你的阵法不够！\n");
	if(sizeof(obs) >=4 )
		return notify_fail("队伍最多四个人！！\n");
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("你需要从新组合队伍。\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("你队伍成员不全在你身边。\n");
	if(!obs[i]->query_skill("wudang-array",1)) return notify_fail("你队伍中有人不会四象两仪阵。\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
	if(ob->query("skill_type") != "sword") return notify_fail("你的队伍中有人没有用剑法！\n");
	if(obs[i]->query_skill_mapped("array") != "wudang-array") return notify_fail("你的队伍中有人没有用四象两仪阵法！\n");
	}	
	message_vision(HIG+"只见$N轻身而退，与众人排成四象两仪阵法，企图用[烟雨清心]来击退$n！！\n"NOR,me,target);
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = style[i];
	extra = obs[i]->query_skill("sword");
	extra *= (i+1);	
        obs[i]->add_temp("apply/attack", extra);
        obs[i]->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	obs[i]->kill_ob(target);	
	obs[i]->add_temp("apply/attack", -extra);
	obs[i]->add_temp("apply/damage", -extra);
	obs[i]->start_busy(2);
	}
	return 1;
}
