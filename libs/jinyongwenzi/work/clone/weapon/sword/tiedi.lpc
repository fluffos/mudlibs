// tiedi.c 铁笛

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("铁笛",({"tie di","di"}));
 set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "支");
                set("value", 600);
                set("material", "steel");
                set("long","这是一支笛子，做工十分精细，笛身隐隐发着红光，似乎是精铁掺杂玄铁所铸。\n");
                set("wield_msg","$N伸手轻轻一招，一支$n已出现在$N手中。\n");
                set("rigidity", 3);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);   
                set("weapon_prop/parry", 2);
                set("unique", 1);
                set("unwield_msg","$N一声清啸，将$n插回腰间。\n");
        }
        init_sword(60);
        setup();
}
