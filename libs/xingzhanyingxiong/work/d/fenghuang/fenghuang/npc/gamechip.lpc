// gamechip.c                   
// 筹码

inherit MONEY;

void create()
{
        set_name("筹码", ({ "gambling chip", "chip", "game_money" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "coin");
                set("long", "这是在游乐场才能使用的代币。\n");
                set("unit", "些");
                set("base_value", 1);
                set("base_unit", "枚");
                set("base_weight", 1);
        }
        set_amount(1);
}

