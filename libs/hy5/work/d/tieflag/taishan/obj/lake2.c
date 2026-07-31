 inherit ITEM;
void create()
{
        set_name("ºÚÁúÌ¶", ({ "ºÚÁúÌ¶" , "lake"}) );
        set_weight(50000);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("long", "Ò»¸öÅµ´óµÄºÚÁúÌ¶¡£\n");
                set("value", 1);
        }
    setup();
} 
int is_container() { return 1; }
