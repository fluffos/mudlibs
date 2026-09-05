// lingbo-weibu.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        GRN"$n借力旋转，扶摇而上，衣裾漫天飞舞，潇洒已极！\n"NOR,
        GRN"$n轻轻一跃，如鸟掠长空，凌虚而行，瞬间已在丈外！\n"NOR,
        GRN"$n仿佛站着未动，不过衣角被风轻轻吹了一下，正是“竦轻躯以鹤立，若将飞而未翔”！\n"NOR,
        GRN"$n从容而立，忽焉趋左，忽焉在右，瞻之在前，顾之已后，体迅飞阖,飘忽若瘢\n"NOR,
        GRN"$n长袖飘飘，足不点地，宛如凌风，$N连衣角都没碰着！\n"NOR,
        GRN"$n如风行水上，愈显得雍容高雅，$N不由得自惭形秽，招数一滞！\n"NOR});

int valid_enable(string usage)
{
    return (usage=="dodge");
}

int valid_learn(object me)
{
    mapping fam;
    if ((!(fam = this_player()->query("family"))|| fam["family_name"] != "天龙寺")&&this_player()->query("chushi/last_family")!="天龙寺")
		if (this_player()->query("tqt/old_family1")!="天龙寺")
		{
			if (this_player()->query("tqt/old_family2")!="天龙寺")
			{
				if (this_player()->query("tqt/old_family3")!="天龙寺")
					return notify_fail("你不是天龙寺的弟子，无法学习凌波微步。\n");
			}
		}

    if( me->query_skill("literate",1) < 100 )
        return notify_fail("你的读书识字还不到 100 级，没法领会凌波微步的玄妙之初。\n");
    return 1;
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    mapping fam;
    if( (int)me->query("qi") < 30 || (int)me->query("jing") < 20 )
        return notify_fail("你的气或神不够，不能练凌波微步。\n");
    me->receive_damage("qi", 30);
    me->receive_damage("jing", 10);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"lingbo-weibu/" + action;
}

int effective_level() { return 10;}

int learn_bonus()
{
    return 10;
}
int practice_bonus()
{
    write("凌波微步靠的是悟性，是实践，光苦练是无济于事的。");
    return 2;
}
int black_white_ness()
{
    return 20;
}

