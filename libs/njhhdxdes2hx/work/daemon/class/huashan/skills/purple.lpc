// purple.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
        int lvl;

        lvl = (int)me->query_skill("purple", 1);

        if( (int)me->query("shen") < 0 )
                return notify_fail("你的邪气太重，无法修炼紫气东来。\n");

        if(me->query("gender") == "无性" && lvl > 39)
                return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。\n");


        return 1;
}

int practice_skill(object me)
{
        return notify_fail("紫气东来只能靠学习来提高。\n");
}
