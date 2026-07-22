// 离火身法

inherit SKILL;

string *dodge_msg = ({
	"$n轻轻一纵，使个「御火步」，避开了这一招。\n",
	"$N眼一花，$n使出「御火式」一个筋斗从$N头顶越过。\n",
	"$n一声：好！一招「踏火式」连翻几个筋斗，连影子都没了。\n",
	"$n左足一点，腾空而起，避了开去。\n",
	"但是$n身子轻轻飘了开去。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me) 
{ 
	int i;
	string *skills;
	skills = ({
		"wudu-shenzhang","shenghuo-spear","shenghuo-spear","shenghuo-spear",
	}); 
	if( me->query("public_skill/lihuo-dodge_abandon") )
		return notify_fail("你以前曾经学过离火身法，现在再也不能学习了。\n");
	if( (int)me->query_skill("dodge", 1) < 300)
                return notify_fail("你的基本轻功火候不够，无法练离火身法。\n");	
	for(i=0;i<sizeof(skills);i++)
	{
		if( me->query_skill(skills[i],2)>=1 )
			return notify_fail("你学过「"+to_chinese(skills[i])+"」，就无法再学「离火身法」了。\n");
		if( me->query("public_skill/"+skills[i]+"_abandon") )
			return notify_fail("你以前曾经学过「"+to_chinese(skills[i])+"」，再也不能学习「离火身法」了。\n");	
	} 
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够。\n");
	if( me->query_skill("lihuo-dodge",2)<150 )
		return notify_fail("你的「离火身法」还不够纯熟，光靠练是没用的。\n");		
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

string perform_action_file(string func) {
  	return CLASS_D("public") + "/lihuo-dodge/" + func;
}

string query_type(){ return "public";}