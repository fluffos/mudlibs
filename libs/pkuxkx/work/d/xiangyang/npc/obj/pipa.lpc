#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name(YEL"琵琶"NOR, ({ "pi pa"}) );
        set_weight(1000);
        if( clonep() )
          set_default_object(__FILE__);
        else {
          set("unit", "把");
          set("long",GRN"这是一把江南名师制作的琵琶.\n"NOR);
          set("value", 1000);
          set("material", "wood");
          set("music", "pipa");
        }
        init_hammer(10);
        setup();
}

