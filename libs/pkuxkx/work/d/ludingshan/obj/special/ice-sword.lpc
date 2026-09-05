#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
 	set_name(HIW "寒冰剑" NOR , ({ "ice sword", "jian", "sword" }) );
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一柄寒冰冻结而成的宝剑，异常锋利，不过在手中握得太久可能会化掉。\n");
                set("material", "ice");
                set("no_sell", 1);
                set("no_pawn", 1);
                set("no_store", 1);
                set("no_put", 1);

                set("value", 1);
                set("wield_msg", WHT "一道寒光闪过，$N紧紧的握住了寒冰剑 ! \n" NOR );
                set("unwield_msg", WHT"$N将手中的$n插入背后的剑鞘。\n");
        }
        init_sword(250 + random(151), 1 + random(2));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if(random(3) == 0)
	{
		victim->start_busy(3);
		return HIC "$n感到一阵凛冽的寒气扑面而来，不由得浑身哆嗦。\n" NOR;
	}
	else if(random(3) == 0)
	{
		victim->receive_damage("qi", damage_bonus, me);
		victim->receive_wound("qi", damage_bonus / 2, me);
		return HIC "$n感到一阵凛冽的寒气扑面而来，吓得魂不附体，竟被冰剑锋芒所伤。\n" NOR;
	}
	else
	return 0;
}

void init()
{
	remove_call_out("des");
        call_out("des", 180, this_player(), this_object());
}
int des(object me, object ob)
{
        if (objectp(me)) 
        	tell_object(me, HIW"冰剑慢慢溶化,最后化成一滩水消失掉了!\n"NOR);
        if( ob->query("equipped") )  ob->unequip();
        destruct(ob);
        return 1;
}

