// Shenghuo-spear.c 圣火枪法
// Cracked by 凌惊雪 5-20-2003

inherit SKILL;

mapping *action = ({
//1
([      "action" : "$N微一反身，使出「天火燎原」，舞出万朵火花，只见红光闪闪，$n被罩入一片红光之中。\n",
	"parry_msg" : "结果$n$W舞出万朵火花，轰的一声将之格开。\n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//2
([      "action" : "$N狂喝一声，$w己泛起一道红芒，只见狂风大作，$N枪势一带，这招「火云敝日」摧枯拉朽，击向$n。\n",
	"parry_msg" : "结果$n$W泛起一道红芒，$p枪势一带，立刻将之架开。\n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//3
([      "action" : "$N使出一招「风火无边」，手中$w中宫直进，对准$n的$l刺出。\n",
	"parry_msg" : "结果$n使出一招「风火无边」，$W中宫直进将之格在一旁。\n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//4
([      "action" : "$N$w一抖，向$n脚下磋来，搅起一片尘土，这招「火烧连营」逼得$n连连后退，无处落脚。\n",
	"parry_msg" : "结果$n一招「火烧连营」，搅起一片尘土，逼得$N不得不收招回防。\n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//5
([      "action" : "$N使出一招「双龙吐焰」，手中$w一横，两道内力交叉攻向$n的$l。\n",
	"parry_msg" : "结果$n一招「双龙吐焰」，两道内力交叉逼得$N不得不收招回防。\n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//6
([      "action" : "$N使出一招「刀山火海」，$w向下斜戳，顿时万千道内力从四面八方攻向$n。\n",
	"parry_msg" : "结果$n一招「刀山火海」，顿时万千道内力从四面八方逼向$N，$P不得不收招回防。\n",
        "dodge" : -50,
        "parry" : -50,
        "damage" : 100,
        "damage_type" : "刺伤",
]),
//7
([      "action" : "$N使出一招「火内莲花」，双臂一并，手中$w带起一道道内劲如排山倒海般攻向$n。\n",
	"parry_msg" : "结果$n一招「火内莲花」，$W带起一道道内劲如排山倒海般将之挡开。\n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
//8
([      "action" : "$N使出一招「祝融怀焰」，$w一抖，枪影满天，吐雾遮三界，喷云照四方。\n",
	"parry_msg" : "结果$n一招「祝融怀焰」，$W枪影满天，将其格开。\n",
        "dodge" : -20,
        "parry" : -30,
        "damage" : 40,
        "damage_type" : "刺伤",
]),
});


int valid_enable(string usage) 
{ 
	return (usage == "spear") || (usage == "parry"); 
}

int valid_learn(object me)
{
	int i;
	string *skills;
	object ob;

	if( me->query("public_skill/shenghuo-spear_abandon") )
		return notify_fail("你以前曾经学过圣火枪法，现在再也不能学习了。\n");
        if((int)me->query_maxforce() < 500)
                return notify_fail("你的内力太弱，无法练「圣火枪法」。\n");
	if (!(ob = me->query_temp("weapon")) 
         || (string)ob->query("skill_type") != "spear" ) 
		return notify_fail("你必须先找一杆枪才能练枪法。\n");                 
	skills = ({
		"wudu-shenzhang","lieyang-jian","lihuo-dodge","wuhu-blade",
	}); 
	for(i=0;i<sizeof(skills);i++)
	{
		if( me->query_skill(skills[i],2)>=1 )
			return notify_fail("你学过「"+to_chinese(skills[i])+"」，就无法再学「圣火枪法」了。\n");
		if( me->query("public_skill/"+skills[i]+"_abandon") )
			return notify_fail("你以前曾经学过「"+to_chinese(skills[i])+"」，再也不能学习「圣火枪法」了。\n");	
	}               
        return 1;
}

mapping query_action(object me, object weapon)
{
	int i = me->query_temp("pfm-shenghuo");
	if( i<=0 )
	        return action[random(sizeof(action))];
	if( i>8 )
		i = 8;
	return action[i-1];
}

int practice_skill(object me)
{
        if((int)me->query("kee") < 60)
                return notify_fail("你的体力不够练「圣火枪法」。\n");
        if((int)me->query("force") < 50)
                return notify_fail("你的内力不够练「圣火枪法」。\n");
	if( me->query_skill("shenghuo-spear",2)<150 )
		return notify_fail("你的「圣火枪法」还不够纯熟，光靠练是没用的。\n");
        me->receive_damage("kee", 50);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("public") + "/shenghuo-spear/" + func;
}

string query_parry_msg(object weapon)
{
    return action[random(sizeof(action))]["parry_msg"];
}

string query_type(){ return "public";}