

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(YEL"替身傀儡"NOR, ({"tishen kuilei"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("base_value", 10000);
		set("yuanbao", 100);
        set("no_put",1);
        set("no_get",1);
        set("no_give",1);
  		set("no_drop",1);
  		set("no_sell",1);
  		set("no_steal",1);
		set("unit", "个");
		set("base_unit", "个");
		set("weight", 10);
		set("base_weight", 10);
		set("long","这是地狱家族秘制的替身傀儡，可以免去一次死亡损失！\n");
	}
	setup();
}
