#include <mudlib.h>
inherit WEAPON;
 
int check_ali()
void create()
{
        set_name("quake wand", "地裂杖");
        add ("id",({ "wand" }) );
        set_short("地裂杖");
        set_long(
"这是一支黯黑色的木杖，也许如其名般地可以让大地为之震撼。\n"
        );
        set( "unit", "支" );
        set( "weapon_class", 40 );
        set( "type", "wand" );
        set( "min_damage", 20 );
        set( "max_damage", 30 );
        set( "weight", 60 );
        set( "power_on", 1);
        set( "no_sale", 1);
        set( "value", ({ 5000, "silver" }) );
 
        set( "hit_func", "wand_hit" );
        set( "charge_left", 9 );
        set( "max_charge", 9 );
        set( "special_damage_type", "none" );
        set( "special_damage", (: check_ali :) );
        set( "special_c_msg", "一挥，一道黑色的□划过地面，大地为之剧烈地震动。\n");
}
int check_ali()
{
    object holder;
    int my_ali,max;
 
    holder = this_player();
    my_ali = (int)holder->query("alignment");
    if (my_ali > 0) return 50;
    else
       if (my_ali < -30000) return 100;
    max = (-my_ali/1000)+70;
    return max;
}
