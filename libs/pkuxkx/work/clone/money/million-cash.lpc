// million-cash.c

#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIG "百万两银票" NOR, ({"million-cash", "million-cash_money", "cash"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "million-cash");
                set("long", "一张面额值一百万两银子的银票。\n");
                set("unit", "叠");
                set("base_value", 100000000);
                set("base_unit", "张");
                set("base_weight", 5);
        //      set("no_get", 1);
        //      set("no_drop", 1);
        }
        set_amount(1);
}
