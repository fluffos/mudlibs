#include <armor.h>
#include <ansi.h>;
inherit CLOTH;

void create()
{
        set_name( HIW"ÓğÃ«"NOR, ({ "yu mao", "mao" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´é");
        set("long","Ò»´éÃÀÀöµÄÓğÃ«.\n");
                set("value", 5000);
        set("combat_exp", 5000000);
                set("material", "leather");
                set("armor_prop/armor", 1);
        }
        setup();
}

