// qimen-bagua.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        if( me->query_skill("qimen-bagua", 1 ) >= 200 ) 
              return notify_fail("你不能再提高奇门八卦的等级了。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("奇门八卦只能靠学(learn)来提高。\n");
}
