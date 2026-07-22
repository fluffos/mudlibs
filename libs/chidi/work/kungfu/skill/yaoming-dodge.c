// yaoming-dodge 杳冥身法
inherit SKILL;
string *dodge_msg = ({
"$n一式「"+YEL+"楼观飞惊"+NOR+"」，身形快得如一抹淡烟,躲过了$N的功势。\n",
"$n一式「"+HIM+"凤凰展翅"+NOR+"」，陡然间身形拔起，在空中一个转折，轻轻巧巧的落在数丈之外，昂首从$N眼前跨过。\n",
"$n一式「"+WHT+"踏雪无痕"+NOR+"」，不见动作，人已换了方向，简直如同灵魂鬼，一下子绕到了$N的身后。\n",
"$n一式「"+CYN+"旋风转"+NOR+"」，身形一欺，手中剑夹雷霆之威，罩身攻向你，轻松让过了$N的凌厉攻势。\n",
"$n一式「"+MAG+"升转异星"+NOR+"」，脚踏七星，身游八卦，登时幻出千条人影，飘出丈远。\n",
"$n一式「"+MAG+"天外飞仙"+NOR+"」，惊世骇俗，身似电闪，人如脱弦怒箭，飘出丈远。\n",
});
int practice_level(){   return 150;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yaoming-dodge", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("yaoming-dodge",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 60 )
        return notify_fail("你的体力太差了，不能练杳冥身法。\n");
    me->receive_damage("qi", 60);
    return 1;
}
