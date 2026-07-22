#include <armor.h>
#include <ansi.h>
#include <mudlib.h>
inherit SURCOAT;
 
void create()
{
         set_name(HIC"黄金腰带"NOR, ({ "huangjin yaodai", "yaodai" }));

        set_weight(500);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "条");
                set("long", "这是一件黄金腰带，用以保护腹部。增加防御力500,下线不掉。\n");
              	set("jym_money",2);
	      	set("no_put",1);
              	set("no_sell",1);
              	set("no_get", 1);
              	set("no_give", 1);
              	set("no_drop",1);
              	set("armor_prop/armor", 500);
              	set("armor_prop/dodge", -3);
        }
        setup();
}