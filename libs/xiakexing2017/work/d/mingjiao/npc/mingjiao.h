// MingJiao.h for all npc of mingjiao
#include <ansi.h>
void greeting(object me, object ob)
{
	mapping party;
	if ( environment(ob) != environment(me) ) return;
	party = ob->query("party");
	if ( mapp(party) && party["party_name"] == HIG "明教" NOR )
	{
	if ( (int)ob->query("mjlevel") >= me->query("level"))
		message_vision("$N对$n躬身行礼，说道："+me->query("title")+me->query("name")
			+"，参见"+party["rank"]+ob->query("name")+"！\n", me, ob );
	else
message_vision("$n对$N躬身行礼，说道：“"+party["rank"]+ob->query("name")+"，参见"+me->query("title")+me->query("name")+"！”\n", me, ob );
	}
}
