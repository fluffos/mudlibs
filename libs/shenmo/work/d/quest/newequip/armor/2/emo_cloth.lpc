// kuku@sjsh 2003.09.14

#include <ansi.h>
#include <armor.h>
inherit CLOTH;
inherit "/d/quest/newequip/calculate";

void create()
{
        string msg = "";  
        set_name(HIB"恶魔衣"NOR, ({"emo yi", "cloth"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
                set("material", "cloth");
                set("unit", "件");
                set("need_class",-1);
                set("lvl",2);                   
                set("Is_Diablo_Obj",1);
                set("value", 1000);
                set("armor_prop/armor", 50);
        }
        msg += "一件薄薄的衣服。\n"+"基本防御: "+query("armor_prop/armor")+"\n"; 
        msg += query_desc(); 
        set("long",msg);
        setup();
}
