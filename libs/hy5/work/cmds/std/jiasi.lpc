// jiasi.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
//	if(me->query("class") != "bandit")
//		return notify_fail("名门正派的人不可以装死！\n");
        seteuid(getuid());
	if (me->query("combat_exp",1)> 800000)
		return notify_fail("你这么大人，装死没用的!\n");

        if( !me->is_fighting() )
                return notify_fail("你不在战斗中，不需要假装死。\n");
	if (me->is_busy() )
		return notify_fail("你现在正忙着呢!\n");

	wimpy = (int)me->query("env/wimpy");
	message_vision("$N惨叫一声，一头栽倒在地下。\n$N死了。\n",me);
	me->set_temp("disable_inputs",1);
	me->set_temp("block_msg/all",1);
	me->disable_player(HIG "<假死中>" NOR);
//        me->set("no_get",1);
        me->remove_all_killer();
	me->remove_all_enemy();
me->set("qi",me->query("qi")/5);
me->set("qi",me->query("jing")/5);
	me->delete("env/wimpy");
        me->start_call_out( (: call_other, __FILE__, "remove_jiasi", me, wimpy :), 
random(80 - (int) me->query_con()));
	return 1;
}

void remove_jiasi(object me, int wimpy)
{
        int i;
	object env;
	env = environment(me);
//	me->set("no_get",0);
	me->delete_temp("disable_inputs");
	me->enable_player();
	me->delete_temp("block_msg/all");
	me->set("env/wimpy",wimpy);
   	message_vision("$N在地上悄悄地翻了个身，小心翼翼地睁开了眼。\n",me);
	if (env)
	{
		while (env->is_character() && environment(env))
			env = environment(env);
		if (env != environment())
                	me->move(env);
	}

//	me->move(environment(me),1);

}

int help(object me)
{
        write(@HELP
指令格式 : jiasi
让你在战斗中装死，创造逃生的机会。
名门正派的人不可以装死。

HELP
        );
        return 1;
}
 
