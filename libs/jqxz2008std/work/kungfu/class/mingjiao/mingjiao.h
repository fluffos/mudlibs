// MingJiao.h for all npc of mingjiao

// HIG/NOR (ansi color macros) are used below but not every includer of
// this header already has <ansi.h> in scope (e.g. litianyuan.lpc/
// yinyewang.lpc reach this transitively via tangzhu.h, neither of which
// includes ansi.h) -- include it here directly so this header is
// self-contained regardless of the includer.
#include <ansi.h>

void greeting(object me, object ob)
{
	if ( environment(ob) != environment(me) ) return;
	if ( ob->query("party")["party_name"] == HIG + "明教" + NOR )
	{
	if ( ob->query("party")["level"] < me->query("level"))
		message_vision("$N对$n躬身行礼，说道："+me->query("title")+me->query("name")
			+"，参见"+ob->query("party")["rank"]+ob->query("name")+"！\n", me, ob );
	}

}
