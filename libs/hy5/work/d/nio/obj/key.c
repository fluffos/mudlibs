// /u/jpei/thd/obj/key.c

inherit ITEM;

void create()
{
        set_name("Í­Ô¿³×", ({ "kezhan key", "key" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
        }
        setup();
}

