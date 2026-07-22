// juemen-gun.c 绝门棍
inherit SKILL;
string *dodge_msg = ({
    "$n右脚轻轻一点跃开躲过了$N的攻击。\n",
    "$n向旁边扑出，顺势一滚，闪到一边。\n",
    "$n斜里冲前一步，身法诡异，$N这一招落到空处。\n",
    "$n忽然直身飞入半空，很久也不见人影，半响后竟闪到了$N的背后。\n",
    "$n突然一个急转身，$N的这一招滑到了一边。\n",
});
mapping *action = ({
([  "action" : "$N斜里冲前一步，身法诡异，手中$w横扫$n的$l",
    "damage": 50,
    "dodge" : 50,
    "damage_type" : "挫伤"
]),
([  "action" : "$N忽然直身飞入半空，很久也不见人影，$n正搜寻间，$N已
飞身扑下，$w攻向$n的$l",
    "damage": 70,
    "dodge" : 45,
    "damage_type" : "挫伤"
]),
([  "action" : "$N原地一个后滚翻，却在落地的一刹那，身体向$n平飞过
去，手中$w指向$n的$l",
    "damage": 100,
    "dodge" : 60,
    "damage_type" : "挫伤"
]),
([  "action" : "$N突然一个急转身，$w横扫一圈后挟着猛烈的劲道打向$n的$l",    
    "damage": 120,
    "dodge" : 75,
    "damage_type" : "挫伤"
]),
([  "action" : "$N向前扑出，顺势一滚，接着翻身跳起，手里$w斜向上击
向$n的$l",
    "damage": 150,
    "dodge" : 65,
    "damage_type" : "挫伤"
])
});
int valid_enable(string usage){return usage=="staff" || usage=="parry"; }
