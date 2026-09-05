inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/chuanxin");
        return 0;
    }
    if( !living(me) ) 
    {
         message("vision", HIR+me->name() + "身上的伤口完全止不住血流。\n"+NOR, environment(me), me);
    }
    else 
    {
        tell_object(me, HIR "你身上的伤口汩汩地往外流着血！\n" NOR );
        message("vision", HIR + me->name() + "身上的伤口血如泉涌。\n"+NOR, environment(me), me);
    }
    me->set_temp("death_cond_id", "chuanxin");
	F_POISON->poison_eff(me,"chuanxin",(["qi":({0,me->query("max_qi")*duration/1000}),"qi":({1,me->query("max_qi")*duration/1000}),]),1); 
    me->apply_condition("chuanxin", duration - 1);

    return CND_CONTINUE;
}

string query_type(object me)
{
	return "injure";
}

