// Object: /clone/herb/candle.c 七心海棠蜡烛
// Date: Mar. 3 2002 by Pound
/*
   七心海棠蜡烛点燃之后，发出的毒气既无臭味，又无烟雾。
   无色无臭，无影无踪，再精明细心的人也防备不了，不知不觉之间，已是中毒而死。
   完整的七心海棠做成蜡烛后可以使用四次。
   点燃蜡烛，可以导致所有在场的人中毒致死，内力精深者运气好的可以不死，但会暂时失明。
   此物毒性太过霸道，好在得之不易。持有者务必慎用。
*/

#include "/clone/herb/herb.h"
int do_dian(string arg);
int do_qu(string arg);
int do_fang(string arg);
string long_desc();

void create()
{
	set_name(HIY "蜡烛" NOR, ({"haitang candle", "candle"}));
	if (clonep())
	    set_default_object(__FILE__);
	else 
	{
	    set("base_unit", "根");
	    set("long", (: long_desc :));
	    set("no_sell", 1);	
	    set("base_value", 200000);
	    set("no_drop", 1);
	    set("no_steal", 1);
	    set("no_beg", 1);
//	  set("poison_type", "haitang_posion");
	    set("base_weight", 60);
	}		   
	setup();
}

string long_desc()
{
	string descrp;
	object ob;
	ob = this_player();
	descrp = HIY "这是根细小精致的蜡烛，" NOR;

// 通过look candle可以获取蜡烛还能使用的次数。
	if (ob->query("yaowang/candle/using") == 1)
	    descrp += YEL "已经快用完啦，看上去只能再用一次。"NOR"\n";
	else if (ob->query("yaowang/candle/using") == 2)
		descrp += YEL "大约有一寸多长，看上去并不是用来照明的。"NOR"\n";
	else if (ob->query("yaowang/candle/using") == 3)
		descrp += YEL "长度大约有一寸半多点，看来也用不了几次。"NOR"\n";
	else if (ob->query("yaowang/candle/using") == 4)
		descrp += YEL "大约有二寸多长，恰好能攥在手心里。"NOR"\n";
	else
	    descrp += YEL "不过看上去好象出了问题，快点找巫师吧。"NOR"\n";
	return descrp;
}

void init()
{   
	add_action("do_dian", "dian"); 
	add_action("do_qu", "qu"); 
}

int do_qu(string arg)
{
	object me;
	me = this_player();

	if (! arg || ! id(arg))
	    return notify_fail("你想要取什么？\n");
	if (me->is_busy())
	    return notify_fail("你还是先忙完再取东西吧！\n");

	if (arg == "candle" || arg == "haitang candle")
	{
	    if (me->query_temp("qu_candle"))
		return notify_fail("你已经把蜡烛取出来了。\n");
	    message_vision("$N小心翼翼地从怀里取出一根细小的蜡烛。\n", me);
	    me->set_temp("qu_candle", 1); 
// 七心海棠蜡烛毒性非常霸道，故设置了多种限制。此处设置qu指令，是为了引起周围人的注意，只要不是robot，均有机会逃跑。
// 另外，建议修改go.c，加上对qu_candle的判断，显示手拿蜡烛者。
	    me->start_busy(1 + random(2));
	    add_action("do_fang", "fang");	  
	}
	return 1;
}

int do_fang(string arg)
{
	object me;
	me = this_player();

	if (! arg || ! id(arg))
	    return notify_fail("你想要放什么？\n");
	if (me->is_busy())
	    return notify_fail("你还是先忙完再放东西吧！\n");

	if (arg == "candle" || arg == "haitang candle")
	{
	    if (! me->query_temp("qu_candle"))
		return notify_fail("你手里没有蜡烛。\n");
	    message_vision("$N小心翼翼地把蜡烛放回到怀里。\n", me);
	    me->start_busy(1 + random(2));
	    me->delete_temp("qu_candle"); 
	}
	return 1;
}

int do_dian(string arg)
{
	object me;
	me = this_player();

	if (! arg || ! id(arg))
	    return notify_fail("你想要点燃什么？\n");
	if (me->is_busy())
	    return notify_fail("你还是先忙完再点东西吧！\n");

	if (arg == "candle" || arg == "haitang candle")
	{
	    if (environment(me)->query("no_fight") || environment(me)->query("outdoors") == "city")
		return notify_fail("在这里用蜡烛害人会遭天遣的。\n");
	    if (! me->query_temp("qu_candle"))
		return notify_fail("你手里没有蜡烛。\n");
	    message_vision(HIY "$N小心翼翼地点燃了手中的蜡烛，烛光黯淡，火焰随风摇曳，忽明忽暗。"NOR"\n", me);
	    me->start_busy(1 + random(2));
	    me->add("yaowang/candle/using", -1); 
	    remove_call_out("do_effect");
	    call_out("do_effect", 2, me); // 两次心跳后起效用。给对手可逃跑的机会，比较公平些。
	}

	return 1;
}

int do_effect(object me, object target)
{
	object *ob;
	int i;

	ob = all_inventory(environment(me));
	for(i = 0; i < sizeof(ob); i++) 
	{
	    if (! living(ob[i]) || ob[i] == me)
		continue;

	    me->want_kill(ob[i]);
	    ob[i]->kill_ob(me);

// 点燃蜡烛，可以导致所有在场的人中毒致死，内力精深者运气好的可以不死，但会暂时失明。
	    if (random((int)ob[i]->query("neili")) < 6000)
	    {
		message_vision(HIB "$N" HIB "双膝渐渐弯曲，身子软了下来，脸上似笑非笑，神情极是诡异。"NOR"\n", ob[i]);
		ob[i]->set_temp("die_reason", "死的时候脸上始终带着微笑，似乎十分平安喜乐");
		tell_object(ob[i], "你突然感觉周围事物在逐渐离自己而去，不知不觉之间，你已是中了奇毒！\n");
		ob[i]->die();
	    }
	    else
	    {
		tell_object(ob[i], "你感觉有些异样，幸好内力精深，得以不死，但双目己然抵受不住，竟自盲了！\n");
		message_vision(HIB "$N" HIB "双手在空中乱抓乱扑，两眼无神，神情极是恐怖。"NOR"\n", ob[i]);
		ob[i]->set_temp("block_msg/all", 1);
	    }

	}

// 判断蜡烛是否还能再用，如果无法再用则destruct。
	if (me->query("yaowang/candle/using") < 1) 
	{
	    me->delete("yaowang/candle");
	    message_vision(HIY "$N手中的蜡烛点到了尽头，只见忽地一亮，火焰吐红，一声轻响过后，蜡烛熄灭了。"NOR"\n", me);
	    destruct(this_object());
	}
	else message_vision(HIY "一阵风吹了过来，$N手中的蜡烛，烛火一闪，登时熄了。"NOR"\n", me);

	return 1;

}