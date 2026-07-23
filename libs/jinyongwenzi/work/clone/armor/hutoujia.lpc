// hutoujia.c

#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(YEL"虎头斗兽甲"NOR, ({ "hutou jia" , "armor", "jia" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "bronze");
		set("value", 8000);
// cut armor river@
                set("armor_prop/armor", 15);
                set("long","这件铠甲以整块铜板打造，胸口护心处雕着个狰狞的虎头。\n");
           }
        setup();
}
