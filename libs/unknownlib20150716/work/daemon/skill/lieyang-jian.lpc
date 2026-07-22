// Lieyang-jian.c 烈阳剑法
// Cracked by 凌惊雪 4-13-2003

inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「水深火热」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l。\n",
	"parry_msg" : "结果$n手中$W嗡嗡微振，将之轻松震开。\n",
	"force" : 20,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "水深火热",
	"damage_type":	"割伤"
]),
([	"action":"$N错步上前，使出「闪电惊虹」，手中$w划出一道剑光劈向$n的$l。\n",
	"parry_msg" : "结果$n手中$W划出一道剑光，将之斜斜架开。\n",
	"force" : 30,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "闪电惊虹",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w一抖，一招「日在九天」，斜斜一剑反腕撩出，攻向$n的$l。\n",
	"parry_msg" : "结果$n斜斜一剑反腕撩出，将其架在一旁。\n",
	"force" : 20,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "日在九天",
	"damage_type":	"割伤"
]),
([	"action":"$N手中剑锵啷啷长吟一声，一式「火色烈阳」，一道剑光飞向$n的$l。\n",
	"parry_msg" : "结果$n一式「火色烈阳」，逼得$N无功而返。\n",
	"force" : 30,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "火色烈阳",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「怒剑骄阳」，手中$w舞出无数剑花，使$n难断虚实，无可躲避。\n",
	"parry_msg" : "结果$n一式「怒剑骄阳」，逼得$N慌忙换招。\n",
	"force" : 25,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "怒剑骄阳",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式「九弧震日」，对准$n的$l斜斜击出。\n",
	"parry_msg" : "结果$n一式「九弧震日」，震得$N$w斜斜歪开。\n",
	"force" : 30,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "九弧震日",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「风火连天」，手腕急抖，挥洒出万点金光，刺向$n的$l。\n",
	"parry_msg" : "结果$n一式「风火连天」，万点金光将其卸在一旁。\n",
	"force" : 20,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "风火连天",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式「天火直下」，$w飞斩盘旋，如疾电般射向$n的胸口。\n",
	"parry_msg" : "结果$n一式「天火直下」，$N无奈之下，只得撤招回防。\n",
	"force" : 35,
        "dodge" : -20,
        "parry" : -10,
	"damage": 50,
	"skill_name" : "天火直下",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) 
{ 
	return (usage == "sword") || (usage == "parry");
}

int valid_learn(object me)
{
	int i;
	string *skills;
	object ob;
	if( me->query("public_skill/lieyang-jian_abandon") )
		return notify_fail("你以前曾经学过烈阳剑法，现在再也不能学习了。\n");
	if ((int)me->query("force") < 100)
   		return notify_fail("你的内力不够。\n");
    	if ((int)me->query_skill("force", 1) < 10)
   		return notify_fail("你的内功火候太浅。\n");
	if (!(ob = me->query_temp("weapon")) 
         || (string)ob->query("skill_type") != "sword" ) 
		return notify_fail("你必须先找一把剑才能练剑法。\n"); 
	if( (int)me->query_skill("sword", 1) < 300)
                return notify_fail("你的基本剑术火候不够，无法练烈阳剑法。\n");		
	skills = ({
		"wudu-shenzhang","shenghuo-spear","lihuo-dodge","shenghuo-spear",
	}); 
	for(i=0;i<sizeof(skills);i++)
	{
		if( me->query_skill(skills[i],2)>=1 )
			return notify_fail("你学过「"+to_chinese(skills[i])+"」，就无法再学「烈阳剑法」了。\n");
		if( me->query("public_skill/"+skills[i]+"_abandon") )
			return notify_fail("你以前曾经学过「"+to_chinese(skills[i])+"」，再也不能学习「烈阳剑法」了。\n");	
	}    		
    	return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("PERFORM_LIEYANG");
	if( i<=0 )
		i = random(8)+1;
	if( i>8 )
		i = 8;	
	return action[i-1];
}  
      
int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||  (int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习烈阳剑法。\n");
	if( me->query_skill("lieyang-jian",2)<150 )
		return notify_fail("你的「烈阳剑法」还不够纯熟，光靠练是没用的。\n");		
	me->add("kee", -30);
	me->add("force", -3);
	return 1;
}

string perform_action_file(string func) {
  	return CLASS_D("public") + "/lieyang-jian/" + func;
}

string query_parry_msg(object weapon)
{
    return action[random(sizeof(action))]["parry_msg"];
}

string query_type(){ return "public";}