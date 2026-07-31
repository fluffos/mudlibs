//Cracked by Roath
//君子剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("君子剑", ({ "junzi jian","sword","jian" }));
        set_color(HIW);
	set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("long", "这是一把寒气逼人的宝剑，剑刃较之一般长剑似乎要略长一些。\n");
		set("value", 1000);
                set("material", "steel");
		
        }
	init_sword(55+random(11));
        setup();
	::create();
}
int wield()
{
        object me = environment();
        object ob = this_object();
        int ret;

        if( !wizardp(me) && me->query("gender") != "男性" )
        {
        message_vision(MAG"$N轻轻拿出$n，只觉的有点重，不太合手,还是丢了吧！” 于是$N随手把$n丢到了地上。\n"NOR, me, ob);
	ob->move(environment(me));
	return 0;
        }
        else if( ret = ::wield() )
        {
	message_vision(HIC"只见$N浅浅一笑，从怀中轻轻拔出一把君子剑握在手中。\n"NOR, me );
	return 0;
        }
}