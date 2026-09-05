
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( RED "龙阳刀" NOR, ({ "blade" }) );
    set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把采天地之精炼制的龙阳刀\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N一反腕从背后拔出一把$n握在手中，一股浓重的刀气直逼过来。\n");
 set("unwield_msg", "呛啷一声，$N反腕将手中的$n插到背后。\n");
        }

     init_blade(3000);
        setup();

}


/*

void init()
{
        if (environment()->query("id")!="gudu")
        {
                message_vision(query("name")+"已通灵，看到$N不是主人司马长风，从$N的身上飞出，化作一道精练飞向天际。\n",this_player());
                destruct(this_object());
                return;
        }
}

*/
string query_autoload()
{
        return query("name");
}

void autoload()
{}

