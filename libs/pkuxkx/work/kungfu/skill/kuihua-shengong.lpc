//jiuyin-shenggong.c
//changed by lianxing

inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}
int practice_skill(object me)
{
	return notify_fail("葵花神功只能用学(learn)或读来增加熟练度。\n");
}

string exert_function_file(string func)
{
       return SKILL_D("kuihua-shengong/") + func;
}

void disable_skill(object me)
{
	string gm = exert_function_file("guangming");
	if (me->query_temp("daguangming/apply"))
		gm->remove_effect(me);
}
