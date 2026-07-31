#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"赤霞披风"NOR, ({"pifen9"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
     set("long", "一件赤霞披风．\n");
                set("material", "steel");
                set("value", 3200);
                set("armor_prop/armor", 66);
set("armor_prop/damage", 17);
set("armor_prop/attack", 17);
        }
        setup();
}


