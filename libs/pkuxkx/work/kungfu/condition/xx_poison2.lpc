// 毒神附体下的毒掌毒

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	object *all_enemy,*enemy,env=environment(me);
	string victim="";
	int dushen,qi_damage,jing_damage,splash=0;
    if( duration < 1 )
    {
		me->delete("dushen_poison");
        me->delete_temp("death_cond_origin/xx_poison2");
        return 0;
    }

	if( !living(me) )
		message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	else
	{
		tell_object(me, HIB "忽然一阵刺骨的奇寒袭来，你中的"+cond_def["xx_poison2"]["name"]+"发作了！\n" NOR );
		if(environment(me) && environment(me)->query("real_dark") != 1)
	    {
    		message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
    			environment(me), me);
		}
	}
	
    me->set_temp("death_cond_id", "xx_poison2");
	dushen=me->query("dushen_poison");
	if (!dushen) dushen=100+random(100);
	qi_damage=dushen*3/5+random(dushen*2/5);
	jing_damage=dushen/3+random(dushen/3);
	F_POISON->poison_eff(me,"xx_poison2",(["qi":({1,qi_damage}),"jing":({1,jing_damage}),]),2+random(3)); 
	F_POISON->poison_eff(me,"xx_poison2",(["qi":({0,qi_damage*3/4+random(qi_damage/4)}),"jing":({0,jing_damage*3/4+random(jing_damage/4)})]),2+random(3)); 
	me->apply_condition("xx_poison2", duration - 1);
	all_enemy=all_inventory(env);
	all_enemy=filter_array(all_enemy, (: $1->query_temp($2) :), "dushen");
	all_enemy=filter_array(all_enemy, (: $1->is_fighting($2) :), me);
	if (sizeof(all_enemy)>0)
	{
		enemy=all_enemy[0]->query_enemy();
		if (enemy&&arrayp(enemy))
		for (int i=0;i<sizeof(enemy);i++)//传染
		{
			if (enemy[i]==me) continue;
			F_POISON->poison_attack(me,enemy[i],"xx_poison2",2+random(2));
			enemy[i]->set("dushen_poison",enemy[i]->query("dushen_poison")>me->query("dushen_poison")?enemy[i]->query("dushen_poison"):me->query("dushen_poison"));
			victim=enemy[i]->query("name");
			break;
		}
		if (victim!="") 
		if (!env->query("real_dark"))	
		message_vision(HBRED+HIW+"毒神附体之毒从$N"+HBRED+HIW+"扩散到场间"+victim+"等人身上。\n"NOR,me);
		else
		tell_object(all_enemy[0],HBRED+HIW+"毒神附体之毒从"+me->query("name")+HBRED+HIW+"扩散到场间"+victim+"等人身上。\n"NOR);
	}
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
