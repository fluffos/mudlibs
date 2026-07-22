
// Modified by snow for JHFY (11/20/99)

#include <ansi.h>
int parse_inquiry(object me, object ob, string topic)
{
	switch( topic ) {
		case "name":
			message_vision( YEL "$N向$n"+YEL"问道：敢问" + RANK_D->query_respect(ob)
				+ "尊姓大名？\n" NOR, me, ob);
			return 1;
		case "here":
			message_vision(YEL "$N向$n"+YEL"问道：这位" + RANK_D->query_respect(ob)
				+ "，" + RANK_D->query_self(me) + "初来乍到，不知这里有些什麽风土人情？\n" NOR,
				me, ob);
			return 1;
		case "rumors":
			message_vision(RED "$N向$n"+RED"问道：这位" + RANK_D->query_respect(ob)
				+ "，不知最近有没有听说什么小道消息？\n" NOR, me, ob);
			return 1;
		case "marry":
			message_vision(CYN "$N眯着一双贼眼，不怀好意的向$n"+CYN"问道：敢问这位"+RANK_D->query_respect(ob)
						+"是否婚配？\n" NOR,me,ob);
			return 1;
		case "food":
			message_vision(CYN "$N可怜兮兮的向$n"+CYN"问道：“不知这位"+RANK_D->query_respect(ob)
						+"是否能给我点吃的, 在下已经三天没有进食了？”\n" NOR,me,ob);
			return 1;
	
		case "water":
			message_vision(CYN "$N可怜兮兮的向$n"+CYN"问道：“不知这位"+RANK_D->query_respect(ob)
						+"是否能给我点喝的, 在下口渴得很？”\n" NOR,me,ob);
			return 1;
	
		case "money":
			message_vision(CYN "$N双手抱拳向$n"+CYN"问道：“在下初来咋到，行走江湖缺了些盘缠,这位"+RANK_D->query_respect(ob)
						+"是否能施舍一二, 在下不甚感激？”\n" NOR,me,ob);
						return 1;
		case "friend":
			message_vision(CYN "$N双手抱拳向$n"+CYN"说道：“四海之内皆兄弟也,这位"+RANK_D->query_respect(ob)
						+",不知愿否与在下交个朋友”\n" NOR,me,ob);
						return 1;
		default:
			return 0;
	}
}