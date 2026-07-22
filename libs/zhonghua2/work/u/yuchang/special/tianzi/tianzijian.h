#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_ITEMMAKE;


void create()
{
        set_name(HIY "真命天子剑" NOR, ({ "tianzijian" }));
        set("special", 1);
	 set_weight(15000);
	 set("item_make", 1);
	 set("unit", "柄");         
        set("long", "LONG_DESCRIPTION");   
        set("owner_id","ID");  
        set("no_sell", 1 ); 
        set("no_steal", 1);      
        set("value",1);   
        set("point", 560);       
        set("material", "tian jing");
        set("wield_msg", HIY "真命天子剑划破天际，阵阵金光耀眼万分，却早已落入$N" HIY"手中。\n" NOR);
        set("unwield_msg", HIY "$N" HIY "仰天长啸，真命天子剑叮呤做响，刹那间金光尽散，天子剑早已"
                          "没了踪影。\n" NOR);
        if (! check_clone()) return;
        restore();
        init_sword(apply_damage());
        setup();    
}

string long() { return query("long") + item_long(); }



