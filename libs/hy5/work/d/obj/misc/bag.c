// bag by Calvin

inherit ITEM;

void create()
{
        set_name("布袋", ({ "bag" }) );
        set_weight(1000);
        set_max_encumbrance(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只用带装东西的布袋\n");
                set("value", 1000);
        }
}
int is_container() { return 1; }
