// qiangui.c
// by augx@sj  3/13/2002

#include <ansi.h>
inherit ITEM;
#include <group.h>

void create()
{
	set_name(YEL"钱柜"NOR, ({ "qian gui","cash box" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long", "这是一具放钱的钱柜。你可以用他来：\n查帐：check\n存钱：deposit\n取钱：withdraw\n");
		set("value", 15000000);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
	set("hp",3000);
	set("max_hp",3000);
}

void init()
{
	add_action("do_drop", ({"drop","fangzhi","放置"}));
	add_action("do_check", ({"check", "chazhang", "查帐"}));
	add_action("do_deposit", ({"deposit", "cun", "存"}));
	add_action("do_withdraw", ({"withdraw", "qu", "取"}));
}

int do_drop(string arg)
{
	object me = this_player() , env = environment(this_object());

	if( !arg || !id(arg) || env!=me ) return 0;
	env = environment(me);
	if( !me->query("group/id") ) {
		tell_object(me,"你并没有开帮立派，要钱柜何用？\n");
		return 1;
	}
	if( env && stringp(env->query("outdoors")) ) {
		tell_object(me,"钱柜不能放在室外。\n");
		return 1;
	}
	if( !GROUP_D->site_now(me->query("group/id")) ) {
		tell_object(me,GROUP_D->get_last_error());
		return 1;
	}

	GROUP_D->drop_object(this_object(),me,env,"$N开始小心的摆放钱柜……\n","你忙碌了半天，总算把钱柜放置好。\n");
	return 1;
}

int do_check(string arg)
{
	object me = this_player() , env = environment(this_object());
	int money;

	if( !env || env==me ) return 0;
	if( !env->query("group1") ) {
		tell_object(me,"你只能在帮会之内使用这个"+this_object()->name()+"。\n");
		return 1;
	}
	if( me->is_busy() ) {
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}

	money = GROUP_D->query_money( env->query("group1") );
	if( money < -50000 ) {
		tell_object(me,"数据库查询错误，请报告巫师！\n");
		return 1;
	}

	tell_object(me,"现在"+name()+"之中，总共存有"HIY"黄金"NOR+CHINESE_D->chinese_number(money)+"锭。\n");
	if(!wizardp(me)) me->start_busy(2);
	return 1;
}

int do_deposit(string arg)
{
	object me = this_player() , env = environment(this_object());
	object gold;
	string gold_money;
	int money;

	if( !env || env==me ) return 0;
	if( !arg || sscanf(arg,"%d %s",money, gold_money) != 2 || gold_money != "gold")
		return notify_fail("你要放入(deposit <数量> gold)多少黄金？\n");
	if( !env->query("group1") )
		return notify_fail("你只能在帮会之内使用这个"+this_object()->name()+"。\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
	if( !(gold=present("gold_money",me)) || gold->query_amount()<money )
		return notify_fail("你带的钱不够。\n");

	if( GROUP_D->add_money(env->query("group1"),money) < -50000 )
		return notify_fail("数据库操作失败，请报告巫师！\n");
	gold->add_amount(-money);

	message_vision("$N拿出"+CHINESE_D->chinese_number(money)+"锭"HIY"黄金"NOR"，放入钱柜。\n", me);
	if(!wizardp(me)) me->start_busy(2);
	return 1;
}

int do_withdraw(string arg)
{
	object me = this_player() , env = environment(this_object());
	object gold;
	string gold_money;
	int money;

	if( !env || env==me ) return 0;
	if( !arg || sscanf(arg,"%d %s",money, gold_money) != 2 || gold_money != "gold")
		return notify_fail("你要取出(withdraw <数量> gold)多少黄金？\n");
	if( !env->query("group1") )
		return notify_fail("你只能在帮会之内使用这个"+this_object()->name()+"。\n");
	if( me->query("group/id")!=env->query("group1") || me->query("group/class")>2 )
		return notify_fail("你没有权利从这个"+name()+"里取钱。\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
	if( (GROUP_D->query_money(env->query("group1"))-LIMIT_GOLD) < money )
		return notify_fail("去除"+CHINESE_D->chinese_number(LIMIT_GOLD)+"锭黄金的保证金之后，"+name()+"里的黄金不够你取的。\n");

	if( GROUP_D->add_money(env->query("group1"),-money) < -50000 )
		return notify_fail("数据库操作失败，请通知巫师！\n");
	gold = new("/clone/money/gold");
	gold->set_amount(money);
	gold->move(me);

	message_vision("$N从"+name()+"里拿出"+CHINESE_D->chinese_number(money)+"锭"HIY"黄金"NOR"。\n", me);
	if(!wizardp(me)) me->start_busy(2);
	return 1;
}

void broken()
{
	object room = environment(this_object()) , gold;
	int money;
	string groupid;

	if( !room ) return;
	if( sscanf(base_name(room),"/d/group/%s/",groupid) < 1 ) return;
	if( (money=GROUP_D->query_money(groupid)) <= 0 ) return;
	if( money > LIMIT_GOLD ) money = LIMIT_GOLD;

	if( GROUP_D->add_money(groupid,-money) < -10000 ) return;
	tell_room(room,name()+"被打破了，掉出很多金元宝。\n");
	gold = new("/clone/money/gold");
	gold->set_amount(money);
	gold->move(room);
}

varargs int move(mixed dest, int silently)
{
	int result;
	if( !(result = ::move(dest,silently)) ) return result;
	if( !objectp(dest) || clonep(dest) ) return result;
	if( !dest->query("group2") ) return result;

	set("name",YEL+dest->query("group2")+HIY"的钱柜"NOR);
	return result;
}
