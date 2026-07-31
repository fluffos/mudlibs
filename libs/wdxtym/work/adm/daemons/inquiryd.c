// inquiryd.c

#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch (topic)
	{
	case "name":
		message_vision( CYN "$N向$n问道：敢问" + RANK_D->query_respect(ob)
			+ "尊姓大名？"NOR"\n", me, ob);
		return 1;

	case "here":
		message_vision(CYN "$N向$n问道：这位" + RANK_D->query_respect(ob)
			+ "，" + RANK_D->query_self(me) +
			"初到贵宝地，不知这里有些什麽风土人情？"NOR"\n",
			me, ob);
		return 1;

	case "rumors":
	case "消息":
		message_vision(CYN "$N向$n问道：这位" + RANK_D->query_respect(ob)
			+ "，不知最近有没有听说什么消息？"NOR"\n", me, ob);
		return 1;

	default:
		return 0;
	}
}
