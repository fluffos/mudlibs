// liehuo-jian.c -ÁÒ»ð½£

inherit SKILL;

mapping *action = ({
([      "action" : "$NÒ»Ê½[1;36m¡¸ÁÒ»ðÊÆ¡¹[2;37;0m£¬½£·æÆ½Ö¸£¬½£ÊÆÈç·ç£¬Ò»ÆøºÇ³ÉºáÉ¨$nµÄÑü¼ä",
        "force" : 120,
        "dodge" : -10,
        "damage" : 25,
        "lvl" : 0,
        "skill_name" : "ÁÒ»ðÊÆ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÏòÇ°Ô¾ÉÏÒ»²½£¬×óÊÖ½£¾÷£¬ÓÒÊÖ$wÊ¹³öÒ»Ê½[37m¡¸ÆÆ»ðÊÆ¡¹[2;37;0mÖ±´Ì$nµÄ$l",
        "force" : 140,
        "dodge" : -10,
        "damage" : 30,
        "lvl" : 10,
        "skill_name" : "ÆÆ»ðÊÆ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N°Î²½Í¦Ñü£¬Ò»Ê½[1;33m¡¸ÆË»ðÊÆ¡¹[2;37;0m£¬ÊÖÖÐ$w³ÁÖÍÎÞ±È£¬»º»º»Ó½£×²Ïò$nµÄ$l",
        "force" : 170,
        "dodge" : 5,
        "damage" : 35,
        "lvl" : 20,
        "skill_name" : "ÆË»ðÊÆ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÒ»Ê½[31m¡¸½Á»ðÊÆ¡¹[2;37;0m£¬$w×Ô×ó¶øÓÒ»®³öÒ»¸ö´ó»¡£¬Æ½Æ½µØÏò$nµÄ$l»ÓÈ¥",
        "force" : 190,
        "dodge" : 5,
        "damage" : 40,
        "lvl" : 30,
        "skill_name" : "½Á»ðÊÆ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N»ØÉíÅ¡Ñü£¬ÓÒÊÖÐé±§³ÉÔ²£¬Ò»Ê½[31m¡¸¿ªÌìÊÆ¡¹[2;37;0m£¬$wÖÐ¹¬Ö±½ø£¬´ÌÏò$nµÄÐØ¿Ú",
        "force" : 240,
        "dodge" : 10,
        "damage" : 50,
        "lvl" : 40,
        "skill_name" : "¿ªÌìÊÆ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÒ»Ê½[1;32m¡¸ÅüµØÊÆ¡¹[2;37;0m£¬$w´ÓÉÏÖÁÏÂÃÍÅü£¬½£·æÖ±³ö£¬Ð®±¬ÁÑÖ®ÉùÖèÈ»Õ¶Ïò$nµÄ$l",
        "force" : 280,
        "dodge" : 5,
        "damage" : 60,
        "lvl" : 49,
        "skill_name" : "ÅüµØÊÆ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÔËÆøÊ©³ö[1;32m¡¸À×ÕëÊÆ¡¹[2;37;0m£¬$w½£¼â±Æ³öÒ»µÀÇàÃ¢£¬ÉÁµç°ãÆÆ¿ÕÉäÏò$nµÄ$l",
        "force" : 350,
        "dodge" : 5,
        "damage" : 75,
        "lvl" : 57,
        "skill_name" : "À×ÕëÊÆ",
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NË«ÍÈ°ëÇü°ë¶×£¬Ò»Ê½[35m¡¸ÁúÍÌÊÆ¡¹[2;37;0m£¬½£¼â»®³öÎÞÊýÔ²È¦£¬¿ñ·çÖèÆð£¬ÁýÕÖÌìµØ",
        "force" : 400,
        "dodge" : 5,
        "damage" : 90,
        "lvl" : 64,
        "skill_name" : "ÁúÍÌÊÆ",
        "damage_type" : "´ÌÉË"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        if ((int)me->query_skill("shenghuo-shengong", 1) < 100)
                return notify_fail("ÄãµÄÊ¥»ðÉñ¹¦Ì«Ç³¡£\n");
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
        level   = (int) me->query_skill("liehuo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    if ( me->query_temp("perform_jue")) level+=level;
    a_action["dodge"]  = 0-level;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level;
    a_action["damage"] = level*4;
    return a_action;
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·ÁÒ»ð½£¡£\n");
        me->receive_damage("qi", 35);
        return 1;
}
string perform_action_file(string action)
{
    return __DIR__"liehuo-jian/" + action;
}



