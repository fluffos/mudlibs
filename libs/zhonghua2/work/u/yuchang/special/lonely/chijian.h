#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_ITEMMAKE;


void create()
{
        set_name(HIR "赤剑" NOR, ({ "chijian" }));
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
        set("wield_msg", HIR "赤剑当空一击，宛如赤龙升天，瞬间落入$N手中。\n" NOR);
        set("unwield_msg", HIG"$N手中赤剑嗡嗡做响，刹那间红光尽散，赤剑便没了踪影。\n" NOR);
        if (! check_clone()) return;
        restore();
        init_sword(apply_damage());
        setup();             
       
}
string long() { return query("long") + item_long(); }




