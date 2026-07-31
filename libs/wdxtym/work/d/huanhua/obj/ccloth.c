

#include <ansi.h>

#include <armor.h>



inherit CLOTH;



void create()

{

        set_name(HIB "蓝色劲装" NOR, ({"cloth"}) );

    set_weight(3000);

    if( clonep() )

       set_default_object(__FILE__);

    else {

        set("unit", "件");

                set("long", "一件普普通通的兰色劲装。\n");

        set("material", "cloth");

        set("armor_prop/armor", 2);

    }

    setup();

}

