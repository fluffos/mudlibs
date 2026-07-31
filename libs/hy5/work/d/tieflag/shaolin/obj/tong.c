 inherit ITEM;
void create()
{
        set_name("Í­±®", ({ "tong bei", "bei", "Í­±®"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "behind");
                set("unit", "×ù");
                set("long", "ÖıÔìÍ­ÃÖÀÕ±®¼Ç\n");
                set("value", 1);
        }
} 
int is_container() { return 1; }   
