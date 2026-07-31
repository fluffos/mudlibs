// Created by kuku@sjsh 2003.09.14

#include <weapon.h>
inherit WHIP;
#include <ansi.h>
inherit "/d/quest/newequip/calculate";

void create()
{        
        string msg = "";   
        set_name(HIB"恐惧鞭"NOR, ({"kongju bian", "whip"}));    
        set_weight(4000);                 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 5000);
                set("material", "steel");
                set("lvl",4);
                set("Is_Diablo_Obj",1);  
                set("need_class",-1);
                set("inset_hole",2);
                set("wield_msg", "$N左手一甩，一条蛇型皮鞭绕腰而出。\n");
                set("unwield_msg", "$N把手中$n缠回腰间。\n");                
        }
        init_whip(80);  
        msg += "一条长长的鞭子，上面沾满了血。\n"+"基本攻击: "+query("weapon_prop/damage")+"\n"; 
        set("old_long",msg);
        if( query("lvl")>2){
                if( !query("identification") ) 
                        msg =query("old_long") + RED "这样东西还没有鉴定。\n"NOR;
                        set("long",msg);
        } 
        setup();
}
