//Cracked by Roath
//淑女剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("淑女剑", ({ "shunv jian","sword","jian" }));
        set_color(HIM);
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把细长的古剑，剑刃上依稀有两个篆刻的小字：
[淑女]\n"NOR);
                set("value", 1000);
                set("material", "steel");
                set("ductile", 10);
                set("sharpness", 10);
                set("female_only", 1);
               // set("wield_msg","$N浅浅一笑，从怀中轻轻拔出一把$n握在手中。\n");
                //set("unwield_msg","$N将手中的$n小心的收回剑鞘。\n");
        }
init_sword(100+random(11));
        setup();
       
}
int wield()
{
        object me = environment();
        object ob = this_object();
        int ret;

        if( !wizardp(me) && me->query("gender") != "女性" )
        {
        message_vision(MAG"$N轻轻拿出$n，只觉的很是不舒服,心里隐隐约约有
个声音：“女人的东西,我还是不要动的好。” 于是$N随手把$n丢到了地上。\n"NOR, me, ob);
	ob->move(environment(me));
	return 0;
        }
        else if( ret = ::wield() )
        {
	message_vision(HIC"只见$N浅浅一笑，从怀中轻轻拔出一把淑女剑握在手中。\n"NOR, me );
	return 0;
        }
}


