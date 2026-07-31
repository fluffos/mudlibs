 inherit ITEM;
void create()
{
        set_name("±øÆ÷¼Ü", ({ "weapon shelf", "shelf", "±øÆ÷¼Ü"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("prep", "on");
            set("unit", "¸ö");
            set("long", "Ò»¸ö±øÆ÷¼Ü£¬°ÚÂúÁË¸÷Ê½±øÆ÷¡£\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; }    
