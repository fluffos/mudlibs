// Created by kuku@sjsh 2003.09.14

#include <weapon.h>
inherit AXE;
#include <ansi.h>
inherit "/d/quest/newequip/calculate";

void create()
{        
        string msg = "";   
        set_name(BRED"传说斧"NOR, ({"chuanshuo fu", "axe"}));    
        set_weight(9000);                 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 5000);
                set("material", "steel");
                set("lvl",6);
                set("Is_Diablo_Obj",1);  
                set("is_monitored",1);  
                set("inset_hole",4);
                set("need_class",1);
                set("wield_msg", "$N拿出一把$n握在手中，眼前闪过一道寒光。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_axe(100);  
        msg += "这是把沉重的大斧，有八尺多长，锋利无比。\n"+"基本攻击: "+query("weapon_prop/damage")+"\n"; 
        set("old_long",msg);
        if( query("lvl")>2){
                if( !query("identification") ) 
                        msg =query("old_long") + RED "这样东西还没有鉴定。\n"NOR;
                        set("long",msg);
        } 
        setup();
}
