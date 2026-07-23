// tiezhang-zhangfa 铁掌帮 铁掌掌法
// by zqb
//update by cool 981010
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action": "$N右掌一拂而起，一招"+(order[random(13)])+"「推窗望月」"NOR"，自侧面连消带打，登时将$n的力道带斜。",
        "dodge": 5,
        "force": 200,
        "damage": 300,
        "parry": 40,
        "lvl": 0,
        "damage_type": "瘀伤"
]),
([      "action": "$N使一招"+(order[random(13)])+"「分水擒龙」"NOR"，左掌陡然沿着伸长的右臂，飞快的一削而出，斩向$n的$l",
        "dodge": 10,
        "force": 260,
        "damage": 330,
        "parry": 35,
        "lvl": 0,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然使一式"+(order[random(13)])+"「白云幻舞」"NOR"，双臂如旋风一般一阵狂舞，刮起一阵旋转的气浪。 ",
        "dodge": 15,
        "damage": 300,
        "force": 300,
        "parry": 30,
        "lvl": 10,
        "damage_type": "瘀伤"
]),
([      "action": "$N一招"+(order[random(13)])+"「掌中乾坤」"NOR"，猛地侧过身来，右臂自左肋下疾翻而出，拇，中两指扣圈猛弹$n的$l",
        "dodge": 20,
        "damage": 330,
        "force": 280,
        "parry": 25,
        "lvl": 20,
        "damage_type": "瘀伤"
]),
([      "action": "$N一招"+(order[random(13)])+"「落日赶月」"NOR"，伸掌一拍一收，一拍无丝毫力道，一收之间，一股阴柔无比的力道才陡然发出。",
        "dodge": 25,
        "damage": 360,
        "force": 320,
        "parry": 20,
        "lvl": 30,
        "damage_type": "瘀伤"
]),
([      "action": "$N身行暴起，一式"+(order[random(13)])+"「蛰雷为动」"NOR"，双掌横横切出，掌缘才递出，呜呜呼啸之声狂作。",
        "dodge": 20,
        "force": 350,
        "parry": 15,
        "damage": 370,
        "lvl": 40,
        "damage_type": "瘀伤"
]),
([      "action": "$N一招"+(order[random(13)])+"「天罗地网」"NOR"，左掌大圈而出，右掌小圈而出，两股奇异的力道一会之下，击向$n的$l",
        "dodge": 25,
        "force": 400,
        "parry": 10,
        "damage": 380,
        "lvl": 50,
        "damage_type": "瘀伤"
]),
([      "action": "$N一招"+(order[random(13)])+"「五指幻山」"NOR"，猛一吐气，单掌有如推门，另一掌却是迅疾无比的一推即收。",
        "dodge": 30,
        "force": 450,
        "parry": 5,
        "damage": 390,
        "lvl": 60,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然大吼一声，身行疾飞而起，猛向$n直扑而下，空气中暴出“呜”的一声刺耳尖啸。",
        "force": 540,
        "parry": 10,
        "dodge": 40,
        "damage": 400,
                 "lvl": 100,
        "damage_type": "瘀伤"
                ]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="unarmed"; }
int valid_combine(string combo) { return combo=="liumang-quan"; }

mapping query_action(object me, object weapon)
{
                  int i,level,lev;

        if (random(me->query_skill("strike", 1)) > 100 
            && random(me->query_skill("tiezhang-zhangfa", 1)) > 200 
            && me->query_skill("force") > 100
            && me->query("neili") > 30 
            && !me->is_busy()) {
                me->add("neili", -20);
                return ([
                  "action": HIR"$N突然大吼一声，身行疾飞而起，猛向$n直扑而下，空气中暴出“呜”的一声刺耳尖啸。"NOR,
                  "force": 650,
                  "parry": 10,
                  "dodge": 40,
                  "damage": 630,
                  "damage_type": "瘀伤"
                ]);
        }
        level = (int) me->query_skill("tiezhang-zhangfa",1);
                lev   = (int) me->query_skill("guiyuan-tunafa",1);
        
        if (me->query_temp("tzzf") && me->query("jiali") < 50 )
        me->set("jiali",50);
        
          for(i = sizeof(action); i > 0; i--) {
                                 if(level > action[i-1]["lvl"]) {
                               if (me->query_temp("tzzf")) {                
                    return ([  
                    "action" : WHT+action[NewRandom(i, 20, level/5)]["action"]+NOR,
                    "force" : action[NewRandom(i, 20, level/5)]["force"]+random(30),
                    "dodge":action[NewRandom(i, 20, level/5)]["dodge"],
                    "damage": level/4+random(lev/4),
                    "lvl" : action[NewRandom(i, 20, level/5)]["lvl"],
                    "weapon" : "掌刀",
                    "damage_type" : random(2)?"瘀伤":"割伤",
                    ]);
               } else return action[NewRandom(i, 20, level/5)];
                           }
                           }
}


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练铁掌掌法必须空手。\n");
        if ((int)me->query_skill("guiyuan-tunafa", 1) < 10)
                return notify_fail("你的归元吐呐法火候不够，无法练铁掌掌法。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够，无法练铁掌掌法");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("你的本门内功太低了。\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("你的本门轻功太低了。\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("你的通臂六合掌太低了。\n");
        return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("你的内力不够练铁掌掌法。\n");
       if (((int)me->query_skill("guiyuan-tunafa", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("你的本门内功太低了。\n");
       if (((int)me->query_skill("shuishangpiao", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("你的本门轻功太低了。\n");
       if (((int)me->query_skill("tongbi-zhang", 1)+100) < (int)me->query_skill("tiezhang-zhangfa", 1))
               return notify_fail("你的通臂六合掌太低了。\n");
        if (me->query_skill("tiezhang-zhangfa", 1) < 50)
                me->receive_damage("jing", 20);
        else
                me->receive_damage("jing", 30);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tiezhang-zhangfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lev,damage, i;
        object weap;
        int level, jiali, time,level2;
        object weapon;
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("guiyuan-tunafa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "guiyuan-tunafa" && lvl > 300 && random(8)==0)
{
                  msg = HIG"$N深吸一口气，身体如一片落叶随风飘舞,$n头一昏，不知所措!\n"NOR;

victim->start_busy(3);

                return msg;
}
        weap = victim->query_temp("weapon");
        lev =me->query("tiezhang-zhangfa");
	if( damage_bonus < 20 ) return 0;
	if( damage_bonus/2+20  > victim->query_str() ) {
if(me->query_skill("guiyuan-tunafa", 1) > 10 && random(2) == 1)
{
		victim->receive_wound("qi", (damage_bonus ) +10 );
		return HIW "碰! "+ victim->name()+"被掌风扫中！口角上吐出血丝....\n" NOR;
}
        if( (me->query("neili") > 1000)&& (victim->query_temp("weapon"))
                                            && (me->query_temp("tzzf"))
                         && (random(me->query_str()) > victim->query_str()/2) )
                 {      
                                      if (!weap->query("ownmake"))
                        {
                        message_vision(HIW "$N运掌如刀，连击三十六下，只听见"+(order[random(13)])+"「啪」"NOR"地一声，$n手中的" + weap->name()
                                + "已经断为两截！\n" NOR, me, victim );
                        weap->move(environment(me));
                        weap->set("name", "断掉的"+weap->query("name"));
                        weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        } else {
                        message_vision(HIW "$N运掌如刀，连击三十六下，只听见"+(order[random(13)])+"「当」"NOR"地一声，$n手中的" + weap->name()
                                + "差点被刀气震落到地上！\n" NOR, me,victim );
                        victim->start_busy(3);
                                                }
                                                victim->reset_action();
                        me->add("neili", -100);
                        return 1;
                 }

	}
 
       
}

