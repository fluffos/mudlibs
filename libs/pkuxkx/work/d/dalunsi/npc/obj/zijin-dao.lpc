// zijin-dao.c 紫金刀

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIM"紫金刀"NOR , ({ "zijin dao", "dao","blade" }));
        set_weight(7500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIM"这是把紫色的宝刀，据说只有身负龙象内功的人才能发挥它全部的威力。\n"NOR);
                set("value", 1000000000);
                set("unique", 1);
                set("rigidity", 10);
                set("weapon_prop/dodge", 1);
                set("wield_maxneili", 2000);
                set("treasure",1);
                set("material", "steel");
        }
        init_blade(10);
        setup();
}

int wield()
{
        object ob = environment();

        if( !ob || !living(ob) ) return 0;

        if( (int)ob->query_skill("longxiang-boruo",1) > 100 ) {
                set("weapon_prop/damage" , ob->query_skill("longxiang-boruo",1)/2 );
                if( query("weapon_prop/damage")>90 )    
                        set("weapon_prop/damage" , 90 );
        }
        else
                set("weapon_prop/damage" , 10 );

        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

