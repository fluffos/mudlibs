// canhe-zhi.c 参合指
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
//inherit F_SSERVER;
inherit SKILL;
string *xue_name = ({ 
        "劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
        "幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

string *xue2_name = ({
        MAG "$N默运神元神功，将内力聚于手指，平平淡淡毫无花俏地点向$n的膻中穴" NOR,
        YEL "$N两掌竖合，掌心微虚，如莲花之开放，接着双手食指轻轻一弹，两股指风同时袭向$n" NOR,
        WHT "$N凌空虚点数指，数道指风合成一股剑气，直向$n攻去"NOR,
        RED "$N缓缓举手，五指先是箕张，再缓缓拢指合拳，霎时生出气凝河岳般的剑气狂扬" NOR,
        HIR "$N指风犀利，似一道无形剑气，将$n笼罩于内，$n只觉胸口一痛，全身真气狂泻而出" NOR
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



mapping *action = ({
([      "action" : "$N劲风激荡，双指错落搭置，一招"+(order[random(13)])+"「目不识丁」"NOR"凶狠地向$n的$l插去",
        "force" : 100,
        "dodge" : 15,
        "damage": 209,
		"lvl" : 0,
		"weapon" : "指风",
        "skill_name" : "目不识丁",
        "damage_type" : "刺伤"
]),
([      "action" : "$N大吼一声，十指上下分飞，一招"+(order[random(13)])+"「画龙点睛」"NOR"，双指直取$n的$l",
        "force" : 130,
        "dodge" : 18,
		"damage": 315,
		"weapon" : "指风",
        "lvl" : 20,
        "skill_name" : "画龙点睛",
        "damage_type" : "刺伤"
]),
([      "action" : "$N十指互错，虚幻虚实，一招"+(order[random(13)])+"「扑朔迷离」"NOR"，前后左右，瞬息间向$n攻出了六招",
        "force" : 170,
        "dodge" : 15,
		"damage": 320,
		"weapon" : "指风",
        "lvl" : 40,
        "skill_name" : "扑朔迷离",
        "damage_type" : "刺伤",
]),
([      "action" : "$N身行腾空而起，一招"+(order[random(13)])+"「受宠若惊」"NOR"，来势奇快，向$n的$l猛插下去",
        "force" : 200,
        "dodge" : 10,
        "damage": 325,
		"weapon" : "指风",
		"lvl" : 60,
        "skill_name" : "受宠若惊",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身行一闪，若有若无捱到$n身前，一招"+(order[random(13)])+"「滔滔不绝」"NOR"，插向$n的$l",
        "force" : 220,
        "dodge" : 15,
		"damage": 330,
		"weapon" : "指风",
        "lvl" : 70,
        "skill_name" : "滔滔不绝",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「退避三舍」"NOR"，右手一拳击出，左掌化指，一掌一指凌空击向$n的$l",
        "force" : 200,
        "dodge" : 20,
        "damage": 230,
        "lvl" : 80,
        "skill_name" : "退避三舍",
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌化指，指中带掌，双手齐推，一招"+(order[random(13)])+"「卧薪尝胆」"NOR"，一股排山倒海的内力，直扑$n$l",
        "force" : 260,
        "dodge" : 25,
        "damage": 130,
        "lvl" : 90,
        "skill_name" : "卧薪尝胆",
        "damage_type" : "内伤"
]),
([      "action" : "$N突然身行急转，一招"+(order[random(13)])+"「相煎何急」"NOR"，十指飞舞，霎时之间将$n四面八方都裹住了",
        "force" : 220,
        "dodge" : 25,
        "damage": 330,
        "lvl" : 100,
        "skill_name" : "相煎何急",
        "damage_type" : "震伤"
]),
([      "action": "$N双指并拢虚点而出，合「"NOR + MAG "天竺佛指" NOR "」及"
                  "「" NOR + MAG "修罗指" NOR "」为一式，顿时一股罡风直射$n",
        "force" : 280,
        "attack": 50,
        "parry" : 50,
        "dodge" : 55,
        "lvl" : 200,
        "damage": 160,
        "weapon" : HIR "参合破体剑气" NOR,
        "damage_type" : "刺伤"
]),
([      "action": "$N双指齐点而出，合「" HIG "莲花指" NOR "」及「" HIG "多罗叶"
                  "指" NOR "」为一式，顿时剑气已笼罩$n全身各处",
        "force" : 260,
        "attack": 50,
        "parry" : 50,
        "dodge" : 55,
        "lvl" : 200,
        "damage": 180,
        "weapon" : HIR "参合破体剑气" NOR,
        "damage_type" : "刺伤"
]),
([      
        "action": "只见$N十指箕张，随手指指点点，将「" HIY "祁连五绝指" NOR "」及"
                  "「" HIY "大天龙指" NOR "」的精髓招式同时使出，\n顿时剑气纵横，尘"
                  "砂四起，逼向$n而去",
        "force" : 260,
        "attack": 50,
        "parry" : 55,
        "dodge" : 55,
        "lvl" : 200,
        "damage": 180,
        "weapon" : HIR "参合破体剑气" NOR,
        "damage_type" : "刺伤"
]),
([      
        "action": "只见$N纵身跃起，长啸一声，凌空而下，「" HIM "七星剑气" NOR "」已射"
                  "向$n全身各处",
        "force" : 260,
        "attack": 20,
        "parry" : 25,
        "dodge" : 25,
        "lvl" : 300,
        "damage": 200,
        "weapon" : HIR "参合破体剑气" NOR,
        "damage_type" : "刺伤"
]),
([      "action": "$N伸出两指，弹指无声，陡见两缕紫气由指尖透出，「" HIW "幽冥剑气" NOR
                  "」射向$n周身大穴",
        "force" : 260,
        "attack": 20,
        "parry" : 30,
        "dodge" : 25,
        "lvl" : 300,
        "damage": 200,
        "weapon" : HIR "参合破体剑气" NOR,
        "damage_type" : "刺伤"
]),
([      "action": "遥见$N伸出一指轻轻拂向$n，指未到，「" HIR "参合剑气" NOR "」已将$n压"
                  "得透不过气来",
        "force" : 280,
        "attack": 20,
        "parry" : 30,
        "dodge" : 35,
        "lvl" : 300,
        "damage": 240,
        "weapon" : HIR "参合破体剑气" NOR,
        "damage_type" : "刺伤"
])
});


int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="qxxy-shou" || combo=="xingyi-zhang"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练参合指必须空手。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("你的神元功火候不够，无法学参合指。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练参合指。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (random(2)==0 && random(me->query_dex()) >= 25 && me->query_skill("canhe-zhi",1) > 200 &&
             me->query_skill("parry",1) > 80 
             && random(10)>5
             ) {
                me->add("neili", -30);
                return ([
                "action": HIY "$N默运神元神功，指风轻飘飘地点向$n，一股内劲无声无息的绕向$n周身大穴！"NOR,
                "force": 650,
                "dodge": 35,
                "damage": 635,
                "damage_type": "内伤"]);
        }
        if (random(2)==0 && random(me->query_dex()) >= 30 && me->query_skill("canhe-zhi",1)> 200 &&
                me->query_skill("parry",1) > 120 
                && random(10)>5){
                me->add("qi",-30);            
                me->add("neili", -50);
                return ([
                "action": HIY "$N指风犀利，似一道无形剑气，将$n笼罩于内！$n只见眼前剑光闪动，茫然不知所措。"NOR,
                "force": 780,
                "dodge": 45,
                "damage": 735,
                "damage_type": "刺伤"]);
        }
        level   = (int) me->query_skill("canhe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        int lvl = me->query_skill("canhe-zhi", 1);
        int i = sizeof(action);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["canhe-zhi"])
                while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jing") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练参合指。\n");
        me->receive_damage("jing", 20);
        me->add("neili", -10);
		return 1;
}
string perform_action_file(string action)
{
        return __DIR__"canhe-zhi/" + action;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        string name, weapon;
        name = xue_name[random(sizeof(xue_name))];

	if( damage_bonus < 20 ) return 0; 
         if( damage_bonus > 20 && random(3)==0 ) 
{
        victim->receive_wound("qi", damage_bonus/2+10 );
        return HIY "只听一声惨嚎，一股鲜血从$n被指中的伤口喷出！\n" NOR;	
}

                if (random(5)==0 && (me->query("neili") > 200) && random(me->query_skill("canhe-zhi", 1)) > 60)
                {
                        victim->start_busy(2);
                        me->add("neili",-30);
                        victim->receive_wound("qi", damage_bonus / 2 + 30);
                        if (victim->query("neili") <= (damage_bonus / 2 + 30))
                                victim->set("neili", 0);
                        else
                                victim->add("neili", - damage_bonus / 2 + 30);
                                
                        return HIW "$N默运神元神功，指风轻飘飘地点向$n，一股内劲无声无息的绕向$n周身大穴！\n"
                               HIW "$n只觉全身一麻，已被一招点中「" HIR + name + HIW "」！\n" NOR;
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