#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
 set_name(HIR "飞凤丝衣" NOR, ({ "cloth", "siyi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "件");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", 1000);
               set("female_only", 1);
             set("no_get",1); 
               set("no_drop",1); 
               set("no_give",1); 
                set("long","这是痴心妄想门的宝衣，是开山门主用冰蚕丝做成。\n");
      }
        setup();
}
