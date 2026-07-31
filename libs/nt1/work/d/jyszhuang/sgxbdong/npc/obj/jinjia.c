#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIY"»Æ½ð¼×"NOR, ({ "jin jia","jia" }) );   
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "gold");
                set("value", 1000000);
                set("armor_prop/armor", 400);
                set("no_steal",1);
                set("no_get",1);
                set("no_put",1);    
        }
        setup();
}

