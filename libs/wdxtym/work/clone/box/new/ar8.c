#include <ansi.h> 
#include <armor.h>

inherit ARMOR;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
        set_name((order[random(13)])+"霞蔚披风"NOR, ({"pifen8"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
     set("long", "一件霞蔚披风．\n");
                set("material", "steel");
                set("value", 3100);
                set("armor_prop/armor", 65);
set("armor_prop/damage", 17);
set("armor_prop/attack", 16);
        }
        setup();
}


