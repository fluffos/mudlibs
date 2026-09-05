inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/yf_condition");
        return 0;
    }

    if( !living(me) ) {
      message("vision", me->name() + "痛苦地蠕动了一下，嘴里哼哼着『痒！痒死我了！』。\n", environment(me), me);
    }
    else {
      tell_object(me, HIG "你忽然感觉被玉蜂针射中的地方一阵奇痒，不禁用手去挠，哪知一挠之下剧痛无比，你痛苦地嚎叫起来！\n" NOR );
      message("vision",HIG + me->name() + "挠了挠身上，突然杀猪般地嚎叫起来！\n" + NOR,
            environment(me), me);
    }
    me->set_temp("death_cond_id", "yf_condition");
	F_POISON->poison_eff(me,"yf_condition",(["qi":({0,25+random(50)}),"jing":({1,30+random(50)}),]),1); 
    me->apply_condition("yf_condition", duration - 1);

    return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}


