// Filename : /cmds/verb/get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount;
	string wiz_status;

	wiz_status = SECURITY_D->get_status(me);	
        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("由于你没有心跳，请重新登陆!!\n");
        }
      if( environment(me)->query("no_get") )
        return notify_fail("这里不准捡东西。\n");

	if( !arg ) return notify_fail("你要捡起什麽东西？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
        if( env->query_temp("no_kill") 
        && env->query("pubmaster"))
        return notify_fail("此人不能get！\n");

        if (userp(env) && !query_heart_beat(env))
        {
         write("你想做什么！\n");
        return notify_fail("此人无心跳！\n");
        }
        if (userp(env) && env->query_temp("netdead"))
        {
         write("你想做什么！\n");
        return notify_fail("此人无心跳！\n");
        }

	if( (env->query("no_get_from") || living(env) ) 
			&& (wiz_level(me) <= wiz_level(env)))
			return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
	if( userp(env) && query_ip_name(env)==query_ip_name(me) )
			return notify_fail("相同IP之间，不允许搜身。\n");


	if( (env->query("no_get_from") || living(env) ) 
	&& wiz_status != "(admin)" && wiz_status != "(arch)" && wiz_status != "(wizard)")
		return notify_fail("只有 (wizard) 以上的巫师才能搜身。\n");

	} else env = environment(me);

	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("这里没有这样东西。\n");
        if (userp(obj) && !query_heart_beat(obj))
		return notify_fail("此人拿不起来。\n");
        if (userp(obj) && !userp(me))
		return notify_fail("NPC不能背人。\n");

        if (userp(env) && env->query_temp("netdead"))
		return notify_fail("此人拿不起来。\n");
        if( obj->query_temp("no_kill") 
        && obj->query("pubmaster"))
		return notify_fail("此人拿不起来。\n");
        if( obj->query_temp("no_kill")
        && obj->query("pubmaster") )
		return notify_fail("此人拿不起来。\n");

		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开拿走。\n");
		if( amount < 1 )
			return notify_fail("东西的个数至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("这里没有那麽多的" + obj->name() + "。\n");
                if (me->query("combat_exp") <1000 
                      && userp(obj))
                      return notify_fail("只有经验大于1000才能背玩家。目前你还背不动。\n");
		else if( amount == (int)obj->query_amount() ) {
			return do_get(me, obj);
		} else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->move(env);			// For containers.
			obj2->set_amount(amount);
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(4);
			return do_get(me, obj);
		}
	}

	// Check if we are makeing a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	return notify_fail("你还在战斗中！只能一次拿一样。\n");
		if( !env->query_max_encumbrance() )	return notify_fail("那不是容器。\n");
        if( env->is_tree() )
             return notify_fail("这是给新手活命用的，还是不要太贪心了吧n");
        if (!userp(me) && env->is_character())
        return notify_fail("NPC搬人做什么!\n");
        if (!userp(me) && userp(env))
        return notify_fail("NPC搬人做什么!\n");
        if (userp(env) && !query_heart_beat(env))
		return notify_fail("此人拿不起来。\n");
        if (userp(env) && env->query_temp("netdead"))
		return notify_fail("此人拿不起来。\n");

 if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
if (!userp(env) && env->is_character())
        return notify_fail("迷宫的妖精你要了做什么!\n");
}
		inv = all_inventory(env);
		if( !sizeof(inv) )
        {
            if( env->is_tree() )
               return notify_fail("树上什么也没有了。\n");
			return notify_fail("那里面没有任何东西。\n");
        }

		for(i=0; i<sizeof(inv); i++) {
			if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
			do_get(me, inv[i]);
		}
		write("捡好了。\n");

		return 1;
	}
if (userp(env)) env->save();
if (userp(me)) me->save();
	if( !objectp(obj = present(arg, env)) || living(obj) )
		return notify_fail("你附近没有这样东西。\n");
        if (!userp(me) && obj->is_character())
        return notify_fail("NPC搬人做什么!\n");
        if (!userp(me) && userp(obj))
        return notify_fail("NPC搬人做什么!\n");
        if (userp(obj) && !query_heart_beat(obj))
		return notify_fail("此人拿不起来。\n");
        if (userp(obj) && obj->query_temp("netdead"))
		return notify_fail("此人拿不起来。\n");

 if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
if (!userp(obj) && obj->is_character())
        return notify_fail("迷宫的妖精你要了做什么!\n");
}
	if( obj->query("no_get") )
		return notify_fail("这个东西拿不起来。\n");
        if( obj->query("winner") )
		return notify_fail("此人拿不起来。\n");
        if( obj->query_temp("no_kill") 
        && obj->query("pubmaster"))
		return notify_fail("此人拿不起来。\n");
        if( obj->query_temp("no_kill")
        && obj->query("pubmaster"))
		return notify_fail("此人拿不起来。\n");
        if (!userp(me) && obj->is_character())
        return notify_fail("NPC搬人做什么!\n");
        if (!userp(me) && userp(obj))
        return notify_fail("NPC搬人做什么!\n");


	return do_get(me, obj);  
}
	
int do_get(object me, object obj)
{
	object old_env, *guard;
	int equipped;
        object *obs;

	if( !obj ) return 0;
	old_env = environment(obj);

	if( obj->is_character() ) {
		if( living(obj) ) return 0;
        
        if( obj->query_temp("no_kill") 
        && obj->query("pubmaster"))
		return notify_fail("此人拿不起来。\n");
        if (!userp(me) && obj->is_character())
        return notify_fail("NPC搬人做什么!\n");
        if (!userp(me) && userp(obj))
        return notify_fail("NPC搬人做什么!\n");

       if( userp(obj) && environment(obj)->query("short")=="关口" )
        return notify_fail("这里不准背玩家。\n");
       if( userp(obj) && environment(obj)->query("short")=="平定州" )
        return notify_fail("这里不准背玩家。\n");
       if( userp(obj) && environment(obj)->query("short")=="玄岳门" )
        return notify_fail("这里不准背玩家。\n");
	if( userp(obj) && query_ip_name(obj)==query_ip_name(me) )
	return notify_fail("你不能背负IP相同的玩家的身体。\n");
 if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
if (!userp(obj) && obj->is_character())
        return notify_fail("迷宫的妖精你要了做什么!\n");
}
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

	if( guard = obj->query_temp("guarded") ) {
		guard = filter_array(guard, (:
			objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2)
			:), me);
		if( sizeof(guard) )
			return notify_fail( guard[0]->name() 
				+ "正守在" + obj->name() + "一旁，防止任何人拿走。\n");
	}

	if( obj->query("equipped") ) equipped = 1;
        obs = filter_array(all_inventory(me), (: ! $1->query("equipped") :));
        if (sizeof(obs) >= 40 &&
            ! obj->can_combine_to(me))
                return notify_fail("你身上的东西实在是太多了，没法再拿东西了。\n");

	if( obj->move(me) ) {
		if( me->is_fighting() ) me->start_busy(1);
		if( obj->is_character() )
			message_vision( "$N将$n扶了起来背在背上。\n", me, obj );
		else
                 if(obj->query("dynamic_quest") || obj->query("dynamic_questjia"))
{
message("channel:chat", HIC"【神书信息】"GRN + me->query("name")+"得到"+HIR"神书:" + obj->query("name")+HIG"啦！\n"NOR,users() );
}
			message_vision( sprintf("$N%s一%s$n。\n", 
                
				old_env==environment(me)? "捡起":
					(old_env->is_character() ?
						"从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
                    (old_env->is_tree() ? "从" + old_env->name() +"上摘下" :
						"从" + old_env->name() + "中拿出") ),
				obj->query("unit")), me, obj );
if (userp(old_env)) old_env->save();
if (userp(me)) me->save();
if (userp(me) && userp(old_env))
	log_file("cmds/get",
		sprintf("%s get %s from %s\n", me->query("name"), obj->query("name"),old_env->query("name")) );

if (userp(me) && me->query_temp("xmud")) 
{
	seteuid(getuid());
	me->force_me("xnventory");
me->force_me("xkan");
}

		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : get <物品名称> [from <容器名>]
 
这个指令可以让你捡起地上或容器内的某样物品.
 
HELP
    );
    return 1;
}
 
