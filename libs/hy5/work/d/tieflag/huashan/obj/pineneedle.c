 inherit ITEM;
void create()
{
        set_name("À…’Î", ({ "pineneedle", "À…’Î", "songzhen" }) );
        set_weight(50000);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("prep","in");
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "∆¨");
            set("long", "µÿ…œ∆Ã¡À“ª≤„∫Ò∫ÒµƒÀ…’Î°£\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; } 
