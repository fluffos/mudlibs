// Created by kuku@sjsh 2003.09.14

#include <weapon.h>
inherit SWORD;
#include <ansi.h>
inherit "/d/quest/newequip/calculate";

void create()
{        
        string msg = "";   
        set_name(HIB"恶魔剑"NOR, ({"emo jian", "sword"}));    
        set_weight(4000);                 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 5000);
                set("material", "steel");
                set("lvl",2);
                set("Is_Diablo_Obj",1);  
                set("need_class",-1);
                set("wield_msg", "$n「唰」地从剑鞘中弹出，落入$N的手中，剑尖还兀自闪个不停。\n");
                set("unwield_msg", "$N将手中的$n插入腰间，脸色更加阴沉了。\n");                
        }
        init_sword(50);  
        msg += "一柄镇妖降魔的宝剑。\n"+"基本攻击: "+query("weapon_prop/damage")+"\n"; 
        msg += query_desc(); 
        set("long",msg);
        setup();
}
