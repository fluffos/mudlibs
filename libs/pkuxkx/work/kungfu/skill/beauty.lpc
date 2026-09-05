// beauty.c

inherit SKILL;


string type() { return "knowledge"; }

int valid_learn(object me)
{
        if (me->query("gender") == "男性" && me->query("age") < 50)
                return notify_fail("你一个大老爷们学这玩意干嘛？\n");
        return 1;
}
