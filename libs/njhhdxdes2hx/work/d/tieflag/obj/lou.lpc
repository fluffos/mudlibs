#include <ansi.h>
#include <weapon.h>
inherit CLAW;
void create()
{
        set_name( GRN "青魔手" NOR, ({ "green claw", "claw" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "兵器谱排名第九。\n");
                set("value", 350000);
                set("material", "sapphire");
		set("rigidity", 500000);
	        set("wield_msg", "$N戴上一副$n。\n");
                set("unequip_msg", "$N摘下$n\n");
                set("weapon_prop/agility", 5);
        }

        init_claw(95);
        setup();
}

void owner_is_killed(object killer)
{
	message_vision(HIR"\n \n 青魔手 " NOR +"落在地上，又弹入$N的怀中！\n\n",killer);
	this_object()->move(killer);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	me->add("bellicosity",10+random(30));
        return HIG "$N的眼里映着青魔手闪出的诡异绿光．．．\n" NOR;
}

