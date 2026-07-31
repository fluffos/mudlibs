 inherit ITEM;
void create()
{
        set_name("¹ÅÌÙ", ({ "vine", "¹ÅÌÙ" }) );
        set_weight(50000);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","inside");
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "Æ¬");
            set("long", "Ã¯ÃÜµÄ¹ÅÌÙ¸²¸ÇÁËÕûÆ¬µÄÑÂ±Ú¡£\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; }   
