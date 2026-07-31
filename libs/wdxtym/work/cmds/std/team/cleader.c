// team command: emote

#include <ansi.h>

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object *t,ob;

	if (! pointerp(t = me->query_team()))
		return notify_fail("你现在并没有和别人组成队伍。\n");
	if (! me->is_team_leader())
		return notify_fail("你又不是队长，移交什么？\n");
	if (!arg||!ob=find_player(arg)||!me->have_team_member(ob))
		return notify_fail("你想把队长移交给谁？\n");
	me->set_team_leader(ob);
	message("team", HIW "【队伍】" + "："+me->query("name")+"将队长移交给"+ob->query("name")+NOR"\n", t);
	return 1;
}
