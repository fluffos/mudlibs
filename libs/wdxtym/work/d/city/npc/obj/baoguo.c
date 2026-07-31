// baoguo.c 包裹

inherit ITEM;

void create()
{
	set_name("包裹", ({ "baoguo", "bag" }));
	set_weight(300);
	set_max_encumbrance(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一只用细布织成的袋子，好像可以装东西。\n");
		set("value", 200);
	}
}

int is_container() { return 1; }
