 inherit ITEM;
void create()
{
        set_name("Ç½±Ú", ({ "wall", "Ç½", "Ç½±Ú"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("prep", "on");
            set("unit", "¶Â");
            set("long", "Ò»¶Â°×Ç½¡£\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; }      
