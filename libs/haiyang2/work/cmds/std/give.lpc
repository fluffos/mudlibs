// give.c
// 星星2000/6/14修正bug

#include <ansi.h>

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
string wiz_status;
	object obj, who, *inv, obj2;
	int i, amount;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("由于你没有心跳，请重新登陆!!\n");
        }

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if( who->query("env/no_accept")&&!wizardp(me) )
		return notify_fail("人家现在不想要什么东西。\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "正被你骑着，不能给人。\n");
if (userp(me) && !userp(who) && obj->is_character())
	return notify_fail("你想把活人送人??\n");

if (who->query("id")!="zhou botong" &&
who->query("id")!="shangguanjiannan")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("这样东西不能随便给人。\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("no_drop")&& obj->query("no_get")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("no_get")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");

}
                if( obj->query("weapon_prop") && me->is_exert() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("你正在使用"+me->query_exert()+"，无法给出"+obj->name()+"。\n");
                if( obj->query("weapon_prop") && me->is_perform() &&
                        obj == me->query_temp("weapon"))
                               return notify_fail("你正在使用"+me->query_perform()+"，无法给出"+obj->name()+"。\n");
	if( obj->query("ownmake") && !wizardp(me) )
		return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("jobfeng") )
		return notify_fail("这样东西不能随便给人。\n");

        if(obj->query("dynamic_quest") && !userp(me))
		return notify_fail("这样东西不能随便给人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");

                // add by hello 1996.12.05
                // 检查玩家身上是不是已有太东西
                inv = all_inventory(who);
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"【玩家监督】"+me->name() + "给" + 
                  who->query("name") + "个"+obj->query("name")+HIC"!"NOR"。\n", users());

                if (inv && sizeof(inv)>49 && userp(who))
                {
                        write(who->name()+"身上都那么多东西了，你还想给他啊！\n");
                        return 1;
                }
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
int exp,pot;
string wiz_status;
if (who->query("id")!="zhou botong")
{
	if( obj->query("no_give")&& obj->query("no_get")&&!wizardp(me))
			return notify_fail("这样东西不能随便给人。\n");

	if( obj->query("no_drop")&&!wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
	if( obj->query("no_get")&& obj->query("no_drop") && !wizardp(me) )
			return notify_fail("这样东西不能随便给人。\n");
}
	if( obj->query("jobfeng") )
		return notify_fail("这样东西不能随便给人。\n");
        if (userp(who) &&
            sizeof(filter_array(all_inventory(who), (: ! $1->query("equipped") :))) >= 40 &&
            ! obj->can_combine_to(who))
        {
		tell_object(me, "人家身上的东西实在是太多了，没法再拿东西了。\n");
                return 0;
        }

	switch ((string)obj->query("equipped"))
	{
	case "worn":
		tell_object(me, obj->name() + "必须脱下来才能给别人。\n");
                return 0;

	case "wielded":
                tell_object(me, obj->name() + "必须解除装备才能给别人。\n");
                return 0;
	}

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
        if(!userp(who)
 && obj->query("name")==me->query_temp("jobitem")
 && who->query("name")==me->query_temp("jobnpc")
 && !userp(obj))
{
exp=random(300)+390;
pot=exp*2/3+random(280);
me->add("potential",pot);
me->add("combat_exp",exp);
tell_object(me,HIW"你被奖励了：\n" + 
chinese_number(exp) + "点实战经验\n" +
chinese_number(pot) + "点潜能\n"+
NOR);
tell_object(me,HIR"你成功的完成了一项任务!\n"+
NOR);

destruct(obj);
me->apply_condition("nonamejob",0);
me->delete_condition("nonamejob");
me->set("quest", 0);
me->delete_temp("jobnpc");
me->delete_temp("jobitem");
//return notify_fail(HIR"你成功的完成了一个任务!。\n"NOR);
return 1;
}

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

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"【玩家监督】"+me->name() + "给" + 
                  who->query("name") + "个"+obj->query("name")+HIC"!"NOR"。\n", users());

	if( !userp(who) && obj->value() ) {
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
if (!obj->query("money_id") || !who->query("pubmaster") || !who->query_temp("no_kill")  || obj->query("base_value") < 100)
{
		destruct(obj);
}
else
{
	obj->move(who);
}
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
	if( !userp(who) && !obj->is_character()
	&& !userp(obj)) 
{
obj->set("no_beg",1);	
obj->set("no_steal",1);
}
		if (userp(who)) who->save();
		if (userp(obj)) obj->save();
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
