// loot.c
// by Vast@PKUxkx

#include <ansi.h>

inherit F_CLEAN_UP;

int do_loot(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj, env;

        if( !arg ) return notify_fail("指令格式 : loot [corpse/skeleton]\n");

        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

	env = environment(me);

        if( !objectp(obj = present(arg, env)) )
                        return notify_fail("这里没有这样东西。\n");

	if(living(obj)) return notify_fail("这个命令只能用来搜查尸体。\n");
        if( !obj->is_corpse() && !obj->is_skeleton())  return notify_fail("这个命令只能用来搜查尸体。\n");

        return do_loot(me, obj);
}

int do_loot(object me, object obj)
{
        object old_env, item;
        object *inv;
        int i, amount;

        if( !obj ) return 0;
        old_env = environment(obj);

        inv = all_inventory(old_env);
        for(i=0;i<sizeof(inv);i++)
           {
            if( !living(inv[i]) ) continue;
            else if(inv[i] != me && (inv[i]->query_temp("guards/object") == obj || inv[i]->query_temp("guards/living") == obj))
                return notify_fail(inv[i]->query("name")+"正在看守" + obj->query("name") + "，你无法搜查！\n");
           }
        if(me->query_temp("guards/object") == obj)
            me->delete_temp("guards/object");

        if(me->query_temp("guards/living") == obj)
            me->delete_temp("guards/living");

	inv = all_inventory(obj);
	amount = sizeof(inv);
	if (amount == 0) return notify_fail("尸体里没有任何东西。\n");
	item = inv[random(amount)];
	amount--;

        if( item->move(me) ) {
                me->start_busy(3);
                message_vision( sprintf("$N%s一%s$n。\n",
                                "从" + obj->name() + "中搜出",
                                item->query("unit")), me, item );
		if(amount == 0)
		{
			message_vision(obj->name() + "里已经没有什么东西了，$N顺势一脚将" + obj->name() + "踢进了路边的杂草中。\n", me);
			destruct(obj);
		}
                return 1;
        }
        else return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : loot [corpse/skeleton]

这个指令可以让你搜查尸体内的某样物品。

HELP
    );
    return 1;
}
