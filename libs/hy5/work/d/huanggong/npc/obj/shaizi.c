#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("骰子", ({ "shai zi" }));
        set_weight(2);
   set("long", "这粒灌了铅的骰子。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("material", "stone");
     set("value", 0);
                //set("no_get", 1);
        }
        setup();
}
