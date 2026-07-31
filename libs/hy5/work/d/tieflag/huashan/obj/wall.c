 inherit ITEM;
void create()
{
        set_name("²ÐÇ½", ({ "wall", "²ÐÇ½" }) );
        set_weight(50000);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","in");
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "¶Â");
            set("long", "Ò»Æ¬²ÐÇ½¶ÏÍß£¬ÅÔ±ßÔÓ²ÝÑÜÉú¡£\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; }       
