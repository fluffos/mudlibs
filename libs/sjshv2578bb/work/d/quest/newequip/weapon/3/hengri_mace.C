// Created by kuku@sjsh 2003.09.14

#include <weapon.h>
inherit MACE;
#include <ansi.h>
inherit "/d/quest/newequip/calculate";

void create()
{        
        string msg = "";   
        set_name(HIM"恒日锏"NOR, ({"hengri mace", "mace"}));    
        set_weight(3000);                 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "steel");
                set("lvl",3);
                set("Is_Diablo_Obj",1);  
                set("need_class",1);
                set("inset_hole",1);
                set("wield_msg", "只见一道蓝光闪过，$N手里已经多了一柄$n。\n");
                set("unwield_msg", "$N收起了$n，四周光芒为之一暗。\n");                
        }
        init_mace(60);  
        msg += "一柄闪闪发光的锏，显然是被人擦了又擦。\n"+"基本攻击: "+query("weapon_prop/damage")+"\n"; 
        set("old_long",msg);
        if( query("lvl")>2){
                if( !query("identification") ) 
                        msg =query("old_long") + RED "这样东西还没有鉴定。\n"NOR;
                        set("long",msg);
        } 
        setup();
}
