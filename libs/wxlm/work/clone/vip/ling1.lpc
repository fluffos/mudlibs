inherit COMBINED_ITEM;
void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIW"通行令牌"NOR, ({"tongxing ling1"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_value", 10000);
		set("yuanbao", 1);
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_steal",1);
		set("base_unit", "个");
		set("long","这是地狱家族发放的通行令牌，遇到劳有诺和空鉴时可以派上用场！\n");
	}
	setup();
}

