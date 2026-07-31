 inherit ITEM;
void create()
{
        set_name("破马车", ({ "mache", "cart" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", "一辆少了一个轮子的破马车，车夫倒毙在座位上。\n");
                set("value", 1);
        }
} 
int is_container() { return 1; } 
