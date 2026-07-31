// qingyi-jian.c ÇéÒå½£

inherit SKILL;

mapping *action = ({
([      "action":"$NÊ¹Ò»Ê½¡¸´ó±¯Ê½¡¹£¬ÊÖÖÐ$wÎËÎËÎ¢Õñ£¬»Ã³ÉÒ»Ìõ¼²¹â´ÌÏò$nµÄ$l",
	"force" : 120,
	"dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "´ó±¯Ê½ù",
	"damage_type":  "´ÌÉË"
]),
([      "action":"$N´í²½ÉÏÇ°£¬Ê¹³ö¡¸´ó»¶Ê½¡¹£¬½£ÒâÈôÓÐÈôÎÞ£¬$wµ­µ­µØÏò$nµÄ$l»ÓÈ¥",
	"force" : 140,
	"dodge" : -10,
	"damage": 20,
	"lvl" : 10,
	"skill_name" : "´ó»¶Ê½",
	"damage_type":  "¸îÉË"
]),
([      "action":"$NÒ»Ê½¡¸´óÀëÊ½¡¹£¬×ÝÉíÆ®¿ªÊý³ß£¬ÔË·¢½£Æø£¬ÊÖÖÐ$wÒ£Ò¡Ö¸Ïò$nµÄ$l",
	"force" : 160,
	"dodge" : 5,
	"damage" : 25,
	"lvl" : 20,
	"skill_name" : "´óÀëÊ½",
	"damage_type":  "¸îÉË"
]),
([      "action":"$N×ÝÉíÏòÇ°Ô¾Æð£¬Ò»Ê½¡¸´óºÏÊ½¡¹£¬½£¹âÈçÂÖ¼²×ª£¬»ô»ôÕ¶Ïò$nµÄ$l",
	"force" : 180,
	"dodge" : 10,
	"damage": 35,
	"lvl" : 30,
	"skill_name" : "´óºÏÊ½",
	"damage_type":  "¸îÉË"
]),
([      "action":"$NÊÖÖÐ$wÖÐ¹¬Ö±½ø£¬Ò»Ê½¡¸´óÏ²Ê½¡¹£¬´ø×ÅË¿Ë¿½£Æø¶Ô×¼$nµÄ$l´Ì³öÒ»½£",
	"force" : 220,
	"dodge" : 15,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "´óÏ²Ê½",
	"damage_type":  "´ÌÉË"
]),
([      "action":"$NÊÖÖÐ$wÐ±Ö¸²ÔÌì£¬½£Ã¢ÍÌÍÂ£¬Ò»Ê½¡¸´óÅ­Ê½¡¹£¬¶Ô×¼$nµÄ$lÐ±Ð±»÷³ö",
	"force" : 260,
	"dodge" : 5,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "´óÅ­Ê½",
	"damage_type":  "´ÌÉË"
]),
([      "action":"$N×óÖ¸Áè¿ÕÐéµã£¬ÓÒÊÖ$w´ø³öÕÉÐíÑ©ÁÁ½£Ã¢£¬Ò»Ê½¡¸´ó°§Ê½¡¹´ÌÏò$nµÄ$l",
	"force" : 320,
	"dodge" : 5,
	"damage": 55,
	"lvl" : 60,
	"skill_name" : "´ó°§Ê½",
	"damage_type":  "´ÌÉË"
]),
([      "action":"$NÒ»Ê½¡¸´óÀÖÊ½¡¹£¬$wÎËÎË×÷Ïì£¬Èç¼²µç°ãÉäÏò$nµÄÐØ¿Ú",
	"force" : 380,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 70,
	"skill_name" : "´óÀÖÊ½",
	"damage_type":  "´ÌÉË"
]),
([      "action":"$NÒ»Ê½¡¸ÐÄ½£¡¹£¬$w¶¸È»»¯Îª×Ýºá½»´íµÄ½£Íø£¬ÆÌÌì¸ÇµØÏò$n¸ÇÏÂÈ¥",
	"force" : 420,
	"dodge" : 5,
	"damage": 60,
	"lvl" : 80,
	"skill_name" : "ÐÄ½£",
	"damage_type":  "´ÌÉË"
]),

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }


int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("qingyi-jian",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("ÄãµÄ¾«Á¦²»¹»Á·´ËÎä¹¦¡£\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·´ËÎä¹¦¡£\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·´ËÎä¹¦¡£\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"qingyi-jian/" + action;
}
