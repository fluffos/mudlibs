// shanjue.c 善诀
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("shanjue", 1);
        int t = 1, j;
         for (j = 1; j < lvl / 20; j++) t ;
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail(HIY"你的基本内功尚不够修炼善诀。\n");
          if (lvl > 10 && (int)me->query("shen") < t * 50)
                return notify_fail(HIW"你的侠义正气太低了，尚不足以领会善诀\n");
        return 1;
}
int practice_skill(object me)
{
	return notify_fail("善诀只能用修炼(xiulian)和学习(learn)的方法来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"shanjue/" + func;
}
