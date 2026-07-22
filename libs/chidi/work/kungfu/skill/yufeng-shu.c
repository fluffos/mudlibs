//  yufeng-shu.c 御蜂术
// By Kayin @ CuteRabbit Studio 1999/3/23 new
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
	return notify_fail("御蜂术只能靠学(learn)来提高。\n");
}
