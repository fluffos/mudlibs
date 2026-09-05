#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object *inv, mine;

        if (!arg || arg == "")
			return notify_fail("你想提纯什么矿石？\n");

        if( me->is_busy() )
			return notify_fail("你上一个动作还没有完成！\n");
	
        if( !objectp(mine = present(arg, me)) )
			return notify_fail("你身上没有这种矿石。\n");
        if (!mine->query("is_castmaterial")) 
			return notify_fail(mine->query("name")+"不是一种矿石。\n");
        if (mine->query("advanced"))
			return notify_fail(mine->query("name")+"之前已经被提纯过了。\n");
		if (me->query_skill("smithing",1)<30||me->query_skill("smithing",1)<mine->query("level")*10+20)
			return notify_fail("你现在的锻造术等级，不足以提纯这种矿石！\n");
        inv = all_inventory(me);
        for(int i = 0; i < sizeof(inv); i++)
        if (inv[i]!= mine && inv[i]->query("is_castmaterial") && !inv[i]->query("advanced")&&
			inv[i]->query("type")==mine->query("type")&&inv[i]->query("level") == mine->query("level"))
        {
			message_vision(HIR"$N"+HIR+"提取出两块"+mine->query("name")+HIR+"中纯度较高的部分。\n"NOR, me);
			me->start_busy(1);
			destruct(inv[i]);
			mine->refine();
            return 1;
		}
        return notify_fail("要想提纯，你必须拥有两块同样品质、同样类型的矿石。\n");
}

int help(object me)
{
        write(@HELP
指令格式：refine <矿石铁料>

你将两块同样品质、同样类型的矿石合并为一个纯度较高的同品质矿石。
HELP
    );
    return 1;
}
