inherit ITEM;

void create()
{
        set_name("ÓÍµÆ", ({ "you deng" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Õµ");
                set("long", "÷îºÚµÄÓÍµÆ,±ßÉÏ¸¡ÁËÒ»²ãµÆÓÍ.\n");
                set("value", 50);
        }
}


