 //绿菊花

#include <armor.h>

inherit HEAD;

void create()
{
         set_name("绿菊花",({ "lu juhua", "flower", "hua" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("value", 0);
                set("material", "plant");
                set("long", "这是一朵凌霜华最喜爱的绿菊花。\n");

        }
           
        setup();
}


