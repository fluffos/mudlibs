// drop.c
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    object obj, *inv, obj2;
    int i, amount;
    string item;

    if(!arg) return notify_fail("指令格式 : drop <id> 或 drop [数量] <id> 或 drop all\n"); 

    if(environment(this_player())->query("cant_drop")) return notify_fail("你在众目睽睽之下最终没有乱扔东西...\n");

    this_player()->save();
    if(sscanf(arg, "%d %s", amount, item)==2) 
    {
        if( !objectp(obj = present(item, me)) )
            return notify_fail("你身上没有 "+item+" 这样东西。\n");
        if( stringp(obj->query("no_drop")) )
            return notify_fail( (string)obj->query("no_drop") );
         if((int)obj->query("gem_ob_autoloaded")>0)
                        return notify_fail("这件东西是自动加载物品，不可轻易丢弃！\n"); 
        if( !obj->query_amount() )
            return notify_fail( obj->name() + "不能被分开丢弃。\n");
        if( amount < 1 )
            return notify_fail("东西的数量至少是一个。\n");
        if( amount > obj->query_amount() )
            return notify_fail("你没有那么多的" + obj->name() + "。\n");
        else if( amount == (int)obj->query_amount() )
            return do_drop(me, obj);
        else
        {
            obj->set_amount( (int)obj->query_amount() - amount );
            obj2 = new(base_name(obj));
            obj2->set_amount(amount);
            return do_drop(me, obj2);
        }
    }

    if(arg=="all") {
    	if  (time() - me->query_temp("last_dropgetall_cmd_time") < 30)
    		return notify_fail("你刚刚整理过太多东西，休息一会儿吧！\n");
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) 
        {
            if( !inv[i]->query("equipped"))
                do_drop(me, inv[i]);
        }
        if (sizeof(inv) > 30)
			me->set_temp("last_dropgetall_cmd_time",time());            
        return 1;
    }

    if(!objectp(obj = present(arg, me)))
        return notify_fail("你身上没有 "+arg+" 这样东西。\n");
    return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
    mixed no_drop;

    if( (no_drop = obj->query("no_drop")) && !wizardp(me))
        return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");

    if( userp(me) && wizardp(me) ) {
        log_file( "wiz/wiz_drop_log", sprintf("%s %s（%s）在%s丢下一%s（%d）%s。\n", 
                    ctime(time()), me->query("name"), me->query("id"), 
                    ( stringp(environment(me)->query("short")) ) ?
                    environment(me)->query("short") : environment(me)->query("name"), 
                    obj->query("unit"), obj->query_amount(), obj->name()));
    }
    if (obj->move(environment(me))) 
    {
        if( obj->is_character() ) {
            if( obj == me->query_temp("created_pet") )
            {
                message_vision("$N把$n从怀中放了出来。\n", me, obj);
                obj->enable_player();
            }
            else message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
        }
        else 
        {
            message_vision( sprintf("$N丢下一%s$n。\n",     obj->query("unit")), me, obj );
            if( !obj->query("value") && !obj->value() ) {
                write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
		//如果是task物品，那么先记录task_lost
		if (obj->query("task_owner"))
			TASK_D->task_lost(obj,me->name());
                destruct(obj);
            }
        }
        return 1;
    }
    return 0;
}

int help(object me)
{
    write(@HELP
指令格式 : drop <id> 或者 drop [数量] id 或者 drop all (已经装备的物品不会被丢掉)
这个指令可以让你丢下你所携带的物品.
HELP
    );
    return 1;
}
