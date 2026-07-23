// Cuff：  查拳、燕青拳、太祖长拳、六合拳、少林长拳、八极拳
// Claw：  大擒拿手、小擒拿手、鹰爪功、虎爪手
// Strike：八卦掌、武当绵掌、游身八卦掌

#include <ansi.h>
inherit SKILL;
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 

mapping *action = ({
([      "action": "$N单手上抬，一招查拳的「冲天炮」，对准$n的$l猛击下去",
        "force" : 420,
        "attack": 130,
        "dodge" : 45,
        "parry" : 45,
        "damage": 180,
        "damage_type":  "砸伤"
]),
([      "action": "$N一招燕青拳的「白鹤亮翅」，身子已向左转成弓箭步，两臂向后成钩手，呼\n"
                  "的一声轻响，反击$n$l",
        "force" : 512,
        "attack": 145,
        "dodge" : 10,
        "parry" : 75,
        "damage": 185,
        "damage_type":  "瘀伤"
]),
([      "action": "$N往后一纵，施展小擒拿手的手法，双手对着$n$l处的关节直直抓去",
        "force" : 410,
        "attack": 170,
        "dodge" : 35,
        "parry" : 35,
        "damage": 278,
        "damage_type":  "抓伤"
]),
([      "action": "$N左拳拉开，右拳转臂回扰，一招少林的少林长拳突然击出，带着许许风声贯向$n",
        "force" : 460,
        "attack": 150,
        "dodge" : 62,
        "parry" : 60,
        "damage": 290,
        "lvl"   : 30,
        "damage_type":  "瘀伤"
]),
([      "action": "只见$N运足气力，使出八极拳中的「八极翻手式」，双掌对着$n的$l平平攻去",
        "force" : 480,
        "attack": 160,
        "dodge" : 40,
        "parry" : 40,
        "damage": 285,
        "damage_type":  "瘀伤"
]),
([      "action": "$N大喝一声，左手往$n身后一抄，右掌往$n反手击去，正是八卦掌的招式",
        "force" : 510,
        "attack": 155,
        "dodge" : 30,
        "parry" : 30,
        "damage": 295,
        "damage_type":  "瘀伤"
]),
([      "action": "$N提气游走，左手护胸，右手一招游身八卦掌的「游空探爪」，迅速拍向$n$l",
        "force" : 510,
        "attack": 150,
        "dodge" : 45,
        "parry" : 45,
        "damage": 310,
        "damage_type":  "瘀伤"
]),
([      "action": "只见$N拉开架式，双手将武当派的绵掌使得密不透风，招招不离$n的$l",
        "force" : 460,
        "attack": 155,
        "dodge" : 160,
        "parry" : 160,
        "damage": 305,
        "damage_type":  "瘀伤"
]),
([      "action": "$N突然飞身一跃而起，双手握做爪状，朝着$n的$l猛然抓去，凛然是鹰爪功的招式",
        "force" : 470,
        "attack": 185,
        "dodge" : 60,
        "parry" : 60,
        "damage": 355,
        "damage_type":  "抓伤"
]),
([      "action": "只见$N身形一矮，双手翻滚，合抱为圈，一招太极拳「云手」直拿$n的$l",
        "force" : 350,
        "attack": 90,
        "dodge" : 210,
        "parry" : 330,
        "damage": 65,
        "damage_type":  "瘀伤"
]),
([      "action": "只见$N跨前一步，左手一记大擒拿手护住上盘，右手顺势一带，施一招摔碑手击向$n",
        "force" : 520,
        "attack": 155,
        "dodge" : 41,
        "parry" : 37,
        "damage": 303,
        "damage_type":  "瘀伤"
]),
([      "action": "$N一个转身，趁$n不备，反手将$n牢牢抱住猛的朝地面摔去，竟然是蒙古的摔角招式",
        "force" : 560,
        "attack": 185,
        "dodge" : 75,
        "parry" : 60,
        "damage": 325,
        "damage_type":  "摔伤"
]),
});

string main_skill() { return "baihua-cuoquan"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练百花错拳必须空手。\n");

        if (me->query("int") < 28)
                return notify_fail("你的先天悟性太差，无法学习百花错拳。\n");

        if (me->query("dex") < 23)
                return notify_fail("你的先天身法孱弱，无法学习百花错拳。\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("你的内力修为远远不足，难以练习百花错拳。\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("你的内功火候尚浅，无法学习百花错拳。\n");

        if ((int)me->query_skill("unarmed", 1) < 150)
                return notify_fail("你的拳脚根基有限，无法体会百花错拳要诣。\n");

        if ((int)me->query_skill("cuff", 1) < 100)
                return notify_fail("你的拳法根基有限，无法体会百花错拳要诣。\n");

        if ((int)me->query_skill("claw", 1) < 100)
                return notify_fail("你的爪法根基有限，无法体会百花错拳要诣。\n");


       if (((int)me->query_skill("houquan", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的猴拳太低了。\n");
       if (((int)me->query_skill("yunlong-zhua", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙爪太低了。\n");

       if (((int)me->query_skill("yunlong-shou", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙手太低了。\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙神功太低了。\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙身法太低了。\n");

        return 1;
}

int valid_enable(string usage) { return usage=="cuff" ||  usage=="parry"; }  

int valid_combine(string combo) { return combo=="houquan" || combo=="bazhen-zhang"; }

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("baihua-cuoquan", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100 )
                return notify_fail("你现在手足酸软，休息一下再练吧。\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("你的内力不够了。\n");
       if (((int)me->query_skill("houquan", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的猴拳太低了。\n");
       if (((int)me->query_skill("yunlong-zhua", 1)+100) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙爪太低了。\n");

       if (((int)me->query_skill("yunlong-shou", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙手太低了。\n");
       if (((int)me->query_skill("yunlong-shengong", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙神功太低了。\n");
       if (((int)me->query_skill("yunlong-shenfa", 1)+200) < (int)me->query_skill("baihua-cuoquan", 1))
               return notify_fail("你的云龙身法太低了。\n");

        me->receive_damage("qi", 80);
        me->add("neili", -120);

        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("baihua-cuoquan", 1);

        if (damage_bonus < 100 || lvl < 150) return 0;
if (me->query_skill_mapped("force") != "yunlong-shengong" )
                return;
        if (random(3)==0)
        {
                victim->receive_wound("qi", (damage_bonus ) / 2+10);
                return HIR "只听$n" HIR "前胸「咔嚓」一声脆响，竟像是"
                       "肋骨断折的声音。\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"baihua-cuoquan/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("baihua-cuoquan",1);
        level2= (int) me->query_skill("yunlong-shengong",1);
        skill = me->query_skill("yunlong-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunlong-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunlong-shengong"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIR"$N"+HIR+"$N左手聚成虎爪状! 「凝血神抓」一把抓住$n的"+ xue_name[random(sizeof(xue_name))] +NOR;
           message_vision(msg, me, ob);
if (ob->query("qi") > damage2)
{
ob->apply_condition("zhua_poison",10);
		ob->receive_damage("qi", damage2/2);
		ob->receive_wound("qi", damage2/2);
}
 if (!ob->is_busy() && random(3)==0) ob->start_busy(2);  
}
 if ( random(4) == 0 && random(level) > 150){
         msg = GRN"$N面对$n的攻势 施出查拳的「冲天炮」，身形一闪，双手同时攻向$n。\n"NOR;
         msg += GRN"$n感到胸口一闷，尽然不能动了!!。\n"NOR;
ob->start_busy(4);
message_vision(msg, me, ob);
}
           return j;
}      
