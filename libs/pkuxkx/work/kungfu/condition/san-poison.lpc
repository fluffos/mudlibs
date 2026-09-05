inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    duration=random(8);
    if( !living(me) )
    {
        message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
    }
    else
    {
        tell_object(me, BLU"断肠散的毒性发作了,你感觉腹中如刀绞一般，肝肠寸断。\n" NOR );
        message("vision", me->name() + "嘴角渗出一丝血迹，脸色苍白，双手捧腹，痛苦的呻吟着，似是中了断肠散之毒。\n", environment(me), me);
    }
	F_POISON->poison_eff(me,"san-poison",(["qi":({0,50}),"jing":({1,100}),]),1); 
    me->apply_condition("san-poison", duration - 1);
    if( duration < 1 ) return 0;
    return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
