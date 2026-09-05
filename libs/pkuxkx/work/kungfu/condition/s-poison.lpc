inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{

	if(duration < 1) return 0;	//原来没有此判断，导致吃了清新散apply_condition("s-poison",0)的效果被随后的random(8)取代
    duration=random(8);
    if( !living(me) )
    {
        message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
    }
    else
    {
        tell_object(me, BLU"断肠散的毒性发作了,你感觉腹中如刀绞一般，肝肠寸断。\n" NOR );
        message("vision", me->name() + "嘴角渗出一丝血迹，脸色苍白，双手捧腹，痛苦的呻吟着，似是中了断肠散之毒。\n",
                environment(me), me);
    }
	F_POISON->poison_eff(me,"s-poison",(["qi":({0,50}),"jing":({1,100}),]),1); 
    me->apply_condition("s-poison", duration);
    //if( duration < 1 ) return 0;  //依靠random(8)清零
    return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
