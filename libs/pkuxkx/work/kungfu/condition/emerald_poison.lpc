inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    int dur;
    message_vision(HIG"$N身体一阵颤抖，痛苦地哼了一声。混身经脉疼痛欲裂,扭结成怪异的肉筋.\n"NOR, me);

    if (duration>20) dur=20;

    //区分玩家和npc中毒效果，免得玩家太高了，npc又太弱了。  
    if ( userp(me) )
    {
		F_POISON->poison_eff(me,"emerald_poison",(["qi":({1,10 + duration*5 + random(10)}),"jing":({1,5 + duration*2 + random(10)}),]),1); 
	}
	else
	{
		F_POISON->poison_eff(me,"emerald_poison",(["qi":({1,10 + duration*10+ random(10)}),"jing":({1,5 + duration*5 + random(10)}),]),1); 
	}
	if (!random(3)) me->start_busy(1);
	me->apply_condition("emerald_poison", duration - 1);

	if( duration < 1 )
   	{
   		tell_object(me,HIG"你身上的毒性终于全部消失了。\n"NOR);
   		return 0;
   	}
	return CND_CONTINUE;
}
