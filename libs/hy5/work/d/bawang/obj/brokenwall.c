 inherit ITEM;
void create()
{
    set_name("¶ÏÇ½", ({ "¶ÏÇ½","²ÐÇ½", "duanqiang","duan qiang" }) );
    set_weight(999999);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
        set("prep","under");
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¶Â");
            set("long", "Ò»¶Â¶ÏÇ½£¬Ò¡Ò¡Óû×¹¡£\n");
            set("value", 1);
    }
    
} 
int is_container() { return 1; }    
