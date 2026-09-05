// huashan-jianfa.c 华山剑法
// modified by darken@SJ

inherit SKILL;
#include <combat.h>
#include <ansi.h>
mapping *action_male = ({
([      "action" : "$N一招「白云出岫」，做一起首试，顿时豪情一片，手中$w蓄势点向$n的$l",
        "force" : 140,
        "dodge" : 5,
        "parry" : 3,
        "damage" : 40,               
        "lvl" : 0,
        "skill_name" : "白云出岫",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「有凤来仪」，剑势飞舞而出，轻盈灵动，$w闪烁不定，刺向$n的$l",
        "force" : 170,
        "dodge" : 4,
        "parry" : 10,
        "damage" : 60,
        "lvl" : 10,
        "skill_name" : "有凤来仪",
        "damage_type" : "刺伤" 
]),

([      "action" : "$N一招「天绅倒悬」，满场游走，$w自上而下划出一个大弧，向$n劈砍下去",
        "force" : 200,
        "dodge" : 10,
        "parry" : -5,
        "damage" : 100,
        "lvl" : 30,
        "skill_name" : "天绅倒悬",
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w看似来势既缓，又无力道，但是$N突然剑锋一转，使出「白虹贯日」直刺$n的$l",
        "force" : 240,
        "dodge" : 20,
        "parry" : 5,
        "damage" : 110,
        "lvl" : 60,
        "skill_name" : "白虹贯日",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，满场游走，一身青衫化成了一片青影，一招「苍松迎客」直刺$n的$l",
        "force" : 280,
        "dodge" : 10,
        "parry" : 10, 
        "damage" : 130,
        "lvl" : 80,
        "skill_name" : "苍松迎客",
        "damage_type" : "刺伤"
]),

([      "action" : "$N手中$w斜晃反挑，一式「无边落木」，这一下出招急快，抑且如梦如幻，直逼$n的$l",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "damage" : 115,
        "lvl" : 100,
        "skill_name" : "无边落木",
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然右手后缩，跟着剑柄疾收，似乎要撞上自己的胸膛，突然一式「青山隐隐」,反身刺向$n",
        "force" : 320,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 145,
        "lvl" : 120,
        "skill_name" : "青山隐隐",
        "damage_type" : "刺伤"
]), 
([      "action" : "$N右臂轻提，手中$w提了两尺，剑尖一抬，一招「古柏森森」只等$n撞了上来",      
        "force" : 340,
        "dodge" : 10,
        "parry" : 2,
        "damage" : 135,
        "lvl" : 150,
        "skill_name" : "古柏森森",
        "damage_type" : "刺伤"
]),
});

mapping *action_famale = ({
([      "action" : "$N使出「有凤来仪」，剑势飞舞而出，轻盈灵动，$w闪烁不定，刺向$n的$l",
        "force" : 120,
        "dodge" : 0,
        "parry" : 5,
        "damage" : 35,
        "lvl" : 0,
        "skill_name" : "有凤来仪",
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w看似来势既缓，又无力道，但是$N突然剑锋一转，使出「白虹贯日」直刺$n的$l",
        "force" : 150, 
        "dodge" : 5,
        "parry" : -5,
        "damage" : 70,
        "lvl" : 16,
        "skill_name" : "白虹贯日",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，满场游走，一身青衫化成了一片青影，一招「苍松迎客」直刺$n的$l",
        "force" : 180,
        "dodge" : 0,
        "parry" : 10,
        "damage" : 90,
        "lvl" : 26,
        "skill_name" : "苍松迎客",
        "damage_type" : "刺伤"
]),

([      "action" : "$N手中$w斜晃反挑，一式「无边落木」，这一下出招急快，抑且如梦如幻，直逼$n的$l",
        "force" : 220,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 45,
        "lvl" : 35,
        "skill_name" : "无边落木", 
        "damage_type" : "刺伤"
]),
([      "action" : "$N威仪整肃一式「玉井天池」，$w轰然一动，犹如千军万马奔驰而来，疾疾刺向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "parry" : 10,
        "damage" : 110,
        "lvl" : 54,
        "skill_name" : "玉井天池",
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑转一式「叠翠浮青」，俨然长枪大戟，黄沙千里，$w电闪雷鸣，将$n笼罩于重重剑气之中",
        "force" : 260,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 130,
        "lvl" : 65,
        "skill_name" : "叠翠浮青",
        "damage_type" : "刺伤"
]),

([      "action" : "$N左手向外一分，右手$w向右掠出一招「无双无对」，剑气森然地向$n的$l挥去",
        "force" : 280,
        "dodge" : 5, 
        "parry" : 5,
        "damage" : 125,
        "lvl" : 92,
        "skill_name" : "无双无对",
        "damage_type" : "刺伤"
]),
([      "action" : "$N轻叹一声，手中$w怀中一抱，一式「落花无意」，$w锵然跃出倏的化作几点带露的桃花，飘然飞向$n的$l",
        "force" : 300,
        "dodge" : 5,
        "parry" : 10,
        "damage" : 145,
        "lvl" : 100,
        "skill_name" : "落花无意",
        "damage_type":  "刺伤"
]),
});

mapping *action_19 = ({
([      "action":HIW"\n$N使一式「悠悠顺自然」，手中$w"+HIW"嗡嗡微振，幻成一条白光刺向$n的$l"NOR,
        "force" : 120,
        "dodge" : -10,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "悠悠顺自然",
        "damage_type":  "刺伤"
]),
([      "action":HIC"\n$N错步上前，使出「来去若梦行」，剑意若有若无，$w"+HIC"淡淡地向$n的$l挥去"NOR,
        "force" : 140,
        "dodge" : -10,
        "damage": 20,
        "lvl" : 8,
        "skill_name" : "来去若梦行",
        "damage_type":  "割伤"
]),
([      "action":HIM"\n$N一式「志当存高远」，纵身飘开数尺，运发剑气，手中$w"+HIM"遥摇指向$n的$l"NOR,
        "force" : 160,
        "dodge" : 5,
        "damage": 30,
        "lvl" : 15,
        "skill_name" : "志当存高远",
        "damage_type":  "刺伤"
]),
([      "action":HIG"$N纵身轻轻跃起，一式「表里俱澄澈」，剑光如水，一泻千里，洒向$n全身"NOR,
        "force" : 180,
        "dodge" : 10,
        "damage": 35,
        "lvl" : 20,
        "skill_name" : "表里俱澄澈",
        "damage_type":  "割伤"
]),
([      "action":HIY"$N手中$w"+HIY"中宫直进，一式「随风潜入夜」，无声无息地对准$n的$l刺出一剑"NOR,
        "force" : 220,
        "dodge" : 15,
        "damage": 40,
        "lvl" : 30,
        "skill_name" : "随风潜入夜",
        "damage_type":  "刺伤"
]),
([      "action":HIR"$N手中$w"+HIR"一沉，一式「润物细无声」，无声无息地滑向$n的$l"NOR,
        "force" : 250,
        "dodge" : 15,
        "damage": 40,
        "lvl" : 40,
        "skill_name" : "润物细无声",
        "damage_type":  "割伤"
]),
([      "action":WHT"\n$N手中$w"+WHT"斜指苍天，剑芒吞吐，一式「云龙听梵音」，对准$n的$l斜斜击出"NOR,
        "force" : 280,
        "dodge" : 25,
        "damage": 45,
        "lvl" : 50,
        "skill_name" : "云龙听梵音",
        "damage_type":  "刺伤"
]),
([      "action":RED"$N左指凌空虚点，右手$w"+RED"逼出丈许雪亮剑芒，一式「万里一点红」刺向$n的咽喉"NOR,
        "force" : 320,
        "dodge" : 15,
        "damage": 55,
        "lvl" : 60,
        "skill_name" : "万里一点红",
        "damage_type":  "刺伤"
]),
([      "action":CYN"$N合掌跌坐，一式「我心化云龙」，$w"+CYN"自怀中跃出，如疾电般射向$n的胸口"NOR,
        "force" : 380,
        "dodge" : 15,
        "damage": 60,
        "lvl" : 70,
        "skill_name" : "我心化云龙",
        "damage_type":  "刺伤"
]),
([      "action":HIC"\n$N呼的一声拔地而起，一式「日月与同辉」，$w"+HIC"幻出万道光影，将$n团团围住"NOR,
        "force" : 420,
        "dodge" : 15,
        "damage": 70,
        "lvl" : 80,
        "skill_name" : "日月与同辉",
        "damage_type":  "内伤"
]),
([      "action":MAG"$N随风轻轻飘落，一式「清风知我意」，手中$w"+MAG"平指，缓缓拍向$n脸颊"NOR,
        "force" : 450,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 90,
        "skill_name" : "清风知我意",
        "damage_type":  "内伤"
]),
([      "action":GRN"$N剑尖微颤作龙吟，一招「高处不胜寒」，切骨剑气如飓风般裹向$n全身"NOR,
        "force" : 500,
        "dodge" : 15,
        "damage": 90,
        "lvl" : 100,
        "skill_name" : "高处不胜寒",
        "damage_type":  "内伤"
]),
([      "action":YEL"$N募的使一招「红叶舞秋山」，顿时剑光中几朵血花洒向$n全身"NOR,
        "force" : 500,
        "dodge" : 25,
        "damage": 100,
        "lvl" : 110,
        "skill_name" : "红叶舞秋山",
        "damage_type":  "内伤"
]),
});

mapping *action_kf = ({
([      "action":HBCYN"$N手上$w"+HBCYN"慢慢点出，突然间在空中一颤，一招「泉鸣芙蓉」，剑刃暗发嗡嗡之声，$w"+HBCYN"来路如鬼如魅，顷刻间竟然已绕到了$n背后",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "泉鸣芙蓉",
        "damage_type":  "刺伤"
]),
([      "action":HBCYN"$N全不理会对方攻势来路，使出一招「鹤翔紫盖」，变化莫测地攻向$n，剑势竟无丝毫迹象可寻",
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage": 25,
        "lvl" : 10,
        "skill_name" : "鹤翔紫盖",
        "damage_type":  "刺伤"
]),
([      "action":HBCYN"$N手中$w"+HBCYN"晃动，「石廪书声」使将出来，剑招奇变横生，$n瞧得心惊神眩，不知$N究竟出了多少招",
        "force" : 260,
        "dodge" : 8,
        "parry" : 8,
        "damage": 30,
        "lvl" : 20,
        "skill_name" : "石廪书声",
        "damage_type":  "割伤"
]),
([      "action":HBCYN"$N$w"+HBCYN"如云雾变化，正是一招「天柱云气」，极尽诡奇之能事，动向无定，不可捉摸，$n觉一阵眼花缭乱，顿感穷於应付",
        "force" : 330,
        "dodge" : 10,
        "parry" : 15,
        "damage": 40,
        "lvl" : 30,
        "skill_name" : "天柱云气",
        "damage_type":  "割伤"
]),
([      "action":HBCYN"$N突然间身子往斜里窜出，使出「雁回祝融」，听$w"+HBCYN"陡发铮然之音，无数光环乱转，霎时之间已将$n裹在一团剑光之中",
        "force" : 410,
        "dodge" : 10,
        "parry" : 10,
        "damage": 50,
        "lvl" : 50,
        "skill_name" : "雁回祝融",
        "damage_type":  "割伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili", 1) < 100)
                return notify_fail("你的内力不够。\n"); 
        if ((int)me->query_skill("zixia-shengong", 1) < 20
                && me->query_skill("huashan-neigong", 1) < 20)
                return notify_fail("你的紫霞功火候太浅。\n");
        if( (int)me->query_skill("sword", 1) < 10 )
                return notify_fail("你的基本剑法还不够娴熟，无法学习华山剑法。\n");
        if ((int)me->query_skill("poyu-quan", 1) < 15)
                return notify_fail("你的破玉拳太弱，无法学习到华山剑法的精髓。\n");
        return 1;
}


mapping query_action(object me, object weapon)
{
        int i, level;

        level=me->query_skill("huashan-jianfa",1);

        if( me->query_temp("hsj_19")) {
        for(i = sizeof(action_19); i > 0; i--) 
                if(level >= action_19[i-1]["lvl"])
                        return action_19[NewRandom(i, 20, level/5)];
        }
        if( me->query_temp("hsj_kf")) {
        for(i = sizeof(action_kf); i > 0; i--) 
                if(level >= action_kf[i-1]["lvl"])
                        return action_kf[NewRandom(i, 20, level/5)];
        }
        if( me->query("gender") != "女性" ) {
        for(i = sizeof(action_male); i > 0; i--)
                if(level >= action_male[i-1]["lvl"])
                        return action_male[NewRandom(i, 20, level/5)];
        }
        for(i = sizeof(action_famale); i > 0; i--) 
                if(level >= action_famale[i-1]["lvl"]) return action_famale[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力不够练华山剑法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

string perform_action_file(string action)
{
               return __DIR__"huashan-jianfa/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        int p;
        string msg;

        p = (int)me->query("qi")*100/(int)me->query("max_qi");
        if (p < 20 &&
        me->query_skill_mapped("sword") == "huashan-jianfa" &&
        me->query_skill_prepared("cuff") == "poyu-quan" &&
        (20 - p) > random(10) &&
        weapon && !me->is_busy() &&
        me->query("env/zhijian"))
        {
                msg = "$N手中长剑被$n一击，脱手飞出！\n"NOR;
                weapon->move(environment(me));
                msg += HIW"$N灵机一动，右手五指急刺，以手指使出一招「金玉满堂」！\n"NOR;
                if (random(me->query_int()) > ob->query_int()/5) {
                        msg += HBRED"结果正中$n的膻中穴！\n"NOR;
                        ob->start_busy(5+random(4));
                } else {
                        msg += HBGRN"结果$n早已料到，轻轻闪过。\n"NOR;
                        me->start_busy(3+random(3));
                }
                message_vision(msg, me, ob);
                return -damage;
        }
        return 0;
}

