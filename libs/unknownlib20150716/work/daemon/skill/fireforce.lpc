// Fireforce.c 烈炎心法
// Cracked by 凌惊雪 6-2-2003

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1;}

int practice_skill(object me)
{
	if( (int)me->query("kee")<100 )
        	return notify_fail("你的体力太低了。\n");
	if( (int)me->query("force")<100 )
                return notify_fail("你的内力不够练烈炎心法。\n");
	if( me->query_skill("fireforce",2)<150 )
		return notify_fail("你的「烈炎心法」还不够纯熟，光靠练是没用的。\n");                
        me->receive_damage("kee",50);
        me->add("force",-100);
        return 1;	
}

string exert_function_file(string func)
{
	return CLASS_D("public") + "/fireforce/" + func;
}