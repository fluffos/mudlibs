// kuangfeng-jianfa ¿ñ·ç½£·¨
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$NÎÕ½ôÊÖÖĞ$wÒ»ÕĞ[37m¡¸´ó·çÆğÙâ¡¹[0mµãÏò$nµÄ$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 20,
        "skill_name" : "¡¸´ó·çÆğÙâ¡¹",
        "lvl"    : 0,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÒ»ÕĞ[1;34m¡¸Ìì»èµØ°µ¡¹[0m£¬ÎŞÊı$wÉÏÏÂ´Ì³ö£¬Ö±Ïò$n±ÆÈ¥",
        "force" : 70,
        "dodge" : 10,
        "damage" : 30,
        "skill_name" : "¡¸Ìì»èµØ°µ¡¹",
        "lvl"    : 20,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÏòÇ°¿çÉÏÒ»²½£¬ÊÖÖĞ$wÊ¹³ö[1;33m¡¸½£Æø·âºí¡¹[0mÖ±´Ì$nµÄºí²¿",
        "force" : 90,
        "dodge" : 80,
        "damage" : 60,
        "skill_name" : "¡¸½£Æø·âºí¡¹",
        "lvl"    : 40,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NĞé»ĞÒ»²½£¬Ê¹³ö[36m¡¸ĞéÖĞÓĞÊµ¡¹[0mÊÖÖĞ$wÖ±´Ì$nµÄºí²¿",
        "force" : 90,
        "dodge" : 80,
        "damage" : 80,
        "skill_name" : "¡¸ĞéÖĞÓĞÊµ¡¹",
        "lvl"    : 60,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "Ö»¼û$NÂÕÆğÊÖÖĞµÄ$w£¬Ê¹³ö[31m¡¸[1;33m¹â[1;35mÃ¢[35mÍò[1;31mÕÉ[31m¡¹[0mÍòµã½ğ¹âÖ±Éä$n",
        "force" : 90,
        "dodge" : 70,
        "damage" : 100,
        "skill_name" : "¡¸¹âÃ¢ÍòÕÉ¡¹",
        "lvl"    : 80,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÂÕÆğÊÖÖĞµÄ$w£¬Ê¹³ö[1;35m¡¸¿ñ·çÂÒ½£¡¹[0mÎŞÊı½£¹âÖ±Éä$n",
        "force" : 120,
        "dodge" : 60,
        "damage" : 140,
        "skill_name" : "¡¸¿ñ·çÂÒ½£¡¹",
        "lvl"    : 100,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊ¹³ö[37m¡¸ÂÒÎè¿ñ·ç¡¹[0m£¬ÊÖÖĞ$wÈç¹ÎÆğ¿ñ·çÒ»°ãÉÁË¸²»¶¨£¬´ÌÏò$n",
        "force" : 200,
        "dodge" : 100,
        "damage" : 130,
        "skill_name" : "¡¸ÂÒÎè¿ñ·ç¡¹",
        "lvl"    : 120,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊ¹³ö¿ñ·ç½£·¨Ö®¾ø¼¼[37m¡¸¿ñ·çËÁÅ°¡¹[0m£¬ÊÖÖĞ$wÈç¹ÎÆğ¿ñ·çÒ»°ãÆÌÌì¸ÇµØµÄ´ÌÏò$n",
        "force" : 500,
        "dodge" : 200,
        "damage" : 200,
        "lvl"    : 501,
        "skill_name" : "¡¸¿ñ·çËÁÅ°¡¹",
        "damage_type" : "´ÌÉË"
]),
([      "action" : HIY"$NÊ¹³ö¿ñ·ç½£·¨Ö®×îÖÕ¾ø¼¼¡¸ÈË½£ºÏÒ»¡¹£¬Õû¸öÈË»¯×÷Ò»°Ñ½ğ½£·ÉÏò$n"NOR,
        "force" : 500,
        "dodge" : 400,
        "damage" : 400,
        "lvl"    : 801,
        "skill_name" : HIY"¡¸ÈË½£ºÏÒ»¡¹"NOR,
        "damage_type" : "´ÌÉË"
]),



});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("zhenfeng-xinfa", 1) < 80)
                return notify_fail("ÄãµÄ¡¸Õğ·çĞÄ·¨¡¹»ğºò²»¹»£¬ÎŞ·¨Ñ§¡¸¿ñ·ç½£·¨¡¹¡£\n");
        if ((int)me->query("max_neili") < 500)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎŞ·¨Á·¡¸¿ñ·ç½£·¨¡¹¡£\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
/*
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
*/
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("kuangfeng-jianfa",1);
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
        if ((int)me->query("qi") < 50)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¡¸¿ñ·ç½£·¨¡¹¡£\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·¡¸¿ñ·ç½£·¨¡¹¡£\n");
        me->receive_damage("qi", 40);
        me->add("neili",-15);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuangfeng-jianfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
//                victim->add("qi", 1 - damage_bonus - 100 * 3 );
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIR "ÄãÌıµ½¡¸à§¡¹Ò»ÉùÇáÏìºÃÏñÁ¹Ò»Õó·ç´µ¹ı£¬ºöÈ»¼ä$nÑªÃ°ÈıÕÉ£¬±»$N½£ÆøËùÉË£¡\n" NOR;
        }
}


