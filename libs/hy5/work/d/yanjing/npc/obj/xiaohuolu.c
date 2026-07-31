inherit ITEM;

void create()
{
        set_name("红泥小火炉", ({ "xiao huolu" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("long", "红色胶泥所制的小火炉,用白铁封边.\n");
                set("value", 500);
        }
}


