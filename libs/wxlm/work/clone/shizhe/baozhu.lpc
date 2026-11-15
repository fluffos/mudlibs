

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
	set_name(HIR "爆竹" NOR, ({"bao zhu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "传闻有一种叫"HIR"年"NOR"的怪兽，头长触角，凶猛异常，长年深居海底，每到除夕才爬上岸，吞食牲畜伤害人命。后来有人偶然点燃竹子"
					"发出“噼里啪啦”的响声惊走了年兽，因此各种“爆竹”慢慢传了下来，形成了中华大地上的一种传统。\n");
		set("base_unit", "节");
		set("yuanbao", 5);
		set("base_value", 50000);
		set("base_weight", 1);
        set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);
	}
	setup();
}
