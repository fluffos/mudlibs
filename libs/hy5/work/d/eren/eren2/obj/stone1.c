 inherit ITEM;
void create()
{
        set_name("³à³Ø", ({ "³à³Ø", "³à","chi" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸ö");
                set("long", "Ë®É«Îª³àµÄ³ØÌ¶\n");
                set("value", 1);
        }
        
} 
int is_container() { return 1; }  
