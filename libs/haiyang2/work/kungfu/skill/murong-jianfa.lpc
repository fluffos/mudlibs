// murong-jiafa 慕容剑法

#include <ansi.h>;
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N剑尖下指，一式"+(order[random(13)])+"「洗耳恭听」"NOR"，双脚后退三步，剑尖直点$n腿部",
        "force" : 100,
        "dodge" : 120,
        "damage" : 180,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N踏前数步，避虚就实，右手使一式"+(order[random(13)])+"「明察秋毫」"NOR"直刺$n的右肋",
        "force" : 100,
        "dodge" : 115,
        "damage" : 160,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「甜言蜜语」"NOR"，剑尖抖起五朵剑花，分别刺向$n的左脸和右耳",
        "force" : 140,
        "dodge" : 115,
        "damage" : 180,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑身横摆，剑尖指向$n的脸部，一招"+(order[random(13)])+"「望尘莫及」"NOR"，宛若万马千军一般，横扫$n的$l",
        "force" : 200,
        "dodge" : 110,
        "damage" : 200,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双脚离地，使出草上飞，身行直奔$n，一招"+(order[random(13)])+"「骑虎难下」"NOR"，剑出中宫，平削$n的$l",
        "force" : 260,
        "dodge" : 105,
        "damage" : 220,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长笑一声，横剑斜削，一招"+(order[random(13)])+"「抛砖引玉」"NOR"，剑风逼向$n的$l",
        "force" : 300,
        "dodge" : 105,
        "damage" : 240,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("你的神元功火候太浅。\n");
        if ((int)me->query_skill("murong-daofa", 1) < 80)
                return notify_fail("你的慕容刀法火候太浅。\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 80)
                return notify_fail("你的燕灵身法火候太浅。\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 80)
                return notify_fail("你的斗转星移掌火候太浅。\n");


        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("你的基本招架火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
         level   = (int) me->query_skill("murong-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 80)
                return notify_fail("你的神元功火候太浅。\n");
        if ((int)me->query_skill("murong-daofa", 1) < 80)
                return notify_fail("你的慕容刀法火候太浅。\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 80)
                return notify_fail("你的燕灵身法火候太浅。\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 80)
                return notify_fail("你的斗转星移掌火候太浅。\n");

        if ((int)me->query("jing") < 20)
                return notify_fail("你的体力不够练慕容剑法。\n");
		if ((int)me->query("neili") < 20)
                return notify_fail("你的体力不够练慕容剑法。\n");
        me->receive_damage("jing", 20);
		me->add("neili",-15);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"murong-jianfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   object weapon = me->query_temp("weapon");

   if(me->query_temp("lianhuan") && !me->query_temp("lianhuan_hit")
      && me->query_skill_prepared("finger") == "canhe-zhi"
      && me->query_skill_mapped("finger") == "canhe-zhi"
      && objectp(weapon)) {
        me->set_temp("lianhuan_hit", 1);
        weapon->unequip();
        if (random(2)==0) victim->start_busy(2);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);  
        weapon->wield();
        me->add("neili", -30);
        me->delete_temp("lianhuan_hit");
        me->add_temp("lianhuan", -1);
        }
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("shenyuan-gong",1);
        skill = me->query_skill("shenyuan-gong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenyuan-gong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "shenyuan-gong" || me->query_skill_mapped("force") == "shenyuan-gong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"凝神运气向$n猛攻快打，使出的招数好似$n的成名绝技，把$n的招数化于无行！\n"NOR;
ob->start_busy(3);
if (random(2)==0)
{
msg += HIC"$N"+HIC+"使出星移斗转，$n这招莫名其妙的在中途转了方向，直奔自己袭来!"+NOR;
if (ob->query("qi") > damage2)
{
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}

}

           message_vision(msg, me, ob);
           return j;
}      
}