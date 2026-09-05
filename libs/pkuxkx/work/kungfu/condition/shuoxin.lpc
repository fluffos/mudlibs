// shuoxin

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    int qi;
    if( duration < 1 ) 
    {
        me->delete_temp("death_cond_origin/shuoxin");
        return 0;
    }

    if( !living(me) ) {
            message("vision",HIR+me->name()+HIR"皮肤变得红通通的，想被正火焰灼烧着一般。\n"NOR,environment(me), me);
    }

    else {
            tell_object(me, RED "你觉得浑身想被火焰灼烧般得钻心疼痛。\n" NOR );
            message("vision", HIR+me->name()+HIR"皮肤变得红通通的，想被正火焰灼烧着一般。\n"NOR,environment(me), me);
    }

    qi = me->query("max_qi")/20;
    if (qi>150) qi=150;
    if (qi<50) qi=50;
    me->set_temp("death_cond_id", "shuoxin");
	F_POISON->poison_eff(me,"shuoxin",(["qi":({1,qi}),"qi":({0,qi}),]),1); 
    me->apply_condition("shuoxin", duration - 1);

    if( random(10)>8 )
    F_POISON->poison_eff(me,"shuoxin",(["busy":({4,5})]),1);
    
    return CND_CONTINUE; 
}

string query_type(object me)
{
	return "injure";
}

