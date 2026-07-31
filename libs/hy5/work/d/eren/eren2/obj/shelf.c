 inherit ITEM;
void create()
{
    set_name("书架", ({ "shelf" , "书架"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "张");
        set("long", "一张很精致的红木书架。\n");
                set("value", 1);
        }
        
} 
int is_container() { return 1; }   
