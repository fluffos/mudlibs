#include <weapon.h>
#include <ansi.h>
inherit STAFF;
inherit F_UNIQUE;

void create()
{
        set_name(BLU"天魔杖"NOR, ({ "tianmo zhang" , "zhang"}) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是白驼山的镇山之宝——天魔杖！");
                set("value", 30000);
                set("material", "steel");
                set("preorder",0);
                set("robinterval",3600);  
        }
        init_staff(160);
        set("wield_msg", HIW"只听“唰”的一声，一道黑光闪过，$N的手中多了把$n。\n"NOR);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
		F_POISON->poison_attack(me,victim,"bt_poison",victim->query_condition("bt_poison")+1);

        return HIR "$n面孔怪异的扭曲，显然是中了白驼的蛇毒！\n\n" NOR;
}



