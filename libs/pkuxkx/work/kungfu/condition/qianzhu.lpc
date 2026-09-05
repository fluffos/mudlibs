// rose_poison.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    int loss;
    string *name=({"狼蛛毒","雪蛛毒","花蛛毒",});
    string *color=({HIB,HIW,HIM,});
    int i=random(sizeof(name));
	loss=(int)me->query_temp("千蛛万毒")*(int)me->query("千蛛万毒")*(5+random(5));

	if( duration < 1 ) 
    {
        me->delete_temp("千蛛万毒");
        me->delete_temp("qzwd");
        me->delete_temp("death_cond_origin/qianzhu");
        return 0;
    }
    if (loss<=0)
    {
        loss=10+random(10);
    }
    if (i==0)
    {
        me->set_temp("death_cond_id", "qianzhu");
		F_POISON->poison_eff(me,"qianzhu",(["jing":({1,loss/2}),]),1); 
    }
    if (i==1)
    {
        me->set_temp("death_cond_id", "qianzhu");
		F_POISON->poison_eff(me,"qianzhu",(["qi":({0,loss/2}),]),1); 
    }
    if (i==2)
    {
		F_POISON->poison_eff(me,"qianzhu",(["neili":({2,-loss}),]),1); 
    }
    me->apply_condition("qianzhu", duration - 1);
	if (me->query_condition("qianzhu")>15)
    {
        me->apply_condition("qianzhu",15);
    }
    message_vision("$N瑟瑟发抖，身上的"+color[i]+name[i]+NOR+"发作了！\n",me);

	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

