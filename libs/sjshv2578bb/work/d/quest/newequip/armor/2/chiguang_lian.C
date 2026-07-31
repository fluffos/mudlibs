// kuku@sjsh 2003.09.14

#include <ansi.h>
#include <armor.h>
inherit NECK;
inherit "/d/quest/newequip/calculate";

void create()
{
        string msg = "";  
        set_name(HIM"赤光项链"NOR, ({"chiguang xianglian", "necklace"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("material", "pearl");
                set("unit", "串");
                set("need_class",1);
                set("lvl",2);                   
                set("Is_Diablo_Obj",1);
                set("value", 1000);
                set("armor_prop/armor", 50);
        }
        msg += "一串珍珠做成的项链。\n"+"基本防御: "+query("armor_prop/armor")+"\n"; 
        msg += query_desc(); 
        set("long",msg);
        setup();
}
