// comb.c
inherit ITEM;
void create()
{
        set_name("红木梳子", ({ "annatto comb", "comb" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 170);
                set("long", "一把质地相当细致的红木梳子。\n");
        }
        setup();
}
