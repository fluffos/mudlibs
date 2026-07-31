 inherit ITEM;
void create()
{
        set_name("ĞüËÉ", ({ "ĞüËÉ", "ËÉ","tree" }) );
        set_weight(50000);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","under");
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "¿Ã");
            set("long", "Ò»¿ÃĞüËÉ£¬¸ùÖ±ÇÍ±Ú£¬ÉíĞü¿ÕÖĞ£¬ò°Ö¦ÉìÕ¹£¬¸ÕÒãÍ¦°Î¡£\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; } 
