
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "凤回剑" NOR, ({ "sword" }) );
    set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把采北山铜母炼制的凤回剑，当世之中只有白秋霜一人可用。\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N一反腕从背后拔出一把$n握在手中，一股森冷的剑气直逼过来。\n");
                set("unequip_msg", "呛啷一声，$N反腕将手中的$n插到背后。\n");
        }

     init_sword(3000);
        setup();

}


void init()
{
        if (environment()->query("name")!="白秋霜"&&environment()->query("name")!="司马长风"&&environment()->query("name")!="冰雁")
        {
                message_vision(query("name")+"已通灵，看到$N不是主人白秋霜，从$N的身上飞出，化作一道精练飞向天际。\n",this_player());
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

