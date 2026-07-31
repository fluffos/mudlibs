inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void create()
{
	set_name(HIW"补天石碎片"NOR, ({"butian suipian", "suipian"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "块");
		set("base_weight", 1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("base_value", 8000000);
		set("long","补天石的碎片，貌似可以合成(hecheng suipian)？\n");
        set("only_do_effect", 1);
	}
	set_amount(1);
	setup();
}

int do_effect(object me)
{
	if(query_amount() < 10)
	{
		tell_object(me, "你的碎片数量不够哦～赶紧多多收集吧！\n");
		return 1;
	}
	else if(random(2))
	{	
		new(__DIR__"butian")->move(me);
		tell_object(me, "你拼凑着补天石，突然手中碎片散发五彩光辉，慢慢变成了一块补天石。\n");
		message("vision", "你看见" + me->name() + "拼凑着补天石碎片，突然碎片发出五彩光辉，" + me->name() + "合成出了补天石！\n", environment(me), ({me}) );
		add_amount(-10);
		return 1;
	}
	
	tell_object(me, "合成失败。\n");
	add_amount(-10);
	return 1;
}