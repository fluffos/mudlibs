// xue-dao.c Ñªµ¶
// Designed by secret(ÃØÃÜ)
//

inherit SKILL;

mapping *action = ({
([      "action" : "$N¸ß¾ÙÊÖÖÐ$w,Ê¹³öÒ»ÕÐ[1;35m¡¸Ä¥ÑÀË±Ñª¡¹[0m£¬Ò»µ¶Ð±Åü$nµÄ$l  ",
        "skill_name" : "Ä¥ÑÀË±Ñª",
        "force" : 100,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 20,
        "damage_type" : "¸îÉË",
]),
([      "action" : "$N¾ÍµØÒ»¹ö£¬Ê¹Ò»ÕÐ[31m¡¸´ÌÑªÂúµØ¡¹[0m£¬ÊÖÖÐ$w¾íÏò$nµÄ´óÍÈ  ",
        "skill_name" : "´ÌÑªÂúµØ",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 25,
        "damage_type" : "¸îÉË",
]),
([      "action" : "$N×ã¼âÒ»µã£¬Ê¹³ö[33m¡¸Ñªº£Ã£Ã£¡¹[0m£¬µ¶·æ×ÔÉÏ¶øÏÂÖ±²å$nµÄ$l  ",
        "skill_name" : "Ñªº£Ã£Ã£",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 30,
        "damage_type" : "¸îÉË",
]),
([      "action" : "$NÊ¹³öÒ»ÕÐ[35m¡¸Å»ÐÄÁ¤Ñª¡¹[0m£¬½«$wÎèµÃÈç°×ÎíÒ»°ãÑ¹Ïò$n  ",
        "skill_name" : "Å»ÐÄÁ¤Ñª",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 40,
        "damage_type" : "¸îÉË",
]),
([      "action" : "$NµÍºðÒ»Éù£¬Ê¹³ö[1;34m¡¸Ñª¿ÚÅçÈË¡¹[0m£¬¾Ù$wÖ±Åü$nµÄ$l  ",
        "skill_name" : "Ñª¿ÚÅçÈË",
        "force" : 250,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 32,
        "damage" : 50,
        "damage_type" : "¸îÉË",
]),
([      "action" : "$NÊ¹³ö[1;36m¡¸Ñª¼£°ß°ß¡¹[0m£¬·ÉÉíÐ±´Ì£¬ºöÈ»·´ÊÖÒ»µ¶ºáÕ¶$nµÄÑü²¿  ",
        "skill_name" : "Ñª¼£°ß°ß",
        "force" : 280,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 40,
        "damage" : 60,
        "damage_type" : "¸îÉË",
]),
([      "action" : "$NÊ¹Ò»Ê½[1;33m¡¸ÒÔÑª»¹Ñª¡¹[0m£¬»Óµ¶Ö±Ö¸$nµÄÐØ¿Ú  ",
        "skill_name" : "ÒÔÑª»¹Ñª",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "lvl" : 48,
        "damage" : 80,
        "damage_type" : "¸îÉË",
]),
([      "action" : "$Nµ¶·æÐéµã£¬Ê¹³öÒ»ÕÐ[1;31m¡¸ÑªÁ÷ÂþÃæ¡¹[0m£¬×ªÉí¾Ù$wºáÅü$nµÄÃæÃÅ  ",
        "skill_name" : "ÑªÁ÷ÂþÃæ",
        "force" : 320,
        "dodge" : 10,
        "parry" : 20,
        "lvl" : 56,
        "damage" : 100,
        "damage_type" : "¸îÉË",
]),
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 500)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("ÄãµÄÄÚ¹¦»ðºòÌ«Ç³¡£\n");

        if ((int)me->query_skill("blade", 1) < 80)
                return notify_fail("ÄãµÄ»ù±¾µ¶·¨»ðºò²»¹»£¬ÎÞ·¨ÐÞÏ°Ñªµ¶µ¶·¨¡£\n");

        if ((int)me->query_skill("blade", 1) < (int)me->query_skill("xue-dao", 1))
                return notify_fail("ÄãµÄ»ù±¾µ¶·¨Ë®Æ½ÓÐÏÞ£¬ÎÞ·¨ÐÞÏ°¸ü¼Ó¸ßÉîµÄÑªµ¶µ¶·¨¡£\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("xue-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»£¬Á·²»ÁËÑªµ¶µ¶·¨¡£\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Á·²»ÁËÑªµ¶µ¶·¨¡£\n");

        me->receive_damage("qi", 60);
        me->add("neili", -63);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xue-dao/" + action;
}

