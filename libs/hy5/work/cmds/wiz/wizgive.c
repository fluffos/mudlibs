// give.c
// 星星2000/6/14修正bug

#include <ansi.h>

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

//	if( who->query("env/no_accept") )
//		return notify_fail("人家现在不想要什么东西。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "正被你骑着，不能给人。\n");
//		if( obj->query("no_drop") )
//			return notify_fail("这样东西不能随便给人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{

//       if( obj->query("no_drop") )
//		return notify_fail("这样东西不能随便给人。\n");
// Add by Java 
	if( userp(obj) )
		return notify_fail("你只能卖玩家。\n");
// on June 3.1998

	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "不是正被你骑着。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");
		// check for dynamic_quests
        if(obj->query("dynamic_quest"))
        if(TASK_D->quest_reward(me,who,obj))
        return 1;
	if( !interactive(who) && !who->accept_object(me, obj) )
//		return notify_fail("你想给，可是人家还不想要你的这样东西。\n");
		return notify_fail("对方不接受这样东西。\n");
/* 
       //给东西记录到/log/cmds/give   星星(lywin)
	log_file("cmds/give",
	sprintf("%s(%s) 在%s把一个(%s) 给了%s（%s）on %s\n",
	me->name(),  //记录使用命令的人名
	geteuid(me), //记录使用命令的ID
	(string)environment(me)->query("short"), //记录复制物品所在的房间
	obj->name(1), //记录给的物品的名称
	who->name(),  //记录使用对象的人名
	geteuid(who), //记录使用对象的ID
	ctime(time()) ) ); //记录使用命令的时间
*/
	if( !userp(who) && obj->value() ) {
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
        me->save();
        if (userp(who)) who->save();
		return 1;
	} else if( obj->move(who) ) {
		printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s给你一%s%s。\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
		if (userp(who)) who->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
