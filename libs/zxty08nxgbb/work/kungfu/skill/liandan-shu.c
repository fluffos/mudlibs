inherit SKILL;
string type() { return "knowledge"; }

int valid_learn(object me)
{
        return notify_fail("炼丹术只能靠炼丹来增加。\n");
}

