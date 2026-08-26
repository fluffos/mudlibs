#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
void create(){
    set("author" , "herself");
    set("short" , "a water cloak");
    set("id" , ({"cloak" , "water cloak" }) );
    set("long", @EndText
A magical blue cloak. It creates a bubble around you.
The bubble protects you from any suffocation damage.
EndText
    );
    set_armor_type("cloak");
    set("size", -1);
    set("magic_defense" , 3);
    set("prevent_drop", 1);
    set("prevent_get", 1);
    set("equip_func", "equip_func");
}

int equip_func(){
    TP->resistance("suffocation" , 0);
    return 1;
}
int query_auto_load(){return 1;}
