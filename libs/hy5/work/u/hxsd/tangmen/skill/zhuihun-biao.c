// zhuihun-biao.c ×·»ê¶áÃüïÚ

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$NÊÖÖĞ$wÒ»ÉÁ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸ÎŞ³£ÇÃÃÅ¡¹"NOR"£¬ÊÖÍóÒ»·­£¬Ïò$nµÄ$l´òÈ¥",
	"force" : 120,
        "dodge" : -10,
        "parry" : 5,
	"damage" : 20,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸Ğ¡¹"NOR"íÄÖ»¨µÆ¡¹"NOR"£¬ÍùµØÉÏÒ»¹ö£¬$wÇÄÎŞÉùÏ¢´òÏò$nµÄ¾±²¿",
	"force" : 130,
        "dodge" : -10,
        "parry" : 10,
	"damage" : 25,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NĞ±Éí½ø²½£¬Ò»ÕĞ"+(order[random(13)])+"¡¸Îå¹íÌ§½Î¡¹"NOR"£¬ÊÖÖĞÎåÃ¶$w,±ÊÖ±·ÉÏò$n",
	"force" : 140,
        "dodge" : -5,
        "parry" : 5,
	"damage" : 30,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÄÎºÎ²»¹éÂ·¡¹"NOR"£¬$wÈöÊÖ·É³ö£¬¾¹ÒÔ²»¿ÉË¼ÒéµÄ½Ç¶È£¬´òÏò$n±³Ãæ",
	"force" : 160,
        "dodge" : 5,
        "parry" : 5,
	"damage" : 35,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÒõÓêÃàÃàÓû¶Ï»ê¡¹"NOR"£¬Ò»°Ñ$wÅüÍ·¸ÇÁ³´òÏò$nµÄĞØ¿Ú¡£",
	"force" : 180,
        "dodge" : 10,
        "parry" : 5,
	"damage" : 40,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÉí×ÓÒ»õÔõÄ£¬ºÃÏóÒªµøµ¹£¬È´¼û¾«Ã¢ÉÁ¶¯£¬ÕıÊÇÒ»ÕĞ"+(order[random(13)])+"¡¸¶Ï³¦ÉËĞÄÎŞÈ¥´¦¡¹"NOR"£¬$w·É¿ìÕÖÏò$n",
	"force" : 210,
        "dodge" : 15,
        "parry" : 15,
	"damage" : 50,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÒ»ÕĞ"+(order[random(13)])+"¡¸ÑÖÂŞ¹ÂµÆ¡¹"NOR"£¬$wÉÁË¸²»¶¨£¬Ê±¿ìÊ±Âı£¬·À²»Ê¤·À´ò$nµÄ$l",
	"force" : 240,
        "dodge" : 5,
        "parry" : 15,
	"damage" : 60,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
([	"action" : "$NÌÚ¿ÕÔ¾Æğ£¬Ò»ÕĞ"+(order[random(13)])+"¡¸Á¶ÓüÁ÷»ğ¡¹"NOR"£¬ÊıÃ¶$wÍÑÊÖ¶ø³ö£¬Ò»Ã¶½ÓÒ»Ã¶£¬¾¹È»³ÉÁËÒ»¸ù»ğÏßÏò$nµÄÈ«Éí´òÈ¥",
	"force" : 280,
        "dodge" : 20,
        "parry" : 10,
	"damage" : 80,
	"damage_type" : "´ÌÉË",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
]),
});


int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 20)
		return notify_fail("ÄãµÄ±ÌÔÆĞÄ·¨»ğºò²»¹»¡£\n");
	if ((int)me->query_skill("biye-wu", 1) < 20)
		return notify_fail("ÄãµÄ±ÌÒ¶Ëæ·çÎè»ğºòÌ«Ç³¡£\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("zhuihun-biao",1);

if (level < 60 )
zhaoshu--;
if (level < 55 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;

return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·×·»ê¶áÃüïÚ¡£\n");
	me->receive_damage("qi", 30);
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{object weapon;weapon=me->query_temp("weapon");
              
        if(weapon && 
        (string)weapon->query("skill_type") == "throwing"){
          victim->apply_condition("tmzhuihun_poison", random(me->query_skill("zhuihun-biao")) + 10 +
	  victim->query_condition("tmzhuihun_poison"));
	}
}
string perform_action_file(string action)
{
		return __DIR__"zhuihun-biao/" + action;
}