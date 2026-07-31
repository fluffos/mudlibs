// drop.c
// 星星2000/6/14修正bug

inherit F_CLEAN_UP;
#include <ansi.h>
int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
string wiz_status;
	if(!arg) return notify_fail("你要丢下什么东西？\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("由于你没有心跳，请重新登陆!!\n");
        }
//        if( me->is_busy() )
//        return notify_fail("你上一个动作还没有完成，不能丢东西！\n");
      if( !environment(me) )
        return notify_fail("这里不准扔东西。\n");

      if( environment(me)->query("no_drop1") )
        return notify_fail("这里不准扔东西。\n");

		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
string wiz_status;
    object *inv;
	mixed no_drop;

	if( obj->query_temp("is_rided_by") == me->query("id"))
		return notify_fail( obj->name() + "不是正被你骑着。\n");
        if( obj->query("weapon_prop") && me->is_exert() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("你正在使用"+me->query_exert()+"，无法丢下"+obj->name()+"。\n");
        if( obj->query("weapon_prop") && me->is_perform() &&
            obj == me->query_temp("weapon"))
                 return notify_fail("你正在使用"+me->query_perform()+"，无法丢下"+obj->name()+"。\n");

//	if( no_drop = obj->query("no_drop") )
//		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");
	inv = all_inventory(environment(me));  
        if (sizeof(inv)>49)
            return notify_fail("地上已经那么多东西了，你想干嘛？\n");

/*        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能丢东西！\n");*/
	if( no_drop = environment(me)->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "这里东西丢弃下去也看不见。\n");

if (userp(obj) &&
!environment(me)->query("no_fight"))
                        return notify_fail("要放下昏了的玩家，得找一个安全的地方！\n");

	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" 
	&& userp(me) && wizardp(me))
message("channel:chat", HIC"【玩家监督】"+me->name() + "扔下了" + 
                  obj->query("name")+HIC"!"NOR"。\n", users());

	if (obj->move(environment(me))) {
		if( obj->is_character() )
 if (!me->is_ghost())
{
			message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
}else 			message_vision("$n从$N身上掉了下来，躺在地上。\n", me, obj);
		else {
			message_vision( sprintf("$N丢下一%s$n。\n",	obj->query("unit")),
				me, obj );
			if( !obj->query("value") && !obj->value() ) {
				write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
				destruct(obj);
			}
/*			if( obj->query("id")=="coin" && !userp(obj)
			&& obj->query("money_id")=="coin" ) {
				write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
				destruct(obj);
			}*/

		}
		me->save();
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : drop <物品名称>
 
这个指令可以让你丢下你所携带的物品.
 
HELP
    );
    return 1;
}
 
