// kuku@sjsh 2003.09.14

#include <ansi.h>
#include <armor.h>
inherit ARMOR;
inherit "/d/quest/newequip/calculate";

void create()
{
        string msg = "";  
        set_name(HIM"赤光甲"NOR, ({"chiguang jia", "armor"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("material", "gold");
                set("unit", "件");
                set("need_class",1);
                set("lvl",2);                   
                set("Is_Diablo_Obj",1);
                set("value", 1000);
                set("armor_prop/armor", 50);
        }
        msg += "一件厚厚的盔甲，不时的闪现出明亮的光泽。\n"+"基本防御: "+query("armor_prop/armor")+"\n"; 
        msg += query_desc(); 
        set("long",msg);
        setup();
}
