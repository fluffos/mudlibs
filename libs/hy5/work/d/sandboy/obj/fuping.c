#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"浮萍"NOR, ({ "fuping","ping" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("material", "wood");
                set("long","一种生长在池塘中的"+HIG+"绿色"+NOR+"水草.\n");
        }
        setup();
}

