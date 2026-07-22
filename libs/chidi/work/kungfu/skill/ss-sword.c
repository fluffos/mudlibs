// ss-sword.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N口中朗朗念到：“绿萍涨断莲舟路,断无蜂蝶慕幽香”一招「踏沙行」，\n"
"接着双足轻轻一点，凌空虚踏几步，潇洒的一个转身，不经意的一剑点向$n的眉心。",
                "dodge":                -40,
                "parry":                -80,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N战到浓处,大喝一声：“好！将军奉命即需行，腰中宝剑匣中鸣”，一招「将军令」，\n"
"$w轻舞，$N的手中立刻现出了一朵剑花，剑花爆开了，从不同的角度刺向$n",
                "dodge":                 80,
                "damage":               170,
                "parry":                 120,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N欲笑还颦,手中$w横护胸口，抱元守一，突的一式「木兰花」，剑随身进，攻向$n的左侧，\n"
"中途突变，手中$w改刺为削，一式「减字木兰花」扫向$n的$l",
                "dodge":                -130,
                "parry":                  50,
                "damage":                190,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N脚踏醉步,行至$n的面前,故做醉态,踉跄便倒，不待身子落地,$w剑尖点地，\n"
"身型拔起,$w借力一抖,化作点点剑花，一招「长庚醉闹黄鹤楼」，攻向$n的$l",
                "dodge":                -200,
                "parry":                -200,
                "damage":               110,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N胸有成竹，朗声长啸,一招「破阵子」，举止幽雅,信手递出,手中的$w直刺$n的$l！",
                "dodge":                -130,
                "parry":                -120,
                "damage":              140,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N默默无语，$w舞出一片寒光，如同高山流水的剑势铺天盖地地裹向$n全身,\n"
"这招有个名堂,叫做「水龙吟」,",
                "dodge":                -130,
                "parry":                -120,
                "damage":               130,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「天边金掌剑成霜」，长身而立,左掌劈出一道掌风罩向$n，随即跃起，\n"
"右手$w自上而下斜劈$n的$l",
                "dodge":                -160,
                "parry":                -120,
                "damage":               180,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「念奴娇」，持剑右腕一扭,用$w的剑柄回磕$n",
                "dodge":                -180,
                "parry":                -180,
                "damage":               90,
                "damage_type":  "割伤"
        ]),
        
});


mapping last_action1 = ([      "action":               
"$N右手$w忽然缩进衣袖，左一掌虚击，中途一变掌势，右手袖中$w接着随手射出，$N左掌变式恰倒好处\n"
"一抓剑柄，一招「落风回天」，反削$n的胸口",
                "dodge":                -150,
                "parry":                -150,
                "damage":               220,
                "damage_type":  "割伤"
        ]);

mapping last_action2 = ([      "action":               
"$N使出书生夺命剑的入门式「缚鸡式」，默运内力于$w上，$w顿时光芒大盛，$N身随剑意，$w直刺$n的$l",
                "dodge":                -90,
                "parry":                -120,
                "damage":               480,
                "damage_type":  "刺伤"
        ]);


int valid_learn(object me)
{
        object ob;
         int taiji_force;
         int max_force = me->query("max_force");

        if( max_force < (int)me->query_skill("ss-sword")*20 )
                return notify_fail("你的内力修为不足，没有办法练书生夺命剑。\n");
        if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够，没有办法练书生夺命剑。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练书生夺命剑。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
         if(me->query_skill("ss-sword",1)>=105 && random(3)>1 )
              return last_action2;
         if(me->query_skill("ss-sword",1)>=150 && random(3)>1 )
              return last_action1;
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40
        ||      (int)me->query("force") < 10 )
                return 
notify_fail("你的内力或气不够，没有办法练习书生夺命剑。\n");
        me->receive_damage("kee", 40);
        me->add("force", -10);
        write("你把书生夺命剑剑法从头到尾练了一遍。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("qimingshuyuan") + "/ss-sword/" + action;
}
 



