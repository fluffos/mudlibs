
// By Zine古董店
#define MAX_ITEMS 10//最大储量
#define EXCHANGE_RATE 5//手续费 5%
inherit ROOM;
inherit F_SAVE;
#include <ansi.h>
#define GUDONGDIAN "/data/business/gudongdian"+this_object()->query("shop_no")
string query_save_file()
{
	return GUDONGDIAN;
}
int restore_itself()
{
	restore();
	this_object()->init_store();
}
nosave object shop=this_object();

int change_save_format(object me)
{
	if (me->query("guwan_store"))
	{
		shop->restore_itself();
		shop->set("guwan_store/"+me->query("id"),me->query("guwan_store"));
		me->delete("guwan_store");
		shop->save();
	}
	return 1;
}

void init()
{
	add_action("do_cun","cun");
	add_action("do_qu","qu");
	add_action("do_list","list");
	add_action("do_blacklist","blacklist");
	change_save_format(this_player());
}

int do_blacklist(string arg)
{
	object me=this_player();
	if (!wizardp(me))
	return 0;
	if (!arg)
	{
		tell_object(me,"你要把谁加入古董交易黑名单？\n");
		return 1;
	}
	shop->restore_itself();
	tell_object(me,"你将"+arg+"加入到此店的黑名单。\n");
	shop->add("blacklist/"+arg,1);
	if (shop->query("blacklist/"+arg)>=2)
	tell_object(me,arg+"已被彻底禁止在此店交易！\n");
	shop->save();
	return 1;
}

int do_list()
{
	object me=this_player();
	int index,rate;
	string msg,id=me->query("id");
	shop->restore_itself();
	if (!sizeof(shop->query("guwan_store/"+id)))
	msg="你在本店没有寄存任何古董。\n";
	else
	{
		msg="你在本店寄存的古董包括：\n";
		for (index=0;index<MAX_ITEMS;index++)
		{
			if (!shop->query("guwan_store/"+id+"/"+index))
			continue;
			rate=(int)shop->query("guwan_store/"+id+"/"+index+"/value")*EXCHANGE_RATE/100*(1+shop->query("blacklist/"+id));//黑名单交易费用上升
			msg+= sprintf("│"+HIW+"编号"+NOR+"：[%1d]│"+HIY+"物品"+NOR+"：%-20s│"+HIR+"赎回价格"+NOR+"：%-32s│\n", index, shop->query("guwan_store/"+id+"/"+index+"/name"), MONEY_D->money_str(rate) );
		}
	}
	tell_object(me,msg);
	return 1;
}

int do_cun(string arg)
{
	object ob,me=this_player();
	int index,posi,flag=0;
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你要存放什么古董？\n");
		return 1;
	}
	if (!present(arg,me))
	{
		tell_object(me,"现在你身上并无这样东西。\n");
		return 1;
	}
	ob=present(arg,me);
	if (!ob->query("is_guwanzihua"))
	{
		tell_object(me,"我这里只能代存古玩字画，其他东西去当铺吧。\n");
		return 1;
	}
	if (ob->query("no_sell_in_playershop"))
	return notify_fail("本店只帮助保存真迹，赝品您还是自己收着吧。\n");
	shop->restore_itself();
	if (shop->query("blacklist/"+me->query("id"))>=2)
	{
		tell_object(me,"你之前有严重欺诈行为，被彻底禁止在本店交易！\n");
		return 1;
	}
	for (index=0;index<MAX_ITEMS;index++)
	{
		if (!shop->query("guwan_store/"+me->query("id")+"/"+index))
		{
			posi=index;
			break;
		}
		else
		flag+=1;
	}
	if (flag>=10)//一人只许存10件古玩字画
	{
		tell_object(me,"您在这里已经寄存了至少十件古玩字画了，再存小店就不敢收了。\n");
		return 1;
	}
	if (ob->query("guwan_jiandinged"))
	{
		shop->set("guwan_store/"+me->query("id")+"/"+posi+"/itemlist",ob->query("itemlist"));
		shop->set("guwan_store/"+me->query("id")+"/"+posi+"/identified",1);
	}
	else
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/unidentified",1);
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/value",ob->query("value"));
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/name",ob->query("name"));
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/id",ob->query("id"));
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/real_value",ob->query("real_value"));
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/level",ob->query("level"));
	if (ob->query("guwan"))
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/type","guwan");
	else
	shop->set("guwan_store/"+me->query("id")+"/"+posi+"/type","zihua");
	shop->save();
	message_vision("$N把$n寄存在古董店。\n",me,ob);
	destruct(ob);
	return 1;
}
int do_qu(string arg)
{
	object ob,me=this_player();
	int index,i,afford,payment;
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if( !arg || sscanf(arg, "%d", index)!=1 )
	return notify_fail("指令格式：qu <物品标号>\n");
	shop->restore_itself();
	if (!sizeof(shop->query("guwan_store/"+me->query("id"))))
	return notify_fail("你并没有在这里寄存任何古董。\n");
	if (index<0||index>MAX_ITEMS)
	return notify_fail("错误的物品编号，请用list查询自己寄存的古董。\n");
	if (!shop->query("guwan_store/"+me->query("id")+"/"+index))
	return notify_fail("错误的物品编号，请用list查询自己寄存的古董。\n");
	payment=(int)shop->query("guwan_store/"+me->query("id")+"/"+index+"/value")*EXCHANGE_RATE/100*(1+shop->query("blacklist/"+me->query("id")));
	if( !(afford = me->can_afford(payment)) )
	{
		tell_object(me,"你没有足够的钱来赎回这样东西。\n");
		return 1;
	}
	if( afford == 2 )
	{
		tell_object(me,"你没有足够的钱来赎回这样东西。\n");
		return 1;
	}
	ob=new("/d/guiyunzhuang/obj/"+shop->query("guwan_store/"+me->query("id")+"/"+index+"/type"));
	tell_object(me, sprintf("%d\n", ob->query("itemlist")) );
	if ( shop->query("guwan_store/"+me->query("id")+"/"+index+"/identified") &&
	     shop->query("guwan_store/"+me->query("id")+"/"+index+"/id") )
	{
	  tell_object(me, sprintf("%d\n", shop->query("guwan_store/"+me->query("id")+"/"+index+"/itemlist")) );
		ob->set("itemlist",shop->query("guwan_store/"+me->query("id")+"/"+index+"/itemlist"));
		tell_object(me, sprintf("%d\n", ob->query("itemlist") ) );
		ob->set("identified",1);
		ob->set("guwan_jiandinged",1);
	  ob->set("real_value", shop->query("guwan_store/"+me->query("id")+"/"+index+"/real_value") );
	  ob->set("value", shop->query("guwan_store/"+me->query("id")+"/"+index+"/value") );
	  ob->set("level", shop->query("guwan_store/"+me->query("id")+"/"+index+"/level") );
    ob->set_name(shop->query("guwan_store/"+me->query("id")+"/"+index+"/name"), ({shop->query("guwan_store/"+me->query("id")+"/"+index+"/id") }) );
		//ob->rename();
	}
	me->start_busy(1);
	shop->delete("guwan_store/"+me->query("id")+"/"+index);
	shop->save();
	MONEY_D->player_pay(me,payment);
	message_vision("$N付出了"+MONEY_D->money_str(payment)+"后，赎回了寄存的$n。\n",me,ob);
	ob->move(me);
	return 1;
}