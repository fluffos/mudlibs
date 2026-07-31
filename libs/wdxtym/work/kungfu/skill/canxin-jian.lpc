// xuedao-daofa.c 血刀
// updated by lwx 

inherit SKILL;
#include <ansi.h> 

string *action_msg = ({
        "$N身体左转，左手剑指，剑尖前端一寸处短促抖腕发力，\n"
    "一招"HIR"「昨日总总」"NOR"，手中$w轻轻颤动，一剑自上而下扎向$n．",

        "$N身形不动，右前臂外旋，剑刃上崩，一招"HIR"「心深种」"NOR"，\n"
    "手中$w向前下反刺，一剑指向$n",

        "$N左脚向前，蹬地跳起，右手$w突向前刺，随转体变向，\n"
    "使出一式"HIR"「他夜梦里」"NOR"，剑光如匹练般泄向$n",

        "$N平剑斜洗，臂圆剑直，双脚交替弧形迈进，右手$w使出一式"HIR"「再续未了缘」"NOR"，"
    "剑锋往来运转如梭，连绵不绝刺向$n",

        "$N屈腕抬臂，剑由前向后上方抽带，挺起中平剑奋勇向前，右手$w使出\n"
    "一式"HIR"「情丝难断」"NOR"刺向$n",

        "$N左上步，抱剑当胸，右手$w一式"HIR"「心难负」"NOR"，"
    "剑意圆润，刺向$n",

        "$N侧身退步，左手剑指划转，右手$w一记"HIR"「仗剑江湖」"NOR"，"

        "$N碎步急进，提剑沿剑身方向疾速上崩，一招"HIR"「梦已远」"NOR"直取$n",

HIG"\n第一剑「仙灵仙岛难觅仙，忽见灵池一朵莲．」，自上而下！"NOR,
HIG"\n第二剑「红颜如月有圆缺，君名逍遥莫悲切．」，从左到右！"NOR,
HIG"\n第三剑「参天树下识苗女，同赴密林寻宝途。」，旋转而至！"NOR,

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{ int level;
        if( me->query("int")<30 )
                return notify_fail("你若有所悟，然而总是有点不明白。\n");

        if( me->query("dex")<30 )
                return notify_fail("你研究了半天，只觉招式始终无法随意施展。\n");

        if( me->query("con")<30 )
                return notify_fail("你研究了半天，只觉得根骨有些差，招式始终无法随意施展。\n");

        if( me->query("str")<30 )
                return notify_fail("你研究了半天，感觉膂力有些低，始终无法随意施展。\n");

level = me->query_skill("canxin-jian", 1);

   if ((int)me->query_skill("sword", 1) < 180)
               return notify_fail("你的基本剑法火候不够，无法学习残心剑。\n");

       if ((int)me->query_skill("sword", 1) < level)
               return notify_fail("你的基本剑法水平有限，无法领会更高深的残心剑。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("xiangsi");
	if( !me->query("xiangsi") ) 
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 200 + random(400), 
                "attack": 100 + random(100),
                "dodge" : 100 + random(100),
                "parry" : 100 + random(100),
                "damage_type": "刺伤", 
        ]);
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 30 )
		return notify_fail("你的内力或气不够，没有办法练习残心剑。\n");
	me->add("qi", -30);
	me->add("neili", -30);
	write(HIC"天若有情天仪老，月如无恨月长圆。\n"NOR,me);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"canxin-jian/" + action;
}

