// shenlong-xinfa.c 神龍心法

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
    return notify_fail("神龍心法只能靠學(learn)來提高。\n");
}
