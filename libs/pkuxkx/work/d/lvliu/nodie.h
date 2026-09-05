#include <ansi.h>

int prevent_die(object me)
{
	if (!objectp(me) || !userp(me))
		return 0;
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", me->query("max_qi"));
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", me->query("max_jing"));
	me->clear_condition();
	message_vision(HIM"眼看$N命在须臾就要倒毙在地，斜刺里忽然冲出两道人影，往$P嘴里塞了一颗丹药，然后架起$P就跑。\n"NOR, me);
	me->move(__DIR__"xiaolu");
	message_vision(HIM"两位绿柳山庄的仆人一前一后，用担架抬着$N匆匆跑了过来，往角落里一放，又急急忙忙地走了。\n"NOR, me);
	if (living(me))
		me->unconcious();
	return 1;
}

