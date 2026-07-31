//仙风云体术 蜀山内功
inherit FORCE;
string type() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if( me->query("family/family_name") != "蜀山派" )
        	return notify_fail("仙风云体术只有蜀山的人才可以学。\n");
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够，还不能学习仙风云体术。\n");
	return 1;
}

int practice_skill(object me)
{
        return notify_fail("仙风云体术只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("shushan") + "/xianfeng-yunti/" + func;
}
