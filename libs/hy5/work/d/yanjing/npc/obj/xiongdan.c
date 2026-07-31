inherit ITEM;

void create()
{
        set_name("熊胆", ({ "xiong dan" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "两");
                set("long", "中药材之一.\n");
                set("value", 100);
        }
}


