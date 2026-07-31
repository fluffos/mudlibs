inherit ITEM;

void create()
{
	set_name("静心丸套餐", ({ "jingxin box" }));
	set("long", "静心丸套餐。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "个");
		set("no_give", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("no_drop", 1);
		set("only_do_effect", 1);
	}

	setup();
}

