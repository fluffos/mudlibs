inherit ITEM;

void create()
{
        set_name("巨石", ({ "ju shi", "shi"}));
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个天然形成的巨石。\n");
        }
        setup();
}