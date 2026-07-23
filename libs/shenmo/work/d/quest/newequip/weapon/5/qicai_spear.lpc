// Created by kuku@sjsh 2003.09.14

#include <weapon.h>
inherit SPEAR;
#include <ansi.h>
inherit "/d/quest/newequip/calculate";

void create()
{        
        string msg = "";   
        set_name(HIM"七彩枪"NOR, ({"qicai qiang", "spear"}));    
        set_weight(5000);                 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 5000);
                set("material", "steel");
                set("lvl",5);
                set("Is_Diablo_Obj",1);  
                set("need_class",1);
                set("inset_hole",3);
                set("wield_msg", "$N提起$n握在手中，威风凛凛。\n");
                set("unwield_msg", "$N舞了一朵枪花，将手中之物收了起来。\n");                
        }
        init_spear(90);  
        msg += "一杆精钢打制的枪。\n"+"基本攻击: "+query("weapon_prop/damage")+"\n"; 
        set("old_long",msg);
        if( query("lvl")>2){
                if( !query("identification") ) 
                        msg =query("old_long") + RED "这样东西还没有鉴定。\n"NOR;
                        set("long",msg);
        } 
        setup();
}
