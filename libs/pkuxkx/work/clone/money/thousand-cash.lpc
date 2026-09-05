// thousand-cash.c
// add color by whuan@pkuxkx ,2008-3-11
#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(RED"一千两银票"NOR, ({"thousand-cash", "cash","cash_money", "thousand-cash_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "thousand-cash");
                set("long", "一张面额值一千两银子的银票。\n");
                set("unit", "叠");
                set("base_value", 100000);
                set("base_unit", "张");
                set("base_weight", 1);
        }
        set_amount(1);
}
