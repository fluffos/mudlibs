// insert.c
// by Vast@pkuxkx
// all comments added by Vast

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_GEMS;


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int i;
	object *inv, gem, gem2;

	if (!arg || arg == "")
		return notify_fail("你想合并什么宝石？\n");

        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

        if( !objectp(gem = present(arg, me)) )
                return notify_fail("你身上没有这种宝石。\n");

	if (gem->query("level") == 8)
		return notify_fail("这种宝石已经是最高等级了！\n");

	if (me->query("max_neili") < 500 || me->query("neili") < 800)
		return notify_fail("以你现在的内力修为，还无法运功合并宝石！\n");

	inv = all_inventory(me);
	for(i = 0; i < sizeof(inv); i++)
	if (inv[i] != gem && inv[i]->query("id") == gem->query("id"))
	{
		if (!objectp(gem2))
			gem2 = inv[i];
		else
		{
			message_vision(HIG"$N暗运内力劲透宝石，但见" + gem->name() + HIG"表面异彩流动，
渐渐的$N收回了内力，只觉" + gem->name() + HIG"似乎变得更加完美了！\n"NOR, me);
				me->add("max_neili", - gem->query("level"));
				me->add("neili", - 500);
				me->start_busy(1);
				new_gem(gem->query("material"), gem->query("level") + 1)->move(me);
				destruct(gem);
				destruct(inv[i]);
				destruct(gem2);
				return 1;
		}
	}
	return notify_fail("你必须有三块同样的宝石才能进行合并！\n");

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式：combine <宝石>

这个指令可以让你将三颗同样的宝石合并为一个高等级的宝石。
合并宝石要消耗玩家的大量内力，并且会降低最大内力。

HELP
    );
    return 1;
}