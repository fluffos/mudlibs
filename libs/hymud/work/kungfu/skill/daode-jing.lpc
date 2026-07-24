// daode-jing.c 道德经
#include <ansi.h>

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    int lvl;

    lvl = (int)me->query_skill("daode-jing", 1);

	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && !me->query("jiuyin/emei"))
		return notify_fail("你试图学习道德经，但似乎毫无进展。\n");
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/emei") && lvl > 100)
		return notify_fail("你试图学习道德经，但似乎毫无进展。\n");

    if( (int)me->query("shen") < 0 )
   return notify_fail("你的邪气太重，无法修炼道德经。\n");

    if(me->query("gender") == "无性" && lvl > 339)
   return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。\n");

    return 1;
}

int practice_skill(object me)
{
    return notify_fail("道德经只能靠学习来提高。\n");
}


void skill_improved(object me)
{
	if (me->query_skill("daode-jing", 1) > 200) {
		tell_object(me,HIW"\n你将道德经与所学的武学相互参照，突然发觉九阴白骨抓和催心掌尽然另有一番天地！\n\n"NOR);
if (me->query_skill("jiuyin-baiguzhua", 1) > 200)
{
		if (me->query_skill("jiuyin-baiguzhua", 1) > me->query_skill("jiuyin-shenzhua", 1))
			me->set_skill("jiuyin-shenzhua", me->query_skill("jiuyin-baiguzhua", 1));
		me->delete_skill("jiuyin-baiguzhua");
}
if (me->query_skill("cuixin-zhang", 1) > 200)
{
		if (me->query_skill("cuixin-zhang", 1) > me->query_skill("jiuyin-shenzhang", 1))
			me->set_skill("jiuyin-shenzhang", me->query_skill("cuixin-zhang", 1));
		me->delete_skill("cuixin-zhang");
}
	}
}
