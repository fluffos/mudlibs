#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(RED"霸王枪"NOR, ({"bawang qiang","qiang","spear"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"纯钢锻造，长一丈三尺七寸三分，重七十三斤七两三钱，中枪者必死，向无例外。\n"NOR);
                set("unit", "把");
                set("no_put",1);
                set("value", 100000);
                set("no_give_user",1);
                set("no_steal",1);
                set("weapon_prop/spear",12+random(12));

        }
        init_spear(120+random(50));
        setup();
}
