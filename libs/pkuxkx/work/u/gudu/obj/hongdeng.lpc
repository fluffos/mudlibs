
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( RED "红灯" NOR, ({ "redlamp" }) );
    set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"司马长风常提着它用来照亮人间不平之路，所到之处宵小授首。\n"
);
                set("value", 21500);
                set("material", "steel");
                set("rigidity", 100000);
                set("wield_msg", "$N一反腕从腰际把$n握在手中，眼中流露出对不平世道的无限无奈。\n");
                set("unwield_msg", "$N一振腕反手将手中的$n插入腰际，眼中一阵迷茫。\n");
        }

     init_sword(3000);
        setup();

}


void init()
{
        if (environment()->query("name")!="司马长风")
        {
                message_vision(query("name")+"已通灵，看到$N不是主人司马长风，从$N的身上飞出，化作一道精练飞向天际。\n",this_player());
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

