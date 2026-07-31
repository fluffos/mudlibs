#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"飞雪披风"NOR, ({"pifen3"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
     set("long", "一件飞雪披风．\n");
                set("material", "steel");
                set("value", 2600);
                set("armor_prop/armor", 60);
set("armor_prop/damage", 14);
set("armor_prop/attack", 14);
        }
        setup();
}


