// zhuangzi-mengwu.c
// by hubo

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        HIW"$n身子一转，虚踢一脚，犹如舞蹈一般！\n"NOR,
        HIW"$n肩和手的伸缩，脚与膝的进退，无不因便施巧，合于音乐节拍，举动就如跳舞一般\n"NOR,
        HIW"$n身子飘来飘去，若隐若离，$N呆若木鸡，忘了出招\n"NOR,
        HIW"$n左晃右晃，犹如庖丁解牛，$N连衣角都碰不到！\n"NOR,
        HIW"$n使一招“彩碟飞舞”，轻轻跃过$N的头顶，落在一边，声息皆无！\n"NOR,
});

int valid_enable(string usage)
{
        return ((usage=="dodge") || (usage=="move"));
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        mapping fam;
            if (!(fam = this_player()->query("family"))|| fam["family_name"] != "红花会")
        return notify_fail("你不是红花会的弟子，无法练习庄子梦舞！\n");
          if( (int)me->query("qi") < 30
        ||      (int)me->query("jing") < 20 )
                return notify_fail("你的气或神不够，不能练庄子梦舞。\n");
          me->receive_damage("qi", 30);
        me->receive_damage("jing", 10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"zhuangzi-mengwu/" + action;
}
