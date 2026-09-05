// rose_poison.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    int loss;
    string *name=({"蛇毒","蛛毒","蟾蜍毒","蜈蚣毒","蝎子毒"});
    string *color=({HIG,HIW,HIY,HIB,RED});
    int i=random(sizeof(name));

	if( duration < 1 ) 
    {
        me->delete("五毒伤害");
        me->delete_temp("death_cond_origin/wudu_poison");
        return 0;
    }
	loss=me->query("五毒伤害");
    if (loss<=0)
    {
        loss=100+random(100);
    }

    me->set_temp("death_cond_id", "wudu_poison");
	F_POISON->poison_eff(me,"wudu_poison",(["qi":({0,loss}),"jing":({1,loss}),"neili":({2,-loss}),]),1); 
	me->apply_condition("wudu_poison", duration - 1);
	
    message_vision("$N瑟瑟发抖，身上的"+color[i]+name[i]+NOR+"发作了！\n",me);

	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

