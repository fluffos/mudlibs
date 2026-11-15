// thousand.c



inherit MONEY;

void create()
{
        set_name(HIY "壹仟两金票" NOR, ({"thousand-gold"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "thousand-cash");
                set("long", "一张面额值一千两黄金的银票。\n");
                set("unit", "叠");
                set("base_value", 10000000);
                set("base_unit", "张");
                set("base_weight", 5);
		    set("material", "paper");
        }
        set_amount(1);
}
