// zhenfeng-jianfa Õð·ç½£·¨

inherit SKILL;

mapping *action = ({
([      "action" : "$NÊÖÖÐ$wµãÏò$nµÄ$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 10,
        "lvl"    : 0,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊ¹³ö[1;30m¡¸ÂÒÎè¿ñ·ç¡¹[0m£¬$wÉÁË¸²»¶¨£¬´ÌÏò$nµÄ$l",
        "force" : 55,
        "dodge" : 30,
        "damage" : 20,
        "lvl"    : 0,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÒ»ÕÐ[1;34m¡¸Ìì»èµØ°µ¡¹[0m£¬ÎÞÊý$wÉÏÏÂ´Ì³ö£¬Ö±Ïò$n±ÆÈ¥",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "lvl"    : 10,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÏòÇ°¿çÉÏÒ»²½£¬ÊÖÖÐ$wÊ¹³ö[1;33m¡¸½£Æø·âºí¡¹[0mÖ±´Ì$nµÄºí²¿",
        "force" : 90,
        "dodge" : 80,
        "damage" : 40,
        "lvl"    : 20,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "Ö»¼û$NÂÕÆðÊÖÖÐµÄ$w£¬Ê¹³ö[5;1;31m¡[5m¸[5m¹[5mâ[5mÃ[5m¢[5mÍ[5mò[5mÕ[5mÉ[5m¡[5m¹[0mÍòµã½ð¹âÖ±Éä$n",
        "force" : 140,
        "dodge" : 70,
        "damage" : 60,
        "lvl"    : 60,
        "damage_type" : "´ÌÉË"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 20)
                return notify_fail("ÄãµÄ¡¸Õð·çÐÄ·¨¡¹»ðºò²»¹»£¬ÎÞ·¨Ñ§¡¸Õð·ç½£·¨¡¹¡£\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·¡¸Õð·ç½£·¨¡¹¡£\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¡¸Õð·ç½£·¨¡¹¡£\n");
        if ((int)me->query("neili") < 30)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·¡¸Õð·ç½£·¨¡¹¡£\n");
        me->receive_damage("qi", 30);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhenfeng-jianfa/" + action;
}
