// dragon-strike.c 降龙十八掌 
// by Lonely 

#include <ansi.h> 
#include <combat.h>

inherit SKILL; 

string main_skill() { return "yinyang-shiertian"; }

mapping *action = ({ 
([      "action" : "$N双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向$n的$l", 
        "force"  : 440, 
        "attack" : 100, 
        "dodge"  : 90, 
        "parry"  : 90, 
        "damage" : 100, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",     
        "force"  : 480, 
        "attack" : 100, 
        "dodge"  : 91, 
        "parry"  : 91, 
        "damage" : 100, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N右掌一招「见龙在田」，迅捷无比地劈向$n的$l", 
        "force"  : 470, 
        "attack" : 100, 
        "dodge"  : 92, 
        "parry"  : 92, 
        "damage" : 100, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N双掌施出一招「鸿渐于陆」，隐隐带着风声拍向$n的$l", 
        "force"  : 460, 
        "attack" : 100, 
        "dodge"  : 93, 
        "parry"  : 93, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N左掌聚成拳状，右掌一招「潜龙勿用」缓缓推向$n的$l", 
        "force"  : 480, 
        "attack" : 100, 
        "dodge"  : 94, 
        "parry"  : 94, 
        "damage" : 90, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N施出一招「利涉大川」，右掌插腰，左掌劈向$n的$l", 
        "force"  : 450, 
        "attack" : 100, 
        "dodge"  : 95, 
        "parry"  : 95, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N使出「突如其来」，右掌从不可能的角度向$n的$l推出", 
        "force"  : 450, 
        "attack" : 100, 
        "dodge"  : 96, 
        "parry"  : 96, 
        "damage" : 90, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N大吼一声，双掌使出「震惊百里」，不顾一切般击向$n", 
        "force"  : 490, 
        "attack" : 100, 
        "dodge"  : 97, 
        "parry"  : 97, 
        "damage" : 120, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N使出「或跃在渊」，向$n的$l连拍数掌", 
        "force"  : 460, 
        "attack" : 100, 
        "dodge"  : 98, 
        "parry"  : 98, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N身形滑动，双掌使一招「双龙取水」一前一后按向$n的$l", 
        "force"  : 460, 
        "attack" : 100, 
        "dodge"  : 99, 
        "parry"  : 99, 
        "damage" : 100, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N使出「鱼跃于渊」，身形飞起，双掌并在一起向$n的$l劈下",     
        "force"  : 450, 
        "attack" : 105, 
        "dodge"  : 100, 
        "parry"  : 100, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N双掌立起，使出「时乘六龙」向$n连砍六下", 
        "force"  : 470, 
        "attack" : 100, 
        "dodge"  : 101, 
        "parry"  : 101, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N使出「密云不雨」，左掌封住$n的退路，右掌斜斜地劈向$l",     
        "force"  : 460, 
        "attack" : 100, 
        "dodge"  : 102, 
        "parry"  : 102, 
        "damage" : 100, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N使出「损则有孚」，双掌软绵绵地拍向$n的$l", 
        "force"  : 490, 
        "attack" : 105, 
        "dodge"  : 103, 
        "parry"  : 103, 
        "damage" : 100, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N脚下一转，突然欺到$n身前，一招「龙战于野」拍向$n的$l",     
        "force"  : 480, 
        "attack" : 110, 
        "dodge"  : 104, 
        "parry"  : 105, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N门户大开，一招「履霜冰至」向$n的$l劈去", 
        "force"  : 460, 
        "attack" : 100, 
        "dodge"  : 105, 
        "parry"  : 100, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N使出「羝羊触蕃」，双掌由下往上击向$n的$l", 
        "force"  : 480, 
        "attack" : 110, 
        "dodge"  : 106, 
        "parry"  : 100, 
        "damage" : 110, 
        "damage_type": "震伤" 
]), 
([      "action" : "$N左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向$n的$l",     
        "force"  : 520, 
        "attack" : 120, 
        "dodge"  : 120, 
        "parry"  : 120, 
        "damage" : 100, 
        "damage_type": "震伤" 
]), 
}); 

// string main_skill() { return "dragon-strike"; } 

mapping sub_skills = ([ 
       "kanglong-youhui"  : 80,        // 1 
       "feilong-zaitian"  : 80,        // 2 
       "jianlong-zaitian" : 80,        // 3 
       "hongjian-yulu"    : 80,        // 4 
       "qianlong-wuyong"  : 80,        // 5 
       "lishe-dachuan"    : 80,        // 6 
       "turu-qilai"       : 80,        // 7 
       "zhenjing-baili"   : 80,        // 8 
       "huoyue-zaiyuan"   : 80,        // 9 
       "shuanglong-qushui": 80,        // 10 
       "yuyue-yuyuan"     : 80,        // 11 
       "shicheng-liulong" : 80,        // 12 
       "miyun-buyu"       : 80,        // 13 
       "sunze-youfu"      : 80,        // 14 
       "longzhan-yuye"    : 80,        // 15 
       "lvshuang-bingzhi" : 80,        // 16 
       "diyang-chufan"    : 80,        // 17 
       "shenlong-baiwei"  : 80,        // 18 
]); 

int get_ready(object me) 
{ 
       return 1; 
} 

int get_finish(object me) 
{ 
       if (me->query("str") < 31 || me->query_str() < 45) 
       { 
               tell_object(me, "你演练完毕，手臂又酸又软，几乎抬不起来。\n"); 
               return 0; 
       } 

       if (me->query("con") < 24 || me->query_con() < 37) 
       { 
               tell_object(me, "你演练完毕，就觉得眼前金星乱冒，太阳穴突突的跳。\n"); 
               return 0; 
       } 

       if ((int)me->query_skill("force") < 150) 
       { 
               tell_object(me, "你演练完毕，几乎虚脱，自己的内功水平看来还有待提高。\n"); 
               return 0; 
       } 

       if ((int)me->query("max_neili") < 1500) 
       { 
               tell_object(me, "你演练完毕，丹田提不起半点力来，看来应该继续锻炼内力。\n"); 
               return 0; 
       } 

       if (random(10) < 5) 
       { 
               tell_object(me, "你对十八掌的奥妙颇有领悟，或许再演练一次就能够融会贯通。\n"); 
               return 0; 
       } 

       tell_object(me, HIY "你一气呵成，将十八掌从头到尾演练了一变，心中顿悟，通\n" 
                           "晓了降龙十八掌的奥妙精髓，融会贯通了掌法的精微之处，\n" 
                           "再也非拆开使用那么那么简单。\n" NOR); 
       return 1; 
} 

mapping query_sub_skills() 
{ 
       return sub_skills; 
} 

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }   

int valid_learn(object me) 
{ 
       if ((int)me->query("str") < 31) 
               return notify_fail("就你这身子骨还练降龙十八掌？小心弄折了胳膊。\n"); 

       if ((int)me->query("con") < 24) 
               return notify_fail("算了吧，你先天根骨不好，别强学了。\n"); 

       if ((int)me->query_skill("force") < 150) 
               return notify_fail("你的内功火候不够，无法学习降龙十八掌。\n"); 

       if ((int)me->query("max_neili") < 1500) 
               return notify_fail("你的内力这么差，怎能融会贯通降龙十八掌？\n"); 

       if ((int)me->query_skill("strike", 1) < 30) 
               return notify_fail("你的基本掌法火候不够，无法学习降龙十八掌。\n"); 

       if ((int)me->query_skill("strike", 1) < (int)me->query_skill("dragon-strike", 1)) 
               return notify_fail("你的基本掌法水平有限，无法领会更高深的降龙十八掌。\n"); 

       return 1; 
} 

mapping query_action(object me, object weapon) 
{ 
       mapping a_action;
       int level, tmp;

       level = (int)me->query_skill("dragon-strike", 1);
       if (me->query_temp("xlz/hanglong"))
       {
                tmp = 4 + random(15);
                me->delete_temp("xlz/hanglong");
                return ([
                        "action": HIY "\n$N叫道：「看招！」左腿微屈，右掌划了个圆圈，平推出去，正是降龙十八掌中的「亢龙有悔」。\n" +
                                  "初推出去看似轻描淡写，但一遇阻力，刹时之间连加" + chinese_number(tmp) + "道後劲，一道强似一道，\n" +
                                  "重重叠叠，直至无坚不摧，无强不破！" NOR,
                        "dodge" : 140,
                        "parry" : 140,
                        "attack": 200,
                        "force" : 500 + 40 * tmp,
                        "damage": 100 + 20 * tmp,
                        "damage_type": random(2)?"内伤":"瘀伤" 
                ]);
        }
        
        return action[random(sizeof(action))]; 
} 

// int double_attack() { return 1; } 

int practice_skill(object me) 
{ 
        int cost; 

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail("练降龙十八掌必须空手。\n"); 

        if ((int)me->query("qi") < 110) 
                return notify_fail("你的体力太低了。\n"); 

        // cost = me->query_skill("dragon-strike", 1) / 5 + 90; 
        if ((int)me->query("neili") < 110) 
                return notify_fail("你的内力不够练降龙十八掌。\n"); 

        me->receive_damage("qi", 100); 
        me->add("neili", -100); 
        return 1; 
} 

mixed hit_ob(object me, object victim, int damage) 
{
        mixed result;
        string msg;
        int lvl; 
        
        lvl = me->query_skill("dragon-strike", 1); 
        
        if (damage < 100 || lvl < 150) return;
        
        result = ([ "damage" : damage ]);
        
        if (random(10) < 2)
                result += ([ "msg" : HIY "$N" HIY "一掌既出，身子抢前，又是一招「亢龙有悔」，" 
                                     "後掌推前掌，双掌力道并在一起，排山倒海的压将过来。\n"
                                     HIR "$n" HIR "那曾见过这样霸道的掌力，顿时身受重创，哇的一声，吐出一口鲜血！\n" 
                                     NOR ]);
        else
        {    
                msg = random(2) ? HIR "$n" HIR "一声惨叫，胸前「咔嚓咔嚓」几声脆" 
                                  "响，口中鲜血狂喷。\n" NOR :
                                  HIR "只听$n" HIR "前胸「咔嚓」一声脆响，竟像是" 
                                  "肋骨断折的声音。\n" NOR;
                result += ([ "msg" : msg ]);
        }
                
        return result;
} 

string perform_action_file(string action) 
{ 
        object me = this_player();
        
        if (! me->query("family/family_name") || me->query("family/family_name") != "丐帮")
                return 0;
                
        return __DIR__"dragon-strike/" + action; 
} 

void skill_improved(object me) 
{ 
        int i; 
        string *sub_skillnames; 

        sub_skillnames = keys(sub_skills); 
        for (i = 0; i < sizeof(sub_skillnames); i++) 
               me->delete_skill(sub_skillnames); 
} 

/*
// Let parry skill take its special effort. 
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp, level;

        if ((level = (int)me->query_skill("dragon-strike", 1)) < 100 ||
            ! living(me) || objectp(me->query_temp("weapon")))
                return;

        mp = ob->query_skill("martial-cognize", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) * 2 / 3 +
             me->query_skill("dragon-strike", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "不待回身，一招「神龙摆尾」，反手还劈一掌。\n"
                                    "$N" HIC "见这招来势凶狠，不敢硬接，纵身避开。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIC "只见$n" HIC "左掌圆劲，右掌直势，使招「见龙在田」，挡在身前。\n"
                                    "这一招纯是防御，却是在双方之间布了一道坚壁。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIC "$n" HIC "当下不敢怠慢，双掌飞舞，将自己全身笼罩在掌力之下。\n"
                                    "这一守当真是稳若渊停岳峙，直无半点破绽。\n" NOR]);
                        break;
                }
                return result;
        } 
}
*/

int query_effect_parry(object attacker, object me) 
{
        int lvl;
        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("dragon-strike", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

// 技能典故介绍 
string query_description()  
{
        return 
        "降龙十八掌勇往直前，它的威力甚至超过了六脉神剑，当然"
        "综合起来与六脉神剑相差还颇有距离。关于降龙十八掌的"
        "定位问题颇有争议，这里是依据萧峰手下的功夫定位的。"
        "当然学习还是要找洪七公，降龙十八掌乃是丐帮专用武功，"
        "其它门派的人物不可学习，丐帮学习的条件是你的妻子或"
        "女友能够拿得出像样的叫化鸡给洪七公吃，如何作菜这就靠自"
        "己摸索了。有几处地方可以学习厨艺。不过如果你没有 31"
        " 点的先天膂力和 24 点的先天根骨，就省省，可不必摸索了。"
        "降龙十八掌要先将十八掌学齐到 80 级，然后通过演练合"
        "成降龙十八掌。";
}

