// lonely-sword.c 独孤九剑

inherit SKILL;
#include <ansi.h>
string *parry_msg = ({
        "却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。\n",
        "$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「快活三」三剑。\n",
        "$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「天外玉龙」企图迫使$P变招。\n",
        "$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！\n"
        "$n不闪不避，举剑闪电般使出「叠翠浮青」反削$P的$l，想挡过你此招。\n",
        "$n突然使出青城派松风剑法的「鸿飞冥冥」，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！\n"
        "$n挺剑一招象是「白云出岫」回刺$P的$l，企图将$P的攻势化解。\n",
        "只见$n不退反进，身如飘风，诡异地一式「天柱云气」，动向无定不可捉摸地挡住了$P的\n进攻。\n",
        "$n不退反进，使出恒山剑招「绵里藏针」，森森剑气充溢四周！架开了$P的这招\n",
});

mapping *action = ({
([      "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「来鹤清泉」直刺$n
的$l！",
        "force" : 10,
        "dodge" : 15,
        "damage": 50,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N奇诡地向$n挥出「泉鸣芙蓉」、「鹤翔紫盖」、「石廪书声」、「
天柱云气」及「雁回祝融」衡山五神剑！",
        "force" : 10,
        "dodge" : 10,
        "damage": 50,
        "lvl" : 7,
        "damage_type" : "刺伤"
]),
([
        "action" : "$N剑随身转，续而刺出十九剑，竟然是华山「玉女十九剑」，但奇的
是这十九剑便如一招，手法之快，直是匪夷所思！",
        "force" : 10,
        "dodge" : 15,
        "damage": 50,
        "lvl" : 14,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢
推去！",
        "force" : 20,
        "dodge" : 15,
        "damage": 50,
        "lvl" : 21,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里
，尽括嵩山剑势击向$n的$l！",
        "force" : 20,
        "dodge" : 10,
        "damage": 50,
        "lvl" : 28,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟
化「泰山十八盘」为一剑攻向$n！",
        "force" : 30,
        "dodge" : 10,
        "damage": 55,
        "lvl" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑招突变，使出衡山的「一剑落九雁」，削向$n的$l，怎知剑到中
途，突然转向，大出$n意料之外！",
        "force" : 40,
        "dodge" : 15,
        "damage": 60,
        "lvl" : 42,
        "damage_type" : "刺伤"
]),
([      "action" : "$N吐气开声，一招似是「独劈华山」，手中$w向下斩落，直劈向$n的
$l！",
        "force" : 50,
        "dodge" : 10,
        "damage": 80,
        "lvl" : 49,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w越转越快，使的居然是衡山的「百变千幻云雾十三式」，剑
式有如云卷雾涌，旁观者不由得目为之眩！",
        "force" : 60,
        "dodge" : 20,
        "damage": 90,
        "lvl" : 56,
        "damage_type" : "刺伤"
]),
([      "action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺
向$n！",
        "force" : 70,
        "dodge" : 10,
        "damage": 100,
        "lvl" : 63,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽
源源不绝地缠向$n！",
        "force" : 80,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩
剑」的剑意表露无遗！",
        "force" : 90,
        "dodge" : 15,
        "damage": 130,
        "lvl" : 77,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N突然虚步提腰，使出酷似武当「蜻蜓点水」的一招！",
        "force" : 100,
        "dodge" : 15,
        "damage": 160,
        "lvl" : 84,
        "damage_type" : "刺伤"
]),
([      "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是「伏
魔剑」的「龙吞式」。",
        "force" : 120,
        "dodge" : 20,
        "damage": 195,
        "lvl" : 91,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然运剑如狂，一手关外的「乱披风剑法」，猛然向$n周身乱刺乱
削！",
        "force" : 140,
        "dodge" : 10,
        "damage": 220,
        "lvl" : 98,
        "damage_type" : "刺伤"
]),
([      "action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的
虚实！",
        "force" : 160,
        "dodge" : 130,
        "damage": 250,
        "lvl" : 105,
        "damage_type" : "刺伤"
]),
([      "action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什
么剑法！",
        "force" : 180,
        "dodge" : 5,
        "damage": 280,
        "lvl" : 112,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知
如何是好！",
        "force" : 200,
        "dodge" : 10,
        "damage": 285,
        "lvl" : 119,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫
得$n不得不守！",
        "force" : 220,
        "dodge" : 10,
        "damage": 350,
        "lvl" : 126,
        "damage_type" : "刺伤"
]),
([      "action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n
难以看清剑招来势！",
        "force" : 240,
        "dodge" : 15,
        "damage": 380,
        "lvl" : 133,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招
式。",
        "force" : 260,
        "dodge" : 20,
        "damage": 400,
        "lvl" : 140,
        "damage_type" : "刺伤"
]),
([      "action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可
思议！",
        "force" : 280,
        "dodge" : 40,
        "damage": 60,
        "lvl" : 147,
        "damage_type" : "刺伤"
]),
([      "action" : "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n
的$l！",
        "force" : 300,
        "dodge" : 20,
        "damage": 120,
        "lvl" : 154,
        "damage_type" : "刺伤"
]),
([
    "action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！",
        "force" : 400,
        "dodge" : 50,
        "damage": 165,
        "lvl" : 180,
    "damage_type" : "刺伤"
])
});

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "华山派"|| myfam["master_id"] != "feng qingyang")
                return notify_fail("独孤九剑只有向风清扬老前辈学习。\n");
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练独孤九剑。\n");
        if( (int)me->query_skill("zixia-shengong",1)<100)
                return notify_fail("独孤九剑必须配合紫霞神功才能练习。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("独孤九剑只能通过「总诀式」来演练。\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
mixed hit_ob(object me, object victim)
{       
        if (random(me->query_skill("lonely-sword",1)) < 150 ||		             me->query_skill("force",1) < 150 )
        return 0;
        if (random(me->query_skill("lonely-sword",1)) > 200 &&
        random(me->query_skill("sword",1))>150 &&
     	me->query_skill("force",1) > 250 )
{
        me->add("neili", -50);
        victim->map_skill("dodge");
        return HIR"$n大吃一惊，竟然忘了闪避！\n"NOR;
        
}
        if (random(me->query_skill("lonely-sword",1)) > 150 &&	
	 random(me->query_skill("sword",1))>120 &&
            me->query_skill("force",1) > 200 )	
{
        
        me->add("neili", -50);
        victim->map_skill("parry");
        return HIY"$n难以看清剑招来势,竟然忘了招架！\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 120 &&	
        random(me->query_skill("sword",1))>120 &&
	 me->query_skill("force",1) > 150)
{
        me->add("neili", -50);
        victim->start_busy(random(3));
        return HIG"$n手忙脚乱，慌乱不堪！\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 100 &&
        random(me->query_skill("sword",1))>100 &&
      	me->query_skill("force",1) > 120 )	
{
        victim->add("neili", -400);
	return HIM"$n使出浑身解数才脱出剑圈！\n"NOR;
}
        if (random(me->query_skill("lonely-sword",1)) > 80 &&	
        random(me->query_skill("sword",1))>80 &&  
	  me->query_skill("force",1) > 100 )	
{
        victim->start_busy(random(2));
	return HIW"$n顿时手足无措，不知如何是好！\n"NOR;
  } 
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}

