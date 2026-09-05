// Modified by iszt@pkuxkx, 2007-04-16

#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me,string arg)
{
	object ob,area;
	int amount;
	string where;
	area=environment(me);
	if(!area)
		return 0;
	if(me->is_busy())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	if (me->query("antirobot/deactivity") > 2) 
	{
		message("vision",HIR"你是机器人吧！！\n"NOR,me);
		return 1;
	}	
	if(arg=="where")
	{
		if(me->query("jing")<100)
		{
			write("你的精不够，钱财乃是身外之物，还是别这么不要命了。\n");
			return 1;
		}
		where="/adm/daemons/dropmoney"->show_msg();
		if(sizeof(where)>10)
			tell_object(me,where);
                else tell_object(me,"好像没发现什么风水宝地~~\n");
		me->receive_damage("jing", 100, "想钱想疯掉");
		me->start_busy(random(2)+1);
		return 1;
	}
	if(me->query("qi")<100)
	{
		write("你的气不够，钱财乃是身外之物，还是别这么不要命了。\n");
		return 1;
	}

	me->receive_damage("qi", 100, "发掘宝藏累");
	message_vision("所谓人为财死，鸟为食亡，$N开始疯狂的进行挖掘，期待能发现金银财宝。\n",me);
	if(!wizardp(me))
		me->start_busy(5+random(5));
	if(!area->query("dig_money"))
	{
		message_vision("$N挖了半天，所见之处只是土石，连一文钱都没挖着。\n",me);
		if(!random(10))
			write(HIY"也许是你找错地方了。\n"NOR);
		else if(!random(9))
			write(HIY"也许是被人挖走了。\n"NOR);
		return 1;
	}
	else
	{
		if((random(188))<random(me->query("kar")))
		{
			message_vision("$N挖了半天，突听“铛”一声，定睛一看，满满一坛黄澄澄的金子！\n",me);
			CHANNEL_D->do_channel(this_object(), "rumor", me->name()+"挖到了满满一坛黄金！");
			amount=(int)area->query("dig_money/value");

			ob=new("/clone/money/gold");
			ob->set_amount(amount+random(amount));
			ob->move(me);
			area->delete("dig_money");
			return 1;	
		}
		else
		{
			message_vision("$N挖了半天，所见之处只是土石，连一文钱都没挖着。\n",me);
			return 1;
		}
	}

	return 1;
}
int help(object me)
{
	write(@HELP
在所在的地方进行挖宝，如果为digmoney where则显示可能埋有
财宝的地点描述。
HELP);
	return 1;
}
