
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "瑯琊仙剑" NOR, ({ "xianjian" }) );
    set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"瑯琊仙子星子的仙家法器。\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N轻一招手，身边一位漂亮的仙子把$n递到$N手中,$N轻轻拂剑，一阵清风拂过，$n呛啷出鞘。\n");
                set("unwield_msg", "$N轻一挥手，身边的漂亮仙子又把$n接过去伺立一旁。\n");
        }

     init_sword(3000);
        setup();

}

void init()
{
        if (environment()->query("id")!="cindere"&&environment()->query("id")!="xian"&&environment()->query("id")!="gudu")
        {
                message_vision(query("name")+"轻哼一声，说道你又不是我主人星子，怎敢用天仙派的仙家法器从$N的身上飞出，化作一道精练飞向天际。\n",this_player());
                destruct(this_object());
                return;
        }
}

string query_autoload()
{
        return query("name");
}

void autoload()
{}

