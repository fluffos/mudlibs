// wushen-jian.c 衡山五神剑
// 由衡山派紫盖剑法、芙蓉剑法、石廪剑法、祝融剑法、天柱剑
// 法合一所创，B+级器械武学。

#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 
mapping *action = ({
([      "action" : "$N一招「落叶飘飘」，$w似幻作无数道银索，四面八方的罩向$n",
        "force"  : 110,
        "attack" : 35,
        "dodge"  : 20,
        "parry"  : 25,
        "damage" : 143,
        "lvl"    : 0,
        "skill_name" : "落叶飘飘",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「水中浮萍」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
        "force"  : 155,
        "attack" : 43,
        "dodge"  : 25,
        "parry"  : 14,
        "damage" : 51,
        "lvl"    : 10,
        "skill_name" : "中浮萍",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「飘然直去」，$w幻一条飞练，带着一股寒气划向$n的$l",
        "force"  : 178,
        "attack" : 48,
        "dodge"  : 28,
        "parry"  : 24,
        "damage" : 162,
        "lvl"    : 20,
        "skill_name" : "飘然直去",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「千里不留行」，右手$w带着一团剑花，逼向$n的$l",
        "force"  : 211,
        "attack" : 53,
        "dodge"  : 22,
        "parry"  : 24,
        "damage" : 184,
        "lvl"    : 30,
        "skill_name" : "千里不留行",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「拂衣抹剑」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
        "force"  : 238,
        "attack" : 69,
        "dodge"  : 28,
        "parry"  : 35,
        "damage" : 195,
        "lvl"    : 50,
        "skill_name" : "拂衣抹剑",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「仙人何去」，剑尖无声无色的慢慢的刺向$n的$l",
        "force"  : 268,
        "attack" : 73,
        "dodge"  : 38,
        "parry"  : 15,
        "damage" : 110,
        "lvl"    : 80,
        "skill_name" : "仙人何去",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「梦里看剑」，剑锋乱指，攻向$n，$n根本不能分辩$w的来路",
        "force"  : 255,
        "attack" : 71,
        "dodge"  : 25,
        "parry"  : 24,
        "damage" : 208,
        "lvl"    : 90,
        "skill_name" : "梦里看剑",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「深山空谷」，$w幻一条飞练，带着一股寒气划向$n的$l",
        "force"  : 270,
        "attack" : 78,
        "dodge"  : 18,
        "parry"  : 19,
        "damage" : 223,
        "lvl"    : 110,
        "skill_name" : "深山空谷",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身子向上弹起，左手下指，一招「群仙聚会」，右手$w带着一团剑花，逼向$n的$l",
        "force"  : 291,
        "attack" : 103,
        "dodge"  : 23,
        "parry"  : 28,
        "damage" : 241,
        "lvl"    : 130,
        "skill_name" : "群仙聚会",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「飘飘不定」，左脚跃步落地，右手$w幻成一条雪白的瀑布，扫向$n的$l",
        "force"  : 283,
        "attack" : 91,
        "dodge"  : 22,
        "parry"  : 25,
        "damage" : 255,
        "lvl"    : 140,
        "skill_name" : "飘飘不定",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右腿半屈般蹲，$w平指，一招「千山万水」，剑尖无声无色的慢慢的刺向$n的$l",
        "force"  : 300,
        "attack" : 97,
        "dodge"  : 28,
        "parry"  : 37,
        "damage" : 258,
        "lvl"    : 150,
        "skill_name" : "千山万水",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「去留人间」，$w在$n的周身飞舞，令$n眼花缭乱，剑身在半空中突然停住刺向$n的$l",
        "force"  : 328,
        "attack" : 118,
        "dodge"  : 25,
        "parry"  : 27,
        "damage" : 270,
        "lvl"    : 160,
        "skill_name" : "去留人间",
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N反转手中$w，剑光夺目，将「" HIR "祝融剑法" NOR
                   "」发挥得淋漓尽致，闪电般射向$n",
        "force" : 430,
        "attack": 147,
        "dodge" : 96,
        "parry" : 128,
        "damage": 290,
        "skill_name" : "祝融剑法",
        "lvl"    : 180,
        "damage_type" : "刺伤",
]),
([ 
        "action" : "$N手中剑花突现，顿时剑光暴长，已将「" HIM "芙蓉剑"
                   "法" NOR "」使出，直刺$n的$l",
        "force" : 420,
        "attack": 154,
        "dodge" : 118,
        "parry" : 120,
        "damage": 310,
        "skill_name" : "芙蓉剑法",
        "lvl"    : 200,
        "damage_type" : "刺伤",
]),
([
        "action" : "$N将$w一挥，长啸一声腾空而起，一式「" HIY "鹤翔紫"
                   "盖" NOR "」，$w已指向$n$l",
        "force" : 420,
        "attack": 156,
        "dodge" : 100,
        "parry" : 120,
        "damage": 323,
        "skill_name" : "鹤翔紫盖",
        "lvl"    : 220,
        "damage_type" : "刺伤",
]),
([
        "action" : "$N轻啸一声，右手$w虚刺$n左眼，突然右腕翻转，将「" HIG 
                   "石廪剑法" NOR "」的精髓发挥到了极致",
        "force" : 430,
        "attack": 160,
        "dodge" : 120,
        "parry" : 140,
        "damage": 348,
        "skill_name" : "石廪剑法",
        "lvl"    : 250,
        "damage_type" : "刺伤",
]),
([
        "action" : "$N手中$w剑路忽快忽慢，若隐若现，一剑「" HIW "天柱云气"
                   NOR "」犹如烟雾飘渺般使了出来",
        "force" : 480,
        "attack": 180,
        "dodge" : 140,
        "parry" : 160,
        "skill_name" : "天柱云气",
        "damage": 360,
        "lvl"    : 300,
        "damage_type" : "刺伤",
]),
});

int valid_enable(string usage) {return usage == "sword" || usage == "parry";}

int valid_learn(object me)
{
        if (me->query("int") < 30)
                return notify_fail("你先天悟性不足，无法领悟逍遥五神剑法。\n");
 
        if ((int)me->query("max_neili") < 2500)
                return notify_fail("你的内力修为不够，无法学习逍遥五神剑法。\n");

        if ((int)me->query_skill("force", 1) < 120)
                return notify_fail("你的基本内功火候太浅，无法学习逍遥五神剑法。\n");

        if ((int)me->query_skill("dodge", 1) < 120)
                return notify_fail("你的基本内功火候太浅，无法学习逍遥五神剑法。\n");

        if ((int)me->query_skill("sword", 1) < 120)
                return notify_fail("你的基本剑法火候不够，无法学习逍遥五神剑法。\n");

        if ((int)me->query_skill("yunlong-bian", 1) < 200)
                return notify_fail("你的云龙鞭法火候不够，无法学习逍遥五神剑法。\n");
        if ((int)me->query_skill("yunlong-jian", 1) < 200)
                return notify_fail("你的云龙剑火候不够，无法学习逍遥五神剑法。\n");
        if ((int)me->query_skill("yunlong-shengong", 1) < 200)
                return notify_fail("你的云龙神功火候不够，无法学习逍遥五神剑法。\n");
        if ((int)me->query_skill("yunlong-shou", 1) < 200)
                return notify_fail("你的云龙手火候不够，无法学习逍遥五神剑法。\n");
        if ((int)me->query_skill("yunlong-zhua", 1) < 200)
                return notify_fail("你的云龙爪火候不够，无法学习逍遥五神剑法。\n");                                                                
        if ((int)me->query_skill("yunlong-shenfa", 1) < 200)
                return notify_fail("你的云龙身法火候不够，无法学习逍遥五神剑法。\n");                                                                


       if (((int)me->query_skill("bazhen-zhang", 1)) < 200)
               return notify_fail("你的八阵八卦掌太低了。\n");
               
       if (((int)me->query_skill("houquan", 1)) < 200)
               return notify_fail("你的猴拳太低了。\n");

       if (((int)me->query_skill("yunlong-shenfa", 1)) < 200)
               return notify_fail("你的云龙身法太低了。\n");
       if (((int)me->query_skill("baihua-cuoquan", 1)) < 200)
               return notify_fail("你的百花错拳太低了。\n");

       if (((int)me->query_skill("wuhu-duanmendao", 1)) < 200)
               return notify_fail("你的五虎断门刀太低了。\n");



        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("wushen-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的逍遥五神剑法。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        int lvl,i;

        lvl = me->query_skill("wushen-jian", 1);
        weapon = me->query_temp("weapon");      


        if (! me->query_temp("weapon")) return 0;

    if (me->query("neili") < 300
           || me->query_skill_mapped("sword") != "wushen-jian"
           || random(3) != 1)
{
if (random(2)==0)
{
        if (lvl < 130 || lvl / 2 + random(lvl) < (int)victim->query_skill("dodge", 1) ||
            me->query("neili") < 150 ||
            me->query_skill("dodge", 1) < 180 ||
            me->query_skill("force", 1) < 150 ||             
            victim->is_busy() )
                 return 0;
        message_vision(HIW "\n$N" HIW "右手" + weapon->name() + HIW "猛然旋转，剑光突"
                       "现，刹那间已将$n" HIW "退路全部封死。\n" NOR, me, victim); 
         victim->receive_wound("qi", (random(lvl)/2+2) / 2, me);
        victim->start_busy(2);
}
                     return 0;
}


        switch(random(4))
        {
           case 1:
              if (damage_bonus / 5 > victim->query_con() || random(5)==0)
              {
                  
                  victim->receive_wound("qi", (random(lvl)/2+1) , me);
                  
                  return random(2) ? HIW "$N" HIW "一剑攻出，刹那间剑气横飞，$n" HIW
                                     "身上顿时鲜血狂涌。\n" NOR:
                                     HIW "$N" HIW "剑锋一转，一剑平平刺向$n" HIW "要害"
                                     "，看似普通的一招其中却蕴藏着极大的杀着。\n" NOR;
             }
             break;

          case 2:
             if ((random(me->query_skill("sword") / 2) + me->query_skill("sword")
                 > victim->query_skill("dodge")) || random(5)==0)
             {
                  weapon = me->query_temp("weapon");
                  if (!victim->is_busy())
                  victim->start_busy(3);
                  return   HIC "$N" HIC "剑法陡然变快，手中" + weapon->name() + HIC "剑光夺目，"
                           "将$n" HIC "笼罩在剑光之中。\n" NOR;
             }
             break;

          case 3:
             if ( random(3) == 1 && !me->is_busy() && !me->query_temp("wsj")  && !me->query_temp("perform_wushenjian/qian") )
             {
                weapon = me->query_temp("weapon");
                message_vision(HIM "\n$N" HIM "轻啸一声，腾空而起，" + weapon->name() + "在"
                             "空中挽出一个剑花，顷刻间剑花四散，洋洋洒洒。犹如无"
                             "数花瓣从半空洒向$n" HIM "全身。\n" NOR, me, victim);
                me->set_temp("wsj",1);
                for (i = 0; i < 5; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(1);

                    COMBAT_D->do_attack(me, victim, weapon, 0);
                
                }                
                me->delete_temp("wsj");
             }
             break;                        

          default:
                return 0;
       }
     

        return 1;                         
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("wushen-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ((int)me->query("qi") < 60)
                return notify_fail("你的体力目前没有办法练习逍遥剑法。\n");

        if ((int)me->query("neili") < 90)
                return notify_fail("你的内力不够，无法练习逍遥剑法。\n");
        
        me->add("qi", -50);
        me->add("neili", -82);
        return 1;
}








string perform_action_file(string action)
{
        return __DIR__"wushen-jian/" + action; 
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 8000)	damage2=8000;
msg = HIR"$N"+HIR+"$N左手聚成虎爪状! 「凝血神抓」一把抓住$n的"+ xue_name[random(sizeof(xue_name))] +NOR;
           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}


           return j;
}      
