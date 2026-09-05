#include <ansi.h>
#include "/clone/npc/bodyguard_config.h"
int accept_object(object me,object ob,object bodyguard)
{
	if (ob->query("money_id") && ob->value() >= 10000&&me->query_temp("give_bodyguard")==this_object())
	{
		me->delete_temp("give_bodyguard");
		BG_HIRE->add_friendship(me,2,1);
		ob->move(VOID_OB);
		destruct(ob);
		bodyguard->command("say 那我就不客气啦。");
		return 1;
	}
	return notify_fail("作为一个有修养的"+bodyguard->query("title")+"，"+bodyguard->query("name")+"肯定不会接受"+ob->query("name")+"的。\n");
}
