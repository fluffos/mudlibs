// yuanyan-dao.c 鸳鸯刀
// 2002-5-31

inherit SKILL;
#include <ansi.h>

string *parry_msg = ({
"$n不闪不避，举$w闪电般反削$N的$l，想挡过$N此招",
"却见$n踏前一步，$w式斜指$N的$l，想要使$N闪身而退",
"$n右腿半屈般蹲，$w尖虚指，转身撩向$N的$l",
"$n回身拧腰，右手虚抱，$w中宫直进，刺向$N的$l",
});

string  *msg = ({
"$N面带微笑，双肩微低，身形一晃，一招"+HIM+"『一见钟情』"+NOR+"，$w直指$n心窝。"NOR,
"$N口中喝到"+HIC+"『地久天长』"+NOR+"，手中$w化做一团寒气笼罩了$n全身."NOR,
"$N将$w掷向天空，又纵身跃起，抓住$w，一招"+HIG+"『海誓山盟』"+NOR+"，$n感到周身充满无形压力."NOR,
"$N脸上笑容突现，好象想起来跟爱人的"+HIB+"『花前月下』"+NOR+"，似乎根本没在意$n."NOR,
"$N口中默默着"+WHT+"『此情可待』"+NOR+"，眼中浮现坚定的决心，$n手上不禁一松..."NOR,
"$N面带微笑，双肩微低，身形一晃，一招"+HIB+"『成双成对』"+NOR+"，一片刀光挥洒如意。"NOR,
"$N骄傲地大声说道：“看好了，这就是"+HIR+"『双宿双栖』"+NOR+"，$w直似从两侧向$n太阳穴点去."NOR,
"$N想起了自己的爱人，心中"+HIR+"『惆怅莫名』"+NOR+"，手中$w随意挥舞，陡然，眼中一缕精光直射$n。"NOR,
"突然间$N身形纵起，口中大喝："+HIW+"『我心依旧』"+NOR+"，四下里直起一阵共鸣。"NOR,

});

int valid_enable(string usage)
{
        return usage == "blade" || usage == "parry";
}

mapping query_action(object me, object weapon)
{
        return ([
                "action":msg[random(sizeof(msg))],
                  "damage":random(4)*50+100,
                "damage_type":random(2)?"砍伤":"割伤",
                "dodge":200,
                "force":400
        ]);
}

string query_parry_msg(object weapon)
{
        if (!weapon) return 0;
        if (weapon->query("skill_type") == "blade")
                return parry_msg[random(sizeof(parry_msg))] + "。\n";
}

int valid_learn(object me)
{
        return notify_fail("鸳鸯刀只能通过领悟来提高。\n");
}

string perform_action_file(string action)
{
        return __DIR__"yuanyang-dao/" + action;
}
