// kuku@sjsh 2003.09.14

#include <ansi.h>
#include <armor.h>
inherit ARMOR;
inherit "/d/quest/newequip/calculate";

void create()
{
        string msg = "";  
        set_name(HIB"骷髅甲"NOR, ({"kulou jia", "armor"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("material", "gold");
                set("unit", "件");
                set("need_class",-1);
                set("lvl",1);                   
                set("Is_Diablo_Obj",1);
                set("value", 1000);
                set("armor_prop/armor", 25);
        }
        msg += "一件厚厚的盔甲，不时的闪现出鬼魅似的光泽。\n"+"基本防御: "+query("armor_prop/armor")+"\n"; 
        msg += query_desc(); 
        set("long",msg);
        setup();
}
