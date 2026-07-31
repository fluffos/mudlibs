// surrender.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	
	if( !me->is_fighting() )
		return notify_fail("投降？现在没有人在打你啊....？\n");

	if (me->is_busy())
		return notify_fail("你现在忙得连投降的机会都没有。\n");

	ob = me->query_temp("last_opponent");
	if( objectp(ob) && living(ob) && ob->is_killing(me) ) {
		message_vision("$N向$n求饶，但是$N大声说道：" + RANK_D->query_rude(me) + "废话少说，纳命来！\n", ob, me);
		return 1;
	}

	me->remove_all_enemy();
	me->stary_busy(1 + random(3));
	if( (int)me->query("score") >= 50 )
		me->add("score", -50 );
	else
		me->set("score", 0);

	message_vision( HIW "$N说道：「不打了，不打了，我投降....。」"NOR"\n", me);
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : surrender
 
这个指令可以让你向敌人投降而终止战斗。
 
HELP
    );
    return 1;
}
 
