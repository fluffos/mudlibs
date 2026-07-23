// 倚天剑法
// write by snkboy
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action": "$N剑尖剑芒暴长，一招「倚天寒芒」，手中$w大开大阖，剑芒直刺$n的$l",
        "force" : 250,
        "attack": 150,
        "dodge" : 50,
        "parry" : 50,
        "damage": 351,
        "lvl"   : 0,
        "skill_name" : "倚天寒芒",
        "damage_type" : "刺伤"
]),
([      "action": "$N剑芒吞吐，单手$w一招「翻江倒海」，剑势曼妙，剑光直逼向$n的$l",
        "force" : 270,
        "attack": 180,
        "dodge" : 60,
        "parry" : 60,
        "damage": 378,
        "lvl"  : 30,
        "skill_name" : "翻江倒海",
        "damage_type" : "刺伤"
]),
([      "action": "$N一式「神剑佛威」，屈腕云剑，剑光如彩碟纷飞，幻出点点星光飘向$n",
        "force" : 280,
        "attack": 220,
        "dodge" : 80,
        "parry" : 80,
        "damage": 347,
        "lvl"   : 50,
        "skill_name" : "神剑佛威",
        "damage_type" : "刺伤"
]),
([      "action": "$N挥剑分击，剑势自胸前跃出，$w一式「群邪辟易」，毫无留恋之势，刺向$n",
        "force" : 290,
        "attack": 231,
        "dodge" : 81,
        "parry" : 83,
        "damage": 355,
        "lvl"   : 80,
        "skill_name" : "群邪辟易",
        "damage_type" : "刺伤"
]),
([      "action": "$N左手剑指划转，腰部一扭，右手$w一记「荡妖除魔」自下而上刺向$n的$l",
        "force" : 300,
        "attack": 275,
        "dodge" : 95,
        "parry" : 95,
        "damage": 393,
        "lvl"   : 150,
        "skill_name" : "荡妖除魔",
        "damage_type" : "刺伤"
]),
(["action": HIR "$N脸色凝重凝重，缓缓举起$w"NOR""HIR"，突然跃起身剑合一，使出一招“倚天不出”，\n手中$w"NOR""HIR"由下至上划出一条美丽的弧线刺向$n的$l" NOR,    
         "damage": 350,  
         "attack": 300,  
         "dodge": 100,  
         "parry": 100,  
         "lvl": 150,  
         "damage_type": "刺伤",  
         "skill_name": "倚天不出",  
]), 
(["action": HIY "$N反身跃起，双手握剑举至头顶使出倚天剑法奥义“谁与争锋”，这看似简简单单的一剑，\n而厚重的剑气直奔$n的$l而去"NOR,  
         "damage": 300,  
         "attack": 350,  
         "dodge": 120,  
         "parry": 120,  
         "lvl": 220,  
         "damage_type": "刺伤",  
         "skill_name": "谁与争锋",  
])
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{


        if ((int)me->query("int") < 30) 
                return notify_fail("以你的资质永远也学不会倚天剑法。\n"); 

        if ((int)me->query("con") < 20)  
                return notify_fail("以你根骨不适合修炼倚天剑法。\n"); 

        if ((int)me->query("max_neili") < 250)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force", 1) < 50)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("bagua-dao", 1) < 100)
                return notify_fail("你的四像八卦刀火候太浅。\n");

        if ((int)me->query_skill("yanxing-dao", 1) < 100)
                return notify_fail("你的雁行刀火候太浅。\n");

        if ((int)me->query_skill("bagua-zhang", 1) < 100)
                return notify_fail("你的四像八卦掌火候太浅。\n");   
                
        if ((int)me->query_skill("jinding-zhang", 1) < 100)
                return notify_fail("你的金顶绵掌火候太浅。\n");
                
        if ((int)me->query_skill("tiangang-zhi", 1) < 100)
                return notify_fail("你的天罡指穴法火候太浅。\n");                

        if ((int)me->query_skill("zhutian-bu", 1) < 100)
                return notify_fail("你的诸天化身步火候太浅。\n");                

        if ((int)me->query_skill("huifeng-jian", 1) < 100)
                return notify_fail("你的回风拂柳剑火候太浅。\n");     
                
        if ((int)me->query_skill("sword", 1) < 50)
                return notify_fail("你的基本剑法火候太浅。\n");

        if (me->query_skill("sword", 1) < me->query_skill("yitian-jian"))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的倚天剑法。\n");

        return 1;
}

mapping query_action(object me, object weapon) 
{
        int i, level; 
        level = (int) me->query_skill("yitian-jian", 1); 
         for (i = sizeof(action); i > 0; i--) 
                 if (level > action[i - 1]["lvl"]) 
                         return action[NewRandom(i, 5, level / 5)]; 
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/*
mapping query_action(object me, object weapon)
{
        int i, level;

        level = (int) me->query_skill("yitian-jian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}
*/

int practice_skill(object me)
{
        object weapon;

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练倚天剑法。\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("你的内力不够练倚天剑法。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -60);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus) 
{
         mixed result; 
         object weapon; 


         if (objectp(weapon) && ((string)weapon->query("id") == "yitian jian" || (string)weapon->query("id") == "sky sword") && random(2)==0) 
         {
         victim->receive_damage("qi", me->query_skill("yitian-jian") / 2+20); 
         victim->receive_damage("jing", me->query_skill("yitian-jian") / 5+20); 
         victim->receive_wound("qi", me->query_skill("yitian-jian") / 5+20); 
         return WHT "$N有了倚天剑，顿时剑光大胜，剑气之声连连呼啸而过，$n" 
                WHT "$n只觉气血翻腾，“哇”的吐出一口鲜血。\n" NOR; 
         }

         if (damage_bonus < 60 || random(3)==0)
         {
                victim->receive_wound("qi", (damage_bonus ) / 3+10, me);
                	return "$n"NOR""HIR"只觉一阵清风拂过，只见"NOR"$n"HIR"的嘴角竟露出一丝血色！\n" NOR;
         }




         if (damage_bonus > 60  && random(2)==0) 
         { 
                victim->receive_wound("qi", (damage_bonus ) / 3+10, me);
                	return "$n"NOR""MAG"只觉一阵清风拂过，只见"NOR"$n"MAG"血冒三丈，已被$N的剑气所伤！\n" NOR;

         } 
}


string perform_action_file(string action)
{
        return __DIR__"yitian-jian/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wa;
                
        string msg,limb;
                
        int i, j, p, skill, neili;

        object wp,wp1;
        int neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("linji-zhuang",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) me->query("neili",1)/8;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "linji-zhuang")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (me->query("qi")<= me->query("max_qi") )
{
	me->add("qi", damage2);
		//ob->add("qi", 10000);
}
if (me->query("eff_qi")<= me->query("max_qi") )
{
	me->add("eff_qi", damage2);
}
msg = HIG"$N 五心向天，运行日月二庄，益气升阳，益阴潜阳，
升降反正，天地二气交泰于身，并配合峨嵋九阳功。灭绝之间顿时大起!！\n"NOR;
msg += "$N神色一变,恢复了些活力！\n",  
           message_vision(msg, me, ob);
           return j;
} 
}