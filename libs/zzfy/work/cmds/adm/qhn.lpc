#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)

{
	object env;
	object ob;
	ob = find_object("/d/fy/npc/zhu");
	if(ob) write("ok\n");
	env = environment(ob);
	if(env) write ("ok\n");
	write(query_host_name());
	return 1;
}
