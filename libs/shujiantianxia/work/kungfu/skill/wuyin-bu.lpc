// xinyuegong.c 雾隐步

inherit SKILL;

string *dodge_msg = ({
"只见$n一闪，已经到了三尺开外。\n",
"却见$n身形不动，脚下运力，已经到了$N侧面。\n",
"那知$n身前一团白雾升起，转眼$p已经不见了。\n",
"$n往下一伏一转，令$N一下失去了$p的踪影。\n"
});

int valid_enable(string usage)
{
        return usage == "dodge";
}

string query_dodge_msg(object weapon)
{        
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        return notify_fail("NPC武功，不对玩家开放。\n");
}