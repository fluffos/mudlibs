// Created by kuku@sjsh 2003.09.14

#include <weapon.h>
inherit STICK;
#include <ansi.h>
inherit "/d/quest/newequip/calculate";

void create()
{        
        string msg = "";   
        set_name(HIM"七彩棍"NOR, ({"qicai gun", "stick"}));    
        set_weight(6000);                 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 5000);
                set("material", "steel");
                set("lvl",5);
                set("Is_Diablo_Obj",1);  
                set("need_class",1);
                set("inset_hole",3);
                set("wield_msg", "$N「呼」地一声抽出一根$n握在手中！\n");
                set("unwield_msg", "$N放下手中的$n。\n");                
        }
        init_stick(90);  
        msg += "一根粉红色的棒子，上面有异彩流动，如同一条火蛇般绕在棒上。\n"+"基本攻击: "+query("weapon_prop/damage")+"\n"; 
        set("old_long",msg);
        if( query("lvl")>2){
                if( !query("identification") ) 
                        msg =query("old_long") + RED "这样东西还没有鉴定。\n"NOR;
                        set("long",msg);
        } 
        setup();
}
