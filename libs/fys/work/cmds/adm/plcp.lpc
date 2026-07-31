#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object npc;
	if(! arg)	return notify_fail("plcp xxx?\n");
	npc=new(__DIR__"stdnpc");
	npc->create(arg);
	npc->move(environment(me));
	write("clone player ok\n");
	return 1;
}
