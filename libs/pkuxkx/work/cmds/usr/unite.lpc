#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object obj, mine;

        if (!arg || arg == "")
			return notify_fail("你想合并什么矿石碎片？\n");

        if( me->is_busy() )
			return notify_fail("你上一个动作还没有完成！\n");
	
        if( !objectp(mine = present(arg, me)) )
			return notify_fail("你身上没有这种矿石碎片。\n");
        if (!mine->query("is_castmaterial_piece")) 
			return notify_fail(mine->query("name")+"不是一种矿石碎片。\n");
		if (me->query_skill("mining",1)<30||me->query_skill("mining",1)<mine->query("level")*10+20||!me->query("weapon_cast/mine_unite"))
			return notify_fail("你没有掌握合成技术，或者限于你的采矿学等级，不足以合成这种矿石碎片！\n");
        if (mine->query_amount()>16)
        {
			obj=new("/obj/smith/materials/material");
			obj->init_material(mine->query("level")-1,random(4));
			message_vision(HIR"$N"+HIR+"把十六片"+mine->query("name")+HIR+"合成出一块"+obj->query("name")+"。\n"NOR, me);
			me->start_busy(1);
			mine->add_amount(-16);
			obj->move(me);
            return 1;
		}
        return notify_fail("要想提纯，你必须拥有至少十六块同样品质的矿石。\n");
}

int help(object me)
{
        write(@HELP
指令格式：unite <矿石碎片>

你将十六块同样品质的矿石碎片合并为一个的同品质矿石材料。
HELP
    );
    return 1;
}
