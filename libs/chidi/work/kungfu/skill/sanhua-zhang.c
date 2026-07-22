// sanhua-zhang.c -É¢»¨ÕÆ
inherit SKILL;
mapping *action = ({
([  "action" : "$NºÏÕÆ±§Çò£¬Ò»Ê½¡¸"+GRN+"´ºÉî·¼²Ý¾¡"+NOR+"¡¹£¬Ë«ÕÆ±ä»ÃÍÌÍÂ£¬»º»ºÍÆÏò$nµÄ$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : GRN "´ºÉî·¼²Ý¾¡" NOR,
        "damage_type" : "ðöÉË"
]),
([  "action" : "$NÎåÖ¸ÕÀ¿ª£¬Ò»Ê½¡¸"+YEL+"ÏÄÏÐ¶ÀÀ¼Ü°"+NOR+"¡¹£¬×óÓÒÕÆ´©²å·­·É£¬¼²Ïò$nµÄ$lÅÄÈ¥",
    "force" : 260,
    "lvl" : 25,
    "skill_name" : YEL "ÏÄÏÐ¶ÀÀ¼Ü°" NOR,
        "damage_type" : "ðöÉË"
]),
([  "action" : "$NÊ¹Ò»Ê½¡¸"+BLU+"Çïº¨¾ÕËªÇå"+NOR+"¡¹£¬×óÕÆÐéÍÐ£¬ÓÒÕÆÕ§ÉìÕ§ºÏ£¬ÃÍµØ²åÍù$nµÄ$l",
    "force" : 340,
    "lvl" : 56,
    "skill_name" : BLU "Çïº¨¾ÕËªÇå" NOR,
        "damage_type" : "ðöÉË"
]),
([  "action" : "$NË«ÕÆÑªºì£¬Ò»Ê½¡¸"+HIW+"¶¬ÎÔÌýÃ·Ò÷"+NOR+"¡¹£¬»Ã³ÉÂþÌìÃ·»¨¶ä¶ä£¬Óêµã°ãÏò$n»÷È¥",
    "force" : 420,
    "lvl" :  72,
    "skill_name" : HIW "¶¬ÎÔÌýÃ·Ò÷" NOR,
        "damage_type" : "ðöÉË"
])
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 72;  }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("Á·É¢»¨ÕÆ±ØÐë¿ÕÊÖ¡£\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·É¢»¨ÕÆ¡£\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("sanhua-zhang", 1))
        return notify_fail("ÄãµÄ»ù´¡²»¹»£¬ÎÞ·¨Áì»á¸ü¸ßÉîµÄ¼¼ÇÉ¡£\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("ÄãµÄìø×ÚÆø¹¦»ðºò²»¹»£¬ÎÞ·¨Ñ§É¢»¨ÕÆ¡£\n");
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("sanhua-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/2;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/3;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("Á·É¢»¨ÕÆ±ØÐë¿ÕÊÖ¡£\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·É¢»¨ÕÆ¡£\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
