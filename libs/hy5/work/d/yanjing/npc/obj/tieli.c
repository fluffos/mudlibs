inherit ITEM;

void create()
{
        set_name("残破铁犁", ({ "tie li" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "已经生锈的铁犁,边上崩了一大块.\n");
                set("value", 100);
        }
}


