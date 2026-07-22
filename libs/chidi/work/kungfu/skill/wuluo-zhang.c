// wuluo-zhang.c ÎåÂÞÇáÑÌÕÆ

inherit SKILL;

mapping *action = ({
([  "action" : "$NÆÁÏ¢¾²Æø£¬ÊÖÆðÒ»ÕÆ¡¸ÇáÑÌôÁôÁ¡¹£¬ÇáÇáÈáÈáµØÅÄÏò$n",
    "force"  : 130,
    "dodge"  : 20,
	"damage" : 0,
    "lvl"    : 0,
	"skill_name" : "ÇáÑÌôÁôÁ",
	"damage_type" : "ðöÉË"
]),
([  "action" : "$NÇáÇáÇ³Ð¦£¬ÈÆµ½$nÉíºó£¬×óÊÖ×öÊÆÎÂÈáÇáÓµ$nÑü¼ä¡£$nõ¾
Ã¼¼±¶ã£¬$NÓÒÊÖÒ»ÕÐ¡¸ÑÌÎíçÔÈÆ¡¹£¬ÎÞÉùÎÞÏ¢Ïò$nµÄ$lÅÄµ½",
    "force"  : 150,
    "dodge"  : 20,
	"damage" : 30,
    "lvl"    : 20,
	"skill_name" : "ÑÌÎíçÔÈÆ",
	"damage_type" : "ÄÚÉË"
]),
([  "action" : "$NÒ»ÕÐ¡¸ÑÌº£ÔÆÌÎ¡¹£¬Ë«ÕÆ»Ã»¯³öÒ»Æ¬ÕÆÓ°£¬ÈçÒ»ÕóÇáÑÌ£¬
½«$nÏ¸Ï¸ÃÜÃÜµØÁýÕÖÓÚÄÚ",
    "force"  : 150,
    "dodge"  : 30,
	"damage" : 45,
    "lvl"    : 40,
	"skill_name" : "ÑÌº£ÔÆÌÎ",
	"damage_type" : "ðöÉË"
]),

([  "action" : "$N·µÉíÔ½³öÈ¦Íâ£¬»ØÊ×Ò»ÕÐ¡¸ÔÆÑÌÃìÃì¡¹£¬Ô¶Ô¶µØÏò$nµÄ$l
ÇáÇáÅÄ³öÁ½ÕÆ£¬ÕÆ·ç¹Îµ½£¬¶¸È»±äÊ¢Ö±ÈÃ$nºô²»³öÆøÀ´",
    "force"  : 200,
    "dodge"  : 25,
	"damage" : 55,
    "lvl"    : 60,
	"skill_name" : "ÔÆÑÌÃìÃì",
    "damage_type" : "ðöÉË"
]),
([  "action" : "$N×óÕÆ´ÓÓÒÕÆÄÚÎ§·­³ö£¬ÇáÆ®Æ®µØÏò$nÅÄÈ¥£¬¿´µ½$nÆðÊÖÕÐ
¼Ü£¬ÓÒÕÆÈ´×ÔÐØ¿Ú¼²ËÙÈ¦³ö£¬Ò»ÕÐ¡¸ÑÌÎíÃÖÂþ¡¹£¬¸Ï³¬×óÕÆ£¬ÅÄÏò$nµÄ$l",
    "force"  : 250,
    "dodge"  : 70,
	"damage" : 10,
    "lvl"    : 80,
	"skill_name" : "ÑÌÎíÃÖÂþ",
    "damage_type" : "ðöÉË"
]),
([  "action" : "$NË«ÕÆÆëÍÆ£¬ÕñÆðÒ»Õó¾¢·ç£¬Ò»ÕÐ¡¸ÑÌÏûÔÆÉ¢¡¹ÔÚÒ»ÕÉ¿ªÍâ
»÷Ïò$n",
    "force"  : 300,
    "dodge"  : 20,
	"damage" : 90,
    "lvl"    : 100,
	"skill_name" : "ÑÌÏûÔÆÉ¢",
    "damage_type" : "ðöÉË"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("Á·ÎåÂÞÇáÑÌÕÆ±ØÐë¿ÕÊÖ¡£\n");
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("ÄãµÄ¿ÝÈÙìø¹¦Ì«Èõ£¬ÎÞ·¨Á·ÎåÂÞÇáÑÌÕÆ¡£\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·ÎåÂÞÇáÑÌÕÆ¡£\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
    level = (int) me->query_skill("wuluo-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·ÎåÂÞÇáÑÌÕÆ¡£\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}


