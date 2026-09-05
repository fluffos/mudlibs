// 西域怪蛇毒

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    int dam_qi, dam_jing, max_dq, max_dj, pflv;

    if( duration < 1 )
	{
		me->delete_temp("death_cond_origin/btgs_poison");
		me->delete_temp("btgs_poison/pflv");
        return 0;
    }

    if( !living(me) ) 
    {
        message("vision", MAG + me->name() + MAG "浑身溃烂，伤口处流淌出黑黄色的汁液。\n" NOR, environment(me), ({me}));
    }
    else 
    {
		tell_object(me, MAG "你忽然四肢僵直，浑身上下都不听使唤，你中的西域怪蛇毒发作了！\n" NOR );
		message("vision", MAG + me->name() + MAG "忽然满面堆欢，裂嘴嘻笑，显得诡异无伦。\n" NOR, environment(me), ({me}));
    }

	pflv = (int)me->query_temp("btgs_poison/pflv");
	
	dam_qi = 100;
	max_dq = (int)me->query("max_qi")/100;
	if (pflv>0)
		max_dq = max_dq * (pflv+random(pflv+1));
	if (dam_qi<max_dq) dam_qi = max_dq;
	
	dam_jing = 100;
	max_dj = (int)me->query("max_jing")/100;
	if (pflv>0)
		max_dj = max_dj * (pflv+random(pflv+1));
	if (dam_jing<max_dj) dam_jing = max_dj;
	
    me->set_temp("death_cond_id", "btgs_poison");
	F_POISON->poison_eff(me,"btgs_poison",(["qi":({1,dam_qi}),"jing":({1,dam_jing}),"busy":({4,2})]), 1); 
	
	me->apply_condition("btgs_poison", duration - 1);
    return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}