// SKILL mjhong.c

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
([    "action" : 
"【"+HIR"怒发冲冠，凭栏处、潇潇雨歇"NOR+"】。$N满脸通红，直接当胸一拳，
带着劲风捣向$n的$l",
        "force" : 130,
        "dodge" : 0,
        "damage" : 220,
        "lvl" : 0,
        "name" : "【怒发冲冠，凭栏处、潇潇雨歇】",
        "damage_type" : "淤伤"
]),
([    "action" : 
"【"+HIR"抬望眼、仰天长啸，壮怀激烈"NOR+"】。$N仰天长啸，双拳齐出，左右
分打$n的太阳穴。",
        "force" : 150,
        "dodge" : 0,
        "damage" : 235,
        "lvl" : 30,
        "name" : "【抬望眼、仰天长啸，壮怀激烈】",
        "damage_type" : "瘀伤"
]),

([    "action" : 
"【"+HIR"三十功名尘与土，八千里路云和月"+NOR"】。$N双袖一摆，激得地上一阵
尘土飞扬！有如流星赶月的一拳已经到了$n的胸前！",
        "force" : 200,
        "dodge" : 5,
        "damage" : 170,
        "lvl" : 40,
        "name" : "【三十功名尘与土，八千里路云和月】",
        "damage_type" : "挫伤"
]),
([    "action" : 
"【"+HIR"莫等闲、白了少年头，空悲切"+NOR"】。$N一脚扫向$n却半途收招！反身
一肘击向$n的额头！另一只手一拳分三影打向$n的气海、天池和肋下！",
        "force" : 250,
        "dodge" : 0,
        "damage" : 200,
        "lvl" : 40,
        "name" : "【莫等闲、白了少年头，空悲切】",
        "damage_type" : "瘀伤"
]),
([    "action" : 
"【"+HIR"靖康耻，犹未雪。臣子恨，何时灭"+NOR"】。$N一拳带着一条血练毫无花巧的
打向$n的面门！那血却不是属于$n的。是$N在无边的怒意之下竟然
把自己的拳头握得鲜血淋漓！",
        "force" : 250,
        "dodge" : 5,
        "damage" : 255,
        "lvl" : 60,
        "name" : "【靖康耻，犹未雪。臣子恨，何时灭】",
        "damage_type" : "淤伤"
]),
([    "action" : 
"【"+HIR"驾长车踏破，贺兰山缺"+NOR"】。$N一步踏出！地面被踩的陷下了一大片，
铁拳一挥，如铁棰般敲向$n的肩头！",
        "force" : 250,
        "dodge" : 0,
        "damage" : 280,
        "lvl" : 100,
        "name" : "【驾长车踏破，贺兰山缺】",
        "damage_type" : "挫伤"
]),

([    "action" : 
"【"+HIR"壮志饥餐胡虏肉，笑谈渴饮匈奴血"+NOR"】。$N运足真气！把杨家的《七七正气拳》
从头打到尾！只见$N一步一个深坑的逼近，漫天拳影也如一座黑墙般的缓缓逼近。",
        "force" : 250,
        "dodge" : 0,
        "damage" : 300,
        "lvl" : 150,
        "name" : "【壮志饥餐胡虏肉，笑谈渴饮匈奴血】",
        "damage_type" : "瘀伤"
]),

([    "action" : 
"【"+HIW"待从头、收拾旧山河，朝天阙"+NOR"】。$N一脚踹出！双臂随即后甩。
只听到一阵爆豆一般的响声从$N的双臂传出来。一声虎吼！双拳带着
壮士一去不复返之势轰向$n",
        "force" : 200,
        "dodge" : 0,
        "damage" : 360,
        "lvl" : 250,
        "name" : "【待从头、收拾旧山河，朝天阙】",
        "damage_type" : "淤伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" ; }

int valid_combine(string combo) { return combo=="huomo-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练满江红必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练满江红。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练满江红。\n");
        me->receive_damage("qi", 25);
        me->add("neili", -10);
        return 1;
}


