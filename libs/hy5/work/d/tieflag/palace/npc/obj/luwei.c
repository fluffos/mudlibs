 inherit ITEM;
void create()
{
        set_name("芦苇", ({ "luwei", "芦苇" }) );
        set_weight(10);
        set("no_show", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根中空的芦苇。\n");
        }
} 
