// qin.c
// 琴法~~！
// God editted by 2005-6

#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit SKILL;
mapping *action =
({
([
"action" : 
""HIR"$N漠然一叹，挥手弹出一支催人心肺的曲子，$n闻之脸色大变，神形一下缓慢下来！好一曲"+HIC"『乱葬』"NOR+"！！"NOR"",
"dodge"  : -25,
"damage" : 160,
"parry"  : 160,
"skill_name"  : "『乱葬』",
"damage_type" : "内伤",
]),
([
"action" : 
""HIY"$N脸上突现红晕，手指缓缓弹奏，一曲"+MAG"『迷心』"NOR+""HIY"把$n弹的如醉如痴，浑然忘记身在何地。。"NOR"",
"dodge"  : -40,
"damage" : 200,
"parry"  : 200,
"skill_name"  : "『迷心』",
"damage_type" : "内伤",
]),
([
"action" : 
""HIC"$N仰天一啸，手指狂弹乱奏，长发漫天飞扬，一曲荒凉凄漫的"+HIW"『天下有雪』"NOR+""HIC"把$n弹的心神大失，口喷鲜血！！"NOR"",
"dodge"  : -60,
"damage" : 250,
"parry"  : 250,
"skill_name"  : "『天下有雪』",
"damage_type" : "内伤",
]),
});

int valid_enable(string usage) {
    return usage == "art";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me) {
    if ((int)me->query_skill("jiuyin-xinjing",1) < 500 )
        return notify_fail("你的九阴心法为尚浅，没法学如此精深的琴艺！\n");
    if ((int)me->query_skill("art", 1) < 500)
        return notify_fail("你的艺术修为尚浅，没法学痴心情长剑！\n");
    if ((int)me->query_skill("literate", 1) < 500)
        return notify_fail("如此无知之人又怎能用音律伤人？\n");
    if ((int)me->query_skill("force", 1) < 500)
        return notify_fail("内力如此虚弱之人又怎能用音律伤人肺腑？\n");
    return 1;
}

int practice_skill(object me) {
    object weapon, target;
    if (!objectp(weapon = me->query_temp("weapon")) ||
        (string)(weapon->query("skill_type")) != "art")
        return notify_fail("你手中无琴，如何练习琴艺？ \n");
    if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
   return notify_fail("琴艺必须配合盘丝洞的九阴心法才能练。\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("你已经精疲力竭，没法儿练下去啦！\n");
    me->receive_damage("kee", 30);
    return 1;
}
void skill_improved(object me)
{
        if( (int)me->query_skill("qin", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 50);
        }
}
string perform_action_file(string action)
{
        return CLASS_D("pansi") + "/qin/" + action;
}
