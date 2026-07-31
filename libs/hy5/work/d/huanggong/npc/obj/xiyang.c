#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("西洋表", ({ "xiyang biao" }));
        set_weight(2);
   set("long", "这只洋人进贡的西洋表。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "stone");
     set("value", 0);
               // set("no_get", 1);
        }
        setup();
}
