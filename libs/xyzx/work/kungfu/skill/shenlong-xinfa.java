// shenlong-xinfa.c 神龙心法

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
    return notify_fail("神龙心法只能靠学(learn)来提高。\n");
}
