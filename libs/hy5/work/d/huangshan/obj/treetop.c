 inherit ITEM;
void create()
{
    set_name("Ê÷¹Ú", ({ "treetop" , "leaf", "Ê÷¹Ú"}) );
    set_weight(50000);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("prep", "in");
        set("unit", "´Ô");
        set("long", "±ÌÂÌÃ¯ÃÜµÄÊ÷¹Ú¡£\n");
        set("value", 1);
    }
        
} 
int is_container() { return 1; }       
